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
    
    ListNode* midll(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast -> next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dnode = new ListNode(-1);
        ListNode* temp = dnode;

        while(temp1 != nullptr && temp2 != nullptr) {
            if(temp1-> val < temp2->val) {
                temp->next = temp1;
                temp = temp1;
                temp1 = temp1->next;
            }
            else {
                temp->next = temp2;
                temp = temp2;
                temp2 = temp2->next;
            }
        }
        if(temp1) temp->next = temp1;
        else temp->next = temp2;
        return dnode->next;
    }

    ListNode* sortList(ListNode* head) {
        // TC = o(N log n) sc = O(n)
        // use no extra space

        // so weh have to apply sort algo in ll itself
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* middle = midll(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
        
    }
};