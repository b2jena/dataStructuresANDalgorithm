/*
Longest Increasing Subsequence

Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in strictly increasing order.
Input Format :
The first line of input contains an integer N. The following line contains N space separated integers, that denote the value of elements of array.
Output Format :
The first and only line of output contains the length of longest subsequence.
Constraints
1 <= N <= 10^3
Time Limit: 1 second
Sample Input 1 :
6
5 4 11 1 16 8
Sample Output 1 :
3
Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).
Sample Input 2 :
3
1 2 2
Sample Output 2 :
2
*/
//author b2jena
#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define EPS 1e-9
#define pi 3.1415926535897932384626433832795

using ll = long long;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;

const int MAX_N = 1e5 + 1;
const double PI = acos(-1.0);

template<typename T> T gcd(T a, T b) {return (b ? __gcd(a, b) : a);}
template<typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}

int add(int a, int b, int c) {int res = a + b; return (res >= c ? res - c : res);}

int mod_neg(int a, int b, int c) {int res; if (abs(a - b) < c)res = a - b; else res = (a - b) % c; return (res < 0 ? res + c : res);}

int mul(int a, int b, int c) {ll res = (ll)a * b; return (res >= c ? res % c : res);}

ll mulmod(ll a, ll b, ll m) {ll q = (ll)(((ld)a * (ld)b) / (ld)m); ll r = a * b - q * m; if (r > m)r %= m; if (r < 0)r += m; return r;}

template<typename T>T expo(T e, T n) {T x = 1, p = e; while (n) {if (n & 1)x = x * p; p = p * p; n >>= 1;} return x;}

template<typename T>T power(T e, T n, T m) {T x = 1, p = e; while (n) {if (n & 1)x = mul(x, p, m); p = mul(p, p, m); n >>= 1;} return x;}

template<typename T>T extended_euclid(T a, T b, T &x, T &y) {
    T xx = 0, yy = 1; y = 0; x = 1; while (b) {
        T q = a / b, t = b; b = a % b; a = t; \
        t = xx; xx = x - q * xx; x = t; t = yy; yy = y - q * yy; y = t;
    } return a;
}

template<typename T>T mod_inverse(T a, T n) {T x, y, z = 0; T d = extended_euclid(a, n, x, y); return (d > 1 ? -1 : mod_neg(x, z, n));}

//brute- force approach O(2^n)

//dynamic programming approach O(n^2)
int longestIncreasingSubsequence(int* arr, int n) {
    int * output = new int[n];
    output[0] = 1;
    for (int i = 1; i < n; i++) {
        output[i] = 1;
        for (int j = i - 1; j >= 0; j--) { //traverse from the (i-1)th element to 0th index
            if (arr[j] >= arr[i]) {
                continue;  //skip
            }
            int possibleAns = output[j] + 1;
            if (possibleAns > output[i]) {
                output[i] = possibleAns;
            }
        }
    }
    int best = 0;
    for (int i = 0; i < n; i++) {
        if (best < output[i]) {
            best = output[i];
        }
    }
    delete [] output;
    return best;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << longestIncreasingSubsequence(arr, n);
    return 0;
}
