#include <bits/stdc++.h>
using namespace std;

typedef long long li;
typedef long double ld;

int main() {
    int t; cin >> t;
    while (t--) {
        li n; ld H;
        cin >> n >> H;
        for (int i=1; i<=n-1; i++) {
            cout << fixed << setprecision(6) << H*sqrt(ld(i)/ld(n));
            if (i<n-1) cout << ' ';
        }
        cout << '\n';
    }
}