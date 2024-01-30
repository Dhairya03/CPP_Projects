#include <iostream>
#include<limits>
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble()
{
    while(true){
    std::cout << "Enter a decimal number: ";
    double x{};
    std::cin >> x;
    if(!std::cin){
        if(std::cin.eof()){
            exit(0);
        }
        std::cin.clear();
        ignoreLine();
    }
    else{
        ignoreLine();
        return x;
    }
    }
}

char getOperator()
{
    while(true){
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char op{};
    std::cin >> op;

    if(!std::cin){
        if(std::cin.eof()){
            exit(0);
        }
        std::cin.clear();
        ignoreLine();
    }
    ignoreLine();
//input extraction succeeds but input is meaningless like wrong chracter in the operator
//checks for the valid operator input and executes un til the operator is not right.
    switch(op){
        case '+':
        case '-':
        case '*':
        case '/':
            return op;
        default:
            std::cout<<"Invalid operator entered.Please enter again."<<std::endl;
    }
    }
}

void printResult(double x, char operation, double y)
{
    switch (operation)
    {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    default:
        std::cout<<"Something wenr wrong. Operator is not right"<<std::endl;
    }

}

int main()
{
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };

    printResult(x, operation, y);

    return 0;
}