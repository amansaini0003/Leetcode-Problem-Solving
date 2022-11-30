class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurances;
        unordered_map<int, bool> isOccured ;
        
        for(int i=0; i<arr.size(); i++) {
            occurances[arr[i]]++;
        }
         
        for(auto it: occurances) {
            if(isOccured.find(it.second) == isOccured.end()) {
                isOccured[it.second] = true;
            } else {
                return false;
            }
        }
       
        return true;
    }
};