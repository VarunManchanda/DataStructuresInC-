#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

//Space:- O(2n) => O(n)
//Time:- O(n) + O(n) => O(n)
//sample test case : 6    5 4 2 1 3 6
void findBuildings(int arr[], int n)
{
    stack<pair<int,int>> s;
    vector<int> ans;
    for(int i=n-1; i>=0; i--) //O(n)
    {
        if(!s.empty())
        {
            cout << "|" << s.top().first << "," << s.top().second << "|" << endl;
            ans.push_back(s.top().second);
        }
        while(!s.empty() && arr[i] > s.top().first)
        {
            s.pop();
        }
        if(s.empty())
        {
            s.push(make_pair(arr[i],0)); //value,count
        }
        else if(arr[i] < s.top().first)
        {
            s.push(make_pair(arr[i],s.top().second+1));
        }
        else if(arr[i] == s.top().first)
        {
            s.push(make_pair(arr[i],s.top().second));
        }
    }
    cout << "|" << s.top().first << "," << s.top().second << "|" << endl;
    ans.push_back(s.top().second);
    reverse(ans.begin(),ans.end());
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    findBuildings(arr,n);
    return 0;
}
