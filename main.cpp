#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <thread>

#include "my_app.h"

int main() {
  MyApp my_app;
  my_app.Initialize();

  while (my_app.IsRunning()) {
    const auto now = std::chrono::system_clock::now();
    const auto now_c = std::chrono::system_clock::to_time_t(now);
    std::cout << "(" << std::put_time(std::localtime(&now_c), "%F %T") << ") ("
              << std::this_thread::get_id() << ") Enter a command: \n";
    std::string command;
    std::getline(std::cin, command);
    my_app.ProcessCommand(command);
  }

  return 0;
}
