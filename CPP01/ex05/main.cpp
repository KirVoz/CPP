#include "Harl.hpp"

int main()
{
	Harl h;
	std::cout << std::endl
			  << "... DEBUG Level ..." << std::endl;
	h.complain("DEBUG");
	std::cout << std::endl
			  << "... INFO Level ..." << std::endl;
	h.complain("INFO");
	std::cout << std::endl
			  << "... WARNING Level ..." << std::endl;
	h.complain("WARNING");
	std::cout << std::endl
			  << "... ERROR Level ..." << std::endl;
	h.complain("ERROR");
	std::cout << std::endl
			  << "... IBVALID Level ..." << std::endl;
	h.complain("INVALID");
	return 0;
}
