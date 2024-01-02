#define _CRT_SECURE_NO_WARNINGS
//Made with ChatGPT

#include <iostream>

// 定义链表节点
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// 定义链表类
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // 在链表头部插入节点
    void prepend(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // 在链表末尾添加节点
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // 查找节点
    Node* find(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // 删除指定位置的节点
    void removeAt(int position) {
        if (head == nullptr) {
            return;
        }
        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            Node* current = head;
            for (int i = 0; i < position - 1 && current != nullptr; i++) {
                current = current->next;
            }
            if (current == nullptr || current->next == nullptr) {
                return;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    // 打印链表
    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.prepend(0);
    list.print();

    Node* foundNode = list.find(2);
    if (foundNode != nullptr) {
        std::cout << "Found node with value 2" << std::endl;
    }
    else {
        std::cout << "Node with value 2 not found" << std::endl;
    }

    list.removeAt(2);
    list.print();

    return 0;
}
