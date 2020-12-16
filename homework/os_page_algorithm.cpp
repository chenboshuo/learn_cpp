#include <cmath>
#include <ctime>
#include <iostream>
#include <string>

#define BLOCK_SIZE 3        // 定义最大块数
#define REFERENCE_TIMES 20  // 定义访问次数
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
  pageInfor *page_reference_series;
  int memory_state[BLOCK_SIZE][REFERENCE_TIMES];
  // memory_state[i][j] 表示内存i在第j次访问存储的页号
  int hit_times;  // 记录命中次数
  /**
   * 在时刻t保持t-1的内存状态
   * @param t 访问的时刻
   */
  void keep_old_memory_states(int t) {
    for (int b = 0; b < BLOCK_SIZE; b++) {
      memory_state[b][t] = memory_state[b][t - 1];
    }
  }
  /**
   * 寻找空块，如果没有返回NOT_EXIST
   * @return 空块的块号（索引）
   */
  int get_space() {
    for (int b = 0; b < BLOCK_SIZE; b++) {
      if (block[b].page_id == -1) { return b; }
    }
    return NOT_EXIST;
  }
  /**
   * 将timer的值最大的内存快替换,
   * timer的意义在不同算法中不同，
   * 在FIFO中，timer为已经在内存中的时间，
   * 在OPT算法中，timer为下一次出现的时间
   * (我们用该函数将不在出现或者下次出现最晚的物理块替换)
   * @param t 时刻
   */
  void replace_block(int t) {
    int replace_pos = 0;
    for (int i = 0; i < BLOCK_SIZE; i++) {
      if (block[i].timer >= block[replace_pos].timer) {  //
        replace_pos = i;
      }
    }
    block[replace_pos] = page_reference_series[t];  // 注意：新页的timer是0
    memory_state[replace_pos][t] =
        block[replace_pos].page_id;  // 记录替换后的结果
  }
  /**
   * 增加所有块的存在时间
   */
  void increase_timer() {
    for (int j = 0; j < BLOCK_SIZE; j++) block[j].timer++;
  }

  /**
   * 是否是简单情况，
   * 如果可以直接命中或者有空闲空间，我们认为这是简单情况，
   * 在该函数直接处理
   * @param  t 时刻t
   * @return   是否是简单情况
   */
  bool is_easy_case(int t) {
    if (can_hit(t)) {  // 如果在当前内存快中存在，直接命中，内存状态不变
      hit_times++;
      return true;
    }
    int space = get_space();
    if (space != NOT_EXIST) {  // 如果有空闲空间，内存分配给对应页
      block[space] = page_reference_series[t];  // 内存空块分配
      memory_state[space][t] = block[space].page_id;
      return true;
    }
    return false;
  }

 public:
  PageReplacement() {
    hit_times = 0;
    // 初始化物理块
    block = new pageInfor[BLOCK_SIZE];
    for (int i = 0; i < BLOCK_SIZE; i++) {
      block[i].page_id = NOT_EXIST;
      block[i].timer = 0;
    }

    // 从全局变量中读取访问序列
    page_reference_series = new pageInfor[REFERENCE_TIMES];
    for (int i = 0; i < REFERENCE_TIMES; i++) {
      page_reference_series[i].page_id = reference_series[i];
      page_reference_series[i].timer = 0;
    }
    // 初始化记录序列
    for (int i = 0; i < REFERENCE_TIMES; i++) {
      for (int j = 0; j < BLOCK_SIZE; j++) { memory_state[j][i] = -1; }
    }
  }
  ~PageReplacement() {
    hit_times = 0;  // TODO ??
  }

  /**
   * 第i次访问是否命中，即第i次的页号page[i]有没有对应的块号block[b]
   * @param  i 第i次访问
   * @return   是否命中
   */
  bool can_hit(int i) {
    for (int b = 0; b < BLOCK_SIZE; b++) {
      if (block[b].page_id == page_reference_series[i].page_id) { return true; }
    }
    return false;
  }

  /**
   * 生成FIFO(first-in,first-out algorithm)页面置换算法的内存状况
   */
  void FIFO() {
    for (int t = 0; t < REFERENCE_TIMES; t++) {
      keep_old_memory_states(t);  // 将当前的状态初始化为t-1时刻的状态
      if (!is_easy_case(t)) {  // 没有空间
        replace_block(t);
      }
      increase_timer();
    }
  }
  /**
   * 利用OPT页面置换算法(optimal page replacement)，
   * 根据访问序列来保证缺页率最小
   * 记录内存状态
   */
  void OPT() {
    for (int t = 0; t < REFERENCE_TIMES; t++) {
      keep_old_memory_states(t);  // 初始化时刻t的内存状态
      if (!is_easy_case(t)) {     // 没有命中且没有空间
        for (int b = 0; b < BLOCK_SIZE; ++b) {
          for (int peek = t; peek < REFERENCE_TIMES; peek++) {
            if (block[b].page_id != page_reference_series[peek].page_id) {
              block[b].timer = 1000;  // 设置一个很大的数
            } else {
              block[b].timer = peek;  // 出现的越晚，timer越大
              break;
            }
          }
        }
        replace_block(t);
      }
    }
  }

  void print_outcome() {
    cout << "-------------------------------------------" << endl;

    cout << "访问\t内存状况" << endl;
    for (int i = 0; i < REFERENCE_TIMES; ++i) {
      cout << reference_series[i] << "\t";
      for (int b = 0; b < BLOCK_SIZE; ++b) {
        int o = memory_state[b][i];
        if (o >= 0) {
          cout << o << " ";
        } else {
          cout << ". ";
        }
      }
      cout << endl;
    }
    cout << "-------------------------------------------" << endl;
    cout << "命中率:" << hit_times << "/" << REFERENCE_TIMES << endl;
    // test_series.~PageReplacement(); // TODO ??
    cout << endl;
  }
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

// int PageReplacement::

// int PageReplacement::

// void PageReplacement::

// void PageReplacement::BlockClear() {
//   for (int i = 0; i < BLOCK_SIZE; i++) {
//     block[i].page_id = -1;
//     block[i].timer = 0;
//   }
// }

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
  cin.clear();  // 清除多余输入，防止影响接下来的操作。
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
/**
 * 提示用户输入直到输入正确结果，
 * 并处理退出
 * 返回用户的有效的选择
 * @return 用户选择的算法
 */
char get_select() {
  char select;
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
  return select;
}

int main() {
  print_title();
  while (1) {
    create_page_reference_series();

    char select = '1';  // 记录用户输入
    while (select == '1' || select == '2' || select == '3') {
      select = get_select();

      if (select == '1') {
        cout << "您选择使用FIFO页面置换算法" << endl;
        cout << "FIFO算法状态:" << endl;
        PageReplacement test_FIFO;
        test_FIFO.FIFO();
        test_FIFO.print_outcome();
      } else if (select == '2') {
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
      } else if (select == '3') {
        cout << "您选择使用OPT页面置换算法" << endl;
        cout << "OPT算法状态:" << endl;
        PageReplacement test_OPT;
        test_OPT.OPT();
        test_OPT.print_outcome();
        cout << endl;
      }
    }
  }
}
