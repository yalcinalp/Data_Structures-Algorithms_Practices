#include "LinkedIntList.h"

#include <iostream>

using namespace std;

LinkedIntList::~LinkedIntList() {
    while (front)
        remove();
}

LinkedIntList::LinkedIntList(const LinkedIntList &rhs) {
    front = NULL;
    *this = rhs; // use the assignment operator =
}

LinkedIntList &LinkedIntList::operator=(const LinkedIntList rhs) {
    if (this != &rhs) {
        while (front)
            remove();
        ListNode *r = rhs.front;

        while (r) {
            add(r->data);
            r = r->next;
        }
    }
    return *this;
}

void LinkedIntList::add(int value) {
    if (front == NULL) {
        // adding to an empty list
        front = new ListNode(value);
    } else {
        // adding to the end of an existing list
        ListNode *current = front;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new ListNode(value);
    }
}

void LinkedIntList::add(int index, int value) {
    if (index == 0) {
        // adding to an empty list
        front = new ListNode(value, front);
    } else {
        // inserting into an existing list
        ListNode *current = front;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        current->next = new ListNode(value, current->next);
    }
}

void LinkedIntList::addSorted(int value) {
    ListNode *current;
    if (front == NULL || front->data >= value) {
        // adding to an empty list
        front = new ListNode(value, front);
    } else {
        current = front;
        while (current->next && current->next->data < value) {
            current = current->next;
        }
        current->next = new ListNode(value, current->next);
    }
}


int LinkedIntList::get(int index) {
    ListNode *current = front;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

int LinkedIntList::remove() {
    if (front == NULL) {
        throw NoSuchElementException();
    } else {
        int result = front->data;
        ListNode *tmp = front;
        front = front->next;
        delete tmp;
        return result;
    }
}

void LinkedIntList::remove(int index) {
    if (index == 0) {
        // special case: removing first element
        ListNode *tmp = front;
        front = front->next;
        delete tmp;
    } else {
        // removing from elsewhere in the list
        ListNode *current = front;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        ListNode *tmp = current->next;
        current->next = current->next->next;
        delete tmp;
    }
}

void LinkedIntList::print() {
    cout << "[ ";
    ListNode *current = front;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "]" << endl;
}

// Write a method called "set" that accepts an index and a value and
// sets the list’s element at that index to have the given value.
// You may assume that the index is between 0 (inclusive) and the size of the list (exclusive).
void LinkedIntList::set(int index, int value) {
    /* TODO */
    
    // what if the linked list is empty? //NO NEED TO CONSİDER THİS SINCE WE HAVE THE INDEX VALID 
    
    ListNode *current = front;
    for (int i = 0; i < index; i++) {
            current = current->next;
        }
        
    // After the for loop we are on the desired index
    current->data = value;
    
}

// Write a method called "min" that returns the minimum value in a list of integers.
// If the list is empty, it should throw a NoSuchElementException.
int LinkedIntList::min() {
    /* TODO */
    
    if(front == NULL){
        throw NoSuchElementException();
    }
    
    else{
        
        int temp_min = front->data;
    
        ListNode *current = front;
        
        while (current != NULL) {
            
            if(temp_min > current->data){
            
                temp_min = current->data;
            }
        
            current = current->next;
        }
        
        return temp_min;
        
    }

    
    
}

// Write a method called "lastIndexOf" that accepts an integer value as a parameter and
// that returns the index in the list of the last occurrence of that value or -1 if the value is not found in the list.
// For example if a variable list stores values [1, 18, 2, 7, 18, 39, 18, 40] then the call of list.lastIndexOf(18)
// should return 6. If the call instead is list.lastIndexOf(3), the method returns -1.
int LinkedIntList::lastIndexOf(int value) {
    /* TODO */
    
    int last_place;
    int index = 0;
    int flag = 0;
    
    ListNode *current = front;
    
    while (current != NULL) {
            
            if(current->data == value){
            
                last_place = index;
                flag = 1;
            }
        
            current = current->next;
            index++;
        }
    
    if(flag == 1){
        
        return last_place;
    }
    
    else{
        return -1;
    }
    
    
}

// Write a method called "deleteBack" that deletes the last value (the value at the back of the list) and
// returns the deleted value. If the list is empty, throw a NoSuchElementException.
int LinkedIntList::deleteBack() {
    /* TODO */
    
    int deleted_val;
    
    //If Linked List is empty:
    if(front == NULL){
        throw NoSuchElementException();
    }
    
    //If Linked List contains 1 element:
    else if(front->next == NULL){
        deleted_val = front->data;
        delete front;
        front = NULL;
        return deleted_val;
    }
    
    //If there are more than 2 or more elementns
    else{
        
        ListNode *current = front;
        
        while(current->next->next != NULL){
            current = current->next;
        }
        
        
        deleted_val = current->next->data;        
        ListNode *tmp = current->next; //last node

        current->next = NULL;
        
        delete tmp; //deleted last node 

        return deleted_val;
    }
        
    
}

// Write a method called "removeAdjacentDuplicates" that remove adjacent duplicate elements
// on the linked list.
// For example if list is currently [18, 7, 7, 7, 4, 4, 24, 11, 11]
// then it becomes [18, 7, 4, 24, 11]
void LinkedIntList::removeAdjacentDuplicates() {
    /* TODO */
    
    ListNode *current = front;
    
    while(current != NULL){
        
        if(current->next != NULL && current->data == current->next->data){
            
            ListNode *tmp = current->next;
            
            current->next = current->next->next;
            
            delete tmp;
            
        }
        
        else{
            
            current = current->next;
        }
    }
    
    
}

// Write a method called "removeAll" that removes all occurrences of a particular value.
// For example if a variable list stores the values [3, 9, 4, 2, 3, 8, 17, 4, 3, 18], the call list.removeAll(3);
// would change the list to store [9, 4, 2, 8, 17, 4, 18].
void LinkedIntList::removeAll(int value) {
    /* TODO */
    
    ListNode *current = front;
    
    while(current != NULL && current->data == value){
        
        ListNode *tmp2 = current;
        front = front->next;
        current = current->next; 
        delete tmp2;
        
    }
    
    while(current != NULL){
        
        if(current->next != NULL && current->next->data == value){
             
            ListNode *tmp = current->next;
            
            current->next = current->next->next;
            
            delete tmp;
            
         }
        
        else{
            
            current = current->next;
        }
         
        
    }
    
}

// Write a method called "equals" that accepts a second list as a parameter,
// returns true if the two lists are equal, and returns false otherwise.
// Two lists are considered equal if they store exactly the same values in exactly the same order and
// have exactly the same length.
bool LinkedIntList::equals(const LinkedIntList &L) {
    /* TODO */

     ListNode *current = front;
     ListNode *current2 = L.front;
     
     int flag = 0; 
     
     while(current != NULL && current2 != NULL){
         
         if(current->data != current2->data){
            flag = 1;
            break;
         }
         
         else{
            current = current -> next;
            current2 = current2 -> next;     
         }
         
     }
     
     if(current == NULL && current2 == NULL){
         return true;
     }
     
     else{
         return false;
     }
    
}

// Write a method called "invert" that inverts the linked list.
// For example if list is currently [4, 5, 9, 22, 8, 33]
// then it becomes [33, 8, 22, 9, 5, 4]
void LinkedIntList::invert() {
    /* TODO */
    
    //taking the size
    
    ListNode *current = front;
    int size = 0;
    
    while(current != NULL){
        current = current->next;
        size++;
    }
    
    int *my_arr = new int [size];
    ListNode *current2 = front;
    int i = 0;
    
    while(current2 != NULL){
        
        my_arr[i] = current2->data;
        current2 = current2->next;
        
        i++;
        
    }
    
    ListNode *current3 = front;
    
    for(int j=size-1; j > -1; j--){
        
        current3->data = my_arr[j];
        current3 = current3->next;
    }
    
    delete[] my_arr;
    
}

// Write a method called "numberOfOccurences" that accepts an integer value as parameter.
// This method returns number of occurences of a value in the list.
// For example if a variable list stores the values [5, 5, 5, 10, 15, 5], the call list.numberOfOccurences(5);
// would return 4.  
int LinkedIntList::numberOfOccurences(int value) {
    /* TODO */
    int counter = 0;
    ListNode *current = front;
    
    while(current != NULL){
        
        if(current->data == value){
            counter++;
        }
        
        current = current->next;
    }
    
    return counter;
    
    
}

// Write a method called "isSorted" that do not accept any parameter.
// This method returns true if the list is sorted; it returns false if the list is unsorted.
// For example if a variable list stores the values [5, 5, 5, 10, 15, 5], the call list.isSorted();
// would return false
// For example if a variable list stores the values [5, 5, 5, 10, 15], the call list.isSorted();
// would return true
bool LinkedIntList::isSorted() {
    /* TODO */
    
    int flag = 0;
    ListNode *current = front;
    
    while(current->next != NULL){
        
        if(current->data <= current->next->data){
        
            current = current->next;
            
        }
        
        else{
            
            flag = 1;
            break;
        }
        
    }
    
    if(flag == 0){
        
        return true;
    }
    
    else{
        
        return false;
    }
    
}
