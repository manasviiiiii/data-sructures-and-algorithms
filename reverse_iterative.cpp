#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // Save the next node
        curr->next = prev;   // Reverse the current node's pointer
        prev = curr;         // Move prev to the current node
        curr = next;         // Move to the next node
    }

    return prev;  // prev will be the new head of the reversed list
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
    
    // Reverse the linked list
    head = reverseList(head);
    
    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);
    
    return 0;
}
