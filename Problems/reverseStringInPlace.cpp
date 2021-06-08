#include <iostream>
#include <string>

void reverseStringInPlace(std::string &input)
{
    for(int i = 0; i < input.length()/2; i++){
        std::swap(input[i], input[input.length()-i-1]);
    }
}

int main()
{
    std::string input;
    std::cout << "Enter string to be reversed: "; 
    std::cin >> input;

    reverseStringInPlace(input);
    std::cout << input;

    return 0;
}