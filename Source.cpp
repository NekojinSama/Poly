#include<iostream>
#include"Handler.h"
#include"Class.h"


void EqGen(int terms, int* coeff, int* degree)
{
	std::cout << "Desired expression is: ";
	for (int i = terms; i > 1; i--)
	{
		std::cout << "(" << coeff[i - 1] << ")x^(" << degree[i - 1] << ") + ";
	}
	std::cout << "(" << coeff[0] << ")x^(" << degree[0] << ")\n\n";
}


int* SeriesOutput(int terms, int start, int finish, int* output, int* coeff, int* degree)
{
	int range = 0;
	for (auto i = start; i <= finish; i++)
	{
		int sum = 0;
		for (auto j = terms; j > 0; j--) { sum += coeff[j - 1] * pow(i, degree[j - 1]); }
		output[range] = sum;
		range++;
	} 
	for (auto i = 0; i < range - 2; i++) { std::cout << output[i] << ", "; }
	std::cout << output[range - 1];
	return output;
}


bool checker1(int num)
{
	bool check = (num > 4) ? false : true;
	return check;
}


bool checker2(int num1, int num2)
{
	bool check = ((num2 > 1 && num1 > 9) || abs(num1) > 1000) ? false : true;
	return check;
}


int main()
{
	int menu = 0;
	//Equation term;
	do {
		std::cout << "Polynomial Coursework Menu";
		std::cout << "\n1. Create an algebric equation, generate the output list and store in .txt file \n2. Read from output list and find the algebric equation \n3. Exit\n\nYour Input: ";
		std::cin >> menu;


		switch (menu)
		{
		case 1:
		{
			int terms = 0, start_num = 0, finish_num = 0;
			std::cout << "Enter number of terms(Max = 4): ";
			std::cin >> terms;
			if (!checker1(terms)) { goto re; }

			Equation Eq;
			for (int i = terms; i > 0; i--)
			{
				std::cout << "Enter Coefficient of " << i << " term: ";
				std::cin >> Eq.co[i - 1];
				std::cout << "Enter Degree of " << i << " term(Range 0-4): ";
				std::cin >> Eq.de[i - 1];
				if (!checker1(Eq.de[i-1])) { goto re; }
				if (!checker2(Eq.co[i - 1], Eq.de[i - 1])) { goto re; }
			}

			EqGen(terms, Eq.co, Eq.de);

			std::cout << "Enter start number: ";
			std::cin >> start_num;
			std::cout << "Enter finish number: ";
			std::cin >> finish_num;
			int* output = new int[100];
			SeriesOutput(terms, start_num, finish_num, output, Eq.co, Eq.de);

			int range = abs(finish_num - start_num) + 1;
			writer(range, output);
			delete[] output;
			output = NULL;
			std::cout << "\n";
		}	
			system("pause");
			system("CLS");
			break;


		case 2:
		{
			std::string name;
			std::cout << "Enter File name w/o extension: ";
			std::cin >> name;
			reader(name);
		}
			system("pause");
			system("CLS");
			break;
		
			

		case 3:
			break;


		default:
		re: std::cout << "Enter correct value\n";
			system("pause");
			system("CLS");
		}
	} while (menu != 3);


}