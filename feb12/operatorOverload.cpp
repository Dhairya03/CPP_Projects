#include<iostream>

struct Object{
    int a,b;

    Object(){
        std::cout<<"Enter values of a and b"<<std::endl;
        std::cin>>a>>b;
    }
    Object Add(Object& obj){
        Object res;
        res.a=a+obj.a;
        res.b=b+obj.b;
        return res;
    }

    Object operator+(Object &obj){
        Object res;
        res.a=a+obj.a;
        res.b=b+obj.b;
        return res;
    }

    void print(){
        std::cout<<a<<" "<<b<<std::endl;
    }

};

int main(){
Object o1;
Object o2;
Object result=o1.Add(o2);
Object result2=o1+o2;
//Object result=o1+o2;
// std::cout<<result;
result.print();
result2.print();


}