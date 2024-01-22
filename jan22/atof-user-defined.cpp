#include<iostream>
#include<cmath>
using namespace std;
double atof(const char* str){
    
    double result = 0.0;
    int sign = 1;
    double decimal=0.1;
    int exponent_sign = 1;
    int exponent=0;

    while(*str == ' '){
        str++;
    }

    if(*str == '-' || *str == '+'){
        if(*str == '-') sign = -1;
        else sign=1;
        str++;
    }

    while(*str >='0' && *str<='9'){
        result=result*10+(*str-'0');
        str++;
    }

    if(*str=='.'){
        str++;
        while(*str >='0' && *str<='9'){
            result+=decimal*(*str-'0');
            decimal*=0.1;
            str++;
        }
    }

    if(*str=='e'){
        str++;  
    if(*str=='-'||*str=='+'){
        if(*str=='-')exponent_sign=-1;
        else exponent_sign=1;
        str++;
    }

    while(*str>='0'&& *str<='9'){
        exponent=exponent*10+(*str-'0');
        str++;
    }
    }

    result*=sign;

    if(exponent!=0){
        result=result*pow(10,exponent*exponent_sign);
    }
    return result;
}

int main(){
    string input;
    cin>>input;
    cout<<"Enter input string"<<endl;
    cout<<"Input String:"<<input<<endl;
    cout<<"Result: "<<atof(&input[0])<<endl;
    return 0;
}