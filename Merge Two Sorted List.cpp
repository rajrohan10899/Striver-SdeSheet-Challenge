// https://leetcode.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head = new ListNode(0);
        ListNode* curr = head;

        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val <= list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr= curr->next;
        }
        //Exhaustion case for any of the list.
        if(list1 != NULL) curr->next = list1;

        else{
            curr->next = list2;
        }
        return head->next;
    }
};

// https://www.codingninjas.com/codestudio/problems/800332?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* head = new Node<int>(0);
    Node<int>* curr = head;

    while(first != NULL && second != NULL)
    {
        if(first->data <= second->data)
        {
            curr->next = first;
            first = first->next;
        }
        else {
            curr->next = second;
            second = second->next;
        }
        curr = curr->next;
    }
    if(first != NULL) curr->next = first;
    
    else{
        curr->next = second;
    }
    return head->next;
}

