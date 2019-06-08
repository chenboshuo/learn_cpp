#include <iostream>

class Account {
 private:
  float balance;

 public:
  /**
   * 设置余额
   * @param money 余额
   */
  void setBalance(float money) {
    if (money > 0) {
      balance = money;
    } else {
      std::cerr << "balance should be nonnegative" << '\n';
    }
  }
  /**
   * 存钱,保证金额大于0
   * @param money 金额
   */
  void credit(float money) {
    if (money > 0) {
      balance += money;
      std::cout << "the balance is " << balance << '\n';
    } else {
      std::cerr << "save money should be nonnegative" << '\n';
    }
  }

  void debit(float money) {
    if (money <= balance) {
      balance -= money;
      std::cout << "the balance is " << balance << '\n';
    } else {
      std::cout << "Debit amount exceed account balance" << '\n';
    }
  }

  /**
   * 返回余额
   * @return 余额
   */
  float getBalance() { return balance; }
};

int main(int argc, char const *argv[]) {
  Account my_alipay, my_wechat;
  my_alipay.setBalance(0.00);
  std::cout << "my_alipay:  " << my_alipay.getBalance() << '\n';
  my_wechat.setBalance(5.00);
  std::cout << "my_alipay:  " << my_wechat.getBalance() << '\n';
  my_alipay.credit(3);
  my_wechat.debit(4);
  return 0;
}
// balance should be nonnegative
// my_alipay:  0
// my_alipay:  5
// the balance is 3
// the balance is 1
