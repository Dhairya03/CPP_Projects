#include <iostream>

template<typename T>
T max(T x,T y){
    return (x>y)?x:y;
}

int main(){
    std::cout<< max(2,3)<<std::endl;
    std::cout<<max('e','i')<<std::endl;
    std::cout<<'e'-'i'<<std::endl;
    std::cout<<max("ello","illo")<<std::endl;
    if("ello">"illo"){
        std::cout<<"ello";
    }else{
        std::cout<<"illo";
    }
    std::cout << "ello" - "illo" << std::endl;
    std::cout<<max(5.4,7.0)<<std::endl;
    return 0;

}