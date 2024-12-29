#include <iostream>
#include <stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* temp = head;
    if (head == NULL || head->next == NULL) {
        return head;
    }

    stack<int> st;
    while (temp != NULL) {
        st.push(temp->val);
        temp = temp->next;  // Move temp to the next node
    }

    temp = head;
    while (!st.empty() && temp != NULL) {
        temp->val = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
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
