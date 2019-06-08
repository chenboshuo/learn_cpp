#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  string s1("happy");
  string s2(" birthday");
  string s3;

  // test overload equality and relation operation
  cout << "s1 is: " << s1 << "\ns2 is :" << s2 << "\ns3 is: " << s3
       << "\n\nThe result of cmparing s1 and s2:"
       << "\ns1 == s2 yields " << (s1 == s2)  // remember()
       << "\ns1 >  s2 yields " << (s1 > s2) << endl;
  /* output
  s1 is: happy
  s2 is : birthday
  s3 is:

  The result of cmparing s1 and s2:
  s1 == s2 yields 0
  s1 >  s2 yields 1
  */

  // test the member-function empty
  cout << "\n\nTesting s3.empty() " << s3.empty() << endl;
  /* output
    Testing s3.empty() 1
   */

  // test overload string concatenation
  cout << "\n\ns1 += s2 yeilds \ns1 =" << (s1 += s2)
       << "\ns1 += \" to you\" yeilds\n"
       << (s1 += " to you") << endl;
  /* output

    s1 += s2 yeilds
    s1 =happy birthday
    s1 += " to you" yeilds
    happy birthday to you
   */

  // test string member function substr
  cout << "\nThe substring of s1 starting at location 0 for\n"
       << "14 characters, s1.substr(0,14) is\n"
       << s1.substr(0, 14) << endl;
  /* output
  The substring of s1 starting at location 0 for
  14 characters, s1.substr(0,14) is
  happy birthday
   */

  // test substr "to-end-of-string" operation
  cout << "\nThe substring of s1 starting at\n"
       << "location 15, s1.substr(15) is\n"
       << s1.substr(15) << endl;
  /* output
    The substring of s1 starting at
    location 15, s1.substr(15) is
    to you
  */

  // test copy constructor
  string s4(s1);
  cout << "\ns4 = " << s4 << endl;
  /* output
    s4 = happy birthday to you
   */

  // test using overload subscript operator to create lvalue
  s1[0] = 'H';
  s1.at(6) = 'B';
  cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' , s1 is\n" << s1 << endl;
  /* output
    s1 after s1[0] = 'H' and s1[6] = 'B' , s1 is
    Happy Birthday to ?
   */

  // test subscript out of range with string member function at
  try {
    cout << "\n\nAttempt to assigned 'd' to s1.at(30) yields" << endl;
    s1.at(30) = 'd';  // error: subscript out of range
  } catch (out_of_range &ex) {
    cout << "An expection occurred: " << ex.what() << endl;
  }
  /* output
    Attempt to assigned 'd' to s1.at(30) yields
    An expection occurred: basic_string::at: __n (which is 30) >= this->size()
    (which is 21)
  */
  return 0;
}
/*
  The result of cmparing s1 and s2:
s1 == s2 yields 0
s1 >  s2 yields 1


Testing s3.empty() 1


s1 += s2 yeilds
s1 =happy birthday
s1 += " to you" yeilds
happy birthday to you

The substring of s1 starting at location 0 for
14 characters, s1.substr(0,14) is
happy birthday

The substring of s1 starting at
location 15, s1.substr(15) is
to you

s4 = happy birthday to you

s1 after s1[0] = 'H' and s1[6] = 'B' , s1 is
Happy Birthday to you


Attempt to assigned 'd' to s1.at(30) yields
An expection occurred: basic_string::at: __n (which is 30) >= this->size()
(which is 21)
 */
