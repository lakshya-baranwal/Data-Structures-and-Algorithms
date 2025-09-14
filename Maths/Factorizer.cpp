namespace factorizer{

template <typename T>
static inline T mul_mod(T a, T b, T mod) {
  return (T)((__int128)a * b % mod);
}

template <typename T>
T mod_pow(T a, T d, T mod) {
    T res = 1;
    while (d > 0) {
        if (d & 1) res = (__uint128_t)res * a % mod;
        a = (__uint128_t)a * a % mod;
        d >>= 1;
    }
    return res;
}

template <typename T>
bool IsPrime(T n, const vector<T>& bases) {
    if (n < 2) {
        return false;
    }
    vector<T> small_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for (const T& x : small_primes) {
        if (n % x == 0) {
            return n == x;
        }
    }
    if (n < 31 * 31) {
        return true;
    }

    int s = 0;
    T d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (const T& a : bases) {
        if (a % n == 0) {
            continue;
        }
        T cur = mod_pow<T>(a, d, n);
        if (cur == 1) {
            continue;
        }
        bool witness = true;
        for (int r = 0; r < s; r++) {
            if (cur == n - 1) {
                witness = false;
                break;
            }
            cur = (__uint128_t)cur * cur % n;
        }
        if (witness) {
            return false;
        }
    }
    return true;
}

bool IsPrime(int64_t n) {
    return IsPrime<int64_t>(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

bool IsPrime(int32_t n) {
    return IsPrime<int32_t>(n, {2, 7, 61});
}

vector<int> least = {0, 1};
vector<int> primes;
int precalculated = 1;
 
void RunLinearSieve(int n) {
  n = max(n, 1);
  least.assign(n + 1, 0);
  primes.clear();
  for (int i = 2; i <= n; i++) {
    if (least[i] == 0) {
      least[i] = i;
      primes.push_back(i);
    }
    for (int x : primes) {
      if (x > least[i] || i * x > n) {
        break;
      }
      least[i * x] = x;
    }
  }
  precalculated = n;
}
 
void RunSlowSieve(int n) {
  n = max(n, 1);
  least.assign(n + 1, 0);
  for (int i = 2; i * i <= n; i++) {
    if (least[i] == 0) {
      for (int j = i * i; j <= n; j += i) {
        if (least[j] == 0) {
          least[j] = i;
        }
      }
    }
  }
  primes.clear();
  for (int i = 2; i <= n; i++) {
    if (least[i] == 0) {
      least[i] = i;
      primes.push_back(i);
    }
  }
  precalculated = n;
}
 
void RunSieve(int n) {
  RunLinearSieve(n);
}

template <typename T>
vector<pair<T, int>> MergeFactors(const vector<pair<T, int>>& a, const vector<pair<T, int>>& b) {
  vector<pair<T, int>> c;
  int i = 0;
  int j = 0;
  while (i < (int) a.size() || j < (int) b.size()) {
    if (i < (int) a.size() && j < (int) b.size() && a[i].first == b[j].first) {
      c.emplace_back(a[i].first, a[i].second + b[j].second);
      ++i;
      ++j;
      continue;
    }
    if (j == (int) b.size() || (i < (int) a.size() && a[i].first < b[j].first)) {
      c.push_back(a[i++]);
    } else {
      c.push_back(b[j++]);
    }
  }
  return c;
}

template <typename T>
vector<pair<T, int>> RhoC(const T& n, const T& c) {
  if (n <= 1) {
    return {};
  }
  if ((n & 1) == 0) {
    return MergeFactors({{2, 1}}, RhoC(n / 2, c));
  }
  if (IsPrime(n)) {
    return {{n, 1}};
  }

  T x = 2;
  T saved = 2;
  T power = 1;
  T lam = 1;
  while (true) {
    x = (mul_mod(x, x, n)+c)%n;
    T diff = (x >= saved) ? (x - saved) : (saved - x);
    T g = __gcd(diff, n);

    if (g != 1) {
      return MergeFactors(RhoC(g, c + 1), RhoC(n / g, c + 1));
    }
    if (power == lam) {
      saved = x;
      power <<= 1;
      lam = 0;
    }
    lam++;
  }
  return {};
}
 
template <typename T>
vector<pair<T, int>> Rho(const T& n) {
  return RhoC(n, (T)1);
}

template <typename T>
vector<pair<T, int>> Factorize(T x) {
  if (x <= 1) {
    return {};
  }
  if (x <= precalculated) {
    vector<pair<T, int>> ret;
    while (x > 1) {
      if (!ret.empty() && ret.back().first == least[x]) {
        ret.back().second++;
      } else {
        ret.emplace_back(least[x], 1);
      }
      x /= least[x];
    }
    return ret;
  }
  if (x <= static_cast<int64_t>(precalculated) * precalculated) {
    vector<pair<T, int>> ret;
    if (!IsPrime(x)) {
      for (T i : primes) {
        T t = x / i;
        if (i > t) {
          break;
        }
        if (x == t * i) {
          int cnt = 0;
          while (x % i == 0) {
            x /= i;
            cnt++;
          }
          ret.emplace_back(i, cnt);
          if (IsPrime(x)) {
            break;
          }
        }
      }
    }
    if (x > 1) {
      ret.emplace_back(x, 1);
    }
    return ret;
  }
  return Rho(x);
}
 
template <typename T>
vector<T> BuildDivisorsFromFactors(const vector<pair<T, int>>& factors) {
  vector<T> divisors = {1};
  for (auto& p : factors) {
    int sz = (int) divisors.size();
    for (int i = 0; i < sz; i++) {
      T cur = divisors[i];
      for (int j = 0; j < p.second; j++) {
        cur *= p.first;
        divisors.push_back(cur);
      }
    }
  }
  sort(divisors.begin(), divisors.end());
  return divisors;
}

} // namespace factorizer 
using namespace factorizer;
