// Custom Hashing using Splitmix64 

// FIXED_RANDOM is initialized using current time, making the hash function non-deterministic across runs.
// Constant (golden ratio of 64-bit numbers) ensures that numbers are well spread out.


//Hashing Function

uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

// CustomHash to be used in competitive programming to reduce chances of getting solution hacked

struct CustomHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//CustomHash function can be modified in the case of pair<int, int>
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return CustomHash()(p.first) ^ (CustomHash()(p.second) >> 1);
    }
};



