#ifndef HARL_HPP
#define HARL_HPP
#define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
#define INFO "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
#define WARNING "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
#define ERROR "This is unacceptable! I want to speak to the manager now."

#include <iostream>

class Harl
{
public:
	Harl();
	~Harl();
	void complain(std::string level);

private:
	void _debug();
	void _info();
	void _warning();
	void _error();
};

#endif
