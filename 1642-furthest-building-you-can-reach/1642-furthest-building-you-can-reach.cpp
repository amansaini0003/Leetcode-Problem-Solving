class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int> >  pq;
        
        int n = heights.size();
        
        for(int i=0; i<n-1; i++) {
            int steps = heights[i] - heights[i+1];
            if(steps >= 0)
                continue;
            
            pq.push(abs(steps));
            
            if(pq.size() > ladders){
                bricks -= pq.top();
                pq.pop();
            } 
            if(bricks < 0)
                return i;
        }
        
        return n-1;
    }
};