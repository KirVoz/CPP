#include "PmergeMe.hpp"
#include <ctime> // Для clock()

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
        {
            std::cerr << "Usage: " << argv[0] << " <numbers separated by spaces>" << std::endl;
            return 1;
        }

        std::ostringstream oss;
        for (int i = 1; i < argc; ++i)
        {
            oss << argv[i] << " ";
        }

        PmergeMe sorter(oss.str());

        std::cout << "Unsorted : ";
        for (std::vector<int>::size_type j = 0; j < sorter._vec.size(); ++j)
            std::cout << sorter._vec[j] << " ";
        std::cout << std::endl;
        clock_t startVec = clock();
        std::vector<int> sortedVec = PmergeMe::FordJohnsonSort(sorter._vec);
        clock_t endVec = clock();

        std::cout << "Sorted : ";
        for (std::vector<int>::size_type i = 0; i < sortedVec.size(); ++i)
            std::cout << sortedVec[i] << " ";
        std::cout << std::endl;

        double timeVec = static_cast<double>(endVec - startVec) * 1000.0 / CLOCKS_PER_SEC;
        std::cout << "Time for " << sortedVec.size() << " elements std::vector: " << timeVec << " miliseconds" << std::endl;

        clock_t startDeq = clock();
        std::deque<int> sortedDeq = PmergeMe::FordJohnsonSort(sorter._deq);
        clock_t endDeq = clock();

        // std::cout << "Sorted deque: ";
        // for (std::deque<int>::size_type i = 0; i < sortedDeq.size(); ++i)
        //     std::cout << sortedDeq[i] << " ";
        // std::cout << std::endl;

        double timeDeq = static_cast<double>(endDeq - startDeq) * 1000.0 / CLOCKS_PER_SEC;
        std::cout << "Time for " << sortedDeq.size() << " elements std::deque: " << timeDeq << " miliseconds" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
