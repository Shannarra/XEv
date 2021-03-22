#ifndef LEXER_H

#define LEXER_H

#include <stack>
#include <string>

typedef int OperandType;
typedef char OperatorType;

class Lexer
{
public:
	Lexer();
	
	const int Weight(OperatorType operatr) const;

	const int RunOperation(OperandType left, OperandType right, OperatorType operatr) const;

	/// <summary>
	/// As a test "10 * (5 * (4 - (6 / 3) ) / 5) + ( (13 * 8) - 24)" will return 100 :)
	/// </summary>
	/// <param name="text">The text to parse</param>
	/// <returns></returns>
	const int Lex(const std::string text);

	~Lexer();

private:
	/// <summary>
	/// Runs a binary operation and consumes operator/operand tokens.
	/// </summary>
	/// <param name="operands"></param>
	/// <param name="operators"></param>
	void ApplyRunnableOperation(std::stack<OperandType>& operands, std::stack<OperatorType>& operators) const;

};
#endif // !LEXER_H
