#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n, s, r;
vl num_ks;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> s >> r;
  num_ks = vl(n, 1);
  for (auto i = 0; i < s; ++i) {
    ll x;
    cin >> x;
    num_ks[x - 1] -= 1;
  }
  for (auto i = 0; i < r; ++i) {
    ll x;
    cin >> x;
    num_ks[x - 1] += 1;
  }

  ll ans = 0;
  for (auto i = 0; i < n; ++i) {
    if (num_ks[i] != 0) continue;

    auto p = i - 1;
    if (p >= 0) {
      if (num_ks[p] >= 2) {
        num_ks[p] -= 1;
        continue;
      }
    }

    auto q = i + 1;
    if (q < n) {
      if (num_ks[q] >= 2) {
        num_ks[q] -= 1;
        continue;
      }
    }

    ++ans;
  }

  cout << ans;

  return 0;
}