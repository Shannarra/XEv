#include "include/lexer.h"

Lexer::Lexer()
{
}

const int Lexer::Weight(OperatorType operatr) const {
	switch (operatr)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	default: 
		return 0;
	}
}

const int Lexer::RunOperation(OperandType left, OperandType right, OperatorType operatr) const {
	switch (operatr)
	{
		case '+': return left + right;
		case '-': return left - right;
		case '*': return left * right;
		case '/': return left / right;
		default: return 0;
	}
}

const int Lexer::Lex(std::string text)  {

	std::stack<OperandType> values;
	std::stack<char> operators;

	for (size_t i = 0; i < text.length(); i++)
	{
		if (text[i] == ' ')
			continue;
		else if (text[i] == '(')
			operators.push(text[i]);
		else if (isdigit(text[i])) {
			OperandType value = 0;

			while (i < text.length() && isdigit(text[i]))
			{
				value = (value * 10) + (text[i] - '0');
				i++;
			}

			values.push(value);
			i--;
		}
		else if (text[i] == ')') {
			while (!operators.empty() && operators.top() != '(') 			
			{
				ApplyRunnableOperation(values, operators);
			}
			if (!operators.empty())
				operators.pop();
		}
		else
		{
			while (!operators.empty() && Weight(operators.top()) >= Weight(text[i])) 
			{
				ApplyRunnableOperation(values, operators);
			}
			operators.push(text[i]);
		}
	}

	while (!operators.empty())
	{
		ApplyRunnableOperation(values, operators);
	}

	return values.top();
}

Lexer::~Lexer()
{
}

void Lexer::ApplyRunnableOperation(std::stack<OperandType>& operands, std::stack<OperatorType>& operators) const
{
	OperandType right = operands.top();
	operands.pop();
	OperandType left = operands.top();
	operands.pop();

	OperatorType oprtr = operators.top();
	operators.pop();

	operands.push(RunOperation(left, right, oprtr));
}
