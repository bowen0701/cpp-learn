// Leetcode 23. Merge k Sorted Lists
// Hard
//
// URL: https://leetcode.com/problems/merge-k-sorted-lists/
//
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//
// Merge all the linked-lists into one sorted linked-list and return it
// 
// Example 1:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// 
// Example 2:
// Input: lists = []
// Output: []
//
// Example 3: 
// Input: lists = [[]]
// Output: []
// 
// Constraints:
// * k == lists.length
// * 0 <= k <= 10^4
// * 0 <= lists[i].length <= 500
// * -10^4 <= lists[i][j] <= 10^4
// * lists[i] is sorted in ascending order.
// * The sum of lists[i].length won't exceed 10^4.

#include <iostream>
#include <vector>
#include <algorithm>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Merge K sorted list by sorting all values.
// Time complexity: O((n1+...+nk)*log(n1+...+nk)), where ni is the length of listi.
// Space complexity: O((n1+..+nk)).
class SolutionSortAll {
public:
    static bool compare(const ListNode* l1, const ListNode* l2) {
        return (l1->val < l2->val);
    }

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // Edge case.
        if (lists.empty()) return nullptr;

        // Append lists's all nodes to vec and sort them.
        std::vector<ListNode*> vec;
        for (auto ls : lists) {
            while (ls) {
                vec.push_back(ls);
                ls = ls->next;
            }
        }
        std::sort(vec.begin(), vec.end(), compare);

        // Append null pointer as final node of linked list.
        vec.push_back(nullptr);

        // Use a dummy node to create a new list based on the sorted nodes.
        ListNode dummy;
        ListNode* current = &dummy;
        for (auto ls : vec) {
            current->next = ls;
            current = current->next;
        }
        return dummy.next;
    }
};

void show(ListNode* ls) {
    while (ls) {
        std::cout << ls->val;
        if (ls->next) std::cout << "->";
        ls = ls->next;
    }
}

int main() {
    // Example 1:
    // Input: lists = [[1,4,5],[1,3,4],[2,6]]
    // Output: [1,1,2,3,4,4,5,6]
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    std::vector<ListNode*> lists{l1, l2, l3};

    ListNode* ls = SolutionSortAll().mergeKLists(lists);
    show(ls); std::cout << std::endl;

    // Example 2:
    // Input: lists = []
    // Output: []
    lists = {};

    ls = SolutionSortAll().mergeKLists(lists);
    show(ls); std::cout << std::endl;

    // Example 3:   
    // Input: lists = [[]]
    // Output: []
    l1 = nullptr;
    
    lists = {l1};

    ls = SolutionSortAll().mergeKLists(lists);
    show(ls); std::cout << std::endl;

    return 0;
}
