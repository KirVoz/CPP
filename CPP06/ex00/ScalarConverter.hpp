#pragma once
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>
#define INT_MAX std::numeric_limits<int>::max()
#define INT_MIN std::numeric_limits<int>::min()
#define FLOAT_MAX std::numeric_limits<float>::max()
#define FLOAT_MIN std::numeric_limits<float>::min()
#define DOUBLE_MAX std::numeric_limits<double>::max()
#define DOUBLE_MIN std::numeric_limits<double>::min()


typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPEC,
	INVALID
} 			e_type;

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &other);
	ScalarConverter &operator=(ScalarConverter const &other);
	~ScalarConverter();
public:
	static void convert(const std::string &str);									
};

e_type findType(const std::string &str, size_t len);
void	convToChar(const std::string &str, size_t len);
void	convToInt(const std::string &str);
void	convToFloat(const std::string &str);
void	convToDouble(const std::string &str);
void	convToSpec(const std::string &str);
