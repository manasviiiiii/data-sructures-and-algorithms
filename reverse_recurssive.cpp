#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to reverse the linked list using recursion
ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Recursively reverse the rest of the list
    ListNode* new_head = reverseList(head->next);

    // Reverse the current node's link
    head->next->next = head;
    head->next = NULL;

    return new_head;  // The new head of the reversed list
}

// Helper function to create a linked list
ListNode* createLinkedList() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create a hardcoded linked list
    ListNode* head = createLinkedList();
    
    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);
    
    // Reverse the linked list using recursion
    head = reverseList(head);
    
    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);
    
    return 0;
}
