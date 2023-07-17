#ifndef MYAPP_H
#define MYAPP_H

#include <atomic>
#include <string>

#include "third_party_library.h"

class MyApp {
 private:
  ThirdPartyLibrary* third_party_lib_;
  std::atomic<bool> is_running_;

 public:
  MyApp();
  ~MyApp();

  void Initialize();
  void Shutdown();
  void StartThirdPartyLibrary();
  void StopThirdPartyLibrary();

  void ProcessCommand(const std::string& command);

  bool IsRunning() const { return is_running_; }
};

#endif
