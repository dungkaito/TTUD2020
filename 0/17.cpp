#include <bits/stdc++.h>
using namespace std;

typedef long long li;

li n, k;

li doDai(li n) {
    if (n==1) return 1;
    return doDai(n-1)*2+1;
}

li solve(li st, li en, li n) {

    li mid = (st+en)/2;
    if (mid == k) return n;
    if (mid > k) return solve(st, mid-1, n-1);
    if (mid < k) return solve(mid+1, en, n-1);
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        if (k%2==1) cout << 1 << endl;
        else cout << solve(1, doDai(n), n) << endl;
    } 
}