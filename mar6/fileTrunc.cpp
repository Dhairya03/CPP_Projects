#include <iostream>
#include <fstream>

int main()
{
    std::fstream fout;

    fout.open("sample.txt",std::ios::trunc);

    if (fout.is_open())
    {
        std::cout << "File is openend" << std::endl;
    }else{
        std::cout<<"Error while opening file"<<std::endl;
    }

    std::string line;

    while (fout)
    {
        std::getline(std::cin, line);
        if (line == "exit")
            break;
        fout << line << std::endl;
        std::cout << fout.tellg() << std::endl;
    }
    std::cout << fout.tellg() << std::endl;
    fout.seekg(0);
    while (getline(fout, line))
    {
        std::cout << line << std::endl;
    }

    fout.close();
}