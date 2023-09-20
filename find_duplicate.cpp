/*
Duplicate in array:

You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging from 0 to 3, and among these, there is a single integer value that is present twice. You need to find and return that duplicate number present in the array.
Note :
Duplicate number is always present in the given array/list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
For each test case, print the duplicate element in the array/list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^6

Time Limit: 1 sec
*/
#include <iostream>
using namespace std;
int findDuplicate(int *, int);
int findDuplicate(int *arr, int n)
{
	int i, sumarr = 0, sumn2 = 0;
	for (i = 0; i < n; i++)
	{
		sumarr = sumarr + arr[i];
	}
	for (i = 0; i <= (n - 2); i++)
	{
		sumn2 = sumn2 + i;
	}
	return (sumarr - sumn2);
}

/*
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]==arr[j]){			//another approach with O(n^2) time complexity
				return arr[i];
			}
		}
	}
	return 0;
		//Write your code here
}
*/

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}
