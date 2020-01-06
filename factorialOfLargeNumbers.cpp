#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void findFact(int n)
{
    int ones = 0, carry = 0, mul = 0;
    vector<int> v(1);
    v[0] = 1;
    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<v.size(); j++)
        {
            mul = (v[j] * i ) + carry;
            ones = mul%10; 
            carry = mul/10;
            v[j] = ones;
            if(carry!=0)
            {
                v.push_back(0);
            }
        }
    }
    reverse(v.begin(),v.end());
    int i = 0;
    for(; i<v.size(); i++)
    {
       if(v[i]==0)
       {
           continue;
       }
       else
       {
           break;
       }
    }
    for(;i<v.size();i++)
    {
        cout << v[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    findFact(n);
    return 0;
}
