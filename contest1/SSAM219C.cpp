/*--------------------------------------------------------------------------------------
O(n^2) time, O(n) space - TLE
Manacher’s Algo O(n)
[geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-4]
----------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
    int N = s.length();
    N = 2*N + 1; //Position count 
    int L[N]; //LPS Length Array 
    L[0] = 0; 
    L[1] = 1; 
    int C = 1; //centerPosition  
    int R = 2; //centerRightPosition 
    int i = 0; //currentRightPosition 
    int iMirror; //currentLeftPosition 
    int maxLPSLength = 0; 
    int maxLPSCenterPosition = 0; 
    int start = -1; 
    int end = -1; 
    int diff = -1; 
      
    //Uncomment it to print LPS Length array 
    //printf("%d %d ", L[0], L[1]); 
    for (i = 2; i < N; i++)  
    { 
        //get currentLeftPosition iMirror for currentRightPosition i 
        iMirror  = 2*C-i; 
        L[i] = 0; 
        diff = R - i; 
        //If currentRightPosition i is within centerRightPosition R 
        if(diff > 0) 
            L[i] = min(L[iMirror], diff); 
  
        //Attempt to expand palindrome centered at currentRightPosition i 
        //Here for odd positions, we compare characters and  
        //if match then increment LPS Length by ONE 
        //If even position, we just increment LPS by ONE without  
        //any character comparison 
        while ( ((i + L[i]) < N && (i - L[i]) > 0) &&  
            ( ((i + L[i] + 1) % 2 == 0) ||  
            (s[(i + L[i] + 1)/2] == s[(i - L[i] - 1)/2] ))) 
        { 
            L[i]++; 
        } 
  
        if(L[i] > maxLPSLength)  // Track maxLPSLength 
        { 
            maxLPSLength = L[i]; 
            maxLPSCenterPosition = i; 
        } 
  
        //If palindrome centered at currentRightPosition i  
        //expand beyond centerRightPosition R, 
        //adjust centerPosition C based on expanded palindrome. 
        if (i + L[i] > R)  
        { 
            C = i; 
            R = i + L[i]; 
        } 
        //Uncomment it to print LPS Length array 
        //printf("%d ", L[i]); 
    } 
    //printf("\n"); 
    return maxLPSLength;    
    /*
    // below mothod TLE
    li ans = 1;
    li n = s.length(), low, high;
    for (li i=1; i<n; i++) {
        // check xâu con đối xứng có độ dài chẵn
        low = i-1; high = i;
        while (low >= 0 && high < n && s[low] == s[high]) {
            ans = max(ans, high-low+1);
            low--; high++;
        }
        // check xâu con đối xứng có độ dài lẻ
        low = i-1; high = i+1;
        while (low >= 0 && high < n && s[low] == s[high]) {
            ans = max(ans, high-low+1);
            low--; high++;
        }
    }
    return ans;
    */
}

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        cout << solve(s) << endl;
    }
}