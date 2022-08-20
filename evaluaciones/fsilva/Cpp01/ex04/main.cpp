#include <string>
#include <iostream>
#include <fstream>

int process_args(int argc)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments\n";
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	std::string line;

	if (process_args(argc))
		return (1);
	std::string filename = argv[1];
	std::string toFind = argv[2];
	std::string replacement = argv[3];
	if (toFind == "" || replacement == "")
	{
		std::cout << "Empty string not allowed as input\n";
		return (1);
	}
	std::ofstream wfile(filename + ".replace");
	if (!wfile.good())
	{
		std::cout << "Error opening/creating output file\n";
		return(1);
	}
	std::ifstream rfile;
	rfile.open(filename);
	if (rfile.is_open())
	{
		while(std::getline(rfile, line))
		{
			std::string::size_type found = line.find(toFind);
			while(found != std::string::npos)
			{
				if (found != std::string::npos)
				{
					line.erase(found, toFind.size());
					line.insert(found, replacement);
				}
				found = line.find(toFind, found + replacement.size());
			}
			wfile << line << std::endl;
		}
		rfile.close();
	}
	else
		std::cout << "Error opening the file\n";
    return (0);
}
