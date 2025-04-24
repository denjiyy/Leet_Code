#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummy = new ListNode(0);
            ListNode* current = dummy;
            int carry = 0;

            while (l1 != nullptr || l2 != nullptr || carry != 0) {
                int sum = carry;
                if (l1 != nullptr) {
                    sum += l1->val;
                    l1 = l1->next;
                }
                if (l2 != nullptr) {
                    sum += l2->val;
                    l2 = l2->next;
                }
                carry = sum / 10;
                current->next = new ListNode(sum % 10);
                current = current->next;
            }

            return dummy->next;
        }
};

int main() {
    Solution solution;
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* result = solution.addTwoNumbers(l1, l2);
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;
    return 0;
}
