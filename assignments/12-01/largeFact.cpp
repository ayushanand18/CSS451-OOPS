// 1c) Write a function largeFact(n1,n2) to perform Factorial of very
// large numbers using the function largeFact(ni,n2). Check the factorial of
// 50. Check the largest factorial that you can calculate in your machine.
// Visualize the plot of a number vs the Number of digits in its factorial.
#include <iostream>
#include <string>
#include "largeNumber.h"

string fact(string num){
    if(num=="1") return "1";
    // cout<<largeMult(num,"1")<<endl;
    string next = string("!", num.size());
    next.replace(0, next.size(), num);
    // subtract 1 from end
    int i=next.size()-1;
    while(next[i]=='0' && i>-1){
        next[i--] = '9';
    }
    next[i] = char(next[i]-1);
    if(next[0]=='0') next.erase(0,1);

    return largeMult(num, fact(next));
}
int main(void){
    string num;
    cout<<"Calculating the Factorial of large number"<<endl;
    cout<<"Enter the number to calculate n!: "<<endl;
    getline(cin, num);
    
    cout<<fact(num)<<" is the factorial"<<endl;
}