#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &str)
{
	size_t len = str.length();
	e_type type = findType(str, len);
	switch (type)
	{
	case CHAR:
		convToChar(str, len);
		break;
	case INT:
		convToInt(str);
		break;
	case FLOAT:
		convToFloat(str);
		break;
	case DOUBLE:
		convToDouble(str);
		break;
	case SPEC:
		convToSpec(str);
		break;
	case INVALID:
		std::cout << "Error: Invalid input" << std::endl;
		break;
	}
}
