#include <bits/stdc++.h>
using namespace std;

void rec(string s, int k, string &maxx) {
    if (k==0) return;
    for (int i=0; i<s.size(); i++) {
        for (int j=i+1; j<s.size(); j++) {
            if (s[i]<s[j]){
                swap(s[i],s[j]);
                if (s.compare(maxx)>0) maxx=s;
                rec(s, k-1, maxx);
                swap(s[i],s[j]);
            }
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int k;
        string s; cin >> k >> s;
        string maxx = s;
        rec(s, k, maxx);
        cout << maxx << endl;
    } 
}