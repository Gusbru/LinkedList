/*
 * Exercicio de Listas Ligadas
 *
 *
 */

#include <iostream>

typedef struct node {
    int id;
    node *next;
};

int insertFirst(node **head, int id){
    node *tmp = (*head);

    (*head) = (node*)malloc(sizeof(node));

    if((*head) == nullptr) return -1;

    (*head)->id = id;
    (*head)->next = tmp;

    return 1;
}

int insertLast(node **head, int id){
    if ((*head) == nullptr) {
        (*head) = (node*)malloc(sizeof(node));
        if((*head) == nullptr) return -1;
        (*head)->id = id;
        (*head)->next = nullptr;
        return 1;
    }

    node *current = (*head);
    while (current->next != nullptr){
        current = current->next;
    }
    current->next = (node*)malloc(sizeof(node));
    if(current->next == nullptr) return -1;
    current->next->id = id;
    current->next->next = nullptr;
    return 1;
}

int insertElement(node **head, int id, int position){
    node *current = (*head);
    node *currentNext = nullptr;
    int count = 0;

    while(current != nullptr){
        count += 1;
        current = current->next;
    }

    if (count < position || position < 0) return -1;

    current = (*head);
    if (position == 0) {
        (*head) = (node*)malloc(sizeof(node));
        (*head)->id = id;
        (*head)->next = current;
        return 1;
    }

    current = (*head);
    for (int i = 0; i < (position-1); ++i) {
        current = current->next;
    }

    currentNext = current->next;

    current->next = (node*)malloc(sizeof(node));
    if (current->next == nullptr) return -1;

    current->next->id = id;
    current->next->next = currentNext;
    return 1;

}

void printList(node *head){
    node *current = head;

    while (current != nullptr){
        std::cout << current->id << "->";
        current = current->next;
    }

    std::cout << std::endl;

}

node *copyList(node *head) {
    if (head == nullptr) return nullptr;
    node * result = (node*)malloc(sizeof(node));
    result->id = head->id;
    result->next = copyList(head->next);
    return result;
}

node *concat(node *head1, node *head2){

    node *result = copyList(head1);

    node *current = head2;
    while (current != nullptr){
        insertLast(&result, current->id);
        current = current->next;
    }

    return result;

}

int sizeList(node *head){
    int count = 0;

    while (head != nullptr){
        count += 1;
        head = head->next;
    }

    return count;
}

int isEqual(node *head1, node *head2){

    if (sizeList(head1) != sizeList(head2)) return -1;

    while (head1 != nullptr && head2 != nullptr){
        if (head1->id != head2->id) return -1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return 1;
}

int searchList(node *head, int n){

    while (head != nullptr){
        if (head->id == n) return 1;
        head = head->next;
    }
    return -1;
}

node *unionList(node *head1, node *head2){
    node *tmp = concat(head1, head2);
    node *result;
    node *current = result;

    while (tmp != nullptr){
        while (current != nullptr) {

        }
    }

}

int main() {

    node *head;

    head = nullptr;

    insertFirst(&head, 72);
    insertFirst(&head, 38);
    insertLast(&head, 100);

    printList(head);

    insertElement(&head, 59, 2);

    printList(head);


    node *headCopy = copyList(head);
    printList(headCopy);

    node *concatList = concat(head, headCopy);
    printList(concatList);

    std::cout << "Comparing... " << isEqual(head, headCopy) << std::endl;
    std::cout << "Comparing... " << isEqual(head, concatList) << std::endl;

    std::cout << "Looking for 59 " << searchList(head, 59) << std::endl;
    std::cout << "Looking for 60 " << searchList(head, 60) << std::endl;

    return 0;
}