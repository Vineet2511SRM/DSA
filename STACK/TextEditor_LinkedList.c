#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DOC 200
typedef struct Node {
    char data[MAX_DOC];
    struct Node *next;
} Node;
Node *undoTop = NULL, *redoTop = NULL;
char doc[MAX_DOC] = "";
int M;           
int undoCount = 0, redoCount = 0;
// ---------- STACK FUNCTIONS ----------
void push(Node **top, const char *state, int *count) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, state);
    newNode->next = *top;
    *top = newNode;
    (*count)++;
    if (*count > M) {
        Node *temp = *top;
        Node *prev = NULL;
        while (temp->next) { prev = temp; temp = temp->next; }
        if (prev) prev->next = NULL;
        free(temp);
        (*count)--;
    }
}
char* pop(Node **top, int *count) {
    if (!*top) return NULL;
    Node *temp = *top;
    char *state = (char*)malloc(MAX_DOC);
    strcpy(state, temp->data);
    *top = temp->next;
    free(temp);
    (*count)--;
    return state;
}
void clearStack(Node **top, int *count) {
    Node *temp;
    while (*top) {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
    *count = 0;
}
// ---------- OPERATIONS ----------
void type(char *str) {
    push(&undoTop, doc, &undoCount);
    strcat(doc, str);
    clearStack(&redoTop, &redoCount);
}
void undo(int k) {
    while (k-- && undoTop) {
        push(&redoTop, doc, &redoCount);
        char *prev = pop(&undoTop, &undoCount);
        strcpy(doc, prev);
        free(prev);
    }
}
void redo(int k) {
    while (k-- && redoTop) {
        push(&undoTop, doc, &undoCount);
        char *next = pop(&redoTop, &redoCount);
        strcpy(doc, next);
        free(next);
    }
}
void reset() {
    doc[0] = '\0';
    clearStack(&undoTop, &undoCount);
    clearStack(&redoTop, &redoCount);
}
// ---------- MAIN ----------
int main() {
    char command[100], str[100];
    int k;
    printf("Enter history size M: ");
    scanf("%d", &M);
    getchar(); // consume newline
    printf("Enter commands (EXIT to quit):\n");
    while (1) {
        if (!fgets(command, sizeof(command), stdin)) break;

        command[strcspn(command, "\n")] = '\0';

        if (strncmp(command, "EXIT", 4) == 0) {
            printf("Exiting program.\n");
            break;
        }
        else if (sscanf(command, "TYPE \"%[^\"]\"", str) == 1) {
            type(str);
        }
        else if (sscanf(command, "UNDO %d", &k) == 1) {
            undo(k);
        }
        else if (sscanf(command, "REDO %d", &k) == 1) {
            redo(k);
        }
        else if (strncmp(command, "RESET", 5) == 0) {
            reset();
        }
        else if (strncmp(command, "PRINT", 5) == 0) {
            printf("\"%s\"\n", doc);
        }
        else {
            printf("Invalid command! Try again.\n");
        }
    }
    return 0;
}
