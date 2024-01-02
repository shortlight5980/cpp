#define _CRT_SECURE_NO_WARNINGS
//Made with ChatGPT

#include <iostream>

// ��������ڵ�
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// ����������
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // ������ͷ������ڵ�
    void prepend(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // ������ĩβ��ӽڵ�
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

    // ���ҽڵ�
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

    // ɾ��ָ��λ�õĽڵ�
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

    // ��ӡ����
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
