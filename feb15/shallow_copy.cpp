#include <iostream>

int main() {
   int* arr1=new int[5];
   int* arr2=new int[5];
   for(int i=0;i<5;i++){
       arr2[i]=i+1;
   }
   arr1=arr2;
   arr1[1]=0;
   for(int i=0;i<5;i++){
       std::cout<<arr1[i]<<arr2[i]<<" ";
       std::cout<<std::endl;
   }

    return 0;
}