#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> pos;
int pi[1000];

void ComputeArray(string P){
    int k;
    pi[1] = k = 0;

    for (int q = 2; q <= P.size(); q++){

        while (k > 0 && P[k] != P[q - 1])
            k = pi[k];

        if (P[k] == P[q - 1]) k++;

        pi[q] = k;
    }
}

void KMP(string P, string T){

    ComputeArray(P);

    //for (int i = 1; i < 11; i++)
    //   cout << pi[i] << " ";

    int q=0;

    for (int i = 0; i < T.size(); i++){
        while ((q > 0) && (P[q] != T[i]))
            q = pi[q];

        if (P[q] == T[i]) q++;
        if (q == P.size()){
            pos.push_back(i - P.size() + 1);
            q = pi[q];
        }
    }

}

int main(){
	string P, T;
	cout << "Nhap chuoi T: ";
	getline(cin, T);
	cout << "Nhap chuoi P: ";
	getline(cin, P);

    KMP(P, T);

    cout << "Cac vi tri cua P trong T la: ";

    for (int i = 0; i < pos.size(); i++){
        cout << pos[i] << "  ";
    }

    cout << endl;
    return 0;
}
