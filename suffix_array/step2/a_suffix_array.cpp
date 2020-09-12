#include <bits/stdc++.h>

using namespace std;

void counting_sort(vector<int> &indexes, vector<int> &weights)
{
  int n = weights.size();

  // the new indexes
  vector<int> new_indexes(n);
  vector<int> pos(n), count(n); // positions and counts

  // get the elements range for counting sort
  for (int i : weights)
  {
    count[i]++;
  }

  // calculate the index of the first element of each new index
  for (int i = 1; i < n; i++)
  {
    pos[i] = pos[i - 1] + count[i - 1];
  }

  for (int i : indexes)
  {
    // key of the element is the class of the left half of the string
    int x = weights[i];

    // put element i into position pos[x] of the new indexes
    new_indexes[pos[x]] = i;

    // increase position
    pos[x]++;
  }

  indexes = new_indexes;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  s += "$";

  int n = s.size(), k = 0;
  vector<pair<char, int>> arr(n);
  vector<int> indexes(n), weights(n);

  for (int i = 0; i < n; i++)
  {
    arr[i] = {s[i], i};
  }

  sort(arr.begin(), arr.end());

  for (int i = 0; i < n; i++)
  {
    indexes[i] = arr[i].second;
  }

  for (int i = 1; i < n; i++)
  {
    if (arr[i].first != arr[i - 1].first)
    {
      weights[indexes[i]] = weights[indexes[i - 1]] + 1;
    }
    else
    {
      weights[indexes[i]] = weights[indexes[i - 1]];
    }
  }

  while ((1 << k) <= n)
  {
    // get sorted strings of length 2^k
    for (int i = 0; i < n; i++)
    {
      indexes[i] = (indexes[i] - (1 << k) + n) % n;
    }

    // sort the pairs by first element
    counting_sort(indexes, weights);

    // create new weights
    vector<int> new_weights(n);

    for (int i = 1; i < n; i++)
    {
      // previous weights
      pair<int, int> prev = {weights[indexes[i - 1]], weights[(indexes[i - 1] + (1 << k)) % n]};

      // current weights
      pair<int, int> now = {weights[indexes[i]], weights[(indexes[i] + (1 << k)) % n]};

      if (now != prev)
      {
        new_weights[indexes[i]] = new_weights[indexes[i - 1]] + 1;
      }
      else
      {
        new_weights[indexes[i]] = new_weights[indexes[i - 1]];
      }
    }

    // update weights
    weights = new_weights;

    k++;
  }

  for (int i : indexes)
  {
    cout << i << " ";
  }

  cout << "\n";

  return 0;
}
