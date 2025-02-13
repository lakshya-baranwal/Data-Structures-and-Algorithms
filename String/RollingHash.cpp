#define ll long long
const ll bs1=31, bs2=53, md1=1e9+7, md2=998244353;



class RollingHash {
public:
    RollingHash(const string &s, long long base, long long mod) : base(base), mod(mod) {
        n = s.size();
        hash_values.resize(n + 1, 0);
        power_base.resize(n + 1, 1);
        
        for (long long i = 0; i < n; ++i) {
            hash_values[i + 1] = (hash_values[i] * base + s[i]) % mod;
            power_base[i + 1] = (power_base[i] * base) % mod;
        }
    }
    
    long long getHash(long long l, long long r) {
        if (l > r) return 0;
        long long hash = (hash_values[r + 1] - hash_values[l] * power_base[r - l + 1]) % mod;
        if (hash < 0) hash += mod;
        return hash;
    }

    void addRight(char c) {
        current_hash = (current_hash * base + c) % mod;
    }
    
    void removeLeft(char c) {
        long long hash_size = power_base[window_length];
        current_hash = (current_hash + mod - c * hash_size % mod) % mod;
        current_hash = (current_hash * mod_inv_base) % mod;
    }
    
    void initWindow(long long length) {
        window_length = length;
        current_hash = 0;
        mod_inv_base = modInverse(base, mod);
    }
    
private:
    long long base;
    long long mod;
    long long n;
    vector<long long> hash_values;
    vector<long long> power_base;
    long long window_length;
    long long current_hash;
    long long mod_inv_base;

    long long modInverse(long long a, long long m) {
        long long m0 = m, t, q;
        long long x0 = 0, x1 = 1;
        if (m == 1) return 0;
        while (a > 1) {
            q = a / m;
            t = m;
            m = a % m, a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }
        if (x1 < 0) x1 += m0;
        return x1;
    }
};


