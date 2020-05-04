#include <iostream>
using namespace std;
void maxsumsubarray(int arr[], int n, int sum)
{
    //storing cursum as first element and start is initialised as 0
    int cursum=arr[0], start=0;
    for(int i=1;i<=n;i++)
    {
        // If currsum exceeds sum deduct the array element from the currsum
        while(cursum > sum and start < i-1)
        {
            cursum-=arr[start];
            start++;
        }

        // check if the currsum is equal to sum print the start as start+1 as start
        // was initialised to zero
        if(cursum==sum){
        cout<<start+1 << " "<< i;return;}

        // This situation comes when currsum<sum so adding the current
        // element to cursum
        if(i<n)
        cursum+=arr[i];



    }

    //  This stage comes when the sum is not available in the array
    cout<<-1;
    return;


}

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        int n, sum;
        cin >> n >> sum;
        int arr[n];
        for(int i = 0 ; i < n ; i++)
        {
            cin >> arr[i];
        }

        maxsumsubarray(arr, n , sum);
        cout<<endl;

    }

	return 0;
}
