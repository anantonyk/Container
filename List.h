#ifndef LIST_H
#define LIST_H

#include "Container.h"

template <typename T1>
struct node {
    T1 data;
    node* next;
    node(T1 value) {
        this->data = value;
        this->next = NULL;
    }
};

template <typename T>
class List : public Container<T>
{
private:
    node<T> *head, *tail;
public:
    List() {
        this->head =this->tail = NULL;
    }

    ~List() {
        delete head;
        delete tail;
    }
    void push(T value) override {
        if(this->size >= this->capacity)
            return;
        node<T>* newnode = new node<T>(value);
        if(this->head == NULL) {
            this->head = newnode;
            this->tail = newnode;
            this->size = 1;
        }
        else {
            this->tail->next = newnode;
            this->tail = this->tail->next;
            this->tail->next = NULL;
            this->size++;
        }
    }

    T pop() {
        if(this->head == NULL) {
            return static_cast<T>(NULL);
        }
        else if(this->size == 1) {
            T val = this->tail->data;
            delete this->tail;
            this->head = this->tail = NULL;
            this->size = 0;
            return val;
        } else {
            node<T>* tmp = this->head;
            while(tmp->next->next!= NULL) {
                tmp = tmp->next;
            }
            this->tail = tmp;
            T val = tmp->next->data;
            delete this->tail->next;
            this->tail->next = NULL;
            this->size--;
            return val;
        }
    }

    T& operator [] (int position) override {
        if(position >= this->size) {
            exit(0);
        }
        int counter = 0;
        node<T> *tmp = head;
        while(counter < position) {
            tmp = tmp->next;
            counter++;
        }
        return tmp->data;
         
    }

    void clear() override {
        while(this->size != 0) {
            if(this->size == 1) {
                delete this->tail;
                this->head = this->tail = NULL;
                this->size = 0;
            } else {
            node<T>* tmp = this->head;
            while(tmp->next->next!= NULL) {
                tmp = tmp->next;
            }
            this->tail = tmp;
            delete this->tail->next;
            this->tail->next = NULL;
            this->size--;
            }
        }
    }

    void shrink_to_fit(){
        this->capacity = this->size;
    }

    void set_capacity(int cap) override {
        if(cap < this->size){
            this->capacity = this->size;
        } else {
            this->capacity = cap;
        }
    }
};
#endif