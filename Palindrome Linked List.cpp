// https://www.codingninjas.com/codestudio/problems/799352?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head == NULL || head->next == NULL)
        {
            return true;
        }
        //Store thr data in vector.
        vector<int> data;
        LinkedListNode<int> *curr = head;

        while(curr != NULL)
        {
            data.push_back(curr->data);
            curr = curr->next;
        }
        //Check the vector is it is palindrome or not.
        int left = 0;
        int right = data.size()-1;

        while (left < right) {
        if (data[left] != data[right])
            return false;
            left++;
            right--;
        }
        return true;
}
