#include<iostream>
#include <fstream>

int main(){
    std::ofstream fout;
    fout.open("sample.txt");
    fout.open("file.txt");

    if(fout.is_open()){std::cout<<"File is openend"<<std::endl;}

    std::string line;

    while(fout.is_open()){
        std::cout<<"inside file"<<std::endl;
        std::getline(std::cin,line);
        if(line=="exit")break;
        //how is this working
        //because fout is object of ofstream class and << operator is overloaded fpr this class
        fout<<line<<std::endl;

    }
    fout.close();
  

    std::ifstream fin("file.txt");

    while(getline(fin,line)){
        std::cout<<line<<std::endl;
    }

    fin.close();
}