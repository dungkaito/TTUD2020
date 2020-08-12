#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int M = 1e9+7;

struct matran{
	int64 a[2][2];
};

matran operator * (matran X, matran Y) {
	matran res;
	res.a[0][0]=(X.a[0][0]*Y.a[0][0]%M+X.a[0][1]*Y.a[1][0]%M)%M;
	res.a[0][1]=(X.a[0][0]*Y.a[0][1]%M+X.a[0][1]*Y.a[1][1]%M)%M;
	res.a[1][0]=(X.a[1][0]*Y.a[0][0]%M+X.a[1][1]*Y.a[1][0]%M)%M;
	res.a[1][1]=(X.a[1][0]*Y.a[0][1]%M+X.a[1][1]*Y.a[1][1]%M)%M;
	return res;
}

matran powM(matran X, int n) {
	if (n==1) return X;
	matran Y=powM(X, n/2);
	if (n%2==0) return Y*Y;
	return X*Y*Y;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		matran X;
		X.a[0][0]=0;X.a[0][1]=1;
		X.a[1][0]=1;X.a[1][1]=1;
		X = powM(X,n-1);
		cout << X.a[1][1] << endl;
	}
}