class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int maxDuration = releaseTimes[0], n = releaseTimes.size();
        char key = keysPressed[0];
        
        for(int i=1; i<n; i++){
            if(releaseTimes[i]-releaseTimes[i-1] == maxDuration){
                maxDuration = releaseTimes[i]-releaseTimes[i-1];
                if(keysPressed[i] > key){
                    key = keysPressed[i];
                }
            }
            else if(releaseTimes[i]-releaseTimes[i-1] > maxDuration){
                maxDuration = releaseTimes[i]-releaseTimes[i-1];
                key = keysPressed[i];
            }
        }
        
        return key;
    }
};