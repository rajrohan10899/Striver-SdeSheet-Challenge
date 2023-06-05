// https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405?topList=top-array-coding-interview-questions

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mini  = prices[0];
    int maxProfit = 0;
    for(int  i = 1; i<prices.size(); i++) {
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}
