// #include <bits/stdc++.h>

// using namespace std;

// #define FOR(i, n) for (int i = 1; i <= n; i++)
// #define F0R(i, n) for (int i = 0; i < n; i++)

// int main()
// {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);

//   int n, k, l, r, res1, res2;
//   cin >> n;

//   vector<int> arr(100005);

//   FOR(i, n)
//   {
//     cin >> arr[i];
//   }

//   sort(arr.begin(), arr.end());

//   cin >> k;

//   while (k--)
//   {
//     cin >> l >> r;

//     int low = 1, high = n;

//     while (low < high)
//     {
//       int mid = (low + high) / 2;

//       if (arr[mid] >= l)
//         high = mid;
//       else
//         low = mid + 1;
//     }

//     res1 = low;

//     if (arr[low] < l)
//     {
//       cout << "0 ";
//       continue;
//     }

//     low = 1, high = n;

//     while (low < high)
//     {
//       int mid = (low + high + 1) / 2;

//       if (arr[mid] <= r)
//         low = mid;
//       else
//         high = mid - 1;
//     }

//     res2 = low;

//     if (arr[low] > r)
//     {
//       cout << "0 ";
//       continue;
//     }

//     if (res2 < res1)
//     {
//       cout << "0 ";
//       continue;
//     }

//     cout << (res2 - res1 + 1) << " ";
//   }

//   cout.flush();

//   cout << "\n";

//   return 0;
// }
#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, l, r, res1;
  cin >> n;

  vector<int> arr(n + 1);

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  cin >> k;

  while (k--)
  {
    cin >> l >> r;

    int low = 1, high = n;

    while (low < high)
    {
      int mid = low + (high - low) / 2;

      if (arr[mid] >= l)
      {
        high = mid;
      }
      else
      {
        low = mid + 1;
      }
    }

    res1 = low;

    if (arr[low] < l)
    {
      cout << "0 ";
      continue;
    }

    low = 1, high = n;

    while (low < high)
    {
      int mid = (low + high + 1) / 2;

      if (arr[mid] <= r)
      {
        low = mid;
      }
      else
      {
        high = mid - 1;
      }
    }

    if (arr[low] > r || low < res1)
    {
      cout << "0 ";
      continue;
    }

    cout << (low - res1 + 1) << " ";
  }

  cout << "\n";

  return 0;
}
