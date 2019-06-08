/**
 * 6.12 停车费问题
 * 停车场3小时收费2美元，超过3小时，每增加一小时或不到一小时收取0.5$的附加费用。
 * 24小时内最多收10$，假设没有车子一次停车超出24小时。
 * 编写一个程序，计算显示三个客户各自停车费用。
 * 要求输入每个客户的停车时间。
 * 程序应以整齐的表格形式打印结果，并计算昨天收费的总和。
 * 使用calculateCharge来确定每个客户的停车费用。
 */
#include <cmath>    // ceil
#include <iomanip>  // setw
#include <iostream>

using namespace std;

class Parking {
 private:
  int time = 0;
  float charge = 2;

 public:
  /**
   * 设定停车时间
   * @param t 停车时间
   */
  void setTime(float t) {
    if (t == 0 || t > 24) {  // 确认数据的有效性
      cout << "Please varify data validity" << '\n';
    }
    time = ceil(t);
    /**
     * ceil
     *
     * Rounds x upward, returning the smallest integral value that is not less
     * than x. 返回不大于t的最大值 Return Value The smallest integral value that
     * is not less than x (as a floating-point value).
     */
  }

  float calculateCharge() {
    if (time == 0) { return 0; }
    for (int t = time; t > 3; t--) { charge += 0.5; }
    return charge < 10 ? charge : 10;  // 保证费用小于10
  }
};
int main(int argc, char const *argv[]) {
  Parking car1, car2, car3;
  float time1, time2, time3;
  float charge1, charge2, charge3;
  // 输入
  cout << "Enter the car1's parking time:  " << '\n';
  std::cin >> time1;
  car1.setTime(time1);
  charge1 = car1.calculateCharge();

  cout << "Enter the car2's parking time:  " << '\n';
  std::cin >> time2;
  car2.setTime(time2);
  charge2 = car2.calculateCharge();

  cout << "Enter the car3's parking time:  " << '\n';
  std::cin >> time3;
  car3.setTime(time3);
  charge3 = car3.calculateCharge();

  // cout << car1.calculateCharge() << '\n';

  cout << "\n";
  cout << "Car" << setw(13) << "Hours" << setw(15) << "Charge" << '\n';
  cout << fixed << "1" << setw(15) << setprecision(1) << time1 << setw(15)
       << setprecision(2) << charge1 << '\n';
  cout << fixed << "2" << setw(15) << setprecision(1) << time2 << setw(15)
       << setprecision(2) << charge2 << '\n';
  cout << fixed << "3" << setw(15) << setprecision(1) << time3 << setw(15)
       << setprecision(2) << charge3 << '\n';
  cout << fixed << "Total" << setw(11) << setprecision(1)
       << time1 + time2 + time3 << setw(15) << setprecision(2)
       << charge1 + charge2 + charge3 << '\n';
  // 不加fixed时setprecision 为保留有效数字

  return 0;
}
// Enter the car1's parking time:
// 1.5
// Enter the car2's parking time:
// 4
// Enter the car3's parking time:
// 24
//
// Car        Hours         Charge
// 1            1.5           2.00
// 2            4.0           2.50
// 3           24.0          10.00
// Total       29.5          14.50
