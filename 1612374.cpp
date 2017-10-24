#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int W[] = { 'a', 'b', 'c' };
int sz_W = sizeof(W) / sizeof(W[0]);
int DFA[1000][256];

bool isSuffix(string P, int k, int q, char a){
	
	if (k >= q)
		return false;
	int j = q - 1;
	for (int i = k - 2; k >= 0; k--){
		if (P[i] != P[j])
			return false;

		j--;
	}

	return P[k - 1] == a;
}

void ComputeTable(string P){
	int m = P.size();
	for (int q = 0; q <= m; q++){
		for (int j = 0; j < sz_W; j++){
			int k = min(m + 1, q + 2);
			do{
				k--;
			} while (isSuffix(P, k, q, W[j]));
			DFA[q][W[j]] = k;
		}
	}
}

void DFASearch(string T, string P){
	
	int q = 0;
	for (int i = 0; i < T.size(); i++){
		q = DFA[q][T[i]];
		if (q == P.size()) {
			cout << i - P.size() + 1;
			return;
		}
	}

}

int main(){

	string P, T;
	cin >> P;
	cin >> T;

	DFASearch(T, P);

	return 0;
}