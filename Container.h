#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <cstddef>

using namespace std;

template <typename T>
class Container
{
protected:
    int size;
    int capacity; //max size
public:
    Container():size{0}, capacity{100} {
    };
    virtual T& operator [] (int position) = 0;
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual void clear() = 0;
    virtual void shrink_to_fit() = 0;
    virtual void set_capacity(int cap) = 0;

    template <typename ... Args>
    void emplace(int position, T value, Args ... args) {
        if(position >= this->size)
            return;
        (*this)[position] = value;
        return emplace(position + 1, args...);
    }

    void emplace(int position, T value) {
        if(position >= this->size)
            return;
        (*this)[position] = value;
    }

    int get_size() {
        return this->size;
    }

    int get_capacity() {
        return this->capacity;
    }

    void print(){
        for(int i = 0; i < this->size; i++){
            cout << (*this)[i] << " ";
        }
        cout << endl;
    }
    
    T get(int position){
        if(position >= this->size)
            return static_cast<T>(NULL);
        return (*this)[position];
    }

    

    void insert(int position, T value){
        if(position >= this->size)
            return;
        (*this)[position] = value;
    }
};
#endif