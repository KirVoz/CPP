#pragma once 

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <stdexcept>
#include <cstdlib>

class RPN
{
private:
	std::stack<double> s;
public:
	RPN();
	RPN(const RPN &other);
	RPN&operator=(const RPN &other);
	~RPN();
	
	double RevPN(const std::string &string);
};
