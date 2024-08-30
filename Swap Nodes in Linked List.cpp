#include <iostream>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to swap the values of kth node from beginning and kth node from end
ListNode* swapNodes(ListNode* head, int k) {
    ListNode* first = head;
    ListNode* second = head;
    ListNode* fast = head;

    // Move 'fast' to the kth node
    for (int i = 1; i < k; ++i) {
        fast = fast->next;
    }

    // Store the pointer to the kth node from the beginning
    first = fast;

    // Move 'fast' to the end to find the kth node from the end
    while (fast->next) {
        fast = fast->next;
        second = second->next;
    }

    // Swap the values
    std::swap(first->val, second->val);

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
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    head = swapNodes(head, 2);

    std::cout << "After swapping: ";
    printList(head);

    return 0;
}

