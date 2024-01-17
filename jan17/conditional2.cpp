#include<iostream>
using namespace std;
int main(){
    // Write a C program to accept a coordinate point in an XY coordinate system 
    // and determine in which quadrant the coordinate point lies. 

    int x, y;
    cout<<"Enter x and y cooridnates"<<endl;
    cin>>x>>y;
    if(x>=0 && y>=0)cout<<"1st quadrant"<<endl;
    else if(x>=0 && y<=0)cout<<"4th quadrant"<<endl;
    else if(x<=0 && y<=0)cout<<"3rd quadrant"<<endl;
    else cout<<"2nd quadrant"<<endl;

    return 0;
}