#include <iostream>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to delete the middle node of the linked list
ListNode* deleteMiddle(ListNode* head) {
    if (!head || !head->next) {
        delete head;
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    // Using two-pointer technique to find the middle
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // 'slow' is pointing to the middle node, 'prev' is the node before 'slow'
    prev->next = slow->next;
    delete slow; // Free the memory of the middle node

    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Main function to test the solution
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(6);

    std::cout << "Original list: ";
    printList(head);

    head = deleteMiddle(head);

    std::cout << "After deleting middle node: ";
    printList(head);

    return 0;
}

