/*
Code : No. of balanced BTs
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 24
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/


#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int balancedBTs(int n) {
    int* dp = new int[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=(int)((long)(dp[i-1])*((2*(long)(dp[i-2]) + dp[i-1])%mod)%mod);
    }
    int result = (dp[n]%mod);
    delete[] dp;
    return result;
    // Write your code here
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
