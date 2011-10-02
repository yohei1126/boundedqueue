#ifndef __bounded_queue_h_
#define __bounded_queue_h_

#include "QueueControl.h"

template <typename T>
class BoundedQueue {
 private:
  QueueControl &consumer_;

 public:
 BoundedQueue(QueueControl& producer, QueueControl& consumer)
   :consumer_(consumer){
    producer.Resume();
    consumer_.Resume();
  }
  void enqueue(const T& item){
    consumer_.Resume();
  }
};

#endif
