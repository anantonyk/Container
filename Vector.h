#ifndef VECTOR_H
#define VECTOR_H

#include "Container.h"

template <typename T>
class Vector : public Container<T> {
private:
    T* arr;
public:
    Vector() {
        this->arr = new T[this->capacity];
    }
    T& operator [] (int position) override {
        if(position >= this->size) {
            exit(0);
        }
        return arr[position];
    }

    ~Vector() {
        delete[] arr;
    }
    void push(T value) override {
        if(this->size < this->capacity) {
           arr[this->size] = value;
           this->size++;
        }
    }

    T pop() override {
        if(this->size == 0) {
            return static_cast<T>(NULL);
        }
        else {
            this->size--;
            T val = this->arr[this->size];
            return val;
        }
    }

    void clear() override {
        while(this->size != 0) {
            this->size--;
        }
    }

    void shrink_to_fit(){
        this->capacity = this->size;
        T* tmp = new T[this->capacity];
        for(int i = 0; i < this->size; i++) {
            tmp[i] = this->arr[i];
        }
        delete[] arr;
        arr = tmp;
    }

    void set_capacity(int cap) override {
        if(cap < this->size){
            this->shrink_to_fit();
        } else {
            this->capacity = cap;
            T* tmp = new T[this->capacity];
            for(int i = 0; i < this->capacity; i++) {
                tmp[i] = this->arr[i];
            }
            delete[] arr;
            arr = tmp;
        }
    }
};
#endif