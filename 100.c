#include <stdio.h>

#define BUFF_SIZE 16
#define TRANSITION_SIZE 8
#define FINAL_STATE 3

struct Transition {
    int initialState;
    char symbol;
    int nextState;
} transitions[TRANSITION_SIZE] = {
    {0, '0', 0},
    {0, '1', 1},

    {1, '0', 2},
    {1, '1', 1},

    {2, '0', 3},
    {2, '1', 1},

    {3, '0', 0},
    {3, '1', 1}
};

int main() {
    char input[BUFF_SIZE];
    int i = 0, currentState = 0;

    scanf("%s", input);

    printf("\nTransitions");
    printf("\n%d", currentState);

    for (i=0; input[i] != '\0'; i++) {
        int found = 0;
        for (int j=0; j<=TRANSITION_SIZE; j++) {
            if (transitions[j].initialState == currentState && transitions[j].symbol == input[i]) {
                currentState = transitions[j].nextState;
                found = 1;
                break;
            }
        }
        printf(" -> %d", currentState);
    }

    if (currentState == FINAL_STATE) {
        printf("\nString accepted\n");
    } else {
        printf("\nString not accepted\n");
    }
    
    printf("\nTransition table\n");
    printf("%10s %10s %10s\n", "Present", "Next 0", " Next 1");
    for (i=0; i<TRANSITION_SIZE; i+=2) {
        printf("%10d %10d %10d\n", transitions[i].initialState, transitions[i].nextState, transitions[i+1].nextState);
    }
}