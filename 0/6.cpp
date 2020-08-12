#include <bits/stdc++.h>
using namespace std;

void in(int x[], int siz) {
	cout << "(";
	for (int i=0; i<siz-1; i++) cout << x[i] << " ";
	cout << x[siz-1] << ") ";
}

int main() {
	int t; cin >> t;
	int n, x[15], siz;
	while (t--) {
		cin >> n;
		x[0] = n; siz = 1;
		while (true) {
			in(x, siz);
			//sinh kt
			int i=siz-1;
			while (i>=0 && x[i]==1) i--;
			if (i<0) break;
			
			x[i] -= 1;
			int feed = 1 + siz - i - 1, nguyen = feed / x[i], du = feed % x[i];
			siz = i+1;
			if (nguyen > 0) {
				siz += nguyen;
				for (int j=i+1; j<siz; j++) x[j] = x[i];
			}
			if (du > 0) {
				siz++;
				x[siz-1] = du;
			}
		}
		cout << "\n";
	}
}