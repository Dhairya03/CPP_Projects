#include<iostream>

int main(){
    int size;
    std::cout<<"Enter the size of array"<<std::endl;
    std::cin>>size;

    int *ptr=(int*)calloc(size,sizeof(int));
    if(ptr==NULL){
        std::cout<<"Memory is not allocated"<<std::endl;
    }
    else{
        std::cout<<"Memory is allocated successfully"<<std::endl;
         std::cout<<"Array elemets are: "<<std::endl;
        for(int i=0;i<size;i++){
            std::cout<<ptr[i]<<" ";
        }

        for(int i=0;i<size;i++){
            ptr[i]=i+1;
        }
        std::cout<<"Array elemets are: "<<std::endl;
        for(int i=0;i<size;i++){
            std::cout<<ptr[i]<<" ";
        }
        std::cout<<&ptr<<" "<<ptr<<std::endl;
    }
    delete(ptr);
}