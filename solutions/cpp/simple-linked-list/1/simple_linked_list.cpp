#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {
  
  std::size_t List::size() const {
    return current_size;
  }

  void List::push(const int entry) {
    Element* new_node = new Element(entry);
    new_node->next = head;
    head = new_node;
    current_size++;
  }

  int List::pop() {
    if (head == nullptr) {
      throw std::runtime_error("List is empty");
    }
    Element* old_head = head;
    int data = old_head->data;
    head = head->next;
    delete old_head;
    current_size--;
    return data;
  }

  void List::reverse() {
    Element* prev = nullptr;
    Element* current = head;
    while (current != nullptr) {
      Element* next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    head = prev;
  }

  List::~List() {
    while (head != nullptr) {
      pop();
    }
  }
  
}  // namespace simple_linked_list
