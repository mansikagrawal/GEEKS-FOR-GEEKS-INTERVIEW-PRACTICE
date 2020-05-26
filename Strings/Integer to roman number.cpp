#include <bits/stdc++.h>
using namespace std;

void convertToRoman(int);

int main() {
  // your code goes here
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;

    convertToRoman(N);
    cout << endl;
  }
  return 0;
}  // } Driver Code Ends

/*you are required to complete
this function*/

// n :given number that you are require to convert
void convertToRoman(int num) {
  // Your code here
  string m[] = {"", "M", "MM", "MMM"};
  string c[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
  string x[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
  string i[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

  // Converting to roman
  string thousands = m[num / 1000];
  string hundereds = c[(num % 1000) / 100];
  string tens = x[(num % 100) / 10];
  string ones = i[num % 10];

  string ans = thousands + hundereds + tens + ones;

  cout << ans;
}
