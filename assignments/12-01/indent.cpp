// 1e) Indentation: Read as input an unindented C program, them write a
// function indent() to convert the input code into an indented code and
// display. Read the input code as an array of strings; treat each line of code
// as a string; maintain a int variable tab. During processing parse each
// string(line) and increment tab when ‘{‘ is encountered and decrement tab
// when ‘}’ is encountered. To obtain desired indentation append specific
// number of blank spaces corresponding to the tab to each string(line) (you
// may use strcat() function to achieve this).
#include <iostream>
#include <string>
using namespace std;

int main(){
    int tab=0, n_lines=0;
    cout<<"Enter number of lines of code: ";
    cin>>n_lines;

    string lines[n_lines+1];
    // read input code as array of strings
    cout<<"Reading "<<n_lines<<" lines."<<endl<<"Enter your code line-by-line."<<endl;
    
    for(int i=0; i<=n_lines; i++){
        getline(cin,lines[i]);
    }

    // append to each line
    for(int i=0; i<=n_lines; i++){
        if(lines[i][0]=='}') tab--;
        lines[i] = string("    ", tab) + lines[i];
        if(lines[i].back()=='{') tab++;
    }

    // and display indented code
    cout<<"--------- Indented Code ---------"<<endl;
    for(int i=0; i<=n_lines; i++){
        cout<<lines[i]<<endl;
    }

}
