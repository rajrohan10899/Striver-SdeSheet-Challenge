// https://www.codingninjas.com/codestudio/problems/pair-swap_759396

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node* pairsSwap(Node *head)
{
    //  Write your code here.
    if(head == NULL || head->next == NULL)
        {
            return head;
        }

        //A = head
        //B = head->next
        //C = head->next->next

        Node* temp = head->next;
        head->next = pairsSwap(head->next->next);
        temp->next = head;

        return temp;
}
