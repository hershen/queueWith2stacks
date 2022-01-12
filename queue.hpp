#pragma once

#include <algorithm>
#include <cstddef>
#include <stack>


template <class T>
class Queue {
public:
    std::size_t size() const {
      return std::max(pushStack.size(), popStack.size());
    }

    void push(const T &element) {
      moveStackContentFromTo(popStack, pushStack);
      pushStack.push(element);
    }

    T pop() {
      moveStackContentFromTo(pushStack, popStack);
      const auto returnValue = popStack.top();
      popStack.pop();
      return returnValue;
    }

private:
  std::stack<T> pushStack;
  std::stack<T> popStack;

  void moveStackContentFromTo(std::stack<T> &fromStack, std::stack<T> &toStack) {
    while(!fromStack.empty()) {
      toStack.push(fromStack.top());
      fromStack.pop();
    }
  }
};
