// Leetcode 21. Merge Two Sorted Lists
// Easy
//
// URL: https://leetcode.com/problems/merge-two-sorted-lists/
//
// Merge two sorted linked lists and return it as a new list. 
// The new list should be made by splicing together the nodes of the first two lists.
//
// Example:
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4
·
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class SolutionSortAll {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // TODO
    }
};

class SolutionRecur {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // TODO
    }
};

class SolutionIter {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // TODO
    }
};

int main() {
	return 0;
}
