#include <iostream>
#include <string>
#include <stack>

bool are_pair(char open, char close)
{
    if(open == '{' && close == '}') return true;
    else if(open == '(' && close == ')') return true;
    else if(open == '[' && close == ']') return true;
    return false;
}

bool is_valid(std::string expression, int str_length)
{
    std::stack<char> opening_parentheses;

    for (int i = 0; i < str_length; i++)
    {
        if (expression[i] == ' ') continue;
        if (expression[i] == '{' || expression[i] == '[' || expression[i] == '(')
            opening_parentheses.push(expression[i]);
        else if (expression[i] == '}' || expression[i] == ']' || expression[i] == ')')
        {
            if (opening_parentheses.empty() || !are_pair(opening_parentheses.top(), expression[i])) return false;
            opening_parentheses.pop();
        }
    }
    return opening_parentheses.empty();
}

int main()
{
    std::string expression1 = "()";
    std::string expression2 = "{";
    std::cout << is_valid(expression1, expression1.length()) << std::endl
              << is_valid(expression2, expression2.length()) << std::endl;

    return 0;
}
