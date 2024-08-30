#include <iostream>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to detect the cycle and find its length
int findCycleLength(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Detecting cycle using two-pointer technique
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // Cycle detected
            int cycleLength = 0;
            do {
                fast = fast->next;
                cycleLength++;
            } while (slow != fast);

            return cycleLength;
        }
    }

    return 0; // No cycle
}

// Main function to test the solution
int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Creating a cycle

    int cycleLength = findCycleLength(head);

    if (cycleLength) {
        std::cout << "Cycle detected with length: " << cycleLength << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    return 0;
}

