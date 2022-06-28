class Solution {
public:
    int minDeletions(string s) {
        map<int, bool> mp;
        int arr[27] = {0};
        int count = 0;
        
        for(int i=0; i<s.size(); i++) {
            int key = s[i] - 'a';
            arr[key]++;
        }
        
        for(int i=0; i<27; i++) {
            int key = arr[i];
            if(key <= 0) continue;
            while(key > 0 && mp.find(key) != mp.end()){
                count++;
                key--;
            }
            mp[key] = true;
        }
        return count;
    }
};