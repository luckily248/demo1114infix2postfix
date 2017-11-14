//ZHIYING LIANG
//  main.cpp
//  demo1114infix2postfix
//
//  Created by lucky on 11/14/17.
//  Copyright © 2017 luck. All rights reserved.
//

#include <iostream>
#include <sstream>
using namespace std;
bool higherpriority(char a, char b){
    bool r=false;
    if ((a=='*'||a=='/')&&(b!='*'&b!='/')){
        r=true;
    }
    return r;
}
bool isoperators(char a){
    bool r=false;
    if (a=='*'||a=='/'||a=='-'||a=='+'){
        r=true;
    }
    return r;
}

int main(int argc, const char * argv[]) {
    char stacks[100];
    int sp=0;
    string inputs;
    cout<<"input:";
    cin>>inputs;
    cout<<"\noutput:";
    for (int i=0; i<inputs.length(); i++) {
        //if is operators
    c1:if (isoperators(inputs[i])) {
        //sp==0 means empty or '(' on top or higher priortity
            if (sp==0||stacks[sp-1]=='('||higherpriority(inputs[i], stacks[sp-1])) {
                //push into stacks
                stacks[sp]=inputs[i];
                sp++;
            }else{
                //pop it and print out go back to check input
                cout<<stacks[sp-1];
                sp--;
                goto c1;
            }
        //if input is'('
        }else if (inputs[i]=='('){
            //push into stacks
            stacks[sp]=inputs[i];
            sp++;
        //if input is ')'
        }else if (inputs[i]==')'){
            while (stacks[sp-1]!='(') {
                //pop and print out
                cout<<stacks[sp-1];
                sp--;
                if (sp==0) {
                    break;
                }
            }
            //get rid of the '('
            sp--;
        }else{
            //others print out
            cout<<inputs[i];
        }
        //print out the stacks to debug
        for (int i=0; i<sp; i++) {
            //cout<<"\nstacks:"<<stacks[i]<<"\n";
        }
    }
    //pop and prints out anything in stacks
    while (sp!=0) {
        cout<<stacks[sp-1];
        sp--;
    }
    cout<<"\n";
    return 0;
}
