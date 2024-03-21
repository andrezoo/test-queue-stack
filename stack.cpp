#include <iostream>

using std::cin;
using std::cout;

struct Node {
    int key;
    int data;
    Node *next;
};

Node* add_node(Node* after) {
    Node* new_node = new Node;
    new_node->next = after;
    return new_node;
}

Node* remove_node(Node* target) {
    Node* after = target->next;
    delete target;
    return after;
}

struct ListStack {
    Node *top = nullptr;
    Node *tail = nullptr;
    size_t size = 0;
};

void push(ListStack &s, int val) {
    if(s.size == 1) s.tail = s.top; // если только один элемент, то заполняем tail 
    s.top = add_node(s.top);
    s.top->data = val;
    s.size++;
}

int pop(ListStack &s) {
    if(s.size == 0) s.tail = new Node;
    auto val = s.tail->data;
    s.tail = remove_node(s.tail);
    s.size--;
    return val;
}

bool is_empty(ListStack &s) {
    return s.top == nullptr;
}

int main() {
    ListStack s;
    push(s, 1);
    std::cout << s.tail->data << ' ';
    push(s, 2);
    std::cout << s.tail->data << ' ';
    push(s, 3);
    std::cout << s.tail->data << ' ';
    push(s, 4);
    while(!is_empty(s))
        std::cout << pop(s) << ' ';
        std::cout << s.tail << ' ';
    return 0;
}
