#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

class InputValidator
{
private:
    int parserChoice;

    bool isValidParserChoice();

    bool isValidInput();

public:
    int getParserChoice();

    bool setParserChoice();
};

#endif