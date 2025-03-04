#pragma once
#include <iostream>


class Brain
{
private:
	std::string _ideas[100];
public:
	Brain();
	Brain(const Brain &copy);
	virtual ~Brain();

	Brain &operator=(const Brain &other);
	
	const std::string &getIdea(size_t) const;
	const std::string *getIdeasAddres(size_t) const;
	void setIdea(size_t, const std::string &idea);
};
