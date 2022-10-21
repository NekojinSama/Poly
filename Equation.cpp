#include <vector>
#include <iostream>
#include<algorithm>


template<typename T>
bool allEqual(std::vector<T> const& v) {
	return std::adjacent_find(v.begin(), v.end(), std::not_equal_to<T>()) == v.end();
}


std::vector<int> compgen(std::vector<int> cpyvect, int coeff, int n, std::vector<int> comp)
{
	if (comp.empty())
	{
		for (int i = 0; i < cpyvect.size(); i++) { comp.push_back(coeff * (pow(i, n))); }
		return comp;
	}
	else
	{
		for (int i = 0; i < comp.size(); i++) { comp[i] = comp[i] + (coeff * (pow(i, n))); }
		return comp;
	}
}

int power(int coef, int degre)
{
	int fact = 1;
	for (int i = 1; i <= degre; ++i) {
		fact *= i;
	}
	std::cout << "(" << coef / fact << ")x^(" << degre << ") + ";
	int coeff = coef / fact;
	return coeff;
}


void calculate(std::vector<int> vect, int n, std::vector<int> cpyvect, std::vector<int> comp, bool flag)
{
	std::vector<int> vect1;
	n++;
	for (auto it = 0; it < vect.size() - 2; it++) { vect1.push_back(vect[it + 1] - vect[it]); }
	if (!allEqual(vect1) && !flag) { flag = true; calculate(vect1, n, cpyvect, comp, false); }
	int coeff = 0; if (!flag)  coeff = power(vect1[0], n);
	comp = compgen(cpyvect, coeff, n, comp);
	std::vector<int> diff; 
	for (auto it = 0; it < cpyvect.size() - 1; it++) { diff.push_back(cpyvect[it] - comp[it]); }
	if (!allEqual(diff) && !flag) { flag = true; calculate(diff, 0, cpyvect, comp, false); }
	else { if(!flag) std::cout << "(" << diff[0] <<")" << "\n"; flag = true; }
}

void exec(std::vector<int> vect)
{
	std::vector<int> cpyVect;
	std::vector<int> comp;

	cpyVect = vect;
	calculate(vect, 0, cpyVect, comp, false);
}