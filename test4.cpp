#include <iostream>
using namespace std;

void Value(int &num1, int &num2);
void Calculate(int num1,int num2);
void ADD(int num1,int num2);
void SUB(int num1,int num2);
void MUL(int num1,int num2);
void DIV(int num1,int num2);
void Compare(int a,int b);

int main(){
    int num1,num2;
    Value(num1,num2);
    Calculate(num1,num2);
    return 0;
}

//获得两个数的值
void Value(int &num1, int &num2){
    cout<<"Please enter two numbers"<<endl;
    cin>>num1>>num2;
}

//算数加比大小
void Calculate(int num1,int num2){
    cout<<"Please make a selection"<<endl;
    cout<<"1) Addition"<<endl;
    cout<<"2) Subtraction"<<endl;
    cout<<"3) Multiplication"<<endl;
    cout<<"4) Division"<<endl;
    cout<<"5) Exit"<<endl;
    int a;
    bool RUN = true;
    do
    {
        cin>>a;
        switch (a)
        {
        case 1:
            ADD(num1,num2);
            break;
        case 2:
            SUB(num1,num2);
            break;
        case 3:
            MUL(num1,num2);
            break;
        case 4:
            DIV(num1,num2);
            break;
        case 5:
            RUN = false;
        default:
            break;
        }
        Compare(num1,num2);
    } while (RUN);
    
}

void ADD(int num1,int num2){
    int num3 = num1 + num2;
    cout<<"Addition:"<<num3<<endl;
}

void SUB(int num1,int num2){
    int num3;
    if (num1>=num2)
    {
        num3 = num1 - num2;
    }else{
        num3 = num2 - num1;
    }
    cout<<"Subtraction:"<<num3<<endl;
}

void MUL(int num1,int num2){
    int num3 = num1 * num2;
    cout<<"Multiplication:"<<num3<<endl;
}

void DIV(int num1,int num2){
    int num3 = num1 / num2;
    cout<<"Division:"<<num3<<endl;
}

//比大小
void Compare(int a,int b){
    if (a>b)
    {
        cout<<a<<" is greater"<<endl;
    }else if (b>a)
    {
        cout<<b<<" is greater"<<endl;
    }else{
        cout<<"The two numbers are the same"<<endl;
    }
}