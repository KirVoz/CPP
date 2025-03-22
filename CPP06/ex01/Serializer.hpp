#pragma once 
#include <iostream> 
#include <string>
#include <stdint.h>

struct Data
{
	std::string s1;
	int n;
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &other);
	~Serializer();
	Serializer &operator=(const Serializer &other);
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
