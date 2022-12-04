#include<stdio.h>

typedef struct Node node;
struct Node{
    int data;
    node *next;
};
node *head = NULL;

node* create_newNode(int value){
    node *newNode = malloc(sizeof(node));
    newNode -> data = value;
    newNode -> next = NULL;

    return newNode;
}

void addAtEnd(){
    int value;
    node *newNode;
    printf("Enter Value: ");
    scanf("%d", &value);
    newNode = create_newNode(value);

    if(head == NULL){
        head = newNode;
    }else {
        node *temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }

}

void addAtPosition(){
    int i, value, position;
    printf("Please, enter the position: ");
    scanf("%d", &position);
    printf("Enter the value: ");
    scanf("%d", &value);

    node *newNode = create_newNode(value);

    i = 2;

    if(head == NULL){
        head = newNode;
    }else if(position == 1){
        newNode -> next = head;
        head = newNode;
    }else {
        node *temp = head;
        while(i < position && temp -> next != NULL){
            temp = temp -> next;
            i++;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }

}

void deleteFromEnd(){
    if(head == NULL){
        printf("The List is empty!\n");
    }else {
        node *temp = head;
        node *prev = head;
        while(temp -> next != NULL){
            prev = temp;
            temp = temp -> next;
        }
        if(prev == temp){
            head = NULL;
        }
        prev -> next = NULL;
        free(temp);
    }
}

void deleteFromPosition(){
    int i, position;
    printf("Please, enter the position: ");
    scanf("%d", &position);

    if(position < 1){
        printf("Position start from 1.\n");
        return ;
    }

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
        printf("1. Add at End\n");
        printf("2. Add at a Certain Position\n");
        printf("3. Delete from the End\n");
        printf("4. Delete from a Certain Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Please, enter your choice: ");
        scanf("%d", &choose);

        switch(choose){
        case 1:
            addAtEnd();
            break;
        case 2:
            addAtPosition();
            break;
        case 3:
            deleteFromEnd();
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
