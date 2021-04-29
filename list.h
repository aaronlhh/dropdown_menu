#ifndef LIST_H
#define LIST_H
#include "linked_list.h"
#include <iostream>

using namespace std;
template <typename T>
class list
{
public:

    class Iterator{
    public:
        friend class list;
        Iterator() {_ptr = nullptr;}
        Iterator(node<T>* p) {_ptr = p;}

        T& operator *() {  //dereference operator
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
        // or friend Iterator operator++(Iterator& it) {...return it;}
        Iterator& operator ++(){  // ++it
            assert(_ptr);
            _ptr = _ptr->_next;
            return *this;
        }

        // or Iterator operator++(int)
        friend Iterator operator ++(Iterator& it,  // it++
                                    int unused){
            assert(it._ptr);
            Iterator temp(it._ptr);
            ++it;
            return temp;
        }
        
       

    private:
        node<T>* _ptr;
    };

    list();

    ~list();
    list(const list<T> &copyThis);
    list& operator =(const list& rhs);

    Iterator insert_head(T i);           //insert i at the head of list

    Iterator insert_after(T i, Iterator iMarker); //insert i after iMarker

    Iterator insert_before(T i, Iterator iMarker);//insert i before iMarker

    Iterator insert_sorted(T i);         //insert i. Assume sorted list

    Iterator insert_back(T i);

    T delete_node(Iterator iMarker);         //delete node pointed to by iMarker


    void print() const;     //print the list

    Iterator search(const T &key);      //return pointer to node containing
                                        //  key. NULL if not there

    Iterator prev(Iterator iMarker);    //get the previous node to iMarker


    T& operator[](int index);       //return the item at index

    Iterator begin() const;        //return the head of the list

    Iterator end() const;              //return the end of the list (nullptr)

    Iterator last_node() const;   // return the iterator of the last node
    
    

    //insertion operator for list
    friend ostream& operator <<(ostream& outs, const list<T>& l);

private:
    node<T>* _head;

};

// ----------------function definitions

void test_list();

template <typename T>
void print_menu(list<T> &list, node<T>* &pos);

template <typename T>
void initialize_list(list<T>& list);

template <typename T>
void print_list_interact(list<T>& list, node<T>* &obj);


// -----------------implementation-------------------

template <typename T>
list<T> :: list(){
    _head = nullptr;
}

template <typename T>
list<T> :: ~list(){
    _clear_list(_head);
}

template <typename T>
list<T> :: list(const list<T> &copyThis){
    _head = _copy_list(copyThis._head);
}

template <typename T>
list<T>& list<T> :: operator =(const list& rhs){
    _clear_list(_head);
    _head = _copy_list(rhs._head);
}

template <typename T>
typename list<T>::Iterator list<T> :: insert_head(T i){
    return Iterator(_insert_head(_head, i));
}

template <typename T>
typename list<T>::Iterator list<T> :: insert_after(T i, Iterator iMarker){
    return Iterator(_insert_after(_head, _search_list(_head, *iMarker), i));
}

template <typename T>
typename list<T>::Iterator list<T> :: insert_before(T i, Iterator iMarker){
    return Iterator(_insert_before(_head, _search_list(_head, *iMarker), i));
}

template <typename T>
typename list<T>::Iterator list<T> :: insert_sorted(T i){
    return Iterator(_insert_sorted(_head, i));
}

template <typename T>
typename list<T>::Iterator list<T>::insert_back(T i){
    return Iterator(_insert_back(_head, i));
}

template <typename T>
T list<T> :: delete_node(Iterator iMarker){
    T item = _delete_node(_head, _search_list(_head, *iMarker));
    return item;
}

template <typename T>
void list<T> :: print() const{
    _print_list(_head);
}

template <typename T>
typename list<T>::Iterator list<T> :: search(const T &key){
    return Iterator(_search_list(_head, key));
}

template <typename T>
typename list<T>::Iterator list<T> :: prev(Iterator iMarker){
    if(iMarker.is_null()){
        return nullptr;
    }
    return Iterator(_previous_node(_head, _search_list(_head, *iMarker)));
}

template <typename T>
T& list<T> :: operator[](int index){
    return _at(_head, index);
}

template <typename T>
typename list<T>::Iterator list<T> :: begin() const{
    return Iterator(_head);
}

template <typename T>
typename list<T>::Iterator list<T>::end() const{
    return Iterator(nullptr);
}

template <typename T>
typename list<T>::Iterator list<T>::last_node() const{
    return Iterator(_last_node(_head));
}


template <typename T>
ostream& operator <<(ostream& outs, const list<T>& l){
    l.print();
    return outs;
}

template <typename T>
void print_list_interact(list<T> &l, typename list<T>::Iterator &obj){
    typename list<T>::Iterator walker = l.begin();
//    while(walker != nullptr){
//        if(walker != obj){
//            cout << "[" << walker->_item << "]->";
//        }else{
//            cout << "{" << walker->_item << "}->";
//        }
//        walker = walker->_next;
//    }
    for(walker = l.begin(); walker != l.end(); walker++){
        if(walker != obj)
            cout << "[" << *walker << "]->";
        else
            cout << "{" << *walker << "}->";
    }
    cout << "|||";
    cout << endl;
}


template <typename T>
void initialize_list(list<T>& l){
    srand(time(NULL));  // generator 5  drandom sorted number
    for(int i = 0; i < 5; i++){
        int number = rand()%100+1;
        if(l.begin().is_null()){
            l.insert_head(number);
        }else{
            l.insert_sorted(number);
        }
    }
}


template <typename T>
void print_menu(list<T> &l, typename list<T>::Iterator& pos){
    string menu = "[R]andom [A]fter  [B]efore [D]elete [S]earch "
                  "[P] Previous  [N] Next  [H]ome  [E]nd";
    cout << "..   ..   ..   ..   ..   ..   ..   ..   "
            "..   ..   ..   ..   ..   ..   ..   ..\n";

    print_list_interact(l, pos);
    cout << menu << endl << endl;
}

#endif // LIST_H
