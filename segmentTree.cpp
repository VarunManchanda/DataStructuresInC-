#include <iostream>
using namespace std;
int st[400001], arr[100001];


void build(int si, int ss, int se)
{
	if(ss==se)
	{
		st[si] = arr[ss];
		return;
	}

	int mid = (ss+se)/2;

	build(2*si,ss,mid); 
	build(2*si+1,mid+1,se);

	st[si] = min(st[2*si],st[2*si+1]);
}

int query(int si, int ss, int se, int qs, int qe)
{
	//no overlap
	if(qe<ss || qs>se)
	{
		return INT_MAX;
	}
	//overlap
	if(ss>=qs && se<=qe)
	{
		return st[si];
	}
	//partial overlap
	int mid = (ss+se)/2;
	return min(query(2*si,ss,mid,qs,qe),query(2*si+1,mid+1,se,qs,qe));
}

void pointUpdate(int si, int ss, int se, int qi)
{
	if(ss==se)
	{
		st[si] = arr[qi];
		return;
	}
	int mid = (ss+se)/2;
	if(qi <= mid) pointUpdate(2*si,ss,mid,qi);
	else pointUpdate(2*si+1,mid+1,se,qi);
	st[si] = min(st[2*si],st[2*si+1]);
}


int main()
{
	int n; cin >> n;
	for(int i=1; i<=n; i++) cin >> arr[i];
	int si = 1, ss = 1, se = n;
	build(si,ss,se);
	int q; cin >> q;
	while(q--)
	{
		int type; cin >> type;
		if(type==1)
		{
			int l,r; cin >> l >> r;//as indexing start from 0 so query from [l+1,r+1]
			cout << query(si,ss,se,l+1,r+1) << endl;
		}
		else if(type==2)
		{
			int index; cin >> index;
			cin >> arr[index];
			pointUpdate(si,ss,se,index+1);
		}
		

	}
	return 0;
}