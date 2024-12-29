#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    vector<int> merge;
    ListNode* h1 = list1;
    ListNode* h2 = list2;

    // Add all elements from the first list to the vector
    while (h1 != NULL) {
        merge.push_back(h1->val);
        h1 = h1->next;
    }

    // Add all elements from the second list to the vector
    while (h2 != NULL) {
        merge.push_back(h2->val);
        h2 = h2->next;
    }

    // Sort the merged values
    sort(merge.begin(), merge.end());

    // Create a new linked list from the sorted values
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    for (int val : merge) {
        temp->next = new ListNode(val);
        temp = temp->next;
    }

    return dummy->next;
}

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return NULL;

    ListNode* head = new ListNode(values[0]);
    ListNode* temp = head;

    for (size_t i = 1; i < values.size(); i++) {
        temp->next = new ListNode(values[i]);
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
    vector<int> list1_values = {1, 2, 4};
    vector<int> list2_values = {1, 3, 4};

    ListNode* list1 = createLinkedList(list1_values);
    ListNode* list2 = createLinkedList(list2_values);

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
