// https://www.codingninjas.com/studio/problems/delete-middle-element

#include <bits/stdc++.h> 

void helper(stack<int>&inputStack, int count, int size) {

   //Base Case
   if(count == size/2) {
      inputStack.pop();
      return;
   }

   int num = inputStack.top();
   inputStack.pop();

   //Recursive Call
   helper(inputStack, count+1, size);
   inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count =0;

   helper(inputStack, count, N);
   
}
