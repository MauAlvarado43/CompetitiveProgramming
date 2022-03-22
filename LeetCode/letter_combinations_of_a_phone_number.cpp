class Solution {
public:
    
    unordered_map<char, string> letters = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
    void buildCombination(vector<string>& combinations, string digits, string temp, int i) {
        
        if(i == digits.length()){
            combinations.push_back(temp);
            return;
        }
        
        for(int j = 0; j < letters[digits[i]].length(); j++) {
            
            temp.push_back(letters[digits[i]][j]);
            buildCombination(combinations, digits, temp, i + 1);
            temp.pop_back();
            
        }
            
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.length() == 0)
            return {};
        
        vector<string> combinations;
        buildCombination(combinations, digits, "", 0);
        return combinations;
        
    }
};