#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h> // booleans

struct NODE{
    struct NODE *next_node;
    int value;
};

void show_node(struct NODE *node){
    printf("this node adress: %p\n", node);
    printf("next_node: %p\n", node->next_node);
    printf("value: %i\n", node->value);
    printf("======================================\n");
}

void show_help(){
    printf("1. Show elements\n");
    printf("2. Add element\n");
    printf("2. show second element\n");
}

void show_all_elements(struct NODE *first_node){
    struct NODE *pointer;
    pointer = first_node;
    for(;;) {
        printf("=============================\nNODE\n");
        printf("Node address: %p\n", pointer);
        printf("value: %i\n", pointer->value);
        printf("next_node address: %p\n", pointer->next_node);
        printf("=============================\n");

        if(pointer->next_node != NULL){
            pointer = pointer->next_node;
        }
        else{break;}
    }
}

// finding last node in linked list based on first node
struct NODE* find_last_node(struct NODE *first_node){
    struct NODE *pointer;
    pointer = first_node;
    while (pointer->next_node != NULL){
        pointer = pointer->next_node;
    }
    return pointer;
}

void add_new_node(struct NODE *first_node, int value){
    struct NODE *new_node = malloc(sizeof(struct NODE));
    new_node->value = value;
    new_node->next_node = NULL;
    struct NODE* last_node = find_last_node(first_node);
    // for debug
    printf("settings last node -> next_node to %p\n", &new_node);
    // changing last node pointer to this
    last_node->next_node = new_node;
}

void show_value_of_element_2(struct NODE *first_node){
    int second_element_value = first_node->next_node->value;
    printf("second_element_value: %i\n", second_element_value);
}

int main(){
    //
    //    first node
    struct NODE first_node;
    first_node.value = 69;
    first_node.next_node = NULL;
    //first_node.next_node = malloc(sizeof(struct NODE));

    // second node
    //struct NODE second_node;
    //second_node.value = 102;
    //second_node.next_node = malloc(sizeof(struct NODE));
    //second_node.next_node = NULL;
    
    //first_node.next_node = &second_node;
    // third node
    //struct NODE third_node;
    //third_node.value = 111;
    //third_node.next_node = malloc(sizeof(struct NODE));

    //second_node.next_node = &third_node;
    //show_node(&first_node);    
    //show_node(&second_node);    

    char x_abc[100];
    int command;
    int new_value;
    while(1){
        show_help();
        scanf("%i", &command);
        switch(command){
            case 1:
                show_all_elements(&first_node);
                break;
            case 2:
                printf("Put a value: ");
                scanf("%i", &new_value);
                add_new_node(&first_node, new_value);
                break;
            case 3:
                show_value_of_element_2(&first_node);
                break;
        }
    }
    return 0;
}


// that is how we scan a string into array
// scanf("%s", command);
