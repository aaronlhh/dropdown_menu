#ifndef STACK_H
#define STACK_H
#include "linked_list.h"

template <typename T>
class Stack{

public:

    class Iterator{
    public:
        friend class Stack;
        Iterator() {_ptr = nullptr;}
        Iterator(node<T>* p) {_ptr = p;}

        T operator *() {  //dereference operator
            assert(_ptr);
            return _ptr->_item;
        }

        T* operator ->() {   //member access operator
            assert(_ptr);
            return &_ptr->_item;
        }

        operator bool() {   // casting operator: true if _ptr not NULL
            if(_ptr) return true;
            else return false;
        }
        bool is_null(){    //true if _ptr is NULL
            if(_ptr) return false;
            else return true;
        }
        friend bool operator !=(const Iterator& left,
                                const Iterator& right){ //true if left != right
            if(left._ptr != right._ptr)
                return true;
            else
                return false;
        }

        friend bool operator ==(const Iterator& left,
                                const Iterator& right){ //true if left == right
            if(left._ptr == right._ptr)
                return true;
            else
                return false;
        }

        Iterator& operator ++(){  // ++it
            _ptr = _ptr->_next;
            return *this;
        }

        friend Iterator operator ++(Iterator& it,  // it++
                                    int unused){
            Iterator temp(it._ptr);
            ++it;
            return temp;
        }

    private:
        node<T>* _ptr;
    };

    Stack(); // constructor initialize _top to nullptr

    // big three
    Stack(const Stack& other);  // copy constructor
    Stack& operator =(const Stack& other); // assignment operator
    ~Stack();  // destructor

    void push(const T& item); // push item to the top
    T pop();  // pop the item from the top and return
    bool empty() const;   // check if the stack is empty
    Iterator top() const;   // returns the address of top
    void clear();   // clear the stack
    void print();  // print out the list, used in test function


private:
    node<T>* _top;

};


// ------------definition

template <typename T>
Stack<T> :: Stack():_top(nullptr){
    // set the _stop to nullptr by default
}

template <typename T>
Stack<T> :: Stack(const Stack& other){
    // copy the other stack to _top
    _top = nullptr;
    _copy_list(_top, other._top);
}

template <typename T>
Stack<T>& Stack<T> :: operator =(const Stack& other){
    if(this == &other){
        return *this;
    }

    _copy_list(_top, other._top);
    return *this;


}

template <typename T>
Stack<T> :: ~Stack(){
    clear();
}

template <typename T>
void Stack<T> :: push(const T& item){
    //bool debug = false;
   // if(debug) cout << "\npushing item "<< item << " into stack\n";

    _insert_head(_top, item);
}

template <typename T>
T Stack<T> :: pop(){
    assert(!empty());

    bool debug = false;

    node<T>* first = _top;
    T item = first->_item;
    _delete_node(_top, first);

    //if(debug) cout << "\npop the item " << item << " out of stack\n";
    return item;
}


template <typename T>
bool Stack<T> :: empty() const{
    if(_top == nullptr)
        return true;
    else
        return false;
}

template <typename T>
typename Stack<T>::Iterator Stack<T> :: top() const{
    return Iterator(_top);
}


template <typename T>
void Stack<T> :: clear(){
    _clear_list(_top);
}

template <typename T>
void Stack<T> :: print(){
    _print_list(_top);
}

// --------------test function

void test_stack_push();






#endif // STACK_H

