#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &arr, int target)
{
  int low = 0, high = arr.size() - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int guess = arr[mid];

    if (guess == target)
    {
      return mid;
    }
    else if (guess < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return -1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q, temp;
  cin >> n >> q;

  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  for (int i = 0; i < q; i++)
  {
    cin >> temp;

    if (binarySearch(arr, temp) != -1)
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }

  return 0;
}
