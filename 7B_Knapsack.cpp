#include<iostream>
using namespace std;

int max(int a,int b)
{
	return (a>b)?a:b;
}

int knapSack(int W,int w[],int v[],int n)
{
	int i,wt,k[n+1][W+1];
	for(i=0;i<=n;i++)
	{
		for(wt=0;wt<=W;wt++)
		{
			if(i==0 || wt==0)
				k[i][wt]=0;
			else if (w[i-1]<=wt)
				k[i][wt]=max(v[i-1]+k[i-1][wt-w[i-1]],  k[i-1][wt]);
			else
				k[i][wt]=k[i-1][wt];
		}
	}
	return k[n][W];
}

int main()
{
	int W,n,max;
	cout<<"Enter the no. of items :";
	cin>>n;
	int w[n],v[n];
	cout<<"Enter the weights and values of the items : "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Item "<<i<<": ";
		cin>>w[i];
		cin>>v[i];
	}
	cout<<"Enter the capacity :";
	cin>>W;
	max=knapSack(W,w,v,n);
	cout<<"Solution :"<<max<<endl;
	return 0;
}