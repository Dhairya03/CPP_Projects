#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        int index=arr[i]%n;
        arr[index]+=n;
    }
    for(int i=0;i<n;i++){
        if(arr[i]/n>=2){
            ans.push_back(i);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
}