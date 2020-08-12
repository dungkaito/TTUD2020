#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, x[15]; cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) x[i] = n-i;
        while (1) {
            for (int i=0; i<n; i++) cout << x[i];
            cout << " ";

            // sinh
            int i=n-2; 
            while (i>=0 && x[i]<x[i+1]) i--;
            if (i<0) break; 
            for (int j=n-1; j>i; j--) {
                if (x[j] < x[i]) {
                    swap(x[j], x[i]);
                    break;
                }
            }
            for (int l=i+1, r=n-1; l<r; l++, r--) swap(x[l], x[r]);
        }
        cout << endl;
    }
}