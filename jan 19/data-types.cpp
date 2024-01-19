#include<iostream>
using namespace std;
int main(){
    int a='1';
    cout<<a;//prints the ascii value of character

   // int b=111111111111;
   // cout<<b;//guves error for overflow

   char c='1';
   cout<<c;

   char d=100;
   cout<<d;//prints the character present at ascii value=100

   short int e=12345;
   cout<<e;

   float f=12345.7890653988549;
   cout<<f;//gives precision upto 1 decimal point

   cout<<endl;
   f='1';
   cout<<f;//prints ascii value of character
    bool v=1111111111111111111;
    cout<<v<<endl;

    c=65.98794837;
    cout<<c;
    f=15.458379105583456;
    cout<<f;
}