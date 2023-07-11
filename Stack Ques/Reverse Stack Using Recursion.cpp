// https://www.codingninjas.com/studio/problems/reverse-stack-using-recursion_631875?leftPanelTab=1

void InsertAtBottom(stack<int> &stack, int x) {
     if(stack.empty()) {

        stack.push(x);

        return;
    }

    int num = stack.top();
    stack.pop();

    //Recusrive Call
    InsertAtBottom(stack, x);
    
    stack.push(num);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    
    //Base Case 
    if(stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();

    //Recursive call
    reverseStack(stack);

    InsertAtBottom(stack, num);
}
