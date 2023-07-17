#include "third_party_library.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>

ThirdPartyLibrary::ThirdPartyLibrary() { Start(); }

ThirdPartyLibrary::~ThirdPartyLibrary() { Stop(); }

void ThirdPartyLibrary::Start() {
  if (!worker_thread_.joinable()) {
    should_stop_ = false;
    worker_thread_ = std::thread(&ThirdPartyLibrary::Worker, this);
  } else {
    std::cout << "Worker thread is already running.\n";
  }
}

void ThirdPartyLibrary::Stop() {
  should_stop_ = true;
  cond_var_.notify_all();
  if (worker_thread_.joinable()) {
    worker_thread_.join();
  }
}

void ThirdPartyLibrary::Worker() {
  while (!should_stop_) {
    std::unique_lock<std::mutex> lock(mtx_);
    cond_var_.wait_for(lock, std::chrono::seconds(10));
    if (!should_stop_) {
      DoWork();
    }
  }
}

void ThirdPartyLibrary::DoWork() {
  const auto now = std::chrono::system_clock::now();
  const auto now_c = std::chrono::system_clock::to_time_t(now);
  std::cout << "(" << std::put_time(std::localtime(&now_c), "%F %T") << ") ("
            << std::this_thread::get_id() << ") Working...\n";
}
