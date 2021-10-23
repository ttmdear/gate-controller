cmake_minimum_required(VERSION 3.15)
project(gate_controller_pilot)

set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_CXX_STANDARD 11)

# Arduino
# ------------------
set(ARDUINO_HOME_DIR /opt/arduino-1.8.9)
set(ARDUINO_BOARD_PRO_MINI 1)
set(AVR_PORT /dev/ttyUSB0)

include(arduino-cmake/arduino.cmake)

# Libraries
# ------------------

# VirtualWire
add_library(VirtualWire
    libraries/VirtualWire/VirtualWire.cpp)

include_directories(
    libraries/VirtualWire)

# Target
# ------------------
include_directories(include)

add_executable(gate_controller_pilot
    src/main.cpp)

target_link_libraries(gate_controller_pilot Arduino_Core SPI VirtualWire)
