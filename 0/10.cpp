#include <bits/stdc++.h>
using namespace std;

int n, a[15][15], check, chosen[15][15];
string res;

void Try(int x, int y) {
    if (x==n-1 && y==n-1) {
        cout << res << " ";
        check = 1;
    }
    if (x+1<n && a[x+1][y]==1 && chosen[x+1][y]==0) {
        res += 'D';
        chosen[x+1][y]=1;
        Try(x+1,y);
        res.resize(res.size()-1);
        chosen[x+1][y]=0;
    }
    if (y-1>=0 && a[x][y-1]==1 && chosen[x][y-1]==0) {
        res += 'L';
        chosen[x][y-1]=1;
        Try(x,y-1);
        res.resize(res.size()-1);
        chosen[x][y-1]=0;
    }
    if (y+1<n && a[x][y+1]==1 && chosen[x][y+1]==0) {
        res += 'R';
        chosen[x][y+1]=1;
        Try(x,y+1);
        res.resize(res.size()-1);
        chosen[x][y+1]=0;
    }
    if (x-1>=0 && a[x-1][y]==1 && chosen[x-1][y]==0) {
        res += 'U';
        chosen[x-1][y]=1;
        Try(x-1,y);
        res.resize(res.size()-1);
        chosen[x-1][y]=0;
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
            memset(chosen, 0, sizeof(chosen));
            chosen[0][0]=1;
            Try(0, 0);
            if (check==0) cout << -1;
        }
        cout << "\n";
    } 
}