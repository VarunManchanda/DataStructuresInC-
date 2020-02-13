/*Question:- Element with left side smaller and right side greater
Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated array elements.

Output:
For each test case, in a new line print the required element. If no such element present in array then print -1.

Constraints:
1 <= T <= 100
3 <= N <= 106
1 <= A[i] <= 106

Example:
Input:
3
4
4 2 5 7
3
11 9 12
6
4 3 2 7 8 9

Output:
5
-1
7
Explanation:
Testcase 1 : Elements on left of 5 are smaller than 5 and on right of it are greater than 5.
*/
/*Solution Time:- O(n), Space:- O(2n) */
/*
Explanation:-
12
7 13 10 2 3 8 11 12 17 18 19 20
make 2 arrays left and right
left will have maximum element from front to back
and right will have minimum element from back to front


arr[]   =  7 13 10 2  3  8  11 12 17 18 19 20
left[]  =  7 13 13 13 13 13 13 13 17 18 19 20
right[] =  2 2  2  2  3  8  11 12 17 18 19 20

now start iterating from i=1 uptil n-1,
and check when left[i]==right[i], catch that element and break from loop!!

*/
#include <iostream>
#include <math.h>
using namespace std;
#define _fast_ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int pivotElement(int *arr, int n)
{
    int *minPrefixArray = new int[n]; //move from R->L
    int *maxPrefixArray = new int[n]; //move from L->R
    int pivot = -1;
    maxPrefixArray[0] = arr[0];
    for(int i=1; i<n; i++)
    {
        maxPrefixArray[i] = max(maxPrefixArray[i-1], arr[i]);
    }
    minPrefixArray[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--)
    {
        minPrefixArray[i] = min(minPrefixArray[i+1], arr[i]);
    }
    for(int i=1; i<n-1; i++)
    {
        if(minPrefixArray[i]==maxPrefixArray[i])
        {
            pivot = maxPrefixArray[i];
            break;
        }
       
    }

    delete[] minPrefixArray;
    delete[] maxPrefixArray;
    return pivot;
}

int main()
{
    _fast_;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];
        cout << pivotElement(arr,n) << endl;
        delete[] arr;
    }
    return 0;
}
