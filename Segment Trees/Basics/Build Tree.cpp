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

int main()
{
    int a[] = { 1, 3, 2, -5, 6, 4 };
    int n = sizeof(a) / sizeof(int);

    // construct tree array
    int* tree = new int[4 * n + 1];
    buildTree(a, 0, n - 1, tree, 1);

    // print tree array
    for (int i = 1; i <= 13; i++)
        cout << tree[i] << " ";
}
