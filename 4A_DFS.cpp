#include<iostream>
#include <chrono> 
using namespace std;
using namespace std::chrono;
int G[10][10],visited[10],n;//n is no of vertices and graph is sorted in array G[10][10]
void DFS(int i)
{
int j;
//cout<<i<<endl;
visited[i]=1;
for(j=0;j<n;j++)
if(!visited[j] && G[i][j]==1)
{cout<<i<<"-->"<<j<<endl;
DFS(j);
}
}

int main()
{
int i,j;
cout<<"Enter number of vertices:"<<endl;
cin>>n;
cout<<"\nEnter adjecency matrix of the graph:"<<endl;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
cin>>G[i][j];
for(i=0;i<n;i++)
visited[i]=0;
 auto start = high_resolution_clock::now(); 
DFS(0);
  auto stop = high_resolution_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = stop - start;
	
	cout<<endl<< " \n Time taken is "<<  fp_ms.count() <<" milliseconds"<<endl;
    return 0; 
}