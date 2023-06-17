// https://www.codingninjas.com/codestudio/problems/reverse-the-singly-linked-list_799897?topList=striver-sde-sheet-problems

#include <bits/stdc++.h>
using namespace std;

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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    
     LinkedListNode<int> *prev = NULL;
     LinkedListNode<int> *curr = head;
     LinkedListNode<int>*next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
