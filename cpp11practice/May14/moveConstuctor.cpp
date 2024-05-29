#include <iostream>
#include <string.h>

class String
{
private:
    char *data;
    int size;

public:
    String(const char *string) // constructor
    {
        std::cout << "Created String" << std::endl;
        size = strlen(string);
        data = new char[size];
        memcpy(data, string, size);
    }

    String(const String &other) // copy constructor
    {
        std::cout << "Copy String" << std::endl;
        size = other.size;
        data = new char[size];
        memcpy(data, other.data, size);
    }

    String(String &&other) // move constructor
    {
        std::cout << "Move String" << std::endl;
        size = other.size;
        data = other.data;

        other.size = 0;
        other.data = nullptr;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << data[i];
        }
    }

    ~String() // destructor
    {
        std::cout << "Destroyed String" << std::endl;
        delete data;
    }
};

class Entity
{
private:
    String newString;

public:
    Entity(const String &string)
        : newString(string)
    {
        std::cout << "constrcutor" << std::endl;
    }

    Entity(String &&string)
        : newString(std::move(string))
    {
        std::cout << "rvalue reference" << std::endl;
    }

    void print()
    {
        newString.print();
    }

    ~Entity()
    {
    }
};

int main()
{
    // String &&string="hello";
    // std::cout<<"...."<<std::endl;
    // Entity entity("string");
    // entity.print();
    // String s1 = "hello";
    // String s(std::move(s1));
    String s2("hello");
    String s3(std::move("hello"));

    return 0;
}