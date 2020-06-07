#include <bits/stdc++.h>
using namespace std;

int lazy[1000] = { 0 };

void updateRangeQuery(int* tree, int ss, int se, int l, int r,
    int inc, int index)
{
    // before going down resolve the value if it exists

    if (lazy[index] != 0) {

        tree[index] += lazy[index];
        // non leaf node
        if (ss != se) {

            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }

    // base case
    if (ss > r or l > se) {
        return;
    }

    //another case - complete overlap
    if (ss >= l and se <= r) {
        tree[index] += inc;

        // create a new lazy value for children node
        if (ss != se) {

            lazy[2 * index] += inc;
            lazy[2 * index + 1] += inc;
        }

        return;
    }

    // recursive case
    int mid = (ss + se) / 2;
    updateRangeQuery(tree, ss, mid, l, r, inc, 2 * index);
    updateRangeQuery(tree, mid + 1, se, l, r, inc, 2 * index + 1);
    // update tree[index]
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

int querylazy(int* tree, int ss, int se, int qs, int qe, int index)
{

    // resolve lazy value at current node
    if (lazy[index] != 0) {

        tree[index] += lazy[index];
        // non leaf node
        if (ss != se) {

            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }

    // no overlap
    if (ss > qe or se < qs) {

        return INT_MAX;
    }
    // complete overlap
    if (ss >= qs and se <= qe) {

        return tree[index];
    }

    // partial overlap
    int mid = (ss + se) / 2;

    int left = querylazy(tree, ss, mid, qs, qe, 2 * index);
    int right = querylazy(tree, mid + 1, se, qs, qe, 2 * index + 1);

    return min(left, right);
}

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

int main()
{
    int a[] = { 1, 3, 2, -5, 6, 4 };
    int n = sizeof(a) / sizeof(int);

    // construct tree array
    int* tree = new int[4 * n + 1];
    buildTree(a, 0, n - 1, tree, 1);

    updateRangeQuery(tree, 0, n - 1, 0, 2, 10, 1);
    updateRangeQuery(tree, 0, n - 1, 0, 4, 10, 1);
    cout << "Q1 1-1 " << querylazy(tree, 0, n - 1, 1, 1, 1) << endl;
    updateRangeQuery(tree, 0, n - 1, 3, 4, 10, 1);
    cout << "Q1 3-5 " << querylazy(tree, 0, n - 1, 3, 5, 1);

    return 0;
}
