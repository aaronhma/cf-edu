#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  s += "$";
  int n = s.size();

  vector<pair<char, int>> a(n);
  vector<int> indexes(n), weights(n);

  for (int i = 0; i < n; i++)
    a[i] = {s[i], i};

  sort(a.begin(), a.end());

  for (int i = 0; i < n; i++)
    indexes[i] = a[i].second;

  weights[indexes[0]] = 0;

  // assign the weights
  for (int i = 1; i < n; i++)
  {
    // if the current character is the same as the previous,
    if (a[i].first == a[i - 1].first)
    {
      // add the weight of the current character in place indexes[i]
      weights[indexes[i]] = weights[indexes[i - 1]];
    }
    else
    {
      // move to next weight index in place indexes[i]
      weights[indexes[i]] = weights[indexes[i - 1]] + 1;
    }
  }

  int k = 0;

  while ((1 << k) < n)
  {
    // k -> k + 1
    vector<pair<pair<int, int>, int>> arr(n);

    for (int i = 0; i < n; i++)
    {
      arr[i] = {{weights[i], weights[(i + (1 << k)) % n]}, i};
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
      indexes[i] = arr[i].second;

    // update weights
    for (int i = 1; i < n; i++)
    {
      // if the current character is the same as the previous,
      if (arr[i].first == arr[i - 1].first)
      {
        // add the weight of the current character in place indexes[i]
        weights[indexes[i]] = weights[indexes[i - 1]];
      }
      else
      {
        // move to next weight index in place indexes[i]
        weights[indexes[i]] = weights[indexes[i - 1]] + 1;
      }
    }

    k++;
  }

  for (int i : indexes)
  {
    cout << i << " ";
  }

  cout << "\n";

  return 0;
}
