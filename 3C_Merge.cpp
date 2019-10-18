#include<iostream>
using namespace std;
int mcount=0;
int scount=0;
int bcount=0;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  

    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { mcount++;
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
		
    } 

    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
		
    } 
  

    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
		
    } 
} 
  

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 

        int m = l+(r-l)/2;
		mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 
  
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)     
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1]){  
            swap(&arr[j], &arr[j+1]);
			::bcount++;
		}
}  
  
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
 
    for (i = 0; i < n-1; i++)  
    {  
 
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  {
		min_idx = j;  scount++;}
        swap(&arr[min_idx], &arr[i]);  
    }  
}  
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<<A[i]<<" ";

	
} 

int main() 
{ 
	int n;
    cout<<"Enter number of elements: ";
	cin>>n;
	int arr1[n],arr2[n],arr3[n];
	
	cout<<"Enter elements of array 1: "<<endl;
	for(int i=0;i<n;i++)
		cin>>arr1[i];
	
	cout<<"Enter elements of array 2: "<<endl;
	for(int i=0;i<n;i++)
		cin>>arr2[i];
	
	cout<<"Enter elements of array 3: "<<endl;
	for(int i=0;i<n;i++)
		cin>>arr3[i];
	
	
  
    mergeSort(arr1, 0, n - 1); 
    bubbleSort(arr2,n);
	selectionSort(arr3,n);

	cout<<"\nNumber of comparisons in merge sort: "<<mcount<<endl;
	cout<<"\nNumber of comparisons in bubble sort: "<<bcount<<endl;
	cout<<"\nNumber of comparisons in selection sort: "<<scount<<endl;
    return 0; 
} 
