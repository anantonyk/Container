#include "List.h"
#include "Vector.h"

template <typename T, typename ... Args>
void initialize(Container<T>* A, T value, Args ... args);

template <typename T, typename ... Args>
void work_with_container(Container<T>* A, T value, Args ... ars);

int main(){
    Container<int> * containerV = new Vector<int>;
    Container<char> * containerL = new List<char>;
    initialize(containerV,10,20,30,40,50,60);
    work_with_container(containerV,80,70,60,40);
    cout<<"\n\n\n\n\n\n\n\n";
    initialize(containerL,'a','b','c','d');
    work_with_container(containerL,'z','x','y');
    system("pause");
}

template <typename T, typename ... Args>
void initialize(Container<T>* A, T value, Args ... args) {
    cout << "current size of container: " << A->get_size() << endl;
    cout << "current capacity of container: " << A->get_capacity() << endl;
    cout << "container: ";
    A->print();
    cout << "push values to container" << endl;
    A->push(args...);
    cout << "current size of container: " << A->get_size() << endl;
    cout << "current capacity of container: " << A->get_capacity() << endl;
    cout << "container: ";
    A->print();
}

template <typename T, typename ... Args>
void work_with_container(Container<T>* A, T value, Args ... args) {
    cout << "first element of container: " << A->get(0) << endl;
    A->emplace(1, args ...);
    cout << "container: ";
    A->print();
    cout << "set capacity 40" << endl;
    A->set_capacity(40);
    cout << "current size of container: " << A->get_size() << endl;
    cout << "current capacity of container: " << A->get_capacity() << endl;
    cout << "shrink to fit" << endl;
    A->shrink_to_fit();
    cout << "current size of container: " << A->get_size() << endl;
    cout << "current capacity of container: " << A->get_capacity() << endl;
    cout << "delete last element" << endl;
    A->pop();
    cout << "clear container" << endl;
    A->clear();
    cout << "container: ";
    A->print();
    cout << "current size of container: " << A->get_size() << endl;
    cout << "current capacity of container: " << A->get_capacity() << endl;
}