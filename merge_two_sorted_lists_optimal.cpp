#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    ListNode* h1 = list1;
    ListNode* h2 = list2;

    while (h1 != NULL && h2 != NULL) {
        if (h1->val <= h2->val) {
            temp->next = h1;
            h1 = h1->next;
        } else {
            temp->next = h2;
            h2 = h2->next;
        }
        temp = temp->next;
    }

    if (h1 != NULL) {
        temp->next = h1;
    }

    if (h2 != NULL) {
        temp->next = h2;
    }

    return dummy->next;
}

// Helper function to create a linked list from an array
ListNode* createLinkedList(const int arr[], int size) {
    if (size == 0) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < size; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create two hardcoded linked lists
    int list1Arr[] = {1, 2, 4};
    int list2Arr[] = {1, 3, 4};

    ListNode* list1 = createLinkedList(list1Arr, 3);
    ListNode* list2 = createLinkedList(list2Arr, 3);

    // Print the original linked lists
    cout << "List 1: ";
    printLinkedList(list1);
    cout << "List 2: ";
    printLinkedList(list2);

    // Merge the two lists
    ListNode* mergedList = mergeTwoLists(list1, list2);

    // Print the merged linked list
    cout << "Merged List: ";
    printLinkedList(mergedList);

    return 0;
}
