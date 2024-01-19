#include<iostream>
using namespace std;
enum Fruit{
    a1,a2,a3,a4
};

void printFruit(Fruit fruit){
    switch(fruit){
        case 0: cout<<"THis is apple"<<endl;
                    break;

        case 1: cout<<"THis is banana"<<endl;
                     break;
        
        case 2: cout<<"This ia mango"<<endl;
                    break;

        case 3: cout<<"This is orange"<<endl;
                    break;
        default: cout<<"Invalid choice"<<endl;
    }
}
int main(){
    Fruit fruit= a1;
    printFruit(fruit);
}