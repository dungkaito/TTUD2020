#include <bits/stdc++.h>
using namespace std;

typedef long long li;

li gcd(li x, li y) {
    if (y == 0) return x;
    return gcd(y, x%y);
}

int main() {
    int t; cin >> t;
    while (t--) {
        li a, x, y; cin >> a >> x >> y;
        x = gcd(x,y);
        while (x--) cout << a;
        cout << endl;
    }
}