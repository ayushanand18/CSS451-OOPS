/*
***************************
* sine curve              *
*/
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
    // take the fill value
    float interval, max_val, init_val;
    
    cout << "Enter the initial value (in radians): " << endl;
    cin >> init_val;
    
    cout << "Enter the max value to plot the curve upto (in radians): " << endl;
    cin >> max_val;

    cout << "Enter the interval size to calculate values (in radians): " << endl;
    cin >> interval;

    for(int x = init_val; x<=max_val; x = x+interval){
        if(sin(x)>0){
            cout<<setw(40)<<setfill(' ')<<'|'<<setw(int(sin(x)))<<setfill('*')<<"+"<<endl;
        }
        else{
            cout<<setw(40+sin(x))<<setfill(' ')<<'+'<<setw(int(abs(sin(x))))<<setfill('*')<<'|'<<endl;
        }
    }
    
}