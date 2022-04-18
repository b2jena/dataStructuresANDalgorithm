#include <iostream>
using namespace std;
int findUnique(int *, int);
/*
XOR a number with itself odd number of times the result is number itself.
XOR a number even number of times with itself, the result is 0.
Also XOR with 0 is always the number itself.

XOR is a binary operation, it stands for "exclusive or", that is to say the resulting bit evaluates to one if only exactly one of the bits is set.

This is its function table:

a | b | a ^ b
--|---|------
0 | 0 | 0
0 | 1 | 1
1 | 0 | 1
1 | 1 | 0

*/

int findUnique(int *arr, int n) {
    // Do XOR of all elements and return
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        res = res ^ arr[i];
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}
