#include "Base.hpp"

int main()
{
	srand(time(NULL));
	Base *base = generate();
	Base &ref = *base;
	identify(base);
	identify(ref);
	delete base;
	return 0;
}
