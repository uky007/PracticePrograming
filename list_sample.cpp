#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <stack>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;
};


ListNode *CreateList(vector <int>& nums) {

    ListNode *newnode;
    ListNode *head, *tail;
    ListNode *thisnode;

    head = tail = NULL;

for (int i = 0; i < nums.size(); i++) {
    newnode = new ListNode;
    newnode->val = nums[i];
    newnode->next = NULL;

    if (tail != NULL) {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    } else {
        head = tail = newnode;
        newnode->prev = NULL;
    }
}

    thisnode = head;

    return thisnode;

} 

ListNode *RemoveListNode(ListNode *list, int target) {

    ListNode *thisnode;
    ListNode *head;
    thisnode = head = list;
    while (thisnode != NULL) {
        if (thisnode->val == target) {
            printf("Find %d on %p\n", target, thisnode);
            printf("Remove a this node %d\n", thisnode->val);
            if (thisnode->prev != NULL) {
                thisnode->prev->next = thisnode->next;
            } else {
                head = thisnode->next;
            }

            if (thisnode->next != NULL) {
            thisnode->next->prev = thisnode->prev;
            }

            return head;
        }

        thisnode = thisnode->next;
    }

    if (thisnode == NULL) {
            printf("Not find %d\n", target);
            return head;
        }

    return head;
}

ListNode *AeendListNode(ListNode *list, int num) {

    ListNode *thisnode;
    ListNode *newnode;
    ListNode *head, *tail;
    thisnode = head = list;

    newnode = new ListNode;
    newnode->val = num;
    newnode->next = NULL;

    while(thisnode->next != NULL) {
        thisnode = thisnode->next;
    }
    tail = thisnode;

    if (head != NULL) {
        printf("Append a node in tail...\n");
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    } else {
        printf("List is empty\n");
        return NULL;
    }

    return head;
}

ListNode *InsertListNode(ListNode *list, int num) {
    ListNode *thisnode;
    ListNode *newnode;
    ListNode *head, *tail;
    thisnode = head = list;

    newnode = new ListNode;
    newnode->val = num;

    printf("Searching an insert position...\n");
    while(thisnode->next != NULL) {
        if (thisnode->val <= num && thisnode->next->val >= num) {
            printf("Insert a node...\n");
            newnode->prev = thisnode;
            newnode->next = thisnode->next;
            thisnode->next = newnode;
            thisnode->next->prev = newnode;
            return head;
        } else if (num < head->val) {
            printf("Insert a node...\n");
            newnode->prev = NULL;
            newnode->next = head;
            head = newnode;
            return head;
        } else {
            thisnode = thisnode->next;
        }
    }
    tail = thisnode;

    printf("Insert a node...\n");
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;

    return head;

}

void SearchListNode(ListNode *list, int target) {
    ListNode *thisnode;
    ListNode *head;
    thisnode = head = list;
    while (thisnode != NULL) {
        if (thisnode->val == target) {
            printf("Find %d on %p.\n", target, thisnode);
            return;
        }

        thisnode = thisnode->next;
    }

    if (thisnode == NULL) {
            printf("Not find %d.\n", target);
            return;
        }

    return;

}


int main() {

int n;
cout << "Input a size of initial list numbers:" << endl;
cin >> n;

vector <int> nums(n);
ListNode *list;
ListNode *head;

cout << "Input the elements of the list:" << endl;
for (int i = 0; i < n; i++) {
    cin >> nums[i];
}
cout << "Created this list of numbers:" << endl;
list = CreateList(nums);
head = list;


    while(list != NULL) {
        if (list->next != NULL) {
        printf("%d->", list->val);
        list = list->next;
        } else {
            printf("%d\n", list->val);
            list = list->next;
        }
    }

    int target;

    cout << "Input a number to remove:" << endl;
    cin >> target;

    list = head;
    list = RemoveListNode(list, target);

    while(list != NULL) {
        if (list->next != NULL) {
        printf("%d->", list->val);
        list = list->next;
        } else {
            printf("%d\n", list->val);
            list = list->next;
        }
    }

    list = head;
    cout << "Input a number to search:" << endl;
    cin >> target;
    SearchListNode(list, target);

    int num;
    cout << "Input a number to append this list in tail:" << endl;
    cin >> num;
    list = AeendListNode(list, num);

    while(list != NULL) {
        if (list->next != NULL) {
        printf("%d->", list->val);
        list = list->next;
        } else {
            printf("%d\n", list->val);
            list = list->next;
        }
    }

    list = head;
    cout << "Input a number to insert this node:" << endl;
    cin >> num;
    list = InsertListNode(list, num);

    while(list != NULL) {
        if (list->next != NULL) {
        printf("%d->", list->val);
        list = list->next;
        } else {
            printf("%d\n", list->val);
            list = list->next;
        }
    }

    return 0;

}
