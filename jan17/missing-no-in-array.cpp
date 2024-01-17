#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int arr[n-1];
    cout<<"Enter elements of the array"<<endl;
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    int sum=(n*(n+1))/2;
    int array_sum=0;
    for(int i=0;i<n-1;i++){
        array_sum+=arr[i];
    }
    cout<<sum-array_sum<<endl;
}