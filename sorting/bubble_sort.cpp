#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int32_t main()
{
  int t = 1;
  cin >> t;
  while (t--)
  {
    auto bubble_sort = [&](vector<int> &v) -> void
    {
      int n = v.size();
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n - i - 1; j++)
        {
          if (v[j] > v[j + 1])
            swap(v[j], v[j + 1]);
        }
      }
    };
  }
}