#include<iostream>
using namespace std;

int arr[20]; 

int merge(int arr[],int l,int m,int h)
{
  int arr1[10],arr2[10],count=0;;  
  int n1,n2,i,j,k;
  n1=m-l+1;
  n2=h-m;

  for(i=0;i<n1;i++)
    arr1[i]=arr[l+i];
  for(j=0;j<n2;j++)
    arr2[j]=arr[m+j+1];

  arr1[i]=9999;  
  arr2[j]=9999;

  i=0;j=0;
  for(k=l;k<=h;k++)  
  {
	  count++;
    if(arr1[i]<=arr2[j])
      arr[k]=arr1[i++];
    else
      arr[k]=arr2[j++];
  }
  
  return 0;
}

int merge_sort(int arr[],int low,int high)
{
  int mid;
  if(low<high)
  {
    mid=(low+high)/2;

    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
  }
  
  
  return 0;
}      

int main()
{
  int n,i;
  
  cout<<"Enter the size of array: ";  
  cin>>n;
  cout<<"Enter the elements:\n";
  for(i=0;i<n;i++)
    cin>>arr[i];
  
  merge_sort(arr,0,n-1);  
  
  cout<<"Sorted array: "; 
  for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
  
  cout<<"\n";
  return 0;
}