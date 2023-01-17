#include <string>
#include <iostream>
#include "largeNumber.h"
using namespace std;

int main(){
    int ch;
    cout<<"enter your choice"<<endl
        <<"1: add"<<endl
        <<"2: multiply"<<endl
        <<"3: factorial" <<endl;
    cin>>ch;
    string a,b, n;
    switch(ch){
        case 1: 
            cout<<"enter 1st number: "<<endl;
            cin>>a;
            cout<<"enter 2nd number: "<<endl;
            cin>>b;
            cout<<a<<"+"<<b<<"="<<largeAdd(a,b)<<endl;
            break;
        case 2: 
            cout<<"enter 1st number: "<<endl;
            cin>>a;
            cout<<"enter 2nd number: "<<endl;
            cin>>b;
            cout<<a<<"+"<<b<<"="<<largeMult(a,b)<<endl;
            break;
        case 3: 
            cout<<"enter number: "<<endl;
            cin>>n;
            cout<<n<<"! = "<<largeFact(n)<<endl;
            break;
        default: cout<<"enter correct choice"<<endl; break;
    }
}