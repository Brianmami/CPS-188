#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 8
#define ADD_FOR_CHAR 65

typedef struct node {
    int state; // pos will be used to identify which values are still accessible
    int zero;
    int one;
} node_t;

node_t* state_machine[MAX_SIZE];
node_t* current;
node_t* garbage[MAX_SIZE];
int counter[3] = {0, 0, 0};

int ASCIIAdder(int val) { 
    return val + ADD_FOR_CHAR; 
}

void garbage_collector() {
    int count[2] = {0, 0};
    int temp;
    for(int i = 0; i < MAX_SIZE; i++) {
        count[0] += state_machine[i]->zero;
        count[1] += state_machine[i]->one;
    }
    if(count[0] != counter[0] && count[1] != counter[0]) {
        temp = counter[0] - count[0];
        garbage[counter[2]]->state = temp;
        counter[2]++;
    }
}

void change(int input, int state_change) {
    if(state_change == 1)
        current->one =  input;
    else if(state_change == 0)
        current->zero = input;
    state_machine[current->state] = current;
    garbage_collector();
}

void print() {
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%c %c %c \n", ASCIIAdder(state_machine[i]->state), ASCIIAdder(state_machine[i]->zero), ASCIIAdder(state_machine[i]->one));
}

void updateCurrent(int input) {
    if(input == 1) {
        current = state_machine[current->one];
    }
    else if(input == 0) {
        current = state_machine[current->zero];
    }
    printf("%c \n", ASCIIAdder(current->state));
}

void buildList() {
    for(int i = 0; i < MAX_SIZE; i++) {
        state_machine[i] = malloc(sizeof(node_t));
        garbage[i] = malloc(sizeof(node_t));
    }
    int zeros[MAX_SIZE] = {1, 5, 7, 6, 3, 2, 0, 4};
    int ones[MAX_SIZE] = {4, 7, 3, 3, 1, 0, 5, 2};
    for(int i = 0; i < MAX_SIZE; i++) {
        state_machine[i]->state = i;
        state_machine[i]->zero = zeros[i];
        state_machine[i]->one = ones[i];
        counter[0] += zeros[i];
        counter[1] += ones[i];
    }
}

int main(int argc, char * argv[]) {
    
    char input[10];
    buildList();
    current = state_machine[7];
    printf("%c\n", ASCIIAdder(current->state));
    while(true) {
        printf("Enter your command:");
        scanf("%s", input);
        switch(input[0]) { // use the switch statement to determine which method to call
            case 'c': // change
                change(input[4] - '0', input[2] - '0');
                break;
            case 'g': // garbage
                break;
            case 'd': // delete
                break;
            case 'P': // print
                print();
                break;
            case '0': // update
            case '1':
                updateCurrent(atoi(input));
                break;
            case 'e': // exit
                loop = false;
                break;
            default:
                printf("Please enter a valid command.\n");
                break;
        }
    }
    exit(0);
}
