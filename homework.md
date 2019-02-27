# 第三章
## 3.9 不用using命令使用`string`

```
std::string
```
## 3.10 说明为什么类可以为成员提供`set`, `get`函数

可以通过这类函数修改类的属性

## 3.11 修改Gradebook类
- [x]包括第二个string数据成员,他表示授课教师的名字
- [x]提供一个可以改变教师姓名的函数,以及可以得到名字的get
- [x]修改构造函数,指定两个形参:一个针对课程名称, 另一个针对教师姓名.
- [x]修改成员函数displaymessage,使它首先输出欢迎信息和课程名称,然后输出"This course is presented by:" 跟老师姓名

[代码](https://github.com/chenboshuo/cpp_learning/commit/d6529d2ec3309333f44d6a4cf4e07111be7f8252#diff-52ec402c28719f938d3857a0a7f54c17)

## 3.12 Account 类
创建一个名为Account的类银行可使用它表示银行的账户.
- [x]这个类应该包含一个数据成员表示账户余额.
- [x]函数:接受余额并初始化数据成员(保证余额大于0,否则返回错误信息)
- [x]credit:将一笔金额添加到余额中
- [x]debit:从这个类中取钱,并保证不能超出余额,若超出余额,指出"Debit amount exceed account balance"
- [x]getBalance返回余额
- [x]测试程序,创建两个对象并测试函数

[代码](https://github.com/chenboshuo/cpp_learning/commit/076118b5f251ab11c5e8f2e66abd9ab23d5b18a7#diff-c09b9f03cfaf038e63d8cc54f37e4f23)
