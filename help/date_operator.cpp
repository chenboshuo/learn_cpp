/*
设计一个日期类Date,，要求：
（1）包含年(year)、月(month)和日(day)私有数据成员。
（2）包含构造函数，重载关于一日期加上天数的加法运算符+、重载关于一日期减去天数的减加运算符-、重载输出运算符<<与输入运算符>>等。
*/
#include <iostream>
using namespace std;

class Time {
        friend ostream &operator<<(ostream &,Time &);
        friend istream &operator>>(istream &,Time &);
    private:
        int hour,minute,second;
    public:
        Time(int h=1,int m=1,int s=1) {
            hour=(h>=0&&h<=23)?h:0;
            minute=(m>=0&&m<=59)?m:0;
            second=(s>=0&&s<=59)?s:0;
        }
        Time operator+(Time &);
        Time operator-(Time &);
        int getHour() {
            return hour;
        }
        int getMinute() {
            return minute;
        }
        int getSecond() {
            return second;
        }

};
Time Time::operator+(Time &t1) {
    this->hour +=t1.hour ;
    this->minute +=t1.minute ;
    this->second +=t1.second ;
}

ostream &operator<<(ostream &out,Time &t) {
    out << t.hour << ":" << t.minute << ":" << t.second;
    return out;
}


int main() {
    Time t1(20,20,20);
    Time t2(1,1,1);
    cout << t1+t2;
}
/**
 * clang的报错
 Start
prog.cc:84:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
prog.cc:91:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
prog.cc:29:11: warning: unused variable 'days' [-Wunused-const-variable]
const int days[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
          ^
3 warnings generated.
/tmp/prog-5c8f64.o: In function `Date::endofmonth(int) const':
prog.cc:(.text+0xdc): undefined reference to `Date::days'
/tmp/prog-5c8f64.o: In function `Date::decrement1()':
prog.cc:(.text+0x155): undefined reference to `Date::days'
clang-8: error: linker command failed with exit code 1 (use -v to see invocation)
1
Finish
 */
