cmake_minimum_required(VERSION 3.10)

project(stop_thread_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Use -Wall for strict compilation, and -Wextra for even more strict
add_compile_options(-Wall -Wextra)

# Configure the tab size
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftabstop=2")

# Add your source files here
add_executable(${PROJECT_NAME}
  main.cpp
  my_app.cpp
  third_party_library.cpp
)
