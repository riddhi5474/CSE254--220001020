#include <bits/stdc++.h>
using namespace std;

double median_sorted(vector<int> a1, vector<int> a2)
{
    if (a1.size() > a2.size())
        swap(a1, a2);
    int n = a1.size(), m = a2.size();
    if (!n)
    {
        if (!(m % 2))
            return (a2[m / 2 - 1] + a2[m / 2]) / 2.0;
        return a2[m / 2] * 1.0;
    }

    int l = -1, r = n;
    while (l <= r)
    {
        int l1 = (l + r) / 2, r1 = l1 + 1;
        int l2 = (n + m + 1) / 2 - (l1 + 1) - 1, r2 = l2 + 1;

        int l1e, r1e, l2e, r2e;

        if (l1 > -1)
            l1e = a1[l1];
        else
            l1e = INT_MIN;

        if (r1 < n)
            r1e = a1[r1];
        else
            r1e = INT_MAX;

        if (l2 > -1)
            l2e = a2[l2];
        else
            l2e = INT_MIN;

        if (r2 < m)
            r2e = a2[r2];
        else
            r2e = INT_MAX;

        if (l1e > r2e)
            r = l1 - 1;
        else if (l2e > r1e)
            l = l1 + 1;
        else
        {
            if ((n + m) % 2)
                return max(l1e, l2e) * 1.0;
            else
                return (max(l1e, l2e) + min(r1e, r2e)) / 2.0;
        }
    }

    // int total = n + m;
    // int half = total / 2;
    // int l = 0;
    // int r = n - 1;
    // bool ok = true;
    // while (ok)
    // {

    //     int i = l + (r - l) / 2;
    //     int j = half - i - 2;

    //     int a1left, a1right, a2left, a2right;

    //     if (i >= 0)
    //     {
    //         a1left = a1[i];
    //     }
    //     else
    //     {
    //         a1left = INT_MIN;
    //     }

    //     if (i + 1 < n)
    //     {
    //         a1right = a1[i + 1];
    //     }
    //     else
    //     {
    //         a1right = INT_MAX;
    //     }

    //     if (j >= 0)
    //     {
    //         a2left = a2[j];
    //     }
    //     else
    //     {
    //         a2left = INT_MIN;
    //     }

    //     if (j + 1 < m)
    //     {
    //         a2right = a2[j + 1];
    //     }
    //     else
    //     {
    //         a2right = INT_MAX;
    //     }

    //     if (a1left <= a2right && a2left <= a1right)
    //     {
    //         if (total % 2)
    //         {
    //             return min(a1right, a2right);
    //         }
    //         else
    //         {
    //             return (max(a1left, a2left) + min(a1right, a2right)) / 2;
    //         }
    //     }
    //     else if (a1left > a2right)
    //     {
    //         r = i - 1;
    //     }else{
    //         l=i+1;
    //     }

    //     return 0.0;
    // }
    }

    int main()
    {
        // freopen("test_cases_Q2.txt","r",stdin);
        // freopen("output_Q2.txt","w",stdout);
        int t;
        cin >> t;
        while (t--)
        {
            int n, m;
            cin >> n >> m;
            vector<int> a(n), b(m);
            for (int i = 0; i < n; i++)
                cin >> a[i];
            for (int i = 0; i < m; i++)
                cin >> b[i];
            cout << "Median of the two sorted arrays: " << median_sorted(a, b) << endl;
        }
        return 0;
    }