#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    std::vector<int>v1{1,2,1,2,3,4,5};
    std::cout<<v1.size();
    std::remove(v1.begin(),v1.end(),2);
    std::cout<<v1.size();
    for(int i=0;i<v1.size();i++){
        std::cout<<v1[i];
    }
}