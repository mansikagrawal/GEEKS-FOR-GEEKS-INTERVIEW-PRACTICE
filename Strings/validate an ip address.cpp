#include <bits/stdc++.h>
using namespace std;
int isValid(char *);
int main() {
  // your code goes here
  int t;
  cin >> t;
  while (t--) {
    char s[10000];
    cin >> s;
    cout << isValid(s) << endl;
  }
  return 0;
}  // } Driver Code Ends

/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
int isValid(char *s) {
  // your code here

  int i = 0, count = 0;
  string x;
  while (s[i] != '\0') {
    if (s[i] != '.') {
      x += s[i];
    }
    if (s[i] == '.' || s[i + 1] == '\0') {
      int l = x.size();
      if (l == 1) {
        if (x[0] < '0' || x[0] > '9') {
          return 0;
        }
      } else if (l == 2) {
        if (x < "10" || x > "99") {
          return 0;
        }
      } else if (l == 3) {
        if (x < "100" || x > "255") {
          return 0;
        }
      } else if (l <= 0 || l > 3) {
        return 0;
      }

      x = "";
    }
    if (s[i] == '.') count++;
    i++;
  }

  if (count == 3) return 1;
  return 0;
}
