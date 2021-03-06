//Problem link : https://leetcode.com/problems/longest-substring-without-repeating-characters/

//SOLUTION 1

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();    
        unordered_map<char, int> mp;
        
        int i = 0, j = 0, maxi = 0;
        while(j < len){ 
            if(mp[s[j]] > 0){
                while(i < j && mp[s[j]] != 0){
                    mp[s[i]]--;
                    i++;
                }
            }
            mp[s[j]] = 1;
            maxi = max(maxi, j - i + 1);
            j++;
        }
        
        return maxi;
    }
};




//SOLUTION 2

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();    
        unordered_map<char, int> mp;
        
        int i = 0, j = 0, maxi = 0;
        while(j < len){ 
            if(mp.find(s[j]) != mp.end() && mp[s[j]] >= i){
                i = mp[s[j]] + 1;
            }
            mp[s[j]] = j;
            maxi = max(maxi, j - i + 1);
            j++;
        }
        
        return maxi;
    }
};
