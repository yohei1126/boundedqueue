#ifndef __bounded_queue_h_
#define __bounded_queue_h_

#include "QueueControl.h"
#include <queue>

template <typename T>
class BoundedQueue {
 private:
  QueueControl &consumer_;
  std::queue<T> q;

 public:
 BoundedQueue(QueueControl& producer, QueueControl& consumer)
   :consumer_(consumer){
    producer.Resume();
    consumer_.Resume();
  }
  void enqueue(const T& item){
    q.push(item);
    consumer_.Resume();
  }
  const T& dequeue(){
    const T& val = q.front();
    q.pop();
    return val;
  }
};

#endif
