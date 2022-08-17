class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> vec = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> ans;
        
        for(int i=0; i<words.size(); i++){
            string s = "";
            for(int j=0; j<words[i].size(); j++){
                s+=vec[words[i][j]-'a'];
            }
        ans.insert(s);
        }
    
        return ans.size();
    }
};