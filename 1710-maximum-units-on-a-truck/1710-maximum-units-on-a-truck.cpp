// method 2 - using count sort

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int count[1001] = {0};
        int res = 0;
        
        for(vector<int> &box : boxTypes){
            count[box[1]] += box[0];
        }
        
        for(int units = 1000; units > 0; units--){
            if(count[units] > 0) {
                int fitIn = min(count[units], truckSize);
                res += fitIn * units;
                truckSize -= fitIn;
                if(truckSize == 0)
                    return res;
            }
        }
        return res;
    }
};