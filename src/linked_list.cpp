#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (front_ == nullptr) {
      return;
    }
    Node* previous = nullptr;
    Node* current = front_;
    Node* next = front_->next;
    for (int i = 0; i < size_;i++){
      current->next = previous;
      previous = current;
      current = next;
      if (next != nullptr) {
        next = next->next;
      }
    }
    back_ = front_;
    front_ = previous;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (front_ == nullptr) {
      return;
    }
    reverse_recursive_helper(front_, nullptr);
    Node* elem = front_;
    front_ = back_;
    back_ = elem;
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr->next != nullptr) {
      reverse_recursive_helper(curr->next, curr);
    }
    curr->next = prev;
  }



}
