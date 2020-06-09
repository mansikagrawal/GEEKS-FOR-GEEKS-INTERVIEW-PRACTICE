#include <bits/stdc++.h>
using namespace std;
vector<int> SortBinaryArray(vector<int> binArray);

// binArray is an array that consists only 0s and 1s
// return sorted binary array
vector<int> SortBinaryArray(vector<int> v)
{
    int i, zero, ones;
    for (i = 0; i < v.size(); i++) {
        if (v[i] == 0)
            zero++;
        else
            ones++;
    }
    resizing is done to avoid sigbart error
        v.resize(i);
    int k = 0;
    while (zero--)
        v[k++] = 0;

    while (ones--)
        v[k++] = 1;

    return v;
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> binArray(n);

        for (int i = 0; i < n; i++)
            cin >> binArray[i];

        vector<int> result = SortBinaryArray(binArray);
        for (int i = 0; i < n; i++)
            cout << result[i] << " ";

        cout << endl;
    }
    return 0;
}
