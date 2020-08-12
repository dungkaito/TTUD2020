#include <bits/stdc++.h>
using namespace std;

typedef long long li;

int main() {
    int t; cin >> t;
    while (t--) {
        li n, input; cin >> n;
        priority_queue <li, vector <li>, greater<li> >pq;
        for (int i=0; i<n; i++) {
            cin >> input;
            pq.push(input);
        }
        li ans=0;
        while (pq.size()>1) {
            li one = pq.top(); pq.pop();
            li two = pq.top(); pq.pop();
            ans += (one + two);
            pq.push(one+two); 
        }
        cout << ans << endl;
    } 
}