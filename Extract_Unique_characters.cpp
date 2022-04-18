/*
Extract Unique characters
Send Feedback
Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.
Input format:
The first and only line of input contains a string, that denotes the value of S.
Output format :
The first and only line of output contains the updated string, as described in the task.
Constraints :
0 <= Length of S <= 10^8
Time Limit: 1 sec
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// #include<string>
// string uniqueChar(string str) {
//     string st;
//     int index=0;
//     int len = str.length();
//     for(int i=0;i<len;i++){
//         int j=0;
//         for(j=0;j<i;j++){
//             if(str[i]==str[j]){
//                 break;
//             }
//             if(j==i){
//                 st[index++]=str[i];
//             }
//         }
//         return st;
//     }
//  // Write your code here
// }



string uniqueChar(string str) {
    unordered_map<char, int> hash ;
    string ans ;

    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (hash.count(str[i]))
            continue ;
        ans = ans + str[i];
        hash[str[i]]++ ;
    }

    return ans ;
}
//hash.count(str[i]) will check if hash table has a key with value str[i]
//and return true or false
//if it was already contained in the string then I continued :)
//else If it wasnt added to hashmaps yet, I will add it, then add it to my answer string

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
