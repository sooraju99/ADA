#include<iostream>
#include<string.h>
using namespace std;

void LCS(char *X,char *Y,int m,int n)
{
	int L[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
				L[i][j]=0;
			else if(X[i-1]==Y[j-1])
				L[i][j]=L[i-1][j-1]+1;
			else
				L[i][j]=max(L[i][j-1],L[i-1][j]);
		}
	}
	int index =L[m][n];
	char lcs[index+1];
	lcs[index]='\0';
	int i=m,j=n;
	while(i>0 && j>0)
	{
		if(X[i-1]==Y[j-1])
		{
			lcs[index-1]=X[i-1];
			i--;
			j--;
			index--;
		}
		else if (L[i-1][j] > L[i][j-1]) 
			i--; 
		else
			j--;
	}
	cout<<"LCS of "<<X<<" and "<<Y<<" : "<<lcs<<endl;;
}

int main()
{
	char X[20],Y[20];
	cout<<"Enter the first sequence :";
	cin.getline(X,20);
	cout<<"Enter the second sequence :";
	cin.getline(Y,20);
	int m=strlen(X);
	int n=strlen(Y);
	LCS(X,Y,m,n);
	return 0;
}