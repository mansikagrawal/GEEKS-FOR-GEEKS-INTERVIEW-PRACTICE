#include <bits/stdc++.h>
using namespace std;

int main() {
  int no_of_transactions, friends;
  cin >> no_of_transactions >> friends;

  string x, y;
  int amount;
  map<string, int> net;
  while (no_of_transactions--) {
    cin >> x >> y >> amount;
    if (net.count(x) == 0) {
      net[x] = 0;
    }

    if (net.count(y) == 0) net[y] = 0;

    net[x] += amount;
    net[y] -= amount;
  }

  // iterate over persons
  // add those persons in multiset
  // who have non zero net

  multiset<pair<int , string>> m;

  for (auto p : net)

  {
    string person = p.first;
    int amount = p.second;

    if (net[person] != 0) {
      m.insert(make_pair(amount, person));
    }
  }

  // make settlements

  int cnt = 0;
  while (!m.empty()) {
    auto low = m.begin();
    auto high = prev(m.end());

    int debit = low->first;
    string debit_person = low->second;

    int credit = high->first;
    string credit_person = high->second;

    m.erase(low);
    m.erase(high);

    int settled_amt = min(-debit, credit);
    debit += settled_amt;
    credit -= settled_amt;
    cout << credit_person << " will pay " << settled_amt << " to "
         << debit_person << endl;

    if (debit != 0) {
      m.insert(make_pair(debit, debit_person));
    }
    if (credit != 0) {
      m.insert(make_pair(credit, credit_person));
    }
  }

  return 0;
}
