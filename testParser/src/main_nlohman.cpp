#include <iostream>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

int main(){
    std::ifstream file("../jsonFile/example_2.json");
    json data=json::parse(file);
    std::cout<<data<<std::endl;
}


// g++ -I/home/dhairyagupta/training/c-_dhairyagupta/testParser/lib -o main_nlohmann main_nlohman.cpp