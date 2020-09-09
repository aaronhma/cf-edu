#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  while (k--)
  {
    int temp;
    cin >> temp;

    int low = 0, high = n;

    while (low < high)
    {
      int mid = low + (high - low) / 2;

      if (arr[mid] >= temp)
      {
        high = mid;
      }
      else
      {
        low = mid + 1;
      }
    }

    if (arr[low] < temp)
    {
      cout << n + 1 << "\n";
    }
    else
    {
      cout << low + 1 << "\n";
    }
  }

  return 0;
}
