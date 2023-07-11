https://www.codingninjas.com/studio/problems/sort-a-stack_985275?leftPanelTab=1 

// 1. USING RECURSION.

#include <bits/stdc++.h> 

void SortedStack(stack<int> &stack, int num) {
	if(stack.empty() || stack.top() < num) {
		stack.push(num);
		return;
	}

	int n = stack.top();
	stack.pop();

	//Recursive call
	SortedStack(stack, num);

	stack.push(n);
}


void sortStack(stack<int> &stack)
{
	// Write your code here
	if(!stack.empty()) {
		int num = stack.top();
		stack.pop();

		sortStack(stack);

		SortedStack(stack, num);
	}
}
