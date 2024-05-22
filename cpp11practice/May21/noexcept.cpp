#include <iostream>

// A function that guarantees not to throw any exceptions
void foo() noexcept
{
    std::cout << "foo() - This function is noexcept." << std::endl;
}

// A function that might throw an exception
void bar()
{
    std::cout << "bar() - This function might throw an exception." << std::endl;
}

// A conditional noexcept function
void baz() noexcept(sizeof(int) == 4)
{
    std::cout << "baz() - This function is conditionally noexcept." << std::endl;
}

// A function that is not noexcept but calls a noexcept function
void qux()
{
    foo(); // Calling a noexcept function
    std::cout << "qux() - This function is not noexcept but calls foo()." << std::endl;
}

// A function that might throw an exception
void riskyFunction()
{
    throw std::runtime_error("Error");
}

// Function to demonstrate noexcept in action
void testNoexcept() noexcept
{
    try
    {
        riskyFunction(); // This will throw an exception
    }
    catch (...)
    {
        std::cout << "Caught exception in noexcept function." << std::endl;
        // throw std::runtime_error("Error");
    }
}

int main()
{
    // Test various functions
    foo();
    bar();
    baz();
    qux();

    // Check if functions are noexcept
    std::cout << std::boolalpha;
    std::cout << "Is foo() noexcept? " << noexcept(foo()) << std::endl;
    std::cout << "Is bar() noexcept? " << noexcept(bar()) << std::endl;
    std::cout << "Is baz() noexcept? " << noexcept(baz()) << std::endl;
    std::cout << "Is qux() noexcept? " << noexcept(qux()) << std::endl;

    // Demonstrate exception handling in noexcept function
    try
    {
        testNoexcept();
    }
    catch (...)
    {
        std::cout << "Caught exception in main." << std::endl;
    }

    return 0;
}
