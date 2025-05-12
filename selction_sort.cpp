#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int32_t main()
{
  int t = 1;
  cin >> t;
  while (t--)
  {
    auto selection_sort = [&](vector<int> &v) -> void
    {
      int n = v.size();
      for (int i = 0; i < n-1;i++){
        int mini = i;
        for (int j = i + 1; j < n;j++){
          if(v[j]<v[mini]){
            mini = j;
          }
        }
        swap(v[mini], v[i]);
      }
    };
  }
}