#include<iostream>

int main(){
    int size;
    std::cout << "Enter the size of matrix" << std::endl;
    std::cin >> size;

    int **matrixOne = new int *[size];
    for (int index = 0; index < size; index++)
    {
        matrixOne[index] = new int[size];
    }

    std::cout << "Enter elements of matrixOne" << std::endl;
    int value=1;
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
             matrixOne[row][column]=value;
             value++;
        }
    }

    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            std::cout<< matrixOne[row][column]<<" ";
        }
        std::cout<<std::endl;
    }

for (int column = 0; column < size; column++)
        {
            std::cout<<*matrixOne[column];
        }


}