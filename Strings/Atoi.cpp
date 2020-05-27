#include <bits/stdc++.h>
using namespace std;

int atoi(string str);
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << atoi(s) << endl;
  }
}  // } Driver Code Ends

/*You are required to complete this method */
int atoi(string str) {
  // Your code here

  int res = 0;
  int i = 0;
  int sign;
  if (str[0] == '-') {
    sign = -1;
    i++;
  }
  // Iterate through all characters of input string and
  // update result
  for (; str[i] != '\0'; ++i) {
    char ch = str[i];
    if (ch >= 'a' and ch <= 'z')
      return -1;
    else
      res = res * 10 + str[i] - '0';
  }
  // return result.
  if (sign == -1)
    res = res * sign;

  return res;
}
