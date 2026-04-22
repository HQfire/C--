#include <iostream>
using namespace std;

int first(int Change);
void ifelse(int Change);
int FaToCe(int Fa);
int CeToFa(int Ce);

int main(){
    int Change;
    Change=first(Change);
    ifelse(Change);

    printf("hello");
    return 0;
}

int first(int Change){
    cout<<"Press 1 to convert Fahrenheit to Celsius"<<endl;
    cout<<"Press 2 to convert Celsius to Fahrenheit"<<endl;
    cin>>Change;

    return Change;
}

void ifelse(int Change){
    int Fa, Ce;
    if (Change==1){
        cout<<"Enter temperatrue in Fahrenheit:";
        cin>>Fa;
        Ce=FaToCe(Fa);
        cout<<"In Celsius that's:"<<Ce<<endl;
        
    }else if(Change==2){
        cout<<"Enter temperatrue in Celsius:";
        cin>>Ce;
        Fa=CeToFa(Ce);
        cout<<"In Fahrenheit that's:"<<Fa<<endl;
    }
}

int FaToCe(int Fa){
    int Ce;
    Ce=(Fa-32)*5/9;
    return Ce;
}

int CeToFa(int Ce){
    int Fa;
    Fa=Ce*9/5+32;
    return Fa;
}

