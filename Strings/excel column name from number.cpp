// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
string ExcelColumn(int n);

// } Driver Code Ends

// User function template for C++

string ExcelColumn(int n) {
  string ans = "";
  while (n > 0) {
    // Find remainder
    int rem = n % 26;

    // If remainder is 0, then a 'Z' must be there in output
    if (rem == 0) {
      ans = 'Z' + ans;
      n = n / 26 - 1;
    }
    // If remainder is non-zero
    else {
      ans = char(n % 26 - 1 + 'A') + ans;
      n /= 26;
    }
  }
  return ans;
  // Your code goes here
}

// { Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << ExcelColumn(n) << endl;
  }
  return 0;
}
// } Driver Code Ends
