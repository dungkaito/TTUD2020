#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define fi first
#define se second
#define mp make_pair

int n;
ii cv[1005];

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> cv[i].se;//bat dau
        for (int i=0; i<n; i++) cin >> cv[i].fi;//ket thuc
        sort(cv, cv+n);
    
        int i=0, ans=1;
        for (int j=1; j<n; j++) {
            if (cv[j].se >= cv[i].fi) {
                i = j;
                ans++;
            }
        }
        cout << ans << endl;
    } 
}