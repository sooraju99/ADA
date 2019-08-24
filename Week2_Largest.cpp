#include <iostream>
#include <chrono> 
using namespace std;
using namespace std::chrono; 
void selection_sort (int A[ ], int n , int k) {
		cout<<"Selection sort:"<<endl<<endl;
        int maximum;    
		auto start = high_resolution_clock::now(); 
        for(int i = 0; i < n-1 ; i++)  {
             maximum = i ;
            for(int j = i+1; j < n ; j++ ) {
                if(A[ j ] > A[ maximum ])  {         
                maximum = j ;
                }
             }
		int temp = A[i];
		A[i]=A[maximum];
		A[maximum]=temp;
        }
		auto stop = high_resolution_clock::now();
		for(int i=0;i<n;i++)
		{
			cout<<A[i]<<",";
		}
		
		cout<<endl;
		cout<<"The largest elements upto k are: ";
		for(int i=0;i<k;i++)
		{
			
				cout<<A[i]<<",";
			
		
   }
   
    std::chrono::duration<double, std::milli> fp_ms = stop - start;
	
	cout<<endl<< "Time taken is "<<  fp_ms.count() <<" milliseconds"<<endl;
}

void bubble_sort (int A[ ], int n , int k) {
		cout<<endl<<"Bubble sort:"<<endl<<endl;
		int i;
		auto start = high_resolution_clock::now(); 
{
	for(int j=0;j<n-1-i;j++)
		{
			if(A[j+1]>A[j])
				{	int temp=A[j];
					A[j]=A[j+1];
					A[j+1]=temp;
				}
		}
}
		auto stop = high_resolution_clock::now();
		for(int i=0;i<n;i++)
		{
			cout<<A[i]<<",";
		}
		
		cout<<endl;
		cout<<"The largest elements upto k are: ";
		for(int i=0;i<k;i++)
		{
			
				cout<<A[i]<<",";
			
		
   }
   
    std::chrono::duration<double, std::milli> fp_ms = stop - start;
	
	cout<<endl<< "Time taken is "<<  fp_ms.count() <<" milliseconds"<<endl;
}
   
   
int main()

{		int n;
		cout<<"Enter the array size:"<<endl;
		cin>>n;
		int A[n];
		cout<<"Enter the array elements:"<<endl;
		for(int i = 0; i<n;i++)
		{
			cin>>A[i];
		}
	
		int k;
		cout<<"Enter the kth position you want"<<endl;
		cin>>k;
		selection_sort(A,n,k);
		bubble_sort(A,n,k);

}
