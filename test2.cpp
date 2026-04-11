#include <iostream>
using namespace std;

int menu1();
int menu2(int balance);
int WA(int balance);
int DA(int balance);
int WD(int balance,int amount);
int DE(int balance,int amount);

int main(){
    int balance = menu1();
    menu2(balance);
    
    
}

int menu1(){
    cout<<"Welcome!"<<endl;
    cout<<"Enter your balance:";
    int balance;
    cin>>balance;
    cout<<"----------------------------------"<<endl;
    return balance;
}

int menu2(int balance){
    cout<<"Select an option:"<<endl;
    cout<<"1.Withdraw Amount"<<endl;
    cout<<"2.Deposit Amount"<<endl;
    cout<<"3.Exit"<<endl;
    int enter;
    do{
        cin>>enter;
        cout<<"----------------------------------"<<endl;
        switch (enter)
        {
        case 1:
            balance = WA(balance);
            break;
        case 2:
            balance = DA(balance);
            break;
        case 3:
            cout<<"Thank you for using the system!"<<endl;
            return 0;
            break;
        default:
            break;
        }
    }while(1);
    
}

int WA(int balance){
    cout<<"How much amount you want to withdraw from your account?"<<endl;
    int Amount;
    cout<<"Amount:";
    cin>>Amount;
    if (Amount<=balance)
    {
        int Amount1 = WD(balance,Amount);
        cout<<"Your new blance is:"<<Amount1<<endl;
        return Amount1;
    }else{
        cout<<"error"<<endl;
        return -1;
    }
    
}

int DA(int balance){
    cout<<"How much amount you want to deposit in your account?"<<endl;
    int Amount;
    cout<<"Amount:";
    cin>>Amount;
    int Amount1 = DE(balance,Amount);
    cout<<"Your new blance is:"<<Amount1<<endl;
    return Amount1;
}

int WD(int balance,int amount){
    int amount1=balance-amount;
    return amount1;
}

int DE(int balance,int amount){
    int amount1=balance+amount;
    return amount1;
}