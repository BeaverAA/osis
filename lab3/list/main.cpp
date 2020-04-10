#include <iostream>
#include <vector>

using namespace std;

class Node {

public:
    Node *next;
    Node *prev;
    string value;

    Node(string value) {
        this->next = nullptr;
        this->prev = nullptr;
        this->value = value;
    }
};

class List {

    Node *head;
    Node *tail;

public:

    void addHead(string value) {
        Node *newNode = new Node(value);
        newNode->next = head;
        Node *oldHead = head;
        if (oldHead != nullptr) {
            oldHead->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;

    }

    void addTail(string value) {
        Node *newNode = new Node(value);
        newNode->prev = tail;
        Node *oldTail = tail;
        if (oldTail != nullptr) {
            oldTail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }

    void remove(int index) {
        int i = 0;
        Node *node = head;
        while (i < index) {
            if (node == nullptr) {
                return;
            }
            i += 1;
            node = node->next;
        }
        if (node == nullptr) {
            return;
        }
        Node *prev = node->prev;
        Node *next = node->next;
        if (prev != nullptr) {
            prev->next = next;
        }
        if (next != nullptr) {
            next->prev = prev;
        }
    }

    vector<string> getAll() {
        vector<string> allValues;
        Node *node = head;
        while (node != nullptr) {
            allValues.push_back(node->value);
            node = node->next;
        }
        return allValues;
    }

    void clear() {
        Node *node = head;
        head = nullptr;
        tail = nullptr;
        while (node != nullptr) {
            node = node->next;
        }
    }

};

int main(int argc, const char * argv[]) {

    List *list = new List();

    list->addHead("lol");
    for (auto it : list->getAll()) {
        cout << it << " ";
    }
    cout << endl;

    list->addHead("kek");
    for (auto it : list->getAll()) {
        cout << it << " ";
    }
    cout << endl;

    list->addTail("tail");
    for (auto it : list->getAll()) {
        cout << it << " ";
    }
    cout << endl;

    list->remove(1);
    for (auto it : list->getAll()) {
        cout << it << " ";
    }
    cout << endl;

    list->clear();
    for (auto it : list->getAll()) {
        cout << it << " ";
    }
    cout << endl;

    list->addHead("lol2");
    for (auto it : list->getAll()) {
        cout << it << " ";
    }
    cout << endl;

    list->addHead("kek2");
    for (auto it : list->getAll()) {
        cout << it << " ";
    }
    cout << endl;

    
    
    return 0;
}
