#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char W[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y','z', ' '};
int sz_W = sizeof(W) / sizeof(W[0]);
int DFA[1000][256];

bool isSuffix(string P, int k, int q, char a){

	if (k > q + 1)
		return false;

	int j = q - 1;

	for (int i = k - 2; i >= 0; i--){
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
			} while (isSuffix(P, k, q, W[j]) == false && k != 0);

			DFA[q][W[j]] = k;
		}
	}
}

int DFASearch(string T, string P){

	int q = 0;
	for (int i = 0; i < T.size(); i++){
		q = DFA[q][T[i]];
		if (q == P.size()) {
			return i - P.size() + 1;
		}
	}

    return -1;
}

int main(){

	string P, T;
	cout << "Nhap chuoi T: ";
	getline(cin, T);
	cout << "Nhap chuoi P: ";
	getline(cin, P);


	ComputeTable(P);

    cout << "Vi tri xuat hien dau tien cua P trong T la: " << DFASearch(T, P);

	return 0;
}
