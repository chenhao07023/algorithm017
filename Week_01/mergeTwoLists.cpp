#include <stdio.h>
#include <assert.h>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dump = new ListNode(-1);
        ListNode* dumphead = dump;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val){
            	dump->next = l1;
            	l1 = l1->next;
            }
            else {
            	dump->next = l2;
            	l2 = l2->next;
            }
            dump = dump->next;
        }

        dump->next = l1 ? l1 : l2;
        ListNode* res = dumphead->next;
        delete dumphead;
        return res;
    }
};

int main(int argc, char const *argv[]) {

	ListNode* l1 = new ListNode(1);
	ListNode* l1_1 = new ListNode(2);
	l1->next = l1_1;
	ListNode* l1_2 = new ListNode(4);
	l1_1->next = l1_2;

	ListNode* l2 = new ListNode(1);
	ListNode* l2_1 = new ListNode(3);
	l2->next = l2_1;
	ListNode* l2_2 = new ListNode(4);
	l2_1->next = l2_2;

	Solution s;
	ListNode* l3 = s.mergeTwoLists(l1,l2);
	assert(l3->val == 1);
	assert(l3->next->val == 1);
	assert(l3->next->next->val == 2);
	assert(l3->next->next->next->val == 3);
	assert(l3->next->next->next->next->val == 4);
	assert(l3->next->next->next->next->next->val == 4);


	return 0;
}