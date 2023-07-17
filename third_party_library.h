#ifndef THIRD_PARTY_LIBRARY_H
#define THIRD_PARTY_LIBRARY_H

#include <atomic>
#include <condition_variable>
#include <thread>

// |ThirdPartyLibrary| mimics the behavior of a third-party library that
// performs some sort of work (e.g. communication with a server) on a
// background thread.
// The library is configured so that the users can use |Stop| API to stop the
// background thread and |Start| API to start it again.
class ThirdPartyLibrary {
 private:
  std::thread worker_thread_;
  std::condition_variable cond_var_;
  std::mutex mtx_;
  std::atomic<bool> should_stop_;

  void Worker();
  void DoWork();

 public:
  ThirdPartyLibrary();
  ~ThirdPartyLibrary();

  void Start();
  void Stop();
};

#endif
