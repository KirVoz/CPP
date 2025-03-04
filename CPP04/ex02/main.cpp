#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	// std::cout << "\033[1;31m___CONSTRUCTING___\033[0m" << std::endl;
	// {
	// 	const AAnimal *a = new AAnimal();
	// 	a->makeSound();
	// }
	// {
	// 	AAnimal a("AAnimal");
	// 	a.makeSound();
	// }

	std::cout << "\033[2;31***************************" << std::endl;

	std::cout << "\033[1;31m___CONSTRUCTING___\033[0m" << std::endl;
	{
		AAnimal *AAnimals[10];
		for (size_t i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
			{
				AAnimals[i] = new Dog();
				if (!AAnimals[i])
				{
					std::cerr << "Memory allocation failed" << std::endl;
					return (1);
				}
			}
			else
			{
				AAnimals[i] = new Cat();
				if (!AAnimals[i])
				{
					std::cerr << "Memory allocation failed" << std::endl;
					return (1);
				}
			}
		}
		std::cout << "***************************" << std::endl;

		std::cout << "\033[1;31m___TESTING___\033[0m" << std::endl;

		for (size_t i = 0; i < 10; i++)
		{
			std::cout << "AAnimal is a " << AAnimals[i]->getType() << i + 1 << " says: ";
			AAnimals[i]->makeSound();
		}
		std::cout << "***************************" << std::endl;

		std::cout << "\033[1;31m___DESTRUCTING___\033[0m" << std::endl;
		for (size_t i = 0; i < 10; i++)
		{
			delete AAnimals[i];
		}
		std::cout << "***************************" << std::endl;
	}
	{
		std::cout << "\033[1;31m___TESTING___DEEP_AND_SHALLOW___COPY___\033[0m" << std::endl;

		Dog *a = new Dog();
		for (size_t i = 0; i < 100; i++)
			a->setIdea(i, "\033[3;35mI am a dog\033[0m");
		a->setIdea(101, "FAKE IDEA");

		Dog *b = new Dog(*a);

		std::cout << "\033[1;31m______A______\033[0m" << std::endl;
		a->getIdeas();
		delete (a);

		std::cout << "\033[1;31m______B______\033[0m" << std::endl;
		b->getIdeas();
		delete (b);
		std::cout << "***************************" << std::endl;
	}

	{
		const AAnimal *j = new Dog();
		const AAnimal *i = new Cat();

		delete j; // should not create a leak
		delete i;
	}
	return (0);
}
