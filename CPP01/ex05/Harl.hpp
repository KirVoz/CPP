#ifndef HARL_HPP
#define HARL_HPP
#define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
#include <iostream>

class Harl
{
private:
	void _debug();
	void _info();
	void _warning();
	void _error();

public:
	Harl();
	~Harl();
	void complain(std::string level);
};

#endif
