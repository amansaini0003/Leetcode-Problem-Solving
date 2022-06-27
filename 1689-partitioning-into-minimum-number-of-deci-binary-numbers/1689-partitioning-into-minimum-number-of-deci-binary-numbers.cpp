class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = -1;
        
        for(auto c: n) {
            int digit = c - '0';
            maxDigit = max(digit, maxDigit);
        }
        return maxDigit;
    }
};  