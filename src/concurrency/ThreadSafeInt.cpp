#include "concurrency/ThreadSafeInt.h"
#include "concurrency/PrintThreadSafe.h"

void ThreadSafeInt::readInt() {
  std::unique_lock<std::mutex> lock(mtx);
  writer_cv.wait(lock, [this] { return !writerActive; });

  readersCount++;
  lock.unlock();

  PrintThreadSafe::print("Read: ", data);

  lock.lock();
  readersCount--;

  if (readersCount == 0) {
    reader_cv.notify_all();
  }
}

void ThreadSafeInt::writeInt(int newValue) {
  std::unique_lock<std::mutex> lock(mtx);
  reader_cv.wait(lock, [this] { return readersCount == 0 && !writerActive; });

  writerActive = true;
  lock.unlock();

  data = newValue;
  PrintThreadSafe::print("Write: ", newValue);

  writerActive = false;
  reader_cv.notify_all();
  writer_cv.notify_all();
}
