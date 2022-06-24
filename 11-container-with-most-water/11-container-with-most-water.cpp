class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1; 
        
        int max_amt = INT_MIN;
        while(i < j) {
            int amt = 0;
            if(height[i] < height[j]) {
                amt = (j-i) * height[i];
                i++;
            } else {
                amt = (j-i) * height[j];
                j--;
            }
            max_amt = max(amt, max_amt);
        }
        
        return max_amt;
    }
};