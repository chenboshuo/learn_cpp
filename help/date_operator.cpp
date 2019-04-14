/*
设计一个日期类Date,，要求：
（1）包含年(year)、月(month)和日(day)私有数据成员。
（2）包含构造函数，重载关于一日期加上天数的加法运算符+、重载关于一日期减去天数的减加运算符-、重载输出运算符<<与输入运算符>>等。
*/
#include <iostream>
using namespace std;

class Date {
friend ostream &operator<<(ostream &,Date &);

private:
    int day,month,year;
    static const int days[];
    void increment1();
    void decrement1();

public:
    Date(int y=2019,int m=1,int d=1) {
        year=(y>=1900&&y<=2100)?y:2000;
        month=(m>=1&&m<=12)?m:1;
        if(month!=2) {
            day=(d>=1&&d<days[month])?d:1;
        } else day=(d>=1&&d<=29)?d:1;
    }
    Date operator+(int );
    Date operator-(int );
    const Date &operator+=(int);
    bool leapyear(int ) const;
    bool endofmonth(int ) const;
    bool topofmonth(int )const;
};

const int days[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};

void Date::increment1() {
  if(!endofmonth(day)) day++;
    else {
      if(month<12) {
        month++;
        day=1;
      } else {
        year++;
        month=1;
        day=1;
    }
  }
}

void Date::decrement1() {
  if(!topofmonth(day)) day--;
  else {
    if(month>1) {
      --month;
      day=days[month];
    } else {
      --year;
      month=12;
      day=31;
    }
  }

}

bool Date::endofmonth(int testday) const {
  if(month==2 && leapyear(year)) {
    return testday==29;
  } else {
    return testday==days[month];
  }
}

bool Date::topofmonth(int testday) const {
  return testday==1;
}

bool Date::leapyear(int testyear) const {
  if(testyear%400==0||(testyear%100!=0&&testyear%4==0))
    return true;
  else
    return false;
}

Date Date::operator+(int x) {
  while(x--) {
    Date::increment1();
    return *this;
  }
}

Date Date::operator-(int x) {
  while(x--) {
    Date::decrement1();
    return *this;
  }
}

ostream & operator<<(ostream &output,Date &d) {
  output<<d.year<<"/"<<d.month<<"/"<<d.day<<endl;
  return output;
}

int main() {
  Date d1;
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
