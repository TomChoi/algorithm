#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node { 
    int data;
    int count;
    Node* next;
};

void printList(Node* head) {
    Node* curr = head;
    while(curr != NULL) {
        printf("data: %d, count: %d \n", curr->data, curr->count);
        curr = curr->next;
    }
}

Node* findData(Node* head, int data) {
    Node* curr = head;
    while(curr != NULL) {
        if(curr->data == data)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

void addNode(Node* head, int data) {
    Node* curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->count = 1;
    newNode->next = NULL;

    curr->next = newNode;
}

int main() {
    // 이 프로그램은 arr에 있는 요들의 중복된 개수를 LinkedList에
    // 저장한다.
    int arr[] = {1, 4, 3, 1, 2, 3, 1, 1};    
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i=0; i<n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    Node head = {arr[0], 1, NULL};

    for(int i=1; i<n; ++i) {
        Node* node = findData(&head, arr[i]);
        if(node != NULL) {
            node->count++;
        } else {
            addNode(&head, arr[i]);
        }
    }

    printList(&head);

    return 0;
}
