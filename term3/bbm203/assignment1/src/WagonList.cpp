#include "WagonList.h"

#include <iostream>

WagonList::~WagonList() { clear(); }

void WagonList::clear()
{
    // TODO: Delete all Wagon objects in this list and reset pointers.
    Wagon* curr = rear;
    while(curr){
         Wagon* temp = curr;
         delete temp;
         curr = curr->prev;
    }
    front = rear = nullptr;
}

WagonList::WagonList(WagonList &&other) noexcept
{
    // TODO: Implement move constructor.
    // Transfer ownership of 'other' list’s nodes into this list
    // and leave 'other' in an empty but valid state.
    
    
}

WagonList &WagonList::operator=(WagonList &&other) noexcept
{
    // Operation version of the move constructor.
    // Move constructor creates new object with another objects properties.
    // TODO: Implement it.
    
    
    return *this;
}

Wagon *WagonList::findById(int id)
{
    // TODO: Find and return the Wagon with given ID.
    // Return nullptr if not found.
    
    Wagon* curr = front;
    
    while(curr){
         if (curr->id == id) return curr;
         curr = curr->next;
    }
    return nullptr;
}

void WagonList::addWagonToRear(Wagon *w)
{
    // TODO: Add a Wagon to the rear (end) of the list.
    // This function does not respect the weight order
    // it inserts to end regardless of the weight
    rear->next = w;
    w->prev= rear;
    rear = w;
}

int WagonList::getTotalWeight() const { return totalWeight; }

bool WagonList::isEmpty() const
{
    // TODO: Return true if the list has no wagons.
    if (front) return true;
    return false;
}

void WagonList::insertSorted(Wagon *wagon) // shit as func
{
    // TODO: Insert wagon into this list in descending order of weight.
    totalWeight+=wagon->weight;
    
    if (!front){ // boşsa
         front = rear = wagon;
         front->next = rear;
         rear->prev = front;
    } else if (front == rear){ //tek wagon varsa
         if (wagon->weight < front->weight){
              // front->next = wagon;
              // wagon->prev = front;
              rear = wagon;
         }else{
              front = wagon;
              // front->next = rear;
              // rear->prev = front;
         }
    } else {
         Wagon* curr = front;
         while(curr){
              if(wagon->weight >= curr->weight){
                   wagon->next = curr->next;
                   wagon->prev = curr;
                   curr->next->prev = wagon;
                   curr->next = wagon;
              }else{
                   if (curr == rear){
                        rear->next = wagon;
                        wagon->prev = rear;
                        rear = wagon;
                   }else{
                        curr->next->prev = wagon;
                        wagon->next = curr->next;
                        curr->next = wagon;
                        wagon->prev = curr;
                   }
              }
         }
    }
}

void WagonList::appendList(WagonList &&other)
{
   // TODO: Append another WagonList to this one (merge them).
   // Use move semantics to avoid deep copies. (Double && at the parameter already makes it so)
   // 'other' should end up empty after this operation
   // At merge lists (blocks) will be protected 
   // But the one with heavier wagon at the front will be before the other list
   
}

Wagon *WagonList::detachById(int id)
{
    // TODO: Remove a specific wagon (by ID) from this list and return it.
    // Use: std::cout << "Wagon " << toRemove->id << " detached from Wagon List. " << std::endl;
    // Return nullptr if wagon not found.
    
    Wagon* curr = front;
    while(curr){
         if (curr->id == id){
              curr->prev->next = curr->next;
              curr->next->prev = curr->prev;
              std::cout << "Wagon " << curr->id << " detached from Wagon List. " << std::endl;
              return curr;
         }
         curr = curr->next;
    }
    
    return nullptr;
}


WagonList WagonList::splitAtById(int id)
{
    WagonList newList; // return-by-value (will be moved automatically)

    // TODO: Split this list into two lists at the wagon with given ID.
    // The wagon with 'id' becomes the start of the new list.
    // Return the new WagonList (move return).
    // If 'id' not found, return an empty list.
    
    Wagon* curr = this->front;
    while(curr){
         if (curr->id == id){
              curr
         }
    }

    return newList; // moved, not copied
}

// Print is already implemented
void WagonList::print() const
{

    std::cout << *this << std::endl;
    return;
}

// << operator is already implemented
std::ostream &operator<<(std::ostream &os, const WagonList &list)
{
    if (list.isEmpty())
        return os;

    Wagon *current = list.front;

    while (current)
    {
        os << "W" << current->getID() << "(" << current->getWeight() << "ton)";
        if (current->getNext())
            os << " - ";
        current = current->getNext();
    }
    return os;
}
