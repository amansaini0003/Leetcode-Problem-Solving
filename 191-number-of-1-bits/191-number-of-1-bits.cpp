class Solution {
public:
    int hammingWeight(uint32_t n) {
        int wt = 0;
        while(n) {
            wt += n & 1;
            n = n >> 1;
        }
        return wt;
    }
};