class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> seen;
        deque<char> dq;
        
        for(auto c: s) {
            dq.push_back(c);
            if(dq.size() == k) {
                seen.insert({dq.begin(), dq.end()});
                dq.pop_front();
            }
        }
        
        return seen.size() == 1<<k;
    }
};