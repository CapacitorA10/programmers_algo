#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *prev;
    Node *next;
};

template <typename T>
class DoublyLinkedList
{
private:
    int count;
    Node<T> *header;
    Node<T> *trailer;

public:
    class Iterator
    {
    private:
        Node<T> *ptr;

    public:
        Iterator(): ptr(nullptr) {} // 기본 생성자
        Iterator(Node<T> *p): ptr(p) {} // 생성자

        T& operator*() { return ptr->data; } // 역참조 연산자, data를 참조 형태로 반환

        Iterator& operator++() { // 전위 증가 연산자, ++poo로 작동, poo++로 작동하게 하려면 int operator++(int)을 작성
            ptr = ptr->next;
            return *this;
        }
        Iterator& operator--() { // 전위 감소 연산자, --poo로 작동, poo--로 작동하게 하려면 int operator--(int)을 작성
            ptr = ptr->prev;
            return *this;
        }
        bool operator==(const Iterator& other) const { // 비교 연산자
            return ptr == other.ptr;
        }
        bool operator!=(const Iterator& other) const { // 비교 연산자
            return ptr != other.ptr;
        }

        friend class DoublyLinkedList;
    };

    DoublyLinkedList()
    {
        count = 0;
        header = new Node<T>{T(), nullptr, nullptr};
        trailer = new Node<T>{T(), nullptr, nullptr};
        header->next = trailer;
        trailer->prev = header;
    }
    ~DoublyLinkedList()
    {
        while (!empty())
        {
            pop_front();
        }
        delete header;
        delete trailer;
    }

    Iterator begin() const { return Iterator(header->next); } 
    Iterator end() const { return Iterator(trailer); }
    // the reason of const is that begin(),end() is not supposed to change the object
    // but the return value is not const because we want to change the value of the object

    void insert(const Iterator& pos, const T& val) 
    {
        Node<T> *p = pos.ptr;
        Node<T> *new_node = new Node<T>{val, p->prev, p};
        new_node->prev->next = new_node;
        p->prev = new_node;
        ++count;
    }
    void push_front(const T& val)
    {
        insert(begin(), val);
    }
    void push_back(const T& val)
    {
        insert(end(), val);
    }
    void erase(const Iterator& pos)
    {
        Node<T> *p = pos.ptr;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --count;
    }
    void pop_front()
    {
        erase(begin());
    }
    void pop_back()
    {
        erase(--end());
    }

    Iterator find(const T& val) const
    {
        Node<T> *cursor = header->next;
        while (cursor != trailer)
        {
            if (cursor->data == val)
            {
                return Iterator(cursor);
            }
            cursor = cursor->next;
        }
        return end();
    }

    bool empty()
    {
        return count == 0;
    }
    int size()
    {
        return count;
    }
};

int main()
{
    DoublyLinkedList<int> list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_back(-10);
    // list: header => 30 => 20 => 10 => -10 => trailer
    auto it = list.find(20);
    if (it != list.end()) {
        std::cout << "Found: " << *it << std::endl;
        list.insert(it, 25);
    }
    // list: header => 30 => 25 => 20 => 10 => -10 => trailer
    for (auto n : list) {
        std::cout << n << ", ";
    } 
    std::cout << std::endl;
}