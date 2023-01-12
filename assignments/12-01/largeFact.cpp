// 1c) Write a function largeFact(n1,n2) to perform Factorial of very
// large numbers using the function largeFact(ni,n2). Check the factorial of
// 50. Check the largest factorial that you can calculate in your machine.
// Visualize the plot of a number vs the Number of digits in its factorial.
#include <iostream>
#include <string>
#include "largeNumber.h"

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
int main(void){
    string num;
    
    cout<<"Calculating the Factorial of large number"<<endl
        <<"Enter the number to calculate n!: "<<endl;
    
    getline(cin, num);
    
    cout << num << "! = " << largeFact(num) << endl;
}