cmake_minimum_required(VERSION 3.20)
project(gate_controller_board)
enable_language(ASM)

set(CMAKE_SYSTEM_NAME Generic)
set(PROFILE_ATMEGA_328P_16MHz 1)
set(PROFILE_PROGRAMMER_ARDUINO 1)

# set(CMAKE_CXX_STANDARD 11)

# Arduino
# - - - - - - - - - - - - - - - - - - - - -
set(ARDUINO_HOME_DIR /opt/arduino-1.8.16)
set(AVR_PORT /dev/ttyUSB0)

include(arduino-cmake/arduino.cmake)

add_executable(gate_controller_board
    src/main.cpp
    lib/VirtualWire/VirtualWire.cpp
)

target_link_libraries(gate_controller_board Arduino_Core)

target_include_directories(gate_controller_board PUBLIC ./include ./lib/VirtualWire)