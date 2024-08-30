#include <iostream>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two linked lists
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* prev = nullptr;
    ListNode* current = list1;
    int index = 0;

    // Find node before index 'a'
    while (index < a) {
        prev = current;
        current = current->next;
        index++;
    }

    // Disconnect list1 from the section to be removed
    prev->next = list2;

    // Move current pointer to node 'b'
    while (index <= b) {
        current = current->next;
        index++;
    }

    // Connect the end of list2 to the remaining list1
    ListNode* list2Tail = list2;
    while (list2Tail->next) {
        list2Tail = list2Tail->next;
    }
    list2Tail->next = current;

    return list1;
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
    ListNode* list1 = new ListNode(0);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(2);
    list1->next->next->next = new ListNode(3);
    list1->next->next->next->next = new ListNode(4);
    list1->next->next->next->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1000000);
    list2->next = new ListNode(1000001);
    list2->next->next = new ListNode(1000002);

    std::cout << "Original list1: ";
    printList(list1);

    std::cout << "Original list2: ";
    printList(list2);

    list1 = mergeInBetween(list1, 3, 4, list2);

    std::cout << "After merging: ";
    printList(list1);

    return 0;
}

