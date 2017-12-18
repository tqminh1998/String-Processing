#include <iostream>
using namespace std;

string P,T;
int D[30],n,m;

void ComputeArray()
{
  int x = T.find('?');
  
  if (x == -1)
    for (int i = 65; i <= 122; i++) D[i] = m;
  else
    for (int i = 65; i <= 122; i++) D[i] = m - 1 - x;
  
  for (int i = 0; i < P.size() - 1; i++) D[P[i]] = m-1-i;
}

int main()
{
  cout << "Enter text: ";
  cin >> T;
  cout << "Enter pattern: ";
  cin >> P;
  
  n = T.size();
  m = P.size();
  
  ComputeArray();

  int i=m-1;
  while (i < n)
  {
    int k = 0; 
    while (k < m && (P[m-1-k]==T[i-k]||P[m-1-k]=='?')) k++;
    if (k==m) cout << "found at: " << i-m+1 << endl;
    i+=D[T[i]];
  }

  return 0;
}
