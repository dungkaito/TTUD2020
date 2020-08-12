#include <bits/stdc++.h>
using namespace std;

typedef long long li;

string num;
vector <li> cube;

li solve() {
    li len = num.size();
    for (int i=1e6; i>=1; i--) {
        li tmp = cube[i];
        int last = tmp%10;
        for (int j=len-1; j>=0; j--) {
            if (last == num[j]-'0') {
                tmp/=10;
                last = tmp%10;
            }
        }
        if (tmp==0) return cube[i];
    }
    return -1;
}

int main() {
    for (li i=0; i<=1e6; i++) cube.push_back(i*i*i);
    int t; cin >> t;
    while (t--) {
        cin >> num;
        cout << solve() << endl;
    } 
}