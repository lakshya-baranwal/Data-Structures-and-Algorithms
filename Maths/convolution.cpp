// Convolution using FFT

using base = complex<long double>; // complex numbers for FFT

// Iterative FFT (Cooley-Tukey algorithm)
void fft(vector<base> &a, bool invert) {
    int n = a.size();

    // Bit-reversal permutation (reorders elements for in-place FFT)
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    // Length = current size of the "butterfly"
    for (int len = 2; len <= n; len <<= 1) {
        // Root of unity: exp(±2πi / len)
        long double ang = 2 * acosl(-1) / len * (invert ? -1 : 1);
        base wlen(cosl(ang), sinl(ang));

        for (int i = 0; i < n; i += len) {
            base w(1);
            for (int j = 0; j < len / 2; j++) {
                base u = a[i + j];              // even index value
                base v = a[i + j + len / 2] * w; // odd index value * root of unity
                a[i + j] = u + v;               // butterfly merge
                a[i + j + len / 2] = u - v;
                w *= wlen;                      // multiply by root of unity
            }
        }
    }

    // If inverse FFT, divide by n to normalize
    if (invert) for (base &x : a) x /= n;
}

// Convolution (polynomial multiplication)
vector<ll> convolution(const vector<ll> &a, const vector<ll> &b) {
    // Copy inputs into complex arrays
    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());

    // Find smallest power of 2 >= (n + m - 1)
    int n = 1;
    while (n < (int)a.size() + (int)b.size() - 1) n <<= 1;
    fa.resize(n); fb.resize(n);

    // Apply FFT to both
    fft(fa, false);
    fft(fb, false);

    // Point-wise multiplication in frequency domain
    for (int i = 0; i < n; i++) fa[i] *= fb[i];

    // Inverse FFT to get result back
    fft(fa, true);

    // Extract integer coefficients (rounded)
    vector<ll> res(n);
    for (int i = 0; i < n; i++) res[i] = llroundl(fa[i].real());

    // Trim to exact polynomial size
    res.resize(a.size() + b.size() - 1);
    return res;
}
