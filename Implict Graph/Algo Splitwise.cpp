#include <bits/stdc++.h>
using namespace std;

int main() {
  int no_of_transactions, friends;
  cin >> no_of_transactions >> friends;

  // Make an array to store the net amount that each person will have to take at
  // the end

  int x, y, amount;
  int net[100000] = {0};

  while (no_of_transactions--) {
    cin >> x >> y >> amount;
    net[x] -= amount;
    net[y] += amount;
  }

  multiset<int> m;

  for (int i = 0; i < friends; i++) {
    if (net[i] != 0) m.insert(net[i]);
  }

  // pop out two persons from left and right and settle them
  int cnt = 0;
  while (!m.empty()) {
    auto low = m.begin();
    auto high = prev(m.end());
    // cancel lowest with the highest

    int debit = *(low);
    int credit = *(high);
    // ERase

    m.erase(low);
    m.erase(high);
    int settleamt = min(-debit, credit);
    cnt += 1;
    // settlement amt transferrred from donor to acceptor

    debit += settleamt;
    credit -= settleamt;

    if (debit != 0) m.insert(debit);

    if (credit != 0) m.insert(credit);
  }

  cout << cnt;

  return 0;
}
