// https://www.codingninjas.com/codestudio/problems/majority-element-ii_893027?topList=top-array-coding-interview-questions

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    vector<int> ls;
    map<int, int> mpp;
    int n = arr.size();
    int mini = (int)(n/3)+1;

    for(int i = 0; i<n; i++) {
        mpp[arr[i]]++;
        if(mpp[arr[i]] == mini) {
            ls.push_back(arr[i]);
        }
        if(ls.size() ==  2) break;
    }
    sort(ls.begin(), ls.end());
    return ls;


}