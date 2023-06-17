// https://www.codingninjas.com/codestudio/problems/630457?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include<bits/stdc++.h>
using namespace std;

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node* curr = firstHead;
    int a = 0, b = 0;

    while (curr != NULL)
    {
        a++;
        curr = curr->next;
    }
    curr = secondHead;
    while (curr != NULL)
    {
        b++;
        curr = curr->next;
    }

    // Find Difference:
    int diff = abs(a - b);
    if (a > b)
    {
        while (diff--)
        {
            firstHead = firstHead->next;
        }
    }
    else
    {
        while (diff--)
        {
            secondHead = secondHead->next;
        }
    }

    while (firstHead != NULL && secondHead != NULL)
    {
        if (firstHead == secondHead)
        {
            return firstHead;
        }
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }

    return NULL; 
}

//Leetcode Solu:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr = headA;
        int a=0, b=0;

        while(curr != NULL)
        {
            a++;
            curr = curr->next;
        }
        curr = headB;
        while(curr != NULL)
        {
            b++;
            curr =curr->next;
        }

        int diff = abs(a-b);
        if(a > b)
        {
            while(diff--)
            {
                headA = headA->next;
            }
        }
        else{
            while(diff--)
            {
                headB = headB->next;
            }
        }
        while(headA != NULL && headB != NULL )
        {
            if(headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
