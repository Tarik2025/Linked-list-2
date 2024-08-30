#include <iostream>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to remove nodes with specific value
ListNode* removeElements(ListNode* head, int val) {
    while (head && head->val == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    ListNode* current = head;
    while (current && current->next) {
        if (current->next->val == val) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }

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
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    std::cout << "Original list: ";
    printList(head);

    head = removeElements(head, 6);

    std::cout << "After removing elements with value 6: ";
    printList(head);

    return 0;
}

