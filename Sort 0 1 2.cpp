//https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //Write your code
   int count0 = 0;
   int count1= 0;
   int count2 = 0;

   for(int i=0; i<n; i++) {
      if(arr[i] == 0) count0++;
      else if(arr[i] == 1) count1++;
      else count2++;
   }

   for(int i=0; i<count0; i++) arr[i] = 0;
   for(int i=count0; i<count0+count1; i++) arr[i] = 1;
   for(int i=count0+count1; i<n; i++) arr[i] = 2;
}

// Optimal Approach : Using Dutch National Flag Algorithm or (3Pointer Approach):

int low = 0, mid = 0, high = n-1, // these are 3 pointers. 

while(mid<=high) {
   if(arr[mid] == 0) {
      swap(arr[mid], arr[low]);
      low++;
      mid++;
   }
   else if(arr[mid] == 1) {
      mid++;
   }
   else {
      swap(arr[mid], arr[high]);
      high--;
   }
}
