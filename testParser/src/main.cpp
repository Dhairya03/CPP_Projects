#include <iostream>
#include <fstream>
#include "jsoncpp/json/json.h"

int main()
{
    std::ifstream file("../jsonFile/example_2.json");
    Json::Reader reader;
    Json::Value completeJsonData;
    reader.parse(file, completeJsonData);
    std::cout << "Complete Json Data" << std::endl
              << completeJsonData << std::endl;
    std::cout << "math:" << completeJsonData["quiz"]["maths"]["q2"] << std::endl;
    file.close();
    return 0;
}

// g++ -o main main.cpp -ljsoncpp