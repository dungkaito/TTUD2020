#include <bits/stdc++.h>
using namespace std;

long long toNum(string s) {
    long long res=0;
    for (int i=0; i<s.size(); i++)
        res = res *10 + s[i]-'0';
    return res;
}

string solve(int n) {
    queue <string> q;
    q.push("9");
    while (1) {
        string top=q.front(); q.pop();
        if (toNum(top) % n == 0) return top;
        q.push(top+"0");
        q.push(top+"9");
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << solve(n) << endl;
    }
}