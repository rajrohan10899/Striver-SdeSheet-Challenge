// https://www.codingninjas.com/codestudio/problems/1089580?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h>

vector<long long int> generateRow(int row) {
    long long int ans = 1;
    vector<long long int> ansRow;
    ansRow.push_back(1); // inserting the 1st element

    // calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>> ans;

    // store the entire Pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}

// leetcode solu :
class Solution {
public:
    vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
    vector<vector<int>> generate(int numRows) {
         vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= numRows; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
    }
};
