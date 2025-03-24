#include "Array.hpp"

int main()
{
	{
		Array<int> intArray(5);

		for (unsigned int i = 0; i < intArray.size(); i++)
		{
			intArray[i] = i;
			std::cout << intArray[i] << std::endl;
		}
		std::cout << "Size: " << intArray.size() << std::endl;
	}
	{
		Array<char> charArray(10);
		
		for (unsigned int i = 0; i < charArray.size(); i++)
		{
			charArray[i] = i + 65;
			std::cout << charArray[i] << std::endl;
		}
		std::cout << "Size: " << charArray.size() << std::endl;
	}
	{
		Array<std::string> *stringArray = new Array<std::string>(3);
		
		(*stringArray)[0] = "Hello";
		(*stringArray)[1] = "World";
		(*stringArray)[2] = "!";

		for (unsigned int i = 0; i < stringArray->size(); i++)
			std::cout << (*stringArray)[i] << std::endl;
		std::cout << "Size: " << stringArray->size() << std::endl;
		delete stringArray;
	}
	return 0;
}
