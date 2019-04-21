class rational{
 public:
  //构造函数
  rational(int num=0,int denom=1);
  //重载比较操作符
  int operator<(rational r) const;
  int operator<=(rational r) const;
  int operator==(rational r) const;
  int operator!=(rational r) const;
 private:
  //定义一个有理数num为分母，den为分子
  long num,den;
};
