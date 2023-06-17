// https://www.codingninjas.com/codestudio/problems/1112628?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *l1, Node *l2)
{
    // Write your code here.
    Node* ans = new Node(0);
    Node* p = l1; 
    Node* q = l2;
    Node* curr = ans;

    int carry = 0;

    while(p != NULL || q != NULL)
    {
        int x = (p != NULL) ? p->data : 0;
        int y = (q != NULL) ? q->data : 0;

        int sum = carry+x+y;
        carry = sum/10;

        curr->next = new Node(sum%10);
        curr = curr->next;

        if(p!= NULL) p=p->next;
        if(q!= NULL)  q= q->next;
    }
    if(carry>0)
    {
        curr->next = new Node(carry);
    }
    return ans->next;
}
