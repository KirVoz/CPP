#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>
#include <iomanip>

class BitcoinExchange
{
private:
    std::map<std::string, double> _dataMap;

public:
    BitcoinExchange();
    BitcoinExchange(const std::string &filename);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void readInput(const std::string &filename);
    void readCSV(const std::string &filename);
    bool validateLine(const std::string &line, std::string &date, double &value, char sep);
    bool isValidDate(const std::string &date);
    void isValidValue(const double &value);
    std::map<std::string, double>::iterator findClosestDate(const std::string &date);
};
