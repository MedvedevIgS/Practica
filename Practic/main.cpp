#include <iostream>
#include <vector>
#include "SVG.h"
#include "plant.h"
#include "fun.h"

using namespace std;

int main()
{
    Plant plant;
    plant_init(plant);
    size_t K, L, N;
    size_t x, y, z;
    double Max, Min;
    vector<size_t> M;
    vector<double> R;
    input(K,L,N,M,R);
    vector<vector<double>> max (K, vector<double>(N));
    vector<vector<double>> min (K, vector<double>(N));
    vector<vector<size_t>> Error (K, vector<size_t>(N,0));
    vector<vector<vector<double>>> X (K, vector<vector<double>>(L, vector<double>(N)));
    for(z=0;z<N;z++)
    {
        for(y=0;y<L;y++)
        {
            for(x=0;x<K;x++)
            {
              X[x][y][z]=plant_measure(M[x], plant);
            }
        }
        for(x=0;x<K;x++)
        {
            find_minmax(X, x, L, z, &Max, &Min);
                max[x][z]=Max;
                min[x][z]=Min;
            if(proverka(x,z,max,min,R))
                Error[x][z]++;
        }
    }
    svg_output(max,min,Error,M,K,N);
    return 0;
}
