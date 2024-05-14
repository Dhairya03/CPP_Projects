#include <iostream>
#include <string.h>

class String
{
private:
    char *data;
    int size;

public:
    String(const char *string)
    {
        std::cout << "Created String" << std::endl;
        size = strlen(string);
        data = new char[size];
        memcpy(data, string, size);
    }

    String(const String &other)
    {
        std::cout << "Copy String" << std::endl;
        size = other.size;
        data = new char[size];
        memcpy(data, other.data, size);
    }

    String(String &&other) noexcept
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

    ~String()
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
    }

    Entity(String &&string)
        : newString(("string"))
    {
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
    Entity entity(String("hello"));
    entity.print();
    return 0;
}