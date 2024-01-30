#include<iostream>
#include<string>
using namespace std;
int main(){
    string input="Hello World!!!";
    //cin>>input;
    string input2="Hello  World!!!";
    cout<<input<<endl;
    int result=input.compare(input2);
    cout<<result;

    string substring=input.substr(1,4);
    cout<<substring;

    int found=input.find(substring);
    cout<<found;

    input.replace(0,5,"hey");
    cout<<input;



}