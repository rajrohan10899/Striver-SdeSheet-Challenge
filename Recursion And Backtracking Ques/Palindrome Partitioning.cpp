// https://www.codingninjas.com/studio/problems/799931?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h> 
using namespace std;

bool ispalindrome(string s, int start, int end) {
    while(start <= end) {
        if(s[start] != s[end]) {
            return false;
        }
        start++; 
        end--;
    }
    return true;
}
void func(int idx, string s, vector<string> &path, vector<vector<string>> &ans) {
    //Base case :
    if(idx == s.size()) {
        ans.push_back(path);
        return;
    }

    for(int i = idx; i < s.size(); i++) {
        if(ispalindrome(s, idx , i)) {
            path.push_back(s.substr(idx, i - idx+1));

            func(i+1, s, path, ans);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> path;
    func(0, s, path, ans);
    return ans;
}

//LEETCODE SOLUTION :
class Solution {
public:
    bool ispalindrome(string s, int start, int end) {
    while(start <= end) {
        if(s[start] != s[end]) {
            return false;
        }
        start++; 
        end--;
    }
    return true;
}
void func(int idx, string s, vector<string> &path, vector<vector<string>> &ans) {
    //Base case :
    if(idx == s.size()) {
        ans.push_back(path);
        return;
    }

    for(int i = idx; i <= s.size(); i++) {
        if(ispalindrome(s, idx , i)) {
            path.push_back(s.substr(idx, i - idx+1));

            func(i+1, s, path, ans);
            path.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;
    func(0, s, path, ans);
    return ans;
    }
};
