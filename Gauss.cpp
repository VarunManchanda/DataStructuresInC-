//used for finding missing element from given unique numbers
#include <bits/stdc++.h>
using namespace std;

void solve(int *arr, int n)
{
    int sum = 0;
    for(int i=0; i<n-1; i++) sum += arr[i];
    int ans = (n*(n+1))/2 - sum;
    cout << ans << endl;
    return;
}

int main() {
    int n; cin >> n;
    int *arr = new int[n-1];
    for(int i=0; i<n-1; i++) cin >> arr[i];
    solve(arr,n);
    return 0;
}
