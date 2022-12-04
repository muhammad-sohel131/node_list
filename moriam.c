#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node node;
node *head = NULL;

void addAtBeginning(){
    node *newNode = malloc(sizeof(node));
    printf("Enter Value: ");
    scanf("%d", &newNode -> data);

    newNode -> next = head;
    head = newNode;
}

void addAtPosition(){
    int i, data, position;
    printf("Please, enter the position: ");
    scanf("%d", &position);
    printf("Enter the value: ");
    scanf("%d", &data);

    node *newNode = malloc(sizeof(node));

    i = 2;

    if(head == NULL){
        newNode -> data = data;
        newNode -> next = NULL;
        head = newNode;
    }else if(position == 1){
        newNode -> data = data;
        newNode -> next = head;
        head = newNode;
    }else {
        node *temp = head;
        while(i < position && temp -> next != NULL){
            temp = temp -> next;
        }
        newNode -> data = data;
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }

}

void deleteFromBeginning(){
    if(head == NULL){
        printf("The List is empty!\n");
    }else {
        node *temp = head;
        head = temp -> next;
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
            prev -> next = temp -> next;
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
