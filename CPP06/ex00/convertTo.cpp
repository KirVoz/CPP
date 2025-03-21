#include "ScalarConverter.hpp"

void	convToChar(const std::string &str, size_t len){

	char c;

	if (len == 1)
		c = str[0];
	else 
		c = str[1];
	std::cout << "char: ";
	if (isprint(c)){
		std::cout << "'" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else
		std::cout << "Non displayable" << std::endl;
}

void	convToSpec(const std::string &str){
	if (str == "nan" || str == "nanf"){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff"){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff"){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void	convToInt(const std::string &str){
	long int num = atol(str.c_str());
	std::cout << "char: ";
	if (num < 0 || num > 127){
		std::cout << "impossible" << std::endl;
	} else {
		if (isprint(static_cast<char>(num)))
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (num > INT_MAX || num < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << num << std::endl;
	std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void convToFloat(const std::string &str){
	float num = atof(str.c_str());
	std::cout << "char: ";
	if (num < 0 || num > 127){
		std::cout << "impossible" << std::endl;
	} else {
		if (isprint(num))
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (num > INT_MAX || num < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
	std::cout << "float: ";
	if (num > FLOAT_MAX || num < FLOAT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << num << "f" << std::endl;
	std::cout << "double: ";
	if (num > DOUBLE_MAX || num < DOUBLE_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<double>(num) << std::endl;
}

void convToDouble(const std::string &str){
	double num = atof(str.c_str());
	std::cout << "char: ";
	if (num < 0 || num > 127){
		std::cout << "impossible" << std::endl;
	} else {
		if (isprint(num))
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (num > INT_MAX || num < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
	std::cout << "float: ";
	if (num > FLOAT_MAX || num < FLOAT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: ";
	if (num > DOUBLE_MAX || num < DOUBLE_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << num << std::endl;
}
