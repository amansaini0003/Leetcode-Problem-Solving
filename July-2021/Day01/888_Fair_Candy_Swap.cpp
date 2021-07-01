//  Problem Link : https://leetcode.com/problems/fair-candy-swap/

class Solution {
public:
//     x = alice give to bob 
//     y = bob give to alice
    
//     sumA - x + y == sumB - y + x
    
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        map<int, int> mp;
        vector<int> ans;
        int sumAlice = 0, sumBob = 0;
        
        for(int i=0; i<aliceSizes.size(); i++)
            sumAlice += aliceSizes[i];
        
        for(int i=0; i<bobSizes.size(); i++){
            sumBob += bobSizes[i];
            mp[bobSizes[i]]++;
        }
        
         for(int i=0; i<aliceSizes.size(); i++){
                int x = aliceSizes[i];
                int y = ( (sumBob - sumAlice)/2 ) + x;
             
                if(mp[y] > 0){
                    ans.push_back(x);
                    ans.push_back(y);
                    break;
                }
         }
        
        return ans;
    }
};