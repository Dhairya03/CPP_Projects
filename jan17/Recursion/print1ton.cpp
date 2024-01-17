#include<iostream>
using namespace std;
void print1toN(int n){
    if(n==1){
        cout<<1;
        return;
    }
    print1toN(n-1);
    cout<<n;
    return;

}

void printNto1(int n){
    if(n==1){
        cout<<1;
        return;
    }
    cout<<n;
    printNto1(n-1);
    return;
}

int main(){
    int n;
    cin>>n;
    print1toN(n);
    cout<<endl;
    printNto1(n);
}