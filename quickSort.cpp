#include <iostream>
using namespace std;

int partition(int a[], int s, int e)
{
	int i = s-1; // i belongs to small region initially i --> -1
	int j = s; //initially j--> 0
	int pivot = a[e];
	for(;j<e;j++)
	{
		if(a[j]<=pivot) // if small element is found, then increase small region and swap that element
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[e]);
	return i+1;
}


void quickSort(int a[], int s, int e)
{
	if(s>=e)
	{
		return;
	}
	int p = partition(a,s,e);
	quickSort(a,s,p-1);
	quickSort(a,p+1,e);
}

int main() {
	int a[] = {2,1,5,6,7,5,8};
	int n = sizeof(a)/sizeof(int);
	quickSort(a,0,n-1);
	for(int i=0; i<n; i++)
	{
		cout << a[i] <<  " ";
	}
	return 0;
}
