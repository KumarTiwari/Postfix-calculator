#include<iostream>
#define NULL -1
#include<stack>
#include<string>
#include<cmath>

using namespace std;

stack<char>converter;
stack<int>calculator;

// Switch cases for operator
int calculate_result(int x,int y,char symbol){
    switch(symbol){
    case '+' :
        return x+y;
    case '-' :
        return x-y;
    case '*':
        return x*y;
    case '^':
        return pow(x,y);

}
}
//evaluation of postfix  expression
void calculate(string postfix){
    int a,b;
    int result=0;
    string data;
    for(int i=0;i<postfix.length();i++){
        if(postfix[i] =='*' || postfix[i] =='+' || postfix[i] =='-' || postfix[i] =='^'){
            a=calculator.top();
            calculator.pop();
            b=calculator.top();
            calculator.pop();
            result=calculate_result(b,a,postfix[i]);
            calculator.push(result);
        }
        else{
                if (postfix[i]=='_'){;}
                else if (postfix[i+1] != '_')
                    {data+=postfix[i];}
                else{
                    data+=postfix[i];
                    calculator.push(stoi(data));
                    data.clear();
                }
        }
    }
    cout<<result<<endl;
}
//precision check

int precision_check(char x){
if(x=='^'){
    return 3;
}
else if(x=='*' || x=='/'){
    return 2;
}
else if(x=='+' || x=='-'){
    return 1;
}
else{return NULL;}
}
//infix expression to postfix expression

string infix_to_postfix(string expression){
    string postfix;
    char y;
    converter.push('(');
    for(auto x:expression){
        if(x =='('){converter.push(x);}
        else if(x == ')'){
            while(converter.top() != '('){
                    y=converter.top();
                    converter.pop();
                    postfix+='_';
                    postfix+=y;
                  }
            converter.pop();
        }
        else if(x =='*' || x =='+' || x =='-' || x =='^' || x=='/'){
            postfix+='_';
            if(converter.top() =='(' ){converter.push(x);}
            else if(precision_check(x)>precision_check(converter.top())){converter.push(x);}
            else{
                y=converter.top();
                postfix+=y;
                converter.pop();
                converter.push(x);
            }
        }
        else{
            postfix+=x;

        }

    }
    calculate(postfix);
    return postfix;
}
//driver function

int main(){
string expression;
cout<<"Enter your expression "<<endl;
getline(cin,expression);
expression+=')';
string x=infix_to_postfix(expression);
//cout<<x<<endl;
}

