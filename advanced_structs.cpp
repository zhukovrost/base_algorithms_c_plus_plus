#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
    struct Node {
        T data;
        Node* next;

        Node() : data(T()), next(nullptr) {}

        explicit Node(const T& value) : data(value), next(nullptr) {}

        ~Node() {
            cout << "Node deleted" << endl;
        }
    };

    Node* head;
    Node* tail;
    int listSize;
public:
    LinkedList() : head(nullptr), tail(nullptr), listSize(0) {}
    ~LinkedList(){
        this->clear();
    }

    explicit LinkedList(int size): head(nullptr), tail(nullptr), listSize(0) {
        for (int i = 0; i < size; i++) this->addLast(T());
    }

    void printList(){
        if (isEmpty()){
            cout << "List is empty" << endl;
            return;
        }
        Node* trav = head;
        while (trav != nullptr){
            cout << trav->data << " ";
            trav = trav->next;
        }
        cout << endl;
    }

    void clear(){
        Node* trav = head;
        while (trav != nullptr){
            Node* temp = trav;
            trav = trav->next;
            delete temp;
        }
        head = tail = nullptr;
        listSize = 0;
    };
    int getSize() {
        return listSize;
    };
    bool isEmpty(){
        return (getSize() == 0);
    };

    void addLast(const T& value) {
        Node* newTail = new Node(value);
        if (isEmpty()) {
            head = newTail;
        } else {
            tail->next = newTail;
        }
        tail = newTail;
        ++listSize;
    }
    void addFirst(const T& value){
        if (isEmpty()){
            head = tail = new Node(value);
        }else{
            Node* newHead = new Node(value);
            newHead->next = head;
            head = newHead;
        }
        ++listSize;
    }

    int peekLast(){
        if (isEmpty()){
            cout << "List is empty" << endl;
            return 0;
        }
        return tail->data;
    }
    int peekFirst(){
        if (isEmpty()){
            cout << "List is empty" << endl;
            return 0;
        }
        return head->data;
    }

    int removeFirst(){
        if (isEmpty()){
            cout << "List is empty" << endl;
            return 0;
        }
        Node* temp = head;
        int returnVal = temp->data;
        head = head->next;
        delete temp;
        --listSize;
        return returnVal;
    }

    int removeLast(){
        if (listSize == 0){
            cout << "List is empty" << endl;
            return 0;
        }
        int returnVal = tail->data;
        if (listSize == 1){
            delete head;
            head = tail = nullptr;
        }else{
            Node* trav = head;
            while (trav->next->next != nullptr){
                trav = trav->next;
            }
            delete tail;
            tail = trav;
            trav->next = nullptr;
        }

        --listSize;
        return returnVal;
    }

    int removeAt(int index){
        int returnVal;
        if (index == 0){
            returnVal = head->data;
            removeFirst();
            return returnVal;
        }
        if (isEmpty()){
            cout << "List is empty" << endl;
            return 0;
        }
        if (index >= listSize || index < 0){
            cout << "Out of range!" << endl;
            return 0;
        }

        Node* trav = head;
        while (--index != 0){
            trav = trav->next;
        }
        returnVal = trav->next->data;
        Node* newNext = trav->next->next;
        delete trav->next;
        trav->next = newNext;
        return returnVal;
    }
    bool remove(const T& val){
        if (val == head->data){
            removeFirst();
            return true;
        }
        if (isEmpty()){
            cout << "List is empty" << endl;
            return false;
        }
        Node* trav = head;
        while (trav->next != nullptr){
            if (trav->next->data == val){
                Node* newNext = trav->next->next;
                delete trav->next;
                trav->next = newNext;
                return true;
            }
            trav = trav->next;
        }
        return false;
    }

    int indexOf(const T& val){
        if (isEmpty()){
            cout << "List is empty" << endl;
            return -1;
        }
        Node* trav = head;
        int travIndex = 0;
        while (trav->next != nullptr){
            if (trav->data == val){
                return travIndex;
            }
            trav = trav->next;
            travIndex++;
        }
        if (tail->data == val){
            return listSize - 1;
        }

        return -1;
    }
    bool contains(const T& val){
        return indexOf(val) != -1;
    }
};

template <typename T>
class DoubleLinkedList{
    struct Node{
        T data;
        Node* next;
        Node* prev;

        Node(): data(T()), next(nullptr), prev(nullptr) {}

        explicit Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}

        ~Node(){
            cout << "Node deleted! Data: " << data << endl;
        }
    };

    Node* head;
    Node* tail;
    int listSize;

public:
    DoubleLinkedList(): head(nullptr), tail(nullptr), listSize(0) {}
    explicit DoubleLinkedList(int size): head(nullptr), tail(nullptr), listSize(0) {
        for (int i = 0; i < size; i++) this->addLast(T());
    }

    ~DoubleLinkedList(){
        this->clear();
    }

    void printList(){
        if (isEmpty()){
            cout << "List is empty" << endl;
            return;
        }
        Node* trav = head;
        while (trav != nullptr){
            cout << trav->data << " ";
            trav = trav->next;
        }
        cout << endl;
    }

    void clear(){
        Node* trav = head;
        while (trav != nullptr){
            Node* temp = trav;
            trav = trav->next;
            delete temp;
        }
        head = tail = nullptr;
        listSize = 0;
    };
    int getSize() {
        return listSize;
    };
    bool isEmpty(){
        return (getSize() == 0);
    };

    void addLast(const T& value) {
        Node* newTail = new Node(value);
        if (isEmpty()) {
            head = newTail;
        } else {
            tail->next = newTail;
            newTail->prev = tail;
        }
        tail = newTail;
        ++listSize;
    }
    void addFirst(const T& value){
        if (isEmpty()){
            head = tail = new Node(value);
        }else{
            Node* newHead = new Node(value);
            head->prev = newHead;
            newHead->next = head;
            head = newHead;
        }
        ++listSize;
    }

    int peekLast(){
        if (isEmpty()){
            cout << "List is empty" << endl;
            return 0;
        }
        return tail->data;
    }
    int peekFirst(){
        if (isEmpty()){
            cout << "List is empty" << endl;
            return 0;
        }
        return head->data;
    }



    int removeFirst(){
        if (isEmpty()){
            cout << "List is empty" << endl;
            return 0;
        }
        int returnVal;
        if (getSize() == 1){
            returnVal = head->data;
            delete head;
            head = tail = nullptr;
            --listSize;
            return returnVal;
        }
        Node* temp = head;
        returnVal = temp->data;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        --listSize;
        return returnVal;
    }

    T removeLast(){ // O(1) - double linked
        if (isEmpty()){
            cout << "List is empty" << endl;
            return 0;
        }
        int returnVal;
        if (getSize() == 1){
            returnVal = head->data;
            delete head;
            head = tail = nullptr;
            --listSize;
            return returnVal;
        }
        Node* temp = tail;
        returnVal = temp->data;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        --listSize;
        return returnVal;
    }

    int removeAt(int index){
        int returnVal;
        if (index == 0)
            return removeFirst();
        if (index == listSize - 1)
            return removeLast();

        if (isEmpty()){
            cout << "List is empty" << endl;
            return 0;
        }
        if (index >= listSize || index < 0){
            cout << "Out of range!" << endl;
            return 0;
        }

        Node* trav = head;
        while (--index != -1){
            trav = trav->next;
        }
        returnVal = trav->data;
        trav->prev->next = trav->next;
        trav->next->prev = trav->prev;
        delete trav;
        return returnVal;
    }
    bool remove(const T& val){
        if (isEmpty()){
            cout << "List is empty" << endl;
            return false;
        }
        if (val == head->data){
            removeFirst();
            return true;
        }
        if (val == tail->data){
            removeFirst();
            return true;
        }
        Node* trav = head;
        while (trav->next != nullptr){
            if (trav->data == val){
                trav->prev->next = trav->next;
                trav->next->prev = trav->prev;
                delete trav->next;
                return true;
            }
            trav = trav->next;
        }
        return false;
    }

    int indexOf(const T& val){
        if (isEmpty()){
            cout << "List is empty" << endl;
            return -1;
        }
        Node* trav = head;
        int travIndex = 0;
        while (trav->next != nullptr){
            if (trav->data == val){
                return travIndex;
            }
            trav = trav->next;
            travIndex++;
        }
        if (tail->data == val){
            return listSize - 1;
        }

        return -1;
    }
    bool contains(const T& val){
        return indexOf(val) != -1;
    }
};

template <typename T>
class Stack{
    DoubleLinkedList<T> array;
public:
    int getSize(){
        return array.getSize();
    }
    bool isEmpty(){
        return array.isEmpty();
    }
    int peek(){
        return array.peekLast();
    }
    void push(const T& val){
        array.addLast(val);
    }
    T pop(){
        return array.removeLast();
    }
    void printStack(){
        array.printList();
    }
};

template <typename T>
class Queue{
    LinkedList<T> array;
public:
    int getSize(){
        return array.getSize();
    }
    bool isEmpty(){
        return array.isEmpty();
    }
    int peek(){
        return array.peekFirst();
    }
    bool contains(const T& val){
        return array.contains(val);
    }
    void enqueue(const T& val){
        array.addLast(val);
    }
    int dequeue(){
        return array.removeFirst();
    }
    void printQueue(){
        array.printList();
    }
};
