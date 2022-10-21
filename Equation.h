#pragma once
#include <vector>
#include <iostream>
#include<algorithm>

template<typename T>
bool allEqual(std::vector<T> const& v);
std::vector<int> compgen(std::vector<int> cpyvect, int coeff, int n, std::vector<int> comp);
int power(int coef, int degre);
void calculate(std::vector<int> vect, int n, std::vector<int> cpyvect, std::vector<int> comp);
void exec(std::vector<int> vect);