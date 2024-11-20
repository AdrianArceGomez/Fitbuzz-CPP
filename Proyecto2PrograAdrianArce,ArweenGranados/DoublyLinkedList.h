#pragma once
template<typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void pushBack(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void pushFront(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    T* front() const {
        if (head) {
            return &head->data;
        }
        return nullptr;
    }

    T* back() const {
        if (tail) {
            return &tail->data;
        }
        return nullptr;
    }

    bool empty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void clear() {
        Node<T>* current = head;
        while (current) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }

    T* at(int index) const {
        if (index < 0 || index >= size) {
            return nullptr;
        }

        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return &current->data;
    }

    bool remove(int index) {
        if (index < 0 || index >= size) {
            return false;
        }

        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        if (current->prev) {
            current->prev->next = current->next;
        }
        else {
            head = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        }
        else {
            tail = current->prev;
        }

        delete current;
        size--;
        return true;
    }

    ~DoublyLinkedList() {
        clear();
    }
};