// ?Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

#include <iostream>
using namespace std;
#include <stack>
#include <vector>

vector<int> nextSmaller(int *arr, int size)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(size);
    for (int i = size - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmaller(int *arr, int size)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(size);
    for (int i = 0; i < size; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(int *heights, int n)
{
    vector<int> next(n);
    next = nextSmaller(heights, n);

    vector<int> prev(n);
    prev = prevSmaller(heights, n);
    int area = 0;

    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
            next[i] = n;
        int b = next[i] - prev[i] - 1;

        int newArea = l * b;

        area = max(area, newArea);
    }

    return area;
}

int maxArea(int M[][4], int n, int m)
{
    // Step 1 : Calculate area for 1st row
    int area = largestRectangleArea(M[0], m);

    // Step 2 : For all other rows, add element of previous rows and find area
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] != 0)
            {
                M[i][j] = M[i][j] + M[i - 1][j];
            }
            else
            {
                M[i][j] = 0;
            }
        }
        // int ar = largestRectangleArea(M[i], m);
        area = max(area, largestRectangleArea(M[i], m));
    }
    return area;
}

int main()
{
    int M[4][4] = {{0, 1, 1, 0},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {1, 1, 0, 0}};

    int ans = maxArea(M, 4, 4);

    cout << ans;

    return 0;
}