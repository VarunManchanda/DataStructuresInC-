#include <iostream>
using namespace std;
void bruteForcePN(int n)
{
    if(n==1)
    {
        cout << "No, it's not a Prime" << endl;
        return;
    }
    for(int i=2; i<=n-1; i++)
    {
        if(n%i==0)
        {
            cout << "No, it's not a Prime" << endl;
            return;
        }
    }
    cout << "Yes, it's a Prime" << endl;
    return;
}
void bruteForcePNby2(int n)
{
    if(n==1)
    {
        cout << "No, it's not a Prime" << endl;
        return;
    }
    for(int i=2; i<=n/2; i++)
    {
        if(n%i==0)
        {
            cout << "No, it's not a Prime" << endl;
            return;
        }
    }
    cout << "Yes, it's a Prime" << endl;
    return;
}
void rootNMethod(int n)
{
    if(n==1)
    {
        cout << "No, it's not a Prime" << endl;
        return;
    }
    for(int i=2; i*i<=n; i++) //for 1, 2, 3, 4, 6, 9, 12, 18, 36; check upto 6 only if any number divides 36 then it's not a prime
    {
        if(n%i==0)
        {
            cout << "No, it's not a Prime" << endl;
            return;
        }
    }
    cout << "Yes, it's a Prime" << endl;
    return;
}
void Primesieve(long long int *sieve)
{
    //Time:- O(nloglog) ~ O(n) so compute first
    //mark all odds as prime
    for(long long int i=3; i<= 1000000; i+=2)
    {
        sieve[i] = 1;
    }
    //now apply sieve logic
    for(long long int i=3; i<= 1000000; i+=2)
    {
        //if marked now mark its multiple
        if(sieve[i]==1)
        {
            //as for 5 next multiple will 25 because less than are already marked by number less then 5
            for(long long int j= i*i; j<= 1000000; j=j+i)
            {
                sieve[j] = 0;
            }
        }
    }
    //special case
    sieve[2] = 1;
    sieve[1] = sieve[0] = 0;

}
int main() {
    int n;
    cin >> n;
    bruteForcePN(n); //runs by O(n)
    bruteForcePNby2(n); //runs by O(n/2)
    rootNMethod(n); //runs by O(n^1/2)
    long long int *sieve = new long long int[1000005]{0}; //runs by O(nloglogn) ~ O(n)
    Primesieve(sieve);
    for(int i=1; i<=100; i++)
    {
        if(sieve[i]==1)
        {
            cout << i << " ";
        }
    }
    
    return 0;
}
