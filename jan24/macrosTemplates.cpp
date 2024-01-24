#include<iostream>
#define PI 3.14192
#define AND &&
#define OR ||
#define CONDITION (xCoordinate>=0 AND yCoordinate>=0)
#define AREA(radius) (PI*radius*radius)


int main(){
    double radius;
    int xCoordinate,yCoordinate;
    std::cout<<"Enter coordinates of a point"<<std::endl;
    std::cin>>xCoordinate>>yCoordinate;
    
    if(CONDITION){
        std::cout<<"Point lies in first quadrant"<<std::endl;
    }else{
        std::cout<<"Point does not lie in first quadrant"<<std::endl;
    }
    
      std::cout<<"Value of PI is"<<PI<<std::endl;

      std::cout<<"Enter radius of the circle"<<std::endl;
      std::cin>>radius;
      std::cout<<"Area of the circle is "<<AREA(radius)<<std::endl;
}