#include "Serializer.hpp"

int main() {
	Data *data = new Data();
	data->s1 = "Hello, world!";
	data->n = 42;
	uintptr_t raw = Serializer::serialize(data);
	Data* ptr = Serializer::deserialize(raw);
	std::cout << "data.s1: " << ptr->s1 << std::endl;
	std::cout << "data.n: " << ptr->n << std::endl;
	delete ptr;
	return 0;
}
