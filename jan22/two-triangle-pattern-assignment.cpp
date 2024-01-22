#include<iostream>
using namespace std;
void print_pattern(int n){
    if(n%2==0){
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if(j<=i || j>=2*n-i){
                    if(j%2==0)cout<<"1";
                    else cout<<"0";
                }else cout<<" ";
            }

            for(int j=n+1;j<2*n+1;j++){
                if(j<=i || j>=2*n-i){
                    if((j-i)%2==0)cout<<"1";
                    else cout<<"0";
                }else cout<<" ";
            }
            cout<<endl;

        }
        for(int i=n+1;i<2*n+1;i++){
            for(int j=0;j<n+1;j++){
                if(j<=2*n-i || j>=i){
                    if(j%2==0)cout<<"1";
                    else cout<<"0";
                }else cout<<" ";
            }

            for(int j=n+1;j<2*n+1;j++){
                if(j<=2*n-i || j>=i){
                    if((j-i)%2==0)cout<<"1";
                    else cout<<"0";
                }else cout<<" ";
            }
            cout<<endl;
        }
    }
    else{
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if(j<=i || j>=2*n+1-i){
                    if(j%2==0)cout<<"1";
                    else cout<<"0";
                }else cout<<" ";
            }

            for(int j=n+1;j<2*n+2;j++){
                if(j<=i || j>=2*n+1-i){
                    if((j-i)%2==0)cout<<"0";
                    else cout<<"1";
                }else cout<<" ";
            }
            cout<<endl;

        }
        for(int i=n+1;i<2*n+1;i++){
            for(int j=0;j<n+1;j++){
                if(j<=2*n-i || j>i){
                    if(j%2==0)cout<<"1";
                    else cout<<"0";
                }else cout<<" ";
            }

            for(int j=n+1;j<2*n+2;j++){
                if(j<=2*n-i || j>i){
                    if((j-i)%2==0)cout<<"0";
                    else cout<<"1";
                }else cout<<" ";
            }
            cout<<endl;
        }
    }
    
}
int main(){
    int n=0;
    cout<<"Enter a number"<<endl;
    //cout<<n;
    while(true){
        cin>>n;
        //cout<<n<<endl;
        if (!std::cin)
        {
            if (std::cin.eof())
            {
                exit(0); 
            }
            std::cin.clear(); 
            std::cin.ignore(INT16_MAX, '\n'); 
        }
        if(n<0 || n>=INT16_MAX){
            cout<<"Invalid input!!!.Please try again"<<endl;
            //cout<<n<<endl;
        }
        else{
            print_pattern(n);
            return 0;
        }
    }
}
