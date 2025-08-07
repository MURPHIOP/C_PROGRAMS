#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int i, val;

    for (i = 1; i <= 5; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter value for node %d: ", i);
        scanf("%d", &val);
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("\nOriginal List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    int pos1, pos2;
    printf("\n\nEnter positions to swap (1-based index): ");
    scanf("%d %d", &pos1, &pos2);

    struct Node *node1 = head, *node2 = head;
    for (i = 1; i < pos1 && node1 != NULL; i++)
        node1 = node1->next;
    for (i = 1; i < pos2 && node2 != NULL; i++)
        node2 = node2->next;

    if (node1 != NULL && node2 != NULL) {
        int tempData = node1->data;
        node1->data = node2->data;
        node2->data = tempData;
    } else {
        printf("Invalid positions.\n");
        return 1;
    }

    printf("\nUpdated List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
    return 0;
}
