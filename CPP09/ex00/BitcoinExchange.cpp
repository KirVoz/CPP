#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	readCSV("./data.csv");
	readInput(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _dataMap(other._dataMap) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_dataMap = other._dataMap;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::readCSV(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	bool isFirstLine = true;

	while (std::getline(file, line))
	{
		if (isFirstLine)
		{
			isFirstLine = false;
			continue;
		}

		std::string date;
		double value;

		if (validateLine(line, date, value, ','))
		{
			_dataMap[date] = value;
		}
	}

	file.close();
}

void BitcoinExchange::readInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	bool isFirstLine = true;

	while (std::getline(file, line))
	{
		if (isFirstLine)
		{
			isFirstLine = false;
			continue;
		}

		std::string date;
		double value;

		if (!validateLine(line, date, value, '|'))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		try
		{
			isValidValue(value);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			continue;
		}
		std::map<std::string, double>::iterator dataIt = _dataMap.find(date);
		if (dataIt == _dataMap.end())
		{
			dataIt = findClosestDate(date);
			if (dataIt == _dataMap.end())
			{
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}
		}

		double exchangeRate = dataIt->second;
		double result = value * exchangeRate;

		std::cout << date << " => " << value << " = " << /*std::setprecision(16) << */ result << std::endl;
	}

	file.close();
}

bool BitcoinExchange::validateLine(const std::string &line, std::string &date, double &value, char sep)
{
	std::stringstream ss(line);
	std::string valueStr;

	if (!std::getline(ss, date, sep))
		return false;

	date.erase(0, date.find_first_not_of(' '));
	date.erase(date.find_last_not_of(' ') + 1);

	if (!isValidDate(date))
		return false;

	if (!(ss >> value))
		return false;

	return true;
}

void BitcoinExchange::isValidValue(const double &value)
{
	if (value < 0)
		throw std::runtime_error("not a positive number.");
	if (value > 1000)
		throw std::runtime_error("too large a number.");
}

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	if (date.find_first_not_of("0123456789-") != std::string::npos)
		return false;
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year <= 0 || month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year))
		daysInMonth[1] = 29;

	return day <= daysInMonth[month - 1];
}

std::map<std::string, double>::iterator BitcoinExchange::findClosestDate(const std::string &date)
{
	std::map<std::string, double>::iterator it = _dataMap.lower_bound(date);

	if (it == _dataMap.begin() && it->first != date)
		return _dataMap.end();

	if (it == _dataMap.end() || it->first != date)
		--it;

	return it;
}
