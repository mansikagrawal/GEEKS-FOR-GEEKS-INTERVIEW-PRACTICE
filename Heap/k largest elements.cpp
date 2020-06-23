#include<bits/stdc++.h>
using namespace std;

vector<int> kLargest(int arr[], int n, int k)
{
    // code here
    vector<int> v;
    priority_queue<int> pq(arr, arr+n);
    while(k>0)
    {
      k--;
      v.push_back(pq.top());
      pq.pop();
    }
    return v;
}


vector<int> kLargest(int arr[], int n, int k);

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];

        vector<int> result = kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;

    }
    return 0;
}
