#include <cmath>
#include <ctime>
// #include <cstdio>
#include <iostream>
#include <string>

#define BLOCK_SIZE 3        // 定义最大块数
#define REFERENCE_TIMES 12  // 定义访问次数
#define NOT_EXIST -1        // -1 表示不存在
using namespace std;

int reference_series[REFERENCE_TIMES];  // 页面访问序列 TODO 局部化
int Num = 0;

// 页面信息的定义
struct pageInfor {
  int page_id;  // 页面的标识，即页号
  int timer;
};
/**
 * 页面置换算法的类
 */
class PageReplacement {
 private:
  pageInfor *block;
  pageInfor *page;

 public:
  int memory_state[BLOCK_SIZE][REFERENCE_TIMES];
  // memory_state[i][j] 表示内存i在第j次访问存储的页号
  int hit_times;  // 记录命中次数
  PageReplacement() {
    hit_times = 0;
    // 初始化物理块
    block = new pageInfor[BLOCK_SIZE];
    for (int i = 0; i < BLOCK_SIZE; i++) {
      block[i].page_id = NOT_EXIST;
      block[i].timer = 0;
    }

    // 从全局变量中读取访问序列
    page = new pageInfor[REFERENCE_TIMES];
    for (int i = 0; i < REFERENCE_TIMES; i++) {
      page[i].page_id = reference_series[i];
      page[i].timer = 0;
    }
    for (int i = 0; i < REFERENCE_TIMES; i++) {
      for (int j = 0; j < BLOCK_SIZE; j++) { memory_state[j][i] = 0; }
    }
  }
  ~PageReplacement() {
    hit_times = 0;  // TODO ??
  }
  int findSpace();

  /**
   * 寻找页号对应快号，如果没找到，返回NOT_EXIST(-1)
   * @param  page_id 要查找的页号
   * @return         要查找的块号
   */
  int get_block_id(int page_id) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
      if (block[i].page_id == page[page_id].page_id) { return i; }
    }
    return NOT_EXIST;
  }
  int findReplace();

  /**
   * 生成FIFO页面置换算法的内存状况
   */
  void FIFO() {
    int space, position;
    for (int i = 0; i < REFERENCE_TIMES; i++) {
      int exist = get_block_id(i);
      if (exist != NOT_EXIST) {  // 如果在当前内存快中存在，直接命中
        for (int b = 0; b < BLOCK_SIZE; b++) {
          memory_state[b][i] = memory_state[b][i - 1];
        }
        hit_times++;
      } else {
        space = findSpace();
        if (space != -1) {
          for (int b = 0; b < BLOCK_SIZE; b++) {
            memory_state[b][i] = memory_state[b][i - 1];
          }
          block[space] = page[i];
          memory_state[space][i] = block[space].page_id;
        } else {
          for (int b = 0; b < BLOCK_SIZE; b++) {
            memory_state[b][i] = memory_state[b][i - 1];
          }
          position = findReplace();
          block[position] = page[i];
          memory_state[position][i] = block[position].page_id;
        }
      }
      for (int j = 0; j < BLOCK_SIZE; j++) block[j].timer++;
    }
  }
  void OPT();
  void BlockClear();
  void print_outcome() {
    cout << "-------------------------------------------" << endl;
    // for (int p = 0; p < BLOCK_SIZE; p++) {
    //   for (int q = 0; q < REFERENCE_TIMES; q++) {
    //     cout << memory_state[p][q] << " ";
    //   }
    //   cout << endl;
    // }
    cout << "访问\t内存状况" << endl;
    for (int i = 0; i < REFERENCE_TIMES; ++i) {
      cout << reference_series[i] << "\t";
      for (int b = 0; b < BLOCK_SIZE; ++b) {
        cout << memory_state[b][i] << " ";
      }
      cout << endl;
    }
    cout << "-------------------------------------------" << endl;
    cout << "命中率:" << hit_times << "/" << REFERENCE_TIMES << endl;
    // test_series.~PageReplacement(); // TODO ??
    cout << endl;
  }
  // void initial() {
  //   page = new pageInfor[REFERENCE_TIMES];
  //   for (int i = 0; i < REFERENCE_TIMES; i++) {
  //     page[i].page_id = reference_series[i];
  //     page[i].timer = 0;
  //   }
  //   for (int i = 0; i < REFERENCE_TIMES; i++) {
  //     for (int j = 0; j < BLOCK_SIZE; j++) { memory_state[j][i] = 0; }
  //   }
  // }
};

/**
 * 生成并打印访问序列
 */
void gengerate_random_reference_series() {
  srand((unsigned)time(NULL));
  for (int i = 0; i < REFERENCE_TIMES; i++) {
    reference_series[i] = rand() % 10;
  }
  cout << "页面访问：";
  for (int i = 0; i < REFERENCE_TIMES; i++) {
    cout << reference_series[i] << " ";
  }
  cout << endl;
}

int PageReplacement::findSpace() {
  for (int i = 0; i < BLOCK_SIZE; i++)
    if (block[i].page_id == -1) return i;
  return -1;
}

int PageReplacement::findReplace() {
  int pos = 0;
  for (int i = 0; i < BLOCK_SIZE; i++)
    if (block[i].timer >= block[pos].timer) pos = i;
  return pos;
}

// void PageReplacement::

void PageReplacement::BlockClear() {
  for (int i = 0; i < BLOCK_SIZE; i++) {
    block[i].page_id = -1;
    block[i].timer = 0;
  }
}

typedef struct page {
  int num;
  int time;
} Page;

Page b[BLOCK_SIZE];
Page call[BLOCK_SIZE];
int c[BLOCK_SIZE][REFERENCE_TIMES];
int queue[100];
int K;

void InitL(Page *b, int c[BLOCK_SIZE][REFERENCE_TIMES]) {
  int i, j;
  for (i = 0; i < BLOCK_SIZE; i++) {
    b[i].num = -1;
    b[i].time = REFERENCE_TIMES - i - 1;
  }
  for (i = 0; i < BLOCK_SIZE; i++)
    for (j = 0; j < REFERENCE_TIMES; j++) c[i][j] = -1;
}
int GetMax(Page *b) {
  int i;
  int max = -1;
  int tag = 0;
  for (i = 0; i < BLOCK_SIZE; i++) {
    if (b[i].time > max) {
      max = b[i].time;
      tag = i;
    }
  }
  return tag;
}
int Equation(int fold, Page *b) {
  int i;
  for (i = 0; i < BLOCK_SIZE; i++) {
    if (fold == b[i].num) return i;
  }
  return -1;
}
void Lru(int fold, Page *b) {
  int i;
  int val;
  val = Equation(fold, b);
  if (val >= 0) {
    b[val].time = 0;
    for (i = 0; i < BLOCK_SIZE; i++)
      if (i != val) b[i].time++;
  } else {
    queue[++K] = fold;
    val = GetMax(b);
    b[val].num = fold;
    b[val].time = 0;
    for (i = 0; i < BLOCK_SIZE; i++)
      if (i != val) b[i].time++;
  }
}

void PageReplacement::OPT() {
  int exist, space, position;
  for (int i = 0; i < REFERENCE_TIMES; i++) {
    exist = get_block_id(i);
    if (exist != -1) {
      for (int b = 0; b < BLOCK_SIZE; b++) {
        memory_state[b][i] = memory_state[b][i - 1];
      }
      hit_times++;
    } else {
      space = findSpace();
      if (space != -1) {
        for (int b = 0; b < BLOCK_SIZE; b++) {
          memory_state[b][i] = memory_state[b][i - 1];
        }
        block[space] = page[i];
        memory_state[space][i] = block[space].page_id;
      } else {
        for (int k = 0; k < BLOCK_SIZE; k++) {
          memory_state[k][i] = memory_state[k][i - 1];
          for (int j = i; j < REFERENCE_TIMES; j++) {
            if (block[k].page_id != page[j].page_id) {
              block[k].timer = 1000;
            } else {
              block[k].timer = j;
              break;
            }
          }
        }
        position = findReplace();
        block[position] = page[i];
        memory_state[position][i] = block[position].page_id;
      }
    }
  }
}

void input_reference_series() {
  cout << "请输入" << REFERENCE_TIMES << "个页面号作为访问序列:" << endl;
  for (int i = 0; i < REFERENCE_TIMES; i++) {  // 写入用户输入
    // reference_series[i] = input_reference_series();
    int in;
    cin >> in;
    if (cin.fail()) {
      cout << "输入错误，退出程序" << endl;
      exit(1);
    }
    reference_series[i] = in;
  }
}

/**
 * 打印生成页面的提示，完成页面访问序列的生成
 */
void create_page_reference_series() {
  cout << "请选择产生页面访问序列的方法 a:随机产生  b:输入产生" << endl;
  cout << "- ";
  char input;
  cin >> input;
  while (input != 'a' && input != 'b') {
    cout << "输入错误，请重新输入:";
    cin >> input;
  }
  if (input == 'a') {  // 随机生成字符串
    gengerate_random_reference_series();
  }
  if (input == 'b') {  //用户主动输入
    input_reference_series();
  }
  cout << endl;
  cout << "|---------------------------------------------------------------|"
       << endl;
}

/**
 * 打印标题信息
 */
void print_title() {
  cout << "|-----------------------页 面 置 换 算 法-----------------------|"
       << endl;
  cout << "|---------------------------------------------------------------|"
       << endl;
}

int main() {
  print_title();
  while (1) {
    create_page_reference_series();

    PageReplacement test_OPT;
    char select = '1';  // 记录用户输入
    while (select == '1' || select == '2' || select == '3') {
      cout << "请选择要应用的算法:<1>FIFO算法  <2>LRU算法  <3>OPT算法  <0>退出"
           << endl;
      cout << "- ";
      cin >> select;
      while (select != '0' && select != '1' && select != '2' && select != '3' &&
             select != 'q') {
        cout << "您的输入无效,请重新输入:" << endl;
        cin >> select;
      }
      if (select == '0' || select == 'q') {  // 处理退出
        cout << "退出程序." << endl;
        exit(0);  // 退出程序
      }

      if (select == '1') {
        PageReplacement test_FIFO;
        cout << "您选择使用FIFO算法页面置换" << endl;
        cout << "FIFO算法状态:" << endl;
        test_FIFO.FIFO();
        test_FIFO.print_outcome();
      }
      if (select == '2') {
        int i, j;
        K = -1;
        InitL(b, c);
        for (i = 0; i < REFERENCE_TIMES; i++) {
          Lru(reference_series[i], b);
          c[0][i] = reference_series[i];
          for (j = 0; j < BLOCK_SIZE; j++) c[j][i] = b[j].num;
        }
        cout << "您选择的是菜单<2>" << endl;
        cout << "LRU算法状态:" << endl;
        cout << "------------------------------------------" << endl;
        for (i = 0; i < BLOCK_SIZE; i++) {
          for (j = 0; j < REFERENCE_TIMES; j++) {
            if (c[i][j] == -1)
              cout << " 0";
            else
              cout << " " << c[i][j];
          }
          cout << " " << endl;
        }
        cout << "------------------------------------------" << endl;
        cout << "命中率:" << (REFERENCE_TIMES - (K + 1)) << "/"
             << REFERENCE_TIMES;
        cout << '\t';
        cout << endl;
      }
      if (select == '3') {
        cout << "您选择的是菜单<3>" << endl;
        cout << "OPT算法状态:" << endl;
        // test_OPT.initial();
        test_OPT.OPT();
        test_OPT.BlockClear();
        cout << "------------------------------------------" << endl;
        for (int p = 0; p < BLOCK_SIZE; p++) {
          for (int q = 0; q < REFERENCE_TIMES; q++)
            cout << test_OPT.memory_state[p][q] << " ";
          cout << endl;
        }
        cout << "------------------------------------------" << endl;
        cout << "命中率:" << test_OPT.hit_times << "/" << REFERENCE_TIMES
             << endl;
        test_OPT.~PageReplacement();
        cout << endl;
      }
    }
  }
}
