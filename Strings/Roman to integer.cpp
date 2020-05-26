// Initial template for C++

// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << romanToDecimal(s) << endl;
  }
}  // } Driver Code Ends

// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral
int value(char roman) {
  switch (roman) {
    case 'I':
      return 1;
    case 'X':
      return 10;
    case 'M':
      return 1000;
    case 'D':
      return 500;
    case 'V':
      return 5;
    case 'L':
      return 50;
    case 'C':
      return 100;
  }
}
int romanToDecimal(string &str) {
  // code here

  int p = 0, ans = 0;

  for (int i = str.length() - 1; i >= 0; i--) {
    if (value(str[i]) >= p)
      ans += value(str[i]);

    else
      ans -= value(str[i]);

    p = value(str[i]);
  }

  return ans;
}
