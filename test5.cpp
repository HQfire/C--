#include <iostream>
using namespace std;

void Value();

int main(){
    Value();
}

//获取成绩
void Value(){
    int num;
    int score;
    int n = 0;
    while (n != 10)
    {
        cout<<"Enter marks:";
        cin>>num;
        score += num;
        n++;
    }
    int ave = score / 10;
    cout<<"Class Average is:"<<ave<<endl;
    
}