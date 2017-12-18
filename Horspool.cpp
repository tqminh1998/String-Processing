#include <iostream>
#include <cstdio>
using namespace std;

string T, P;
int D[256], n, m;

void ComputeArray()
{
  for (int i = 0; i < 256;i++) D[i] = m;
  for (int i = 0; i < P.size() - 1; i++) D[P[i]] = m-i-1;
}

int main(){

  printf("Enter text: ");
  cin >> T;
  printf("Enter pattern: ");
  cin >> P;
  
  n = T.size();
  m = P.size(); 

  ComputeArray();
  
  int i = m-1;
  
  while (i < n)
  {
    int k = 0;
    while (k < m && T[i-k]==P[m-1-k]) k++;
    if (k == m) printf("found at: %d\n", i-m+1);
    i+=D[T[i]];
  }

  return 0;
}

