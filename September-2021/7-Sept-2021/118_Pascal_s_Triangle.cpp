class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        
        v.push_back({1});
        if(numRows==1)
            return v;
         v.push_back({1,1});
        if(numRows==2)
            return v;
            
        for(int i=2; i<numRows; i++){
            v.push_back({1});
            for(int j=1; j<=i; j++){
                if(j==i){
                    v[i].push_back(1);
                    continue;
                }
                v[i].push_back(v[i-1][j-1]+v[i-1][j]);
            }
        }
        
        return v;
    }
};