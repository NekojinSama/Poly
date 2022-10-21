#include<string>
#include<fstream>
#include<sstream>
#include "Equation.h"


void write(int range, int* output)
{
    std::ofstream wofile;
    wofile.open("output.txt", std::ios::app);;
    if (wofile.is_open())
    {
        for (int i = 0; i < range - 2; i++) { wofile << output[i] << ", "; }
        wofile << output[range - 1] << "\n";
    }wofile.close();
}


void writer(int range, int* output)
{
	std::ofstream wofile;
	wofile.exceptions(std::ofstream::badbit);
	try {
		wofile.open("output.txt", std::ios::app);
        write(range, output);
        wofile.close();
	}
	catch (const std::ofstream::failure& e) {
		std::cout << "Exception opening/writing file";
	}
}


void printer(std::string line, std::vector<int> vectr)
{
    std::stringstream ss(line);
    for (int i; ss >> i;)
    {
        vectr.push_back(i);
        if (ss.peek() == ',' || ss.peek() == ' ') { ss.ignore(); }
    }
    for (int i = 0; i < vectr.size(); i++) { std::cout << vectr[i] << " "; }
    std::cout << "\n";
    if(!vectr.empty()) exec(vectr);
}


void read(std::string line)
{
    std::vector<int> vect;
    std::ifstream rffile;
    rffile.open("output.txt");
    while (!rffile.eof())
    {
        std::getline(rffile, line);
        printer(line,vect);
        vect.erase(vect.begin(), vect.end());
    }
}


void reader(std::string name)
{
    std::string line;
    std::ifstream rffile;
    rffile.exceptions(std::ifstream::badbit);
    try {
        rffile.open(name+".txt");
        read(line);
        rffile.close();
    }
    catch (const std::ifstream::failure& e) {
        std::cout << "Exception opening/reading file";
    }
}


