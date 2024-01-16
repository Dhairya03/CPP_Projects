#include<iostream>
using namespace std;
int main(){
    // Write a C program to find whether a given year is a leap year or not. 
    
    int year;
    cout<<"Enter the year you want to check"<<endl;
    cin>>year;
    //Using if statement
    if((year%4==0 && year%100!=0) || year%400==0){
        cout<<"this is a leap year"<<endl;
    }

    //Using if-else statement
    if((year%4==0 && year%100!=0) || year%400==0){
        cout<<"this is a leap year"<<endl;
    }else{
        cout<<"This is not a leap year"<<endl;
    }

    //Using if else-if statement
    if(year%400==0){
        cout<<"This is a leap year"<<endl;
    }else if(year%100 ==0){
        cout<<"This is not a leap year"<<endl;
    }else if(year % 4 ==0){
        cout<<"This is a leap year"<<endl;
    }else {
        cout<<"This is not a leap year"<<endl;
    }

    //Using nested if else statement

}