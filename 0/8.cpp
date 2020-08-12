#include <bits/stdc++.h>
using namespace std;

int n;
string s, res;
vector <string> ans;

void Try(int i) {
    for (int j=1; j>=0; j--) {
        if (j==1) res += s[i];
        if (i==n-1) ans.push_back(res);
        else Try(i+1);
        if (j==1) res.resize(res.size()-1);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> s; 
        
        ans.clear();
        res = "";
        Try(0);

        sort(ans.begin(), ans.end());
        for (int i=0; i<ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }
}