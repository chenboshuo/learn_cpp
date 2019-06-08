#include <iomanip>
#include <iostream>

using namespace std;

class Staff {
 public:
  string num;          // 编号
  string name;         // 姓名
  int rate_of_attend;  // 出勤率
  int basic_salary;    // 工资
  int prize;           // 奖金

  Staff(const string &num, const string &name, int rate_of_attend,
        int basic_salary, int prize)
      : num(num),
        name(name),
        rate_of_attend(rate_of_attend),
        basic_salary(basic_salary),
        prize(prize) {}

  virtual int calculate_wages() {
    // 员工实发工资 = 基本工资 + 奖金 * 出勤率
    return static_cast<int>(basic_salary + prize * rate_of_attend * 0.01);
  }
  virtual void output() {
    cout << "No. " << num << "    name: " << name << endl;
    ;
    cout << "rate of attend: " << rate_of_attend << " %" << endl;
    cout << "Basic salary: " << basic_salary << endl;
    cout << "Prize: " << prize << endl;
    cout << "real wages: " << calculate_wages() << endl;
  }
};

class SalesMan : virtual public Staff {
 public:
  int deduct_rate;    // 提成
  int person_amount;  // 个人销售额
  SalesMan(const string &num, const string &name, int rate_of_attend,
           int basic_salary, int prize, int deduct_rate, int person_amount)
      : Staff(num, name, rate_of_attend, basic_salary, prize),
        deduct_rate(deduct_rate),
        person_amount(person_amount) {}

  int calculate_wages() {
    // 销售员实发工资 = 基本工资 + 奖金 * 出勤率 + 个人销售额 * 销售员提成比例
    return static_cast<int>(basic_salary + prize * rate_of_attend * 0.01 +
                            person_amount * deduct_rate * 0.01);
  }
  void output() {
    cout << "No. " << num << "    name: " << name << endl;
    ;
    cout << "rate of attend: " << rate_of_attend << " %" << endl;
    cout << "Basic salary: " << basic_salary << endl;
    cout << "Prize: " << prize << endl;
    cout << "Personal amount: " << person_amount << endl;
    cout << "deduct rate: " << deduct_rate << " %" << endl;
    cout << "real wages: " << calculate_wages() << endl;
  }
};

class Manager : virtual public Staff {
 protected:
  int total_deduct_rate;  // 经理提成比例
  int total_amount;       // 总销售成员
 public:
  Manager(const string &num, const string &name, int rate_of_attend,
          int basic_salary, int prize, int total_deduct_rate, int total_amount)
      : Staff(num, name, rate_of_attend, basic_salary, prize),
        total_deduct_rate(total_deduct_rate),
        total_amount(total_amount) {}

  int calculate_wages() {
    // 经理实发工资 = 基本工资 + 奖金 * 出勤率 + 总销售额 * 经理提成比例
    return basic_salary + prize * rate_of_attend * 0.01 +
           total_amount * total_deduct_rate * 0.01;
  }

  void output() {
    cout << "No. " << num << "    name: " << name << endl;
    ;
    cout << "rate of attend: " << rate_of_attend << " %" << endl;
    cout << "Basic salary: " << basic_salary << endl;
    cout << "Prize: " << prize << endl;
    cout << "Total amount: " << total_amount << endl;
    cout << "Total deduct rate: " << total_deduct_rate << " %" << endl;
    cout << "real wages: " << calculate_wages() << endl;
  }
};

class SalesManager : public SalesMan, public Manager {
 public:
  SalesManager(const string &num, const string &name, int rate_of_attend,
               int basic_salary, int prize, int deduct_rate, int person_amount,
               int total_deduct_rate, int total_amount)
      : Staff(num, name, rate_of_attend, basic_salary, prize),
        SalesMan(num, name, rate_of_attend, basic_salary, prize, deduct_rate,
                 person_amount),
        Manager(num, name, rate_of_attend, basic_salary, prize,
                total_deduct_rate, total_amount) {}
  int calculate_wages() {
    // 销售经理实发工资 =基本工资 + 奖金 * 出勤率 + 个人销售额 * 销售员提成比例+
    // 总销售额 * 经理提成比例
    return static_cast<int>(basic_salary + prize * rate_of_attend * 0.01 +
                            prize * rate_of_attend * 0.01 +
                            total_amount * total_deduct_rate * 0.01);
  }

  void output() {
    cout << "No. " << num << "    name: " << name << endl;
    ;
    cout << "rate of attend: " << rate_of_attend << " %" << endl;
    cout << "Basic salary: " << basic_salary << endl;
    cout << "Prize: " << prize << endl;
    cout << "Total amount: " << total_amount << endl;
    cout << "Total deduct rate: " << total_deduct_rate << " %" << endl;
    cout << "Personal amount: " << person_amount << endl;
    cout << "deduct rate: " << deduct_rate << " %" << endl;
    cout << "real wages: " << calculate_wages() << endl;
  }
};

int main(int argc, char const *argv[]) {
  // 测试staff类
  Staff a_staff("001", "a staff", 50, 5000, 1000);
  a_staff.output();
  /* output
    No. 001    name: a staff
    rate of attend: 50 %
    Basic salary: 5000
    Prize: 1000
    real wages: 5500
   */

  // 测试saleMan
  cout << "\n\n";
  SalesMan a_salesman("002", "a SalesMan", 100, 10000, 1000, 10, 50000);
  a_salesman.output();
  /* output
  No. 002    name: a SalesMan
  rate of attend: 100 %
  Basic salary: 10000
  Prize: 1000
  Personal amount: 50000
  deduct rate: 10 %
  real wages: 16000
   */

  // 测试Manager
  cout << "\n\n";
  Manager a_manager("003", "a manager", 20, 5000, 10000, 20, 100000);
  a_manager.output();
  /*
  No. 003    name: a manager
  rate of attend: 20 %
  Basic salary: 5000
  Prize: 10000
  Total amount: 100000
  Total deduct rate: 20 %
  real wages: 27000
   */

  // 测试SalesManager
  cout << "\n\n";
  SalesManager a_salesmanager("004", "a salesmanger", 80, 8000, 6000, 30, 600,
                              5, 10000);
  a_salesmanager.output();
  /* output
    No. 004    name: a salesmanger
    rate of attend: 80 %
    Basic salary: 8000
    Prize: 6000
    Total amount: 10000
    Total deduct rate: 5 %
    Personal amount: 600
    deduct rate: 30 %
    real wages: 18100
   */
  return 0;
}

/*
 * output
No. 001    name: a staff
rate of attend: 50 %
Basic salary: 5000
Prize: 1000
real wages: 5500


No. 002    name: a SalesMan
rate of attend: 100 %
Basic salary: 10000
Prize: 1000
Personal amount: 50000
deduct rate: 10 %
real wages: 16000


No. 003    name: a manager
rate of attend: 20 %
Basic salary: 5000
Prize: 10000
Total amount: 100000
Total deduct rate: 20 %
real wages: 27000


No. 003    name: a salesmanger
rate of attend: 80 %
Basic salary: 8000
Prize: 6000
Total amount: 10000
Total deduct rate: 5 %
Personal amount: 600
deduct rate: 30 %
real wages: 18100
Finished in 4 ms
No. 001    name: a staff
rate of attend: 50 %
Basic salary: 5000
Prize: 1000
real wages: 5500


No. 002    name: a SalesMan
rate of attend: 100 %
Basic salary: 10000
Prize: 1000
Personal amount: 50000
deduct rate: 10 %
real wages: 16000


No. 003    name: a manager
rate of attend: 20 %
Basic salary: 5000
Prize: 10000
Total amount: 100000
Total deduct rate: 20 %
real wages: 27000


No. 004    name: a salesmanger
rate of attend: 80 %
Basic salary: 8000
Prize: 6000
Total amount: 10000
Total deduct rate: 5 %
Personal amount: 600
deduct rate: 30 %
real wages: 18100
 */
