/*
Code : Edit Distance
Send Feedback
Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note
Strings don't contain spaces
Input Format :
The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.
Output Format :
The first and only line of output contains the edit distance value between the given strings.
Constraints :
1<= m,n <= 10
Time Limit: 1 second
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/
#include <cstring>
#include <iostream>
using namespace std;

// Utility function to find minimum of three numbers
int min(int x, int y, int z) { return min(min(x, y), z); }

int helper(string str1, string str2, int m, int n){
    if(m==0)
        return n;
    if(n==0)
        return m;
    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if (str1[m - 1] == str2[n - 1])
        return helper(str1, str2, m - 1, n - 1);
    // If last characters are not same, consider all three
    // operations on last character of first string,
    // recursively compute minimum cost for all three
    // operations and take minimum of three values.
    return 1 + min(helper(str1, str2, m, n - 1) /* Insert*/, helper(str1, str2, m - 1, n) /* Remove*/, helper(str1, str2, m - 1, n - 1) /*Replace*/ );
}
int editDistance(string s1, string s2) {
    int l1=s1.length();
    int l2=s2.length();
	int out=helper(s1,s2,l1,l2);
    return out;
	// Write your code here
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}
