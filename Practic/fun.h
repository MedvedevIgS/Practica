#ifndef FUN_H_INCLUDED
#define FUN_H_INCLUDED
#include <iostream>
#include <vector>

using namespace std;

bool proverka (size_t x, size_t z, vector<vector<double>> max, vector<vector<double>> min, vector<double> R);

void find_minmax (vector<vector<vector<double>>> X,size_t x, size_t L,size_t z, double *max, double *min);

void input(size_t& K, size_t& L, size_t& N, vector<size_t>& M, vector<double>& R);

#endif // FUN_H_INCLUDED
