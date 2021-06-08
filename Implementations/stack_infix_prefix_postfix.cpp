#include <iostream>
#include <stack>
#include <string>

// Function to verify whether an operator is right associative or not. 
int is_right_associative(char op)
{
	if(op == '$') return true;
	return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence. 
int get_operator_weight(char op)
{
	int weight = -1; 
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}

// Function to perform an operation and return output. 
int has_higher_precedence(char high_op, char low_op)
{ 
	if(get_operator_weight(high_op) == get_operator_weight(low_op))
	{
		if(is_right_associative(high_op)) return false;
		return true;
	}
	return get_operator_weight(high_op) > get_operator_weight(low_op);
}

// Function to verify whether a character is numeric digit. 
bool is_number(char C) 
{
	if(C >= '0' && C <= '9') return true;
	return false;
}

// Function to verify whether a character is operator symbol or not. 
bool is_operator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/') return true;
	return false;
}

// Function to perform an operation and return output. 
int perform_operation(char operation, int num1, int num2)
{
	if(operation == '+') return num1 +num2;
	else if(operation == '-') return num1 - num2;
	else if(operation == '*') return num1 * num2;
	else if(operation == '/') return num1 / num2;

	else std::cout<<"Unexpected Error \n";
	return -1; 
}

int prefix_evaluation(std::string expression)
{
	std::stack<int> nums;
	for(int i=expression.length()-1; i>=0; i--)
	{
		if(is_number(expression[i])) nums.push(expression[i] - '0');
		else if(is_operator(expression[i]))
		{
			int num1 = nums.top(); nums.pop();
			int num2 = nums.top(); nums.pop();
			int result = perform_operation(expression[i], num1, num2);
			nums.push(result);
		}
	}
	return nums.top();
}

int postfix_evaluation(std::string expression)
{
	std::stack<int> nums;
	for(int i=0; i<expression.length(); i++)
	{
		if(is_number(expression[i])) nums.push(expression[i] - '0');
		else if(is_operator(expression[i]))
		{
			int num2 = nums.top(); nums.pop();
			int num1 = nums.top(); nums.pop();
			int result = perform_operation(expression[i], num1, num2);
			nums.push(result);
		}
	}
	return nums.top();
}

std::string infix_to_postfix(std::string infix)
{
	std::stack<char> operators;
	std::string postfix = "";

	for(int i=0; i<infix.length(); i++) 
	{
		if (is_number(infix[i])) postfix += infix[i];
		else if (infix[i] == '(') operators.push(infix[i]);
		else if (is_operator(infix[i]))
		{
			while(!operators.empty() && operators.top() != '(' && has_higher_precedence(operators.top(), infix[i]))
			{
				postfix += operators.top();
				operators.pop();
			}
			operators.push(infix[i]);
		}
		else if(infix[i] == ')')
		{
			while(!operators.empty() && operators.top() != '(')
			{
				postfix += operators.top();
				operators.pop();
			}
			operators.pop();
		}
	}
	while(!operators.empty())
	{
		postfix += operators.top();
		operators.pop();
	}

	return postfix;
}

int main()
{
	std::string postfix_expression = "23*54*+9-"; //value -> 17
	std::string prefix_expression = "-+*23*548"; //value -> 18
	std::string infix_expression = "2+(3*4)"; //postfix -> 234*+

	std::cout << postfix_expression << " -> " << postfix_evaluation(postfix_expression) << std::endl;
	std::cout << prefix_expression << " -> " << prefix_evaluation(prefix_expression) << std::endl;
	std::cout << infix_expression << " -> " << infix_to_postfix(infix_expression) << std::endl;

	return 0;
}