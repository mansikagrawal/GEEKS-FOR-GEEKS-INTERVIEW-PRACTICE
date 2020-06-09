//Initial template for C++

#include <bits/stdc++.h>
using namespace std;
int NumberofElementsInIntersection(int a[], int b[], int n, int m);

// Given two arrays A and B and their sizes N and M respectively
int NumberofElementsInIntersection(int a[], int b[], int n, int m)
{
    // Your code goes here
    unordered_set<int> s1;
    int count = 0;

    // Insert the elements of a[] to set s1
    for (int i = 0; i < n; i++)
        s1.insert(a[i]);

    for (int i = 0; i < m; i++) {
        // if element at b[i] already exists in set
        if (s1.find(b[i]) != s1.end()) {

            // erase element so that is can not be compared again
            s1.erase(b[i]);

            // increase count by 1
            count++;
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];

        cout << NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
