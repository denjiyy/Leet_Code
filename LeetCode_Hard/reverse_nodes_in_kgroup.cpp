#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using std::string;
using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (head == nullptr || k == 1) return head;

            ListNode dummy(0);
            dummy.next = head;
            ListNode* prevGroupEnd = &dummy;

            while (true) {
                ListNode* groupStart = prevGroupEnd->next;
                ListNode* groupEnd = groupStart;

                for (int i = 0; i < k - 1; ++i) {
                    groupEnd = groupEnd->next;
                    if (groupEnd == nullptr) return dummy.next;
                }

                ListNode* nextGroupStart = groupEnd->next;
                groupEnd->next = nullptr;

                prevGroupEnd->next = reverse(groupStart);
                groupStart->next = nextGroupStart;

                prevGroupEnd = groupStart;
            }
        }
    private:
        ListNode* reverse(ListNode* head) {
            ListNode* prev = nullptr;
            ListNode* curr = head;

            while (curr) {
                ListNode* nextTemp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextTemp;
            }
            return prev;
        }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode* result = solution.reverseKGroup(head, k);

    while (result) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;

    return 0;
}
