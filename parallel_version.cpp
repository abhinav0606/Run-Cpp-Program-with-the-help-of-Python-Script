#include<iostream>
#include<omp.h>
#include<iomanip>
#include<chrono>
using namespace std;
using namespace std::chrono;
# define N 1000
double a[N][N],b[N][N];
int c[N][N];
int main()
{

int i,j,k;
omp_set_num_threads(4);
for(i=0;i<N;i++)
{
for(j=0;j<N;j++)
{
a[i][j]=rand()%10;
b[i][j]=rand()%10;
}
}
auto start = high_resolution_clock::now();
#pragma omp parallel for private(i,j,k) shared(a,b,c)
  for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

auto stop = high_resolution_clock::now(); 
  std::chrono::duration<double> elapsed_time = stop - start;
double execution_time = elapsed_time.count();
std::cout << std::fixed << std::setprecision(3)
          << execution_time;
return 0;
}
