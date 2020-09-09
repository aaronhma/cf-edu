#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &arr, int target)
{
  int low = -1, high = arr.size();

  while (low + 1 < high)
  {
    int mid = low + (high - low) / 2;

    if (arr[mid] <= target)
    {
      low = mid;
    }
    else
    {
      high = mid;
    }
  }

  return high;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, temp;
  cin >> n >> k;

  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  for (int i = 0; i < k; i++)
  {
    cin >> temp;

    cout << binarySearch(arr, temp) << "\n";
  }

  return 0;
}
