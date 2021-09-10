class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0}, index = 0;
        
        for(char c: s)
            arr[c-'a']++;
        
        for(char c: s){
              if(arr[c-'a']==1)
                  return index;
            index++;
        }
        return -1;
    }
};