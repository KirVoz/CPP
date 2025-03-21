#include "ScalarConverter.hpp"

static bool isChar(const std::string &str, size_t len)
{
	if (len == 1 && !isdigit(str[0]))
		return true;
	if (len == 3 && str[0] == '\'' && str[2] == '\'' && !isdigit(str[1]))
		return true;
	return false;
}

static bool isInt(const std::string &str, size_t len)
{
	size_t i = 0;
	if (len == 1 && isdigit(str[i]))
		return true;
	if (str[i] == '-' && str[i] == '+')
		i++;
	for (; i < len; i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	// int num = atoi(str.c_str());
	// std::cout << num << std::endl;
	// if (num > INT_MAX || num < INT_MIN)
	// 	return false;
	return true;
}

static bool ifSpec(const std::string &str) {
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return true;
	return false;
}

static bool isFloat(const std::string &str, size_t len) {
    size_t l = len - 1;
    if (str[l] == 'f') {
        l--;
    } else {
        return false;
    }
    bool hasDecimalPoint = false;
    for (; l > 0; l--) {
        if (isdigit(str[l])) {
            continue;
        } else if (str[l] == '.') {
            if (hasDecimalPoint) {
                return false;
            }
            hasDecimalPoint = true;
        } else if (str[l] == '-' || str[l] == '+') {
            if (l == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
		// float num = atof(str.c_str());
		// if (num > FLOAT_MAX || num < FLOAT_MIN)
		// 	return false;
    }
    return true;
}

static bool isDouble(const std::string &str, size_t len) {
	bool hasDecimalPoint = false;
	for (size_t i = 0; i < len; i++) {
		if (isdigit(str[i])) {
			continue;
		} else if (str[i] == '.') {
			if (hasDecimalPoint) {
				return false;
			}
			hasDecimalPoint = true;
		} else if (str[i] == '-' || str[i] == '+') {
			if (i == 0) {
				continue;
			} else {
				return false;
			}
		} else {
			return false;
		}
		// double num = atof(str.c_str());
		// if (num > DOUBLE_MAX || num < DOUBLE_MIN)
		// 	return false;
	}
	return true;
}

e_type findType(const std::string &str, size_t len)
{
	size_t dot = str.find('.');
	size_t f = str.find('f');
	if (dot == std::string::npos)
	{
		if(isChar(str, len))
			return CHAR;
		if(isInt(str, len))
			return INT;
		if (ifSpec(str))
			return SPEC;
	}
	if (f != std::string::npos)
	{
		if (isFloat(str, len))
			return FLOAT;
	}
	else if (isDouble(str, len))
		return DOUBLE;
	return INVALID;
}
