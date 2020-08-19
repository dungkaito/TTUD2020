#include <bits/stdc++.h>
using namespace std;

typedef long long li;

li bigNumMod(string b, li a) {
    li res = 0;
    for (int i=0; i<b.size(); i++)
        res = (res*10 + b[i] - '0') % a;
    return res;
}

li gcd(li a, li b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

int main() {
    int t; cin >> t;
    while (t--) {
        li a; string b;
        cin >> a >> b;
        cout << gcd(a, bigNumMod(b, a)) << endl;
    }
}