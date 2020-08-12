#include <bits/stdc++.h>
using namespace std;

int n, a[25], check;
vector <int> res;

void rec(int x, int i) {
    if (x<0) return;
    if (x==0) {
        //out
        check = 1;
        cout << "[";
        for (int j=0; j<res.size()-1; j++) cout << res[j] << " ";
        cout << res[res.size()-1] << "]";
        return;
    }
    while (i<n && x>=a[i]) {
        res.push_back(a[i]);
        rec(x-a[i], i);
        res.pop_back();
        i++;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int x;
        cin >> n >> x;
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a, a+n);

        check = 0; res.clear();
        rec(x, 0);
        if (check == 0) cout << -1;
        cout << endl;
    }
}