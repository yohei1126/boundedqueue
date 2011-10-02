#ifndef __bounded_queue_h_
#define __bounded_queue_h_

#include "QueueControl.h"
#include <queue>

template <typename T>
class BoundedQueue {
 private:
  QueueControl &producer_;
  QueueControl &consumer_;
  std::queue<T> q;
  size_t max_size;

 public:
 BoundedQueue(QueueControl& producer, QueueControl& consumer, size_t size = 100)
   :producer_(producer), consumer_(consumer), max_size(size){
    producer.Resume();
    consumer.Resume();
  }
  void enqueue(const T& item){
    q.push(item);
    if (q.size() == 1 ) {
      consumer_.Resume();
    }
    if (q.size() == max_size) {
      producer_.Pause();
    }
  }
  const T& dequeue(){
    const T& item = q.front();
    q.pop();
    if (q.size() == 0){
      consumer_.Pause();
    }
    return item;
  }
};

#endif
