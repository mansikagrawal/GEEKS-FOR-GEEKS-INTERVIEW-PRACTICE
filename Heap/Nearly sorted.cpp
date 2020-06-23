/* Problem statement 
    Given an array of n elements,
    where each element is at most k away from its target position, 
    you need to sort the array optimally. */
#include <bits/stdc++.h>
using namespace std;

vector<int> nearlySorted(int arr[], int num, int k)
{
    // Your code here
    priority_queue<int, vector<int>, greater<int> > p(arr, arr + k);
    vector<int> v;
    while (k < num) {
        p.push(arr[k]);
        v.push_back(p.top());
        p.pop();

        k++;
    }
    while (p.empty() == false) {
        v.push_back(p.top());
        p.pop();
    }
    return v;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--) {
        int num, K;
        cin >> num >> K;

        int arr[num];
        for (int i = 0; i < num; ++i) {
            cin >> arr[i];
        }

        vector<int> res = nearlySorted(arr, num, K);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";

        cout << endl;
    }

    return 0;
}
