#include "fun.h"
#include <iostream>

bool proverka (size_t x, size_t z, vector<vector<double>> max, vector<vector<double>> min, vector<double> R)
{
  if((max[x][z]-min[x][z])<R[x])
        return false;
  else
    return true;
}

void find_minmax (vector<vector<vector<double>>> X,size_t x, size_t L,size_t z, double *max, double *min)
{
 *max=X[x][0][z];
 *min=X[x][0][z];
 for(size_t i=1;i<L;i++)
 {
     if(*max<X[x][i][z])
        *max=X[x][i][z];
      if(*min>X[x][i][z])
        *min=X[x][i][z];
 }
 return;
}

void input(size_t& K, size_t& L, size_t& N, vector<size_t>& M, vector<double>& R)
{
    setlocale(LC_ALL, "Russian");
    cerr<<"Введите количество датчиков: K=";
    cin>>K;
    M.resize(K);
    for(size_t i=0;i<K;i++)
    {
        cerr<<"M №";
        cin>>M[i];
    }
    cerr<<"Введите число опросов датчика: L=";
    cin>>L;
    cerr<<"Введите число серий: N=";
    cin>>N;
    R.resize(K);
    for(size_t i=0;i<K;i++)
    {
        cerr<<"R"<<M[i]<<"=";
        cin>>R[i];
    }
    return;
}
