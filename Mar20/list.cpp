#include <iostream>
#include <list>


int main(){
    std::list<int> list1{1,2,3,4};
    std::list<char> vowels{'a','e','i','o','u'};
    for(auto vowel:vowels){
        std::cout<<vowel<<std::endl;
    }
    for(auto number:list1){
        std::cout<<number<<std::endl;
    }
    // for(int i=0;i<list1.size();i++){
    //     std::cout<<list1.front()<<std::endl;
    // }
}