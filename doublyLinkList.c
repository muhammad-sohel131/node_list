#include<stdio.h>

typedef struct Node node;
struct Node{
    int data;
    node *prev;
    node *next;
};

node *head = NULL;

node  *create_node(int data){
    node *new_node = malloc(sizeof(node));
    new_node -> data = data;
    new_node -> prev = NULL;
    new_node -> next = NULL;
}

void addAtBeginning(){
    int data;
    printf("Enter Value: ");
    scanf("%d", &data);

    node *newNode = create_node(data);

    if(head == NULL){
        head = newNode;
        return ;
    }

    head -> prev = newNode;
    newNode -> next = head;

    head = newNode;
}

void addAtPosition(){
    int i, data, position;
    printf("Please, enter the position: ");
    scanf("%d", &position);
    printf("Enter the value: ");
    scanf("%d", &data);

    node *newNode = create_node(data);

    i = 2;

    if(head == NULL){
        head = newNode;
    }else if(position == 1){
        head -> prev = newNode;
        newNode -> next = head;
        head = newNode;
    }else {
        node *temp = head;
        while(i < position && temp -> next != NULL){
            temp = temp -> next;
            i++;
        }
        if(temp -> next == NULL){
            newNode -> next = temp -> next;
            temp -> next = newNode;
            newNode -> prev = temp;
        }
        newNode -> next = temp -> next;
        temp -> next -> prev = newNode;
        temp -> next = newNode;
        newNode -> prev = temp;
    }

}

void deleteFromBeginning(){
    if(head == NULL){
        printf("The List is empty!\n");
    }else {
        node *temp = head;
        head = temp -> next;
        head -> prev = NULL;
        free(temp);
    }
}

void deleteFromPosition(){
    int i, position;
    printf("Please, enter the position: ");
    scanf("%d", &position);

    if(head == NULL){
        printf("The List is empty!\n");
    }else if (position == 1){
        node *temp = head;
        head = temp -> next;
        head -> prev = NULL;
        free(temp);
    }else {
        i = 1;
        node *temp = head;
        node *prev = head;

        while(i < position && temp -> next != NULL){
            prev = temp;
            temp = temp -> next;
            i++;
        }
        if(i < position){
            printf("The length of the list is %d\n", i);
        }else {
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
            free(temp);
        }
    }
}

void display(){
    node *temp = head;

    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    int choose;

    do {
        printf("1. Add at Beginning\n");
        printf("2. Add at a Certain Position\n");
        printf("3. Delete from the Beginning\n");
        printf("4. Delete from a Certain Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Please, enter your choice: ");
        scanf("%d", &choose);

        switch(choose){
        case 1:
            addAtBeginning();
            break;
        case 2:
            addAtPosition();
            break;
        case 3:
            deleteFromBeginning();
            break;
        case 4:
            deleteFromPosition();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Please, enter valid input from 1 to 6.\n");
            break;
        }
    }while(1);
}

