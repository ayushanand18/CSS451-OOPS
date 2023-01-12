// 1b) Write a function largeMult(n1,n2) to perform Multiplication of
// very large numbers using the function largeAdd(ni,n2) following using
// an old school multiplication method.
#include <iostream>
#include <string>
#include "largeNumber.h"
using namespace std;

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

int main(){
    string a, b;
    
    cout<<"Multiplying two large numbers"<<endl;
    cout<<"Enter the first number: "<<endl;
    getline(cin, a);
    cout<<"Enter the second number: "<<endl;
    getline(cin, b);
    // cout<<'2'-'0'<<endl;
    cout<< "-----------------------" << endl
        <<a<<" * "<<b<<" = "<< largeMult(a, b) << endl;
}