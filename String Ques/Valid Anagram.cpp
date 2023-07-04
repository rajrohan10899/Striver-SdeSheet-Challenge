// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;
        
        // Count the frequency of characters in string s
        for (auto it : s) {
            count[it]++;
        }
        
        // Decrement the frequency of characters in string t
        for (auto it : t) {
            count[it]--;
        }
        
        // Check if any character has non-zero frequency
        for (auto it : count) {
            if (it.second != 0) {
                return false;
            }
        }
        
        return true;
    }
};