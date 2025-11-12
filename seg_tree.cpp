#include <bits/stdc++.h>
// Source: https://csacademy.com/lesson/segment_trees
// Problem: https://cses.fi/problemset/task/1648/ (Dynamic Range Sum Queries)

using namespace std;

const int MAXN = 2e5 + 10;
int n, q;
int arr[MAXN];

// Segment tree parameters
typedef int T; // type of the elements of the tree (may be ll if needed)
T seg_tree[MAXN * 4];
const T NEUTRAL = INT_MAX; // neutral element for the operation (sum = 0, min = +inf, max = -inf)
T calculate(T a, T b)
{
    return a + b;
}

//"node" is the index in the array, while "left"
// and "right" are the ends of the current segment
void build(int node, int left, int right)
{
    if (left == right)
    {
        seg_tree[node] = arr[left]; // we are in a leaf node
    }
    else
    {
        int middle = (left + right) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;

        // build children
        build(left_node, left, middle);
        build(right_node, middle + 1, right);

        // update current node
        seg_tree[node] = calculate(seg_tree[left_node], seg_tree[right_node]);
    }
}

void update(int node, int left, int right, int index, int value)
{
    if (left == right)
    { // we are in the xth leaf
        seg_tree[node] = value;
    }
    else
    {
        int middle = (left + right) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;

        if (index <= middle)
        { // we need to update the left son
            update(left_node, left, middle, index, value);
        }
        else
        {
            update(right_node, middle + 1, right, index, value);
        }

        // after updating said son, recalculate the current segment
        seg_tree[node] = calculate(seg_tree[left_node], seg_tree[right_node]);
    }
}

void update(int index, int value)
{
    update(0, 0, n - 1, index, value);
}

T query(int node, int left, int right, int x, int y)
{
    if (x <= left && right <= y)
    {
        // the segment of "node" is completely included in the query
        return seg_tree[node];
    }
    else if (right < x || left > y)
    {
        // the segment of "node" is completely outside the query
        return NEUTRAL;
    }
    else
    {
        // We need to check both left and right sons
        int middle = (left + right) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;

        T answer_left = query(left_node, left, middle, x, y);
        T answer_right = query(right_node, middle + 1, right, x, y);

        return calculate(answer_left, answer_right);
    }
}

T query(int x, int y)
{
    return query(0, 0, n - 1, x, y);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(0, 0, n - 1);

    for (int i = 0; i < q; i++)
    {
        int op, x, y;
        cin >> op >> x >> y;

        if (op == 1)
        {
            // update
            x--;
            update(x, y);
        }
        else
        {
            // query
            x--;
            y--;
            cout << query(x, y) << endl;
        }
    }
}