#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &other){
	this->s = other.s;
}

RPN::~RPN(){}

RPN &RPN::operator=(const RPN &other){
	if (this != &other) {
		this->s = other.s;
	}
	return *this;
}

double RPN::RevPN(const std::string &string)
{

	std::istringstream iss(string);
	std::string token;

	while (iss >> token)
	{
		if ((std::isdigit(token[0]) && !token[1]) || (token[0] == '-' && token.size() > 1) || (token[0] == '+' && token.size() > 1))
		{
			s.push(std::atof(token.c_str()));
		} else {
			if (s.size() < 2)
				throw std::runtime_error("Error");
			double right = s.top();
			s.pop();
			double left = s.top();
			s.pop();
			double res = 0;

			if (token == "+")
				res = left + right;
			else if (token == "-")
				res = left - right;
			else if (token == "*")
				res = left * right;
			else if (token == "/")
			{
				if (right == 0)
					throw std::runtime_error("Error: Divide on ZERO!");
				res = left / right;
			} else {
				throw std::runtime_error("Error: unknown operator '" + token + "'");
			}
			s.push(res);
		}
	}
	if (s.size() != 1)
		throw std::runtime_error("Error: More than one number in stack");
	return s.top();
}
