// Problem Link : https://leetcode.com/problems/find-center-of-star-graph/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0];
        int b = edges[0][1];
        int c = edges[1][0];
        int d = edges[1][1];
        
        if(a==c || a==d)
            return a;
        if(b==c || b==d)
            return b;
        
        return -1;
    }
};