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
    ListNode* kthNode(ListNode* temp,int k){
        ListNode* kNode=temp;
        k--;
        while(k && kNode!=nullptr){
            kNode=kNode->next;
            k--;
        }
        return kNode;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* prev =nullptr;
        ListNode* temp=head;
        while(temp!=nullptr){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevLast=nullptr;
        while(temp!=nullptr){
            ListNode* kNode=kthNode(temp,k);
            if(kNode==nullptr){
                if(prevLast){
                    prevLast->next=temp;
                }
                break;
            }
            ListNode* nextNode=kNode->next;
            kNode->next=nullptr;
            reverseLL(temp);
            if(temp==head){
                head=kNode;
            }else{
                prevLast->next=kNode;
            }
            prevLast=temp;
            temp=nextNode;

        }
        return head;
    }
};