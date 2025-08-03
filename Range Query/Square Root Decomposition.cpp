// Square Root Decomposition Class usecase for minimum range query (it can modified for other types of queries as well)
class sqrtD{
private:
    vector<ll> nums;
    vector<ll> blocks;
    int n;
    int b; // Block Size

public:
    // Constructor function
    sqrtD(const vector<ll> &nums){
        this->nums = nums;
        n = nums.size();
        b = sqrt(n)+1;

        blocks.resize(b, LLONG_MAX);

        // Pre-processing for RMQ (range minimum query) in O(n)

        for(int i = 0; i < n; i++){
            blocks[i/b] = min(nums[i], blocks[i/b]);
        }
    }
    
    // Query in O(sqrt(n))
    ll query(int l, int r){
        
        ll mini = LLONG_MAX;

        while(l <= r){
            if(l%b==0 && l+b-1<=r){
                mini = min(blocks[l/b], mini);
                l += b;
            }
            else{
                mini = min(nums[l], mini);
                ++l;
            }
        }

        return mini;
    }
    
    // Point update in O(sqrt(n))
    // Set index (idx) to val
    void update(int idx, ll val){

        nums[idx] = val;

        int block = idx/b;
        blocks[block] = LLONG_MAX;

        int start = block * b;
        int end = min(n, start + b);

        for(int i = start; i < end; i++){
            blocks[block] = min(nums[i], blocks[block]);
        }
       
    }

};
