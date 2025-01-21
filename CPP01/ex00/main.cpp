#include "Zombie.hpp"

int main()
{
	Zombie *zombie = newZombie("Zomoniak");
	zombie->announce();
	randomChump("Zomonini");
	delete zombie;
	return 0;
}
