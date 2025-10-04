#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOC 200
#define MAX_HISTORY 50

char doc[MAX_DOC] = "";
char undoStack[MAX_HISTORY][MAX_DOC];
char redoStack[MAX_HISTORY][MAX_DOC];
int undoTop = -1, redoTop = -1;
int M; // history size

// ---------- STACK FUNCTIONS ----------
void pushUndo(const char *state) {
    if (undoTop == M - 1) {
        for (int i = 1; i < M; i++)
            strcpy(undoStack[i - 1], undoStack[i]);
        undoTop--;
    }
    strcpy(undoStack[++undoTop], state);
}

void pushRedo(const char *state) {
    if (redoTop == M - 1) {
        for (int i = 1; i < M; i++)
            strcpy(redoStack[i - 1], redoStack[i]);
        redoTop--;
    }
    strcpy(redoStack[++redoTop], state);
}

char* popUndo() {
    if (undoTop < 0) return NULL;
    return undoStack[undoTop--];
}

char* popRedo() {
    if (redoTop < 0) return NULL;
    return redoStack[redoTop--];
}

void clearRedo() { redoTop = -1; }

void type(char *str) {
    pushUndo(doc);
    strcat(doc, str);
    clearRedo();
}

void undo(int k) {
    while (k-- && undoTop >= 0) {
        pushRedo(doc);
        strcpy(doc, popUndo());
    }
}

void redo(int k) {
    while (k-- && redoTop >= 0) {
        pushUndo(doc);
        strcpy(doc, popRedo());
    }
}

void reset() {
    doc[0] = '\0';
    undoTop = redoTop = -1;
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
