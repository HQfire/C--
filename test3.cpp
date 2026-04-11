#include <iostream>
using namespace std;

void Parity(int a,int num);
void Compare(int a,int b);
void Number(int &num1,int &num2);

int main(){
    int num1,num2;
    cout<<"Welcome"<<endl;
    Number(num1,num2);
    Compare(num1,num2);
    Parity(num1,1);
    Parity(num2,2);
    return 0;
}

//取两个数的值
void Number(int &num1,int &num2){
    cout<<"Enter number 1:";
    cin>>num1;
    cout<<"Enter number 2:";
    cin>>num2;
}

//判断奇偶性
void Parity(int a,int num){
    if (a%2==0)
    {
        cout<<"number "<<num<<" is EVEN."<<endl;
    }else{
        cout<<"number "<<num<<" is ODD."<<endl;
    }
}

//比大小
void Compare(int a,int b){
    if (a>b)
    {
        cout<<"number 1 is greater than number 2"<<endl;
    }else if (b>a)
    {
        cout<<"number 2 is greater than number 1"<<endl;
    }else{
        cout<<"The two numbers are the same"<<endl;
    }
}