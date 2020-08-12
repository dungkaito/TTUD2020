#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n ,k, x[1005]; cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i=0; i<k; i++) cin >> x[i];

        // solve
        int i=k-2; 
        while (i>=0 && x[i]+1 == x[i+1]) i--;
        if (i<0 && x[i+1]==1)
            for (int j=0; j<k; j++) x[j] = n-k+j+1;
        else {
            x[++i]--;
            for (int j=i+1; j<k; j++) x[j] = n-k+j+1;
        }
        
        // out
        for (int j=0; j<k; j++) cout << x[j] << " ";
        cout << endl;
    }
}