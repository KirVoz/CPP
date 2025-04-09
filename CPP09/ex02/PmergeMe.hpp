#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <sstream>

class PmergeMe
{
public:
    std::vector<int> _vec;
    std::deque<int> _deq;

    PmergeMe();
    PmergeMe(const std::string &input);
    PmergeMe(const PmergeMe &other);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &other);

    template <typename Container>
    static Container FordJohnsonSort(Container arr);
};

std::vector<int> GenerateJacobsthalIndices(int count);
int BinarySearchInsertPos(const std::vector<int> &sorted, int value);

// Реализация шаблонной функции
template <typename Container>
Container PmergeMe::FordJohnsonSort(Container arr)
{
    int n = arr.size();
    if (n <= 1)
        return arr;

    Container minima, maxima;

    // 1. Разбиваем на пары (min, max)
    for (int i = 0; i + 1 < n; i += 2)
    {
        if (arr[i] < arr[i + 1])
        {
            minima.push_back(arr[i]);
            maxima.push_back(arr[i + 1]);
        }
        else
        {
            minima.push_back(arr[i + 1]);
            maxima.push_back(arr[i]);
        }
    }

    // Если нечётное количество — последний идёт в maxima
    if (n % 2 == 1)
        maxima.push_back(arr.back());

    // 2. Рекурсивно сортируем maxima
    Container sorted = FordJohnsonSort(maxima);

    // 3. Вставляем элементы из minima по порядку чисел Якобсталя
    std::vector<int> jacobIndices = GenerateJacobsthalIndices(minima.size());
    std::vector<int> inserted(minima.size(), 0);

    for (std::vector<int>::size_type j = 0; j < jacobIndices.size(); ++j)
    {
        int index = jacobIndices[j];
        if (index < static_cast<int>(minima.size()) && !inserted[index])
        {
            typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), minima[index]);
            sorted.insert(pos, minima[index]);
            inserted[index] = 1;
        }
    }

    // Вставляем оставшиеся элементы
    for (std::vector<int>::size_type i = 0; i < minima.size(); ++i)
    {
        if (!inserted[i])
        {
            typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), minima[i]);
            sorted.insert(pos, minima[i]);
        }
    }

    return sorted;
}
