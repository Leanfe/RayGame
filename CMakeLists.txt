cmake_minimum_required(VERSION 3.24)
project(rayGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Raylib library
find_package(raylib CONFIG REQUIRED)

# Define sources
set(SOURCES
        src/main.cpp
        src/ui/interface/TextField.h src/ui/animations/Animation.h src/ui/animations/TextAnimation.h src/ui/animations/TextAnimation.cpp src/ui/ResizeHelper.h src/ui/interface/Button.cpp src/ui/interface/Button.h src/files/SaveManager.h)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)