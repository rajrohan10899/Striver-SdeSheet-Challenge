// https://www.codingninjas.com/codestudio/problems/799912?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

/*
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
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    Node* slow = head;
    Node* fast = head;

        while(K--) {
          fast = fast->next;
        }
        //edge case loop.
        if(fast == NULL) {
          return slow->next;
        }
        while(fast->next != NULL) {
          slow = slow->next;
          fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
}
