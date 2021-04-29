#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
struct node{

    T _item;      //content of the node
    node* _next;  //address of the next node

    node(const T& item = T(), node* next = nullptr): _item(item), _next(next){
      //this one ctor acts as a default ctor (zero args) AND as
      //  one and two arg constructors
      //node n;
      //node n(5);
      //node n(5, node_address);
    }

    friend ostream& operator <<(ostream& outs, const node& print_me){
      // templated function must be inline
      outs<<"["<<print_me._item<<"]->";
      return outs;
    }
};

//--------- list declarations


// linked list can manipulate the data
// arrayList can access and store data


template <typename T>
ostream& _print_list(node<T>* head_ptr, ostream& outs = cout);

template <typename T>
ostream& _printList_backwards(node<T> *head, ostream& outs = cout);

template <typename T>
node<T>* _search_list(node<T>* head, const T& item);

template <typename T>
node<T>* _insert_head(node<T>* &headptr, const T& item);

template <typename T>
node<T>* _insert_after(node<T>* &head, node<T>* afterThis, T insertThis);

template <typename T>
node<T>* _insert_before(node<T>* &head, node<T>* beforeThis, T insertThis);

template <typename T>
node<T>* _insert_back(node<T>* &head, T insertThis);

template <typename T>
node<T>* _previous_node(node<T>* head, node<T>* prevToThis);

template <typename T>
T _delete_node(node<T>* &head, node<T>* deleteThis);

template <typename T>
node<T>* _copy_list(node<T>*& dest, node<T>* src);

template <typename T>
void _clear_list(node<T>* &head);

template <typename T>
T& _at(node<T>* head, int pos);

//template <typename T>
//void _sort(node<T>* head);

template <typename T>
node<T>* _where_this_goes(node<T>* head, T item, bool ascending=true);

template <typename T>
node<T>* _insert_sorted(node<T>* &head, T item, bool ascending=true);

template <typename T>
node<T>* _insert_sorted_and_add(node<T>* &head, T item, bool ascending=true);

template <typename T>
node<T>* _last_node(node<T>* head);            //Last Node in the list

//--------- definitions:

template <typename T>
ostream& _print_list(node<T>* head, ostream& outs){
    node<T>* walker = head; //walker points to where head_ptr points
    outs<<"H->";
    // H -> 4 -> 5 -> 7 -> nullptr
    //stop when you get to the end
    while (walker != nullptr){
        outs<<*walker;

        walker = walker->_next;

        // node(item, next_address)      node       node
    }
    outs<<"|||";

    return outs;
}

template <typename T>
ostream& _printList_backwards(node<T> *head, ostream& outs){
    node<T>* walker = head;
    // recursively
    if(walker == nullptr){
        cout << "|||->";
        return outs;
    }
    // printing the list backward, so the end will be the head
    _printList_backwards(walker->_next);
    outs << *walker;

    return outs;
}

template <typename T>
node<T>* _search_list(node<T>* head, const T& item){
    node<T>* walker = head;

    // stop when finding out the item
    while(walker != nullptr){
        if(walker -> _item == item){
            return walker;
        }
        walker = walker -> _next;
    }

    return nullptr;
}


template <typename T>
node<T>* _insert_head(node<T>* &head, const T& item){
    //three steps:
    //1. build a new node
    node<T>* temp = new node<T>(item);
    //2. point the new node's next to where the headptr is pointing to
    temp->_next = head;
    //3. point headptr to this new node
    head = temp;

    return head;
}


template <typename T>
node<T>* _insert_after(node<T>* &head, node<T>* afterThis, T insertThis){
    assert(afterThis != nullptr);

    //1. build a new node containing insertThis
    node<T>* temp = new node<T>(insertThis);
    //2. let the node pointing to the node after afterThis pointer
    temp -> _next = afterThis -> _next;
    //3. let the node afterThis is pointing, points to the inserted node
    afterThis -> _next = temp;
    // return the head
    return head;

}

template <typename T>
node<T>* _insert_before(node<T>* &head, node<T>* beforeThis, T insertThis){
    // if beforeThis == head, then insert_head()
    assert(beforeThis != nullptr);

    node<T>* walker = head;
    if(head == beforeThis){
        _insert_head(head, insertThis);
        head -> _next = beforeThis;
        return head;
    }

//    //1. build a new node containing insert item
//    node<T>* temp = new node<T>(insertThis);

//    //2. find the position we want to insert
//    while(walker->_next != beforeThis){
//        walker = walker -> _next;
//    }

//    //3. let insert item node points to the node that beforeThis is pointing
//    temp -> _next = beforeThis;

//    //4. let the node before the beforeThis points to the inserted item
//    walker -> _next = temp;

//    return head;

    walker = _previous_node(head, beforeThis);
    _insert_after(head, walker, insertThis);
    return head;
}

template <typename T>
node<T>* _insert_back(node<T>* &head, T insertThis){
    if(!head){
        _insert_head(head, insertThis);
        return head;
    }
    _insert_after(head, _last_node(head), insertThis);
    return head;
}

template <typename T>
node<T>* _previous_node(node<T>* head, node<T>* prevToThis){

    if(head == prevToThis){
        return nullptr;
    }
    node<T>* walker = head;
    while(walker -> _next != prevToThis){
        walker = walker -> _next;
    }
    return walker;
}

template <typename T>
T _delete_node(node<T>* &head, node<T>* deleteThis){
    assert(deleteThis != nullptr);

    if(head == deleteThis){
        head = deleteThis -> _next;
        T delete_item = deleteThis -> _item;
        delete deleteThis;
        return delete_item;
    }

    node<T>* prev_node = _previous_node(head, deleteThis);
    node<T>* after_node = deleteThis -> _next;
    prev_node -> _next = after_node;

    T delete_item = deleteThis -> _item;
    delete deleteThis;
    return delete_item;

}

template <typename T>
node<T>* _copy_list(node<T>*& dest, node<T>* src){
    node<T>* walker = src;  // walker go thought src list
    if(dest != nullptr){
        _clear_list(dest);
    }

    if(src == nullptr){
        dest = nullptr;
        return nullptr;
    }

    dest = new node<T>(walker->_item);
    node<T>* temp = dest;  // temp go thru dest list

    while(walker->_next != nullptr){ // assign each element into dest
        // H->1->3->4->5->6->|||
        // H->1->3->4->5->6->|||

        walker = walker->_next;
        temp->_next = new node<T>(walker->_item);
        temp = temp->_next;
    }
    return temp;
}


template <typename T>
void _clear_list(node<T>*& head){
    node<T>* walker = head;
    while(head != nullptr){
        _delete_node(head, walker);
        walker = head;
    }
}

template <typename T>
T& _at(node<T>* head, int pos){
    int count = 1;  // start with 1, to find the position instead of index
    node<T>* walker = head;
    while(count != pos && walker != nullptr){
        count++;
        walker = walker -> _next;
    }
    return walker->_item;
}


template <typename T>
node<T>* _where_this_goes(node<T>* head, T item, bool ascending){
    // if ascending, find the node that is less than item
    // if not ascending, find the node that is greater than item
    if(ascending){
        if(head->_item >= item){
            return nullptr;
        }
        node<T>* walker = head;
        while(walker->_next != nullptr){
            node<T>* temp = walker->_next;
            if(temp->_item >= item){
                return walker;
            }
            walker = walker->_next;
        }
        return walker;
    }else{
        if(head->_item <= item){
            return nullptr;
        }
        node<T>* walker = head;
        while(walker->_next != nullptr){
            node<T>* temp = walker->_next;
            if(temp->_item <= item){
                return walker;
            }
            walker = walker->_next;
        }
        return walker;
    }
}

template <typename T>
node<T>* _insert_sorted(node<T>* &head, T item, bool ascending){
    if(head == nullptr){
        _insert_head(head, item);
        return head;
    }

    if(ascending){
        if(head->_item >= item){
            _insert_before(head, head, item);
            return head;
        }
        node<T>* prev = _where_this_goes(head, item);
        _insert_after(head, prev, item);
        return head;
    }else{
        if(head->_item <= item){
            _insert_before(head, head, item);
            return head;
        }
        node<T>* prev = _where_this_goes(head, item, ascending);
        _insert_after(head, prev, item);
        return head;
    }


}

template <typename T>
node<T>* _insert_sorted_and_add(node<T>* &head, T item, bool ascending){
    node<T>* position = _search_list(head, item);
    if(position){
        position->_item += item;
        return head;
    }else{
        _insert_sorted(head, item, ascending);
        return head;
    }
}


template <typename T>
node<T>* _last_node(node<T>* head){
    node<T>* walker = head;
    if(walker == nullptr){
        return nullptr;
    }
    while(walker->_next != nullptr){
        walker = walker->_next;
    }
    return walker;
}


// ---------- test functions:

void test_linked_list();

void test_wherethisgoes();

template <typename T>
void test_insert(node<T>* &head_ptr);

template <typename T>
void test_delete(node<T>* &head_ptr);

template <typename T>
void test_copy(node<T>* &head_ptr, node<T>* &head2);

template <typename T>
void test_clear(node<T>* &head2);

template <typename T>
void test_find(node<T>* &head_ptr);

template <typename T>
void test_insert_head(node<T>* &head_ptr);




#endif // LINKED_LIST_H
