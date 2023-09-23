#include <iostream>

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList
{
private:
    int count;
    Node* header;
    Node* trailer;

public:
    DoublyLinkedList(){
        count = 0;
        header = new Node {0, nullptr, nullptr};
        trailer = new Node {0, nullptr, nullptr};
        header->next = trailer;
        trailer->prev = header;
    }
    ~DoublyLinkedList() {
        while (!empty()) {
            pop_front();
        }
        delete header;
        delete trailer;
    }
    void insert(Node *p, int val){
        Node* new_node = new Node {val, p->prev, p};
        new_node->prev->next = new_node;
        p->prev = new_node;
        ++count;
    }
    void push_front(int val) {
        insert(header->next, val);
    }
    void push_back(int val) {
        insert(trailer, val);
    }
    void erase(Node* p) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --count;
    }
    void pop_front() {
        erase(header->next);
    }
    void pop_back() {
        erase(trailer->prev);
    }
    bool empty() {
        return count == 0;
    }
    int size() {
        return count;
    }
    void print_all() {
        Node* cursor = header->next;
        while (cursor != trailer) {
            std::cout << cursor->data << ", ";
            cursor = cursor->next;
        }
    }
    void print_reverse() {
        Node* cursor = trailer->prev;
        while (cursor != header) {
            std::cout << cursor->data << ", ";
            cursor = cursor->prev;
        }
    }
};

int main()
{
    DoublyLinkedList list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_back(-10);
    list.print_all();
    // list: header <-> 30 <-> 20 <-> 10 <-> -10 <->trailer
    std::cout << "\n ^ is base doubly linked list" << std::endl;
    list.print_reverse();
    std::cout << "\n ^ is reverse doubly linked list" << std::endl;

    list.pop_front();
    // list: header <-> 20 <-> 10 <-> -10 <->trailer
    list.print_all();
    std::cout << "\n ^ pop front done" << std::endl;
    list.pop_back();
    // list: header <-> 20 <-> 10 <->trailer
    list.print_all();
    std::cout << "\n ^ pop back done" << std::endl;
    

}