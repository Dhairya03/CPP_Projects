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

    String &operator=(const String &other) // copy assignment
    {
        std::cout << "Copy Assignment" << std::endl;
        size = other.size;
        data = new char[size];
        memcpy(data, other.data, size);
        return *this;
    }

    String(String &&other) // move constructor
    {
        std::cout << "Move String" << std::endl;
        size = other.size;
        data = other.data;

        other.size = 0;
        other.data = nullptr;
    }

    String &operator=(String &&other) // move assignment
    {
        std::cout << "MoveAssignment" << std::endl;
        size = other.size;
        data = other.data;

        other.size = 0;
        other.data = nullptr;
        return *this;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << data[i];
        }
        std::cout << std::endl;
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
        std::cout << "constructor" << std::endl;
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
    // String &&string = "hello";
    // String &&string2 = "hi";
    // string2 = string;
    // string2("abcdf")
    Entity entity("string");
    entity.print();
    return 0;
}