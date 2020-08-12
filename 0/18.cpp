#include <bits/stdc++.h>
using namespace std;

typedef long long li;

li F[93];

char fiboWord(li n, li i) {
    if (n==1) return 'A';
    if (n==2) return 'B';
    if (i<=F[n-2]) return fiboWord(n-2, i);
    else return fiboWord(n-1, i-F[n-2]);
}

int main() {
    F[1]=1; F[2]=1;
    for(int i=3; i<=92; i++) F[i] = F[i-1] + F[i-2];

    int t; cin >> t;
    while (t--) {
        li n, ind;
        cin >> n >> ind;
        cout << fiboWord(n, ind) << endl;
    } 
}