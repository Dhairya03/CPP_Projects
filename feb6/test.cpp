// #include <iostream>
// #include<limits>

// int main() {
//     float floatValue;

//     std::cout << "Enter a float number: ";
//     std::cin >> floatValue;

//     // Check if input was successful
//     if (std::cin.fail()||std::cin.get()!='\n') {
//         std::cerr << "Invalid input. Please enter a valid float number." << std::endl;
//         std::cin.clear(); // Clear the error state
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
//         return 1; // indicate error
//     }
//      if (std::cin.peek()!='\n') {
//         std::cerr << "Invalid input. Please enter a valid float number." << std::endl;
//         std::cin.clear(); // Clear the error state
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
//         return 1; // indicate error
//     }

//     // Input was successful, so floatValue now contains the valid float number
//     std::cout << "You entered: " << floatValue << std::endl;

//     return 0;
// }

#include <iostream>
#include <limits>

int main() {
    float floatValue;

    std::cout << "Enter a float number: ";
    std::cin >> std::ws;  // Skip leading whitespace, including spaces

    if (!(std::cin >> floatValue) || std::cin.get() != '\n') {
        std::cerr << "Invalid input. Please enter a valid float number." << std::endl;
        std::cin.clear();  // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
        return 1;  // Indicate error
    }

    // Input was successful, so floatValue now contains the valid float number
    std::cout << "You entered: " << floatValue << std::endl;

    return 0;
}
