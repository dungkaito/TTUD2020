/*-------------------------------------
f(n) = 1^n + 2^n + 3^n + 4^n
f(1)=10
f(2)=30
f(3)=100
f(4)=354
f(5)=1300
f(6)=4890
f(7)=18700
f(8)=72354
f(9)=282340
---------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string n_string; cin >> n_string;

        int twoLastChr=0;
        for (int i=n_string.size()-2;i<n_string.size(); i++)
            twoLastChr = twoLastChr * 10 + n_string[i];

        if (twoLastChr % 4 == 0) cout << "4\n";
        else cout << "0\n";
    }
}