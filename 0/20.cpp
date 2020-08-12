#include <bits/stdc++.h>
using namespace std;

typedef long long li;

const int M = 1e9+7;
int n;

struct Matran {
	li f[11][11];
};

Matran operator * (Matran A, Matran B) {
	Matran res;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			res.f[i][j]=0;
			for (int k=0; k<n; k++) {
				res.f[i][j] = (res.f[i][j] + A.f[i][k]*B.f[k][j]%M)%M;
			}
		}
	}
	return res;
}

Matran powM(Matran M, int k) {
	if (k==1) return M;
	Matran A = powM(M, k/2);
	if (k%2==0) return A*A;
	return M*A*A;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int k; cin >> n >> k;
		Matran M;
		for(int i=0;i<n;i++){
			for (int j=0;j<n;j++) {
				cin >> M.f[i][j];
			}
		}
		M = powM(M, k);
		for(int i=0;i<n;i++){
			for (int j=0;j<n;j++) {
				cout << M.f[i][j] << " ";
			}
			cout << "\n";
		}
	}
}