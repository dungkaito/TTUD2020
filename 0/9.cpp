#include <bits/stdc++.h>
using namespace std;

int n, a[15][15], check;
string res;

void Try(int x, int y) {
    int xx=x+1, yy=y+1;
    if (x==n-1 && y==n-1) {
        cout << res << " ";
        check = 1;
    }
    if (xx<n && a[xx][y]==1) {
        res += 'D';
        Try(xx,y);
        res.resize(res.size()-1);
    }
    if (yy<n && a[x][yy]==1) {
        res += 'R';
        Try(x,yy);
        res.resize(res.size()-1);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++) cin >> a[i][j];

        if (a[0][0]==0) cout << -1;
        else {
            check = 0;
            res = "";
            Try(0, 0);
            if (check==0) cout << -1;
        }
        cout << "\n";
    } 
}