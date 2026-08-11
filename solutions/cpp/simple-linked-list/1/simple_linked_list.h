#ifndef VT_SIMPLE_LINKED_LIST_H
#define VT_SIMPLE_LINKED_LIST_H

#include <cstddef>
#include <vector>

namespace simple_linked_list {
class List {
public:
  List() = default;
  ~List();
  
  // Moving and copying is not needed to solve the exercise.
  // If you want to change these, make sure to correctly
  // free / move / copy the allocated resources.
  List(List const&) = delete;
  List& operator=(List const&) = delete;
  List(List&&) = delete;
  List& operator=(List&&) = delete;
  
  std::size_t size() const;
  void push(const int entry);
  int pop();
  void reverse();
  
private:
  struct Element {
    Element(const int data) : data{data} {}
    int data{};
    Element* next{nullptr};
  };

  Element* head{nullptr};
  std::size_t current_size{0};
};

}  // namespace simple_linked_list

#endif
