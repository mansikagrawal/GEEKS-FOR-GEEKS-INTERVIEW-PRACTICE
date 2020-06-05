#include <bits/stdc++.h>
using namespace std;

void buildTree(int* a, int s, int e, int* tree, int index)
{
    /* Base case s == e */
    if (s == e) {

        tree[index] = a[s];
        return;
    }
    // Recursive case
    int mid = (s + e) / 2;
    // Build tree for left part
    buildTree(a, s, mid, tree, 2 * index);
    // Build right tree
    buildTree(a, mid + 1, e, tree, 2 * index + 1);

    // put element in node
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);

    return;
}

// ss- start of segment tree node
// se - end of segment tree node
int query(int* tree, int ss, int se, int qs, int qe, int index)
{
    // No overlap
    if (qe < ss or qs > se)
        return INT_MAX;

    // complete overlap
    if (ss >= qs and se <= qe) {

        return tree[index];
    }

    // partial overlap

    int mid = (ss + se) / 2;
    int left = query(tree, ss, mid, qs, qe, 2 * index);
    int right = query(tree, mid + 1, se, qs, qe, 2 * index + 1);
    return min(left, right);
}

void update(int* tree, int ss, int se, int i, int increment, int index)
{
    // case where I is out of bound
    if (i > se or i < ss) {

        return;
    }

    // leaf node
    if (ss == se) {

        tree[index] += index;
        return;
    }

    // otherwise
    int mid = (ss + se) / 2;
    update(tree, ss, mid, i, increment, 2 * index);
    update(tree, mid + 1, se, i, increment, 2 * index + 1);

    tree[index] = min(tree[2 * index] , tree[2 * index + 1]);
    return;
}

int main()
{
    int a[] = { 1, 3, 2, -5, 6, 4 };
    int n = sizeof(a) / sizeof(int);

    // construct tree array
    int* tree = new int[4 * n + 1];
    buildTree(a, 0, n - 1, tree, 1);

    //update node
    update(tree, 0, n - 1, 3, +10, 1);

    // read queries
    int q;
    cin >> q;
    while (q--) {

        int l, r;
        cin >> l >> r;
        cout << query(tree, 0, n - 1, l, r, 1) << " ";
    }

    return 0;
}
