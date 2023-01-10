// 1d) Create your header file “largeNumber.h” as a collection of
// functions: largeAdd(), largeMult, largeFact.
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
    string array[a.size()+b.size()];
    fill(array, array+a.size()+b.size(), "!");
    int k=0;
    for(int i=b.size()-1; i>-1; i--){
        carry = 0;
        string res="";
        for(int j=a.size()-1; j>-1; j--){
            product = ((b[i]-'0')*(a[j]-'0')+carry);
            carry = product/10;
            res = to_string(product%10)+res;
        }
        if(carry) res = to_string(carry)+res;
        array[k++] = res+string("0", k);
    }

    string sum = "";
    for(int k=0; array[k]!="!"&&k<(a.size()+b.size()); k++){
        sum = largeAdd(sum, array[k]);
    }

    return sum;
}