#include <iostream>
#include <fstream>

void replaceIfNeeded(const std::string &filename, const std::string &s1, const std::string &s2)
{
	if (s1.empty())
	{
		std::cerr << "Error: S1 is empty" << std::endl;
		return;
	}
	std ::ifstream inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cerr << "Error: Input file is empty or doesn't exist" << std::endl;
		return;
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile)
	{
		std::cerr << "Error: Can't create Outputfile" << std::endl;
		inputFile.close();
		return;
	}
	std::string buf;
	while (std::getline(inputFile, buf))
	{
		std::string res;
		std::size_t pos(0);
		while (pos < buf.length())
		{
			std::size_t found = buf.find(s1, pos);
			if (found != std::string::npos)
			{
				res.append(buf, pos, found - pos);
				res.append(s2);
				pos = found + s1.size();
			}
			else
			{
				res.append(buf, pos, buf.size() - pos);
				break;
			}
		}
		outputFile << res << std::endl;
	}
	inputFile.close();
	outputFile.close();
	std::cout << "Done and dusted. Check: " << filename + ".replace" << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	const std::string filename = av[1];
	const std::string s1 = av[2];
	const std::string s2 = av[3];
	replaceIfNeeded(filename, s1, s2);
	return 0;
}
