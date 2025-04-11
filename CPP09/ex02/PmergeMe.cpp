#include "PmergeMe.hpp"

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::string &input)
{
	std::istringstream iss(input);
	int number;
	while (iss >> number)
	{
		if (number < 0)
			throw std::invalid_argument("Input contains negative numbers!");
		_vec.push_back(number);
		_deq.push_back(number);
	}
	if (!iss.eof())
	{
		throw std::invalid_argument("Input contains invalid characters.");
	}
}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

// Генерация чисел Якобсталя
std::vector<int> GenerateJacobsthalIndices(int count)
{
	std::vector<int> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	while (jacobsthal.back() < count)
	{
		int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

// Бинарный поиск позиции для вставки
int BinarySearchInsertPos(const std::vector<int> &sorted, int value)
{
	return std::lower_bound(sorted.begin(), sorted.end(), value) - sorted.begin();
}
