template <typename T>
void zeta_supersetsum(vector<T> &f) {
    int n = f.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int b = 0; b < n; ++b) {
            if (!(i & b)) {
                f[b] += f[b | i];
            }
        }
    }
}

template <typename T>
void zeta_subsetsum(vector<T> &f) {
    int n = f.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int b = 0; b < n; ++b) {
            if (!(i & b)) {
                f[b | i] += f[b];
            }
        }
    }
}

template <typename T>
void mobius_subset(vector<T> &f) {
    int n = f.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int b = 0; b < n; ++b) {
            if (!(i & b)) {
                f[b] -= f[b | i];
            }
        }
    }
}

template <typename T>
void mobius_superset(vector<T> &f) {
    int n = f.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int b = 0; b < n; ++b) {
            if (!(i & b)) {
                f[b | i] -= f[b];
            }
        }
    }
}
