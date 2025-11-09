#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *data;
    int top;
    int capacity;
} Stack;

Stack *createStack(int cap) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if (!s) { perror("malloc"); exit(EXIT_FAILURE); }
    s->data = (char*)malloc(cap * sizeof(char));
    if (!s->data) { perror("malloc"); exit(EXIT_FAILURE); }
    s->top = -1;
    s->capacity = cap;
    return s;
}

void push(Stack *s, char c) {
    if (s->top == s->capacity - 1) {
        fprintf(stderr, "Stack overflow\n");
        return;
    }
    s->data[++s->top] = c;
}

char popStack(Stack *s) {
    if (s->top == -1) return '\0'; 
    return s->data[s->top--];
}

void freeStack(Stack *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

typedef struct {
    char *data;
    int front;   
    int rear;    
    int capacity;
} Queue;

Queue *createQueue(int cap) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if (!q) { perror("malloc"); exit(EXIT_FAILURE); }
    q->data = (char*)malloc(cap * sizeof(char));
    if (!q->data) { perror("malloc"); exit(EXIT_FAILURE); }
    q->front = 0;
    q->rear = -1;
    q->capacity = cap;
    return q;
}

void enqueue(Queue *q, char c) {
    if (q->rear == q->capacity - 1) {
        fprintf(stderr, "Queue overflow\n");
        return;
    }
    q->data[++q->rear] = c;
}

char dequeue(Queue *q) {
    if (q->front > q->rear) return '\0'; /* empty */
    return q->data[q->front++];
}

void freeQueue(Queue *q) {
    if (!q) return;
    free(q->data);
    free(q);
}

int isPalindrome(const char *s) {
    int len = (int)strlen(s);
    char *filtered = (char*)malloc((len + 1) * sizeof(char));
    if (!filtered) { perror("malloc"); exit(EXIT_FAILURE); }

    int k = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (isalnum((unsigned char)s[i])) {
            filtered[k++] = (char)tolower((unsigned char)s[i]);
        }
    }
    filtered[k] = '\0';

    if (k <= 1) {
        free(filtered);
        return 1;
    }

    Stack *st = createStack(k);
    Queue *q = createQueue(k);

    for (int i = 0; i < k; ++i) {
        push(st, filtered[i]);
        enqueue(q, filtered[i]);
    }

    int isPal = 1;
    for (int i = 0; i < k; ++i) {
        char a = popStack(st);
        char b = dequeue(q);
        if (a != b) { isPal = 0; break; }
    }

    free(filtered);
    freeStack(st);
    freeQueue(q);
    return isPal;
}

int main(void) {
    char input[1001];

    printf("Enter a string (max 1000 chars):\n");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Input error.\n");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';

    if (isPalindrome(input))
        printf("The string is a palindrome.\n");
    else
        printf("The string is NOT a palindrome.\n");

    return 0;
}
