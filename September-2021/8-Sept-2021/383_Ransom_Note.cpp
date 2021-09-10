class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size())
            return false;
        
        int charsInMagzine[26] = {0};
        
        for(char c : magazine)
            charsInMagzine[c-'a']++;
        
        for(char c : ransomNote)
            charsInMagzine[c-'a']--;
        
        for(int i: charsInMagzine){
            if(i<0)
                return false;
        }
        
        return true;
            
    }
};