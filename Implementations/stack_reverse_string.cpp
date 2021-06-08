#include <iostream>
#include <stack>
#include <string>

void reverse(std::string &word, int n)
{
    std::stack<char> rev_word; 
    for(int i=0; i<n; i++) rev_word.push(word[i]);  

    for(int i=0; i<n; i++)
    {
        word[i] = rev_word.top();
        rev_word.pop();
    }
}

int main()
{
    std::string word = "ShubhamJha";
    reverse(word, word.length());
    std::cout << word << std::endl;

    return 0;
}