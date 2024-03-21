#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *next;
};

struct Queue {
    Node* HEAD;
    Node* TAIL;
    Node* NIL = nullptr;
    size_t  size = 0;
};

Queue* create_empty_queue();
void Push(Queue *, int);
void Pop(Queue *);
bool Empty(Queue *);
Node* First(Queue *);
size_t size(Queue *);

int main()
{
    return 0;
}

Queue* create_empty_queue() {
    Queue *queue = new Queue;
    queue->HEAD = new Node;
    queue->TAIL = queue->HEAD;
    queue->NIL = queue->HEAD;
    return queue;
}

void Push(Queue *q, int key) {
    Node *a = new Node;
    a->key = key;
    a->next = q->NIL;
    if (Empty(q)) {
        q->HEAD = a;
        q->TAIL = a;
    } else {
        q->TAIL->next = a;
        q->TAIL = a;
    }
    ++(q->size);
}

void Pop(Queue *q) {
    Node *a = q->HEAD->next;
    if (!Empty(q)) {
        delete q->HEAD;
        q->HEAD = a;
        --(q->size);
        if (q->size == 0)
            q->TAIL = q->NIL;
    }
}

Node* First(Queue *q) {
    return q->HEAD;
}

size_t size(Queue *q) {
    return q->size;
}

bool Empty(Queue *q) {
    return !q->size;
}
