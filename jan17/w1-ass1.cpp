#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n/2+1;i++){
        for(int j=0;j<n/2+1;j++){
            if(j<=i || j>=n-i-1){
                if(j%2==0)cout<<"1";
                else cout<<"0";
            }else cout<<" ";
        }
        for(int j=n/2+1;j<n;j++){
            if(j<=i || j>=n-i-1){
                if((j-i)%2==0)cout<<"1";
                else cout<<"0";
            }else cout<<" ";
        }
        cout<<endl;
    }
    for(int i=n/2+1;i<n;i++){
        for(int j=0;j<n/2+1;j++){
            if(j<=n-1-i || j>=i){
                if(j%2==0)cout<<"1";
                else cout<<"0";
            }else cout<<" ";
        }
        for(int j=n/2+1;j<n;j++){
            if(j<=n-1-i || j>=i){
                if((j-i)%2==0)cout<<"1";
                else cout<<"0";
            }else cout<<" ";
        }
        cout<<endl;
    }
}