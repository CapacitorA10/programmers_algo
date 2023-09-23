#include <iostream>

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    
    // 가장 앞에 리스트 노드를 추가한다.
    void push_front(int val) {
        Node* new_node = new Node {val, NULL};
        if ( head != NULL ) {
            new_node->next = head;
        }
        head = new_node;
    }
    // 가장 앞 노드를 삭제한다.
    void pop_front() {
        if (head != NULL) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }
    // 리스트 전체 출력
    void print_all() {
        Node* cursor = head;
        while (cursor != NULL) {
            std::cout << cursor->data << ", ";
            cursor = cursor->next;
        }
    }
    // 리스트가 비어있는지 확인
    bool empty() {
        return head == NULL;
    }
    // 리스트 삭제
    ~LinkedList() {
        while (!empty()) {
            pop_front();
        }
    }

};


int main() 
{
    LinkedList list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);
    list.print_all();

    std::cout << std::endl;
    list.pop_front();
    list.print_all();

    std::cout << std::endl;
    list.push_front(10);
    list.print_all();
    
    return 0;
}