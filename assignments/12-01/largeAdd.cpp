// 1a) Adding two numbers is trivial. In C/C++, the simple mathematical
// expression such as sum = a + b will add variable &#39;a&#39; and &#39;b&#39;
// and put the result in the variable &#39;sum&#39;. Your task is to add two
// very large numbers which are beyond the capacity to be stored in any existing
// integer data types in C/C++ like long int, etc. [Idea is to treat such a
// large number as a string of characters each consisting of digits in the range
// 0-9. Hence you should take two input numbers (strings) say, “2345” &amp;
// “9876” and perform digitwise addition (perform char to int conversion, add
// and then store the result back as char) as we do addition manually, finally
// display the sum “12221”as a string. Write a function largeAdd(ni,n2) to
// achive this.
#include <iostream>
#include <string>
using namespace std;

string largeAdd(string num1, string num2) {
  string res = "";
  int n1 = num1.size(), n2 = num2.size();
  // first traverse through both the number and add after converting
  // take a carry also.
  int carry = 0, sum = 0;

  for (int i = 0; i < n1 && i < n2; i++) {

    sum = num1[n1 - i - 1] - '0' + num2[n2 - 1 - i] - '0' + carry;
    res = to_string(sum % 10) + res;
    carry = sum / 10;
  }
  // check if n1 is still left, this means n2 is done
  if (res.size() != n1) {
    for (int i = res.size(); i < n1; i++) {
      sum = num1[n1 - i - 1] - '0' + carry;
      res = to_string(sum % 10) + res;
      carry = sum / 10;
    }
  }
  // check if n2 is still left
  else if (res.size() != n2) {
    for (int i = res.size(); i < n2; i++) {
      sum = num2[n2 - i - 1] - '0' + carry;
      res = to_string(sum % 10) + res;
      carry = sum / 10;
    }
  }
  // if some carry is left
  if (carry)
    res = to_string(carry) + res;

  return res;
}

int main(void) {
  string a, b;
  cout << "Enter first string:" << endl;
  getline(cin, a);
  cout << "Enter second string:" << endl;
  getline(cin, b);

  cout << largeAdd(a, b) << endl;
}
