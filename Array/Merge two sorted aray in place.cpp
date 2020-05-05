#include <bits/stdc++.h>
using namespace std;

// AN INC ARRAY IS MIN HEAP
// AN DEC ARRAY IS MAX HEAP


void merge(int a[], int b[], int m, int n)
{

 // Make a min heap as min heap is an inc array
make_heap(b,b+n, greater<int>());
for(int i=0;i<m;i++)
{
    if(a[i] > b[0])
    {
        // removes the first element and push to last of heap
        pop_heap(b, b+n, greater<int>());
        // swap the element with b[n-1] and a[i]
        swap(a[i] ,  b[n-1]);

        // push a[i] to heap
        push_heap(b, b+n, greater<int>());
    }
}
   sort(b,b+n);

   for(int i=0;i<m;i++)
   cout<<a[i]<<" ";
   for(int i=0;i<n;i++)
   cout<<b[i]<<" ";


}

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int a[m], b[n];
        for(int i=0;i<m;i++)
        cin>>a[i];
        for(int i=0;i<n;i++)
        cin>>b[i];



        merge(a,b,m,n);
        cout<<endl;

    }
	//code
	return 0;
}
