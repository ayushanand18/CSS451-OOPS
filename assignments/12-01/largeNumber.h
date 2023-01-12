// 1d) Create your header file “largeNumber.h” as a collection of
// functions: largeAdd(), largeMult, largeFact.

/*
##################################################
# largeNumber.h                                  #
# --------------                                 #
# Module containing functions to add, multiply   #
# and calculate factorial of large numbers       #
# outside the bounds of int, or long int data    #
# types in C++                                   #
#                                                #
# Functions:                                     #
#                                                #
#  largeAdd(string a, string b)                  #
#     Add two large numbers, returns string      #
#                                                #
#  largeMult(string a, string b)                 #
#     Multiply two large numbers, returns string #
#                                                #
#  largeFact(string n)                           #
#     Calculate the factorial of large numbers,  #
#      returns string                            #
##################################################
*/ 

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

string largeMult(string a, string b){
    if(b.size()>a.size()) swap(a,b);

    int carry;
    int product;
    string sum = "0";
    int trailingZeros=0;

    for(int i=b.size()-1; i>-1; i--){
        carry = 0;
        string res="";
        for(int j=a.size()-1; j>-1; j--){
            product = ((b[i]-'0')*(a[j]-'0')+carry);
            carry = product/10;
            res = to_string(product%10)+res;
        }
        if(carry>0) res = to_string(carry)+res;
        
        // now let us add the result to our accumulated partial sum
        for(int z=0; z<trailingZeros; z++)
            res = res + "0";
        sum = largeAdd(sum, res+string("0"));
        trailingZeros++;
    }

    return sum;
}

string largeFact(string num){
    // if the number is 1 then we return 1, base case for recursion
    if(num=="1") return "1";
    
    // for all other cases, recursion
    // copy the string to a new string
    string next = string("!", num.size());
    next.replace(0, next.size(), num);
    
    // and subtract 1 from end
    int i=next.size()-1;
    while(next[i]=='0' && i>-1) {
        // if the last digit is 0 then we change it to 9
        // and propagate a borrow
        next[i--] = '9';
    }
    // now when need not propoagate the borrow, 
    // we subtract 1 (which we borrowed)
    next[i] = char(next[i]-1);

    // now if the resulting number has a leading zero,
    // we might get unexpected results, so we erase the first
    // digit if it is a leading zero
    if(next[0]=='0') next.erase(0,1);
    
    // now we recursively call onto the preceding number
    // it is similar to n*fact(n-1) when dealing with integers
    return largeMult(num, largeFact(next));
}