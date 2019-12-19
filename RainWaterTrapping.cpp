#include<iostream>
#include<vector>
using namespace std;

/*

first calculate maximum in left and maximum of left,
and then apply min(left[i],right[i]) - currentHeight[i].
Now add the resultant values!

*/



int trap(vector<int> &height)
{
    if(height.size()==0)
        {
            return 0;
        }
        vector<int> left;
        vector<int> right;
        int m1 = 0;
        int finalm1 = 0;
        int prev = INT_MIN;
        int result = 0;
        left.push_back(height[0]);
        for(int i=1; i<height.size(); i++)
        {
            for(int j=0; j<i; j++)
            {
                m1 = max(height[j],height[i]);
                if(prev < m1)
                {
                    finalm1 = m1;
                    prev = m1;
                }
            }
            left.push_back(finalm1);
        }
        finalm1 = m1 = prev = 0;
        right.push_back(height[height.size()-1]);
        for(int i = height.size()-2; i>=0; i--)
        {
            for(int j = height.size()-1; j>i; j--)
            {
                m1 = max(height[j],height[i]);
                if(prev < m1)
                {
                    finalm1 = m1;
                    prev = m1;
                }
            }
            right.push_back(finalm1);
        }
        reverse(right.begin(),right.end());
        for(int i = 0; i<left.size(); i++)
        {
            result += min(left[i],right[i]) - height[i];
        }
        
        return result;
}







int main()
{
    int n;
    cin >> n;
    vector<int> height;
    for(int i=0; i<n; i++)
    {
        int val;
        cin >> val;
        height.push_back(val);
    }
    cout << trap(height) << endl;
    return 0;
}