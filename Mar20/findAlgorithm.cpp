#include <iostream>
#include<algorithm>
#include <list>
#include <numeric>

int main(){
std::list <int> l1(6);
std::iota(l1.begin(),l1.end(),0);
std::cout<<*std::min_element(l1.begin(),l1.end())<<std::endl;
auto result=std::find(l1.begin(),l1.end(),3);
l1.insert(result,-1);
for (int i : l1) 
        std::cout << i << ' ';
        std::cout<<*std::min_element(l1.begin(),l1.end())<<std::endl;

// std::cout<<result<<std::endl;
}