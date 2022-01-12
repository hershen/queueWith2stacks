#include <queue.hpp>

#include <cassert>

int main() {
  // push a series of numbers, then pop the whole content of the queue
  {
    Queue<int> queue;

    assert(queue.size() == 0);

    for(int i=0; i<10; ++i) {
      queue.push(i);
      assert(queue.size() == i+1);
    } 
    //queue no holds {9,8,7,6,5,4,3,2,1,0}
    
    for(int expected=0; expected<10; ++expected) {
      const auto element = queue.pop();
      assert(element == expected);
      assert(queue.size() == 9-expected);
    }
  }
  
  // push a series of numbers, pop several of them, push a few more, then pop the whole content of the queue
  {
    Queue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    //queue now holds {5,4,3,2,1}
    assert(queue.size() == 5);

    queue.pop();
    queue.pop();
    //queue now holds {5,4,3}
    assert(queue.size() == 3);

    queue.push(6);
    queue.push(7);
    queue.push(8);
    //queue now holds {8,7,6,5,4,3}
    assert(queue.size() == 6);
    
    for(int expected=3; expected<=8; ++expected) {
      const auto element = queue.pop();
      assert(element == expected);
    }

    assert(queue.size() == 0);
  }
}
