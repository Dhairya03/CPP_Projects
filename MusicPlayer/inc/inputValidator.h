#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

class InputValidator
{
public:
    bool isValidInput()
    {
        bool isValid = false;
        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            isValid = true;
        return isValid;
    }
}