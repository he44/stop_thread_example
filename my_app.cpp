#include "my_app.h"

#include <iostream>

MyApp::MyApp() : is_running_(true) {
  third_party_lib_ = new ThirdPartyLibrary();
}

MyApp::~MyApp() { delete third_party_lib_; }

void MyApp::Initialize() { StartThirdPartyLibrary(); }

void MyApp::Shutdown() {
  is_running_ = false;
  StopThirdPartyLibrary();
}

void MyApp::StartThirdPartyLibrary() { third_party_lib_->Start(); }

void MyApp::StopThirdPartyLibrary() { third_party_lib_->Stop(); }

void MyApp::ProcessCommand(const std::string& command) {
  if (command == "help") {
    std::cout << "Available commands: help, whoami, start, stop, quit\n";
  } else if (command == "whoami") {
    std::cout << "You are the user\n";
  } else if (command == "start") {
    StartThirdPartyLibrary();
  } else if (command == "stop") {
    StopThirdPartyLibrary();
  } else if (command == "quit") {
    Shutdown();
  } else {
    std::cout << "Unknown command\n";
  }
}
