if (DEFINED ARDUINO_BOARD_UNO)
    set(AVR_PROGRAMMER avrisp)
    set(AVR_PARTNO atmega328p)
elseif (DEFINED ARDUINO_BOARD_PRO_MINI)
    set(AVR_PROGRAMMER arduino)
    set(AVR_PARTNO atmega328p)
endif ()

if (NOT DEFINED AVR_PROGRAMMER)
    message(SEND_ERROR "AVR_PROGRAMMER is not set")
endif ()

if (NOT DEFINED AVR_PARTNO)
    message(SEND_ERROR "AVR_PARTNO is not set")
endif ()

if (NOT DEFINED ARDUINO_HOME_DIR)
    set(ARDUINO_HOME_DIR /opt/arduino-1.8.9)
endif ()

if (NOT DEFINED AVR_PORT)
    set(AVR_PORT /dev/ttyACM0)
endif()

set(ARDUINO_CORE ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino)
set(AVR_BIN ${ARDUINO_HOME_DIR}/hardware/tools/avr/bin)
set(AVR_INCLUDE ${ARDUINO_HOME_DIR}/hardware/tools/avr/avr/include/avr)

include_directories(
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/variants/standard
)

# # Compiler/Linker
# message("CMAKE_C_LINK_EXECUTABLE: ${CMAKE_C_LINK_EXECUTABLE}")
# message("CMAKE_C_ARCHIVE_FINISH: ${CMAKE_C_ARCHIVE_FINISH}")
# message("CMAKE_CXX_LINK_EXECUTABLE: ${CMAKE_CXX_LINK_EXECUTABLE}")
# message("CMAKE_CXX_ARCHIVE_FINISH: ${CMAKE_CXX_ARCHIVE_FINISH}")

set(ARDUINO_FLAGS "-DARDUINO=10809 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR")

# C
set(CMAKE_C_COMPILER ${AVR_BIN}/avr-gcc)
set(CMAKE_C_FLAGS "-g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L ${ARDUINO_FLAGS}")
set(CMAKE_C_LINK_EXECUTABLE "${ARDUINO_HOME_DIR}/hardware/tools/avr/bin/avr-gcc -Wall -Wextra -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> rcs <TARGET> <LINK_FLAGS> <OBJECTS>")
set(CMAKE_C_ARCHIVE_FINISH true)

# C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER "${AVR_BIN}/avr-g++")
set(CMAKE_CXX_FLAGS "-g -Os -Wall -Wextra -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L ${ARDUINO_FLAGS} -D__cplusplus")
set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_C_LINK_EXECUTABLE}")
set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> rcs <TARGET> <LINK_FLAGS> <OBJECTS>")
set(CMAKE_CXX_ARCHIVE_FINISH true)

# set(CMAKE_RANLIB "")
set(CMAKE_AR ${ARDUINO_HOME_DIR}/hardware/tools/avr/bin/avr-gcc-ar)

if (DEFINED ARDUINO_BOARD_UNO)
    add_custom_target(upload
        COMMAND avr-objcopy -j .text -j .data -O ihex ${PROJECT_NAME} ${PROJECT_NAME}.hex
        COMMAND avr-size --mcu=atmega328p -C ${PROJECT_NAME}
        COMMAND avrdude -p ${AVR_PARTNO} -c ${AVR_PROGRAMMER} -U flash:w:${PROJECT_NAME}.hex:i -F -P ${AVR_PORT} -C "${ARDUINO_HOME_DIR}/hardware/tools/avr/etc/avrdude.conf"
        VERBATIM)
elseif (DEFINED ARDUINO_BOARD_PRO_MINI)
    add_custom_target(upload
        COMMAND avr-objcopy -j .text -j .data -O ihex ${PROJECT_NAME} ${PROJECT_NAME}.hex
        COMMAND avr-size --mcu=atmega328p -C ${PROJECT_NAME}
        COMMAND avrdude -p ${AVR_PARTNO} -c ${AVR_PROGRAMMER} -U flash:w:${PROJECT_NAME}.hex:i -b57600 -D -v -P ${AVR_PORT} -C "${ARDUINO_HOME_DIR}/hardware/tools/avr/etc/avrdude.conf"
        VERBATIM)
endif()

add_dependencies(upload ${PROJECT_NAME})

add_library(Arduino_Core
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/hooks.c
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/WInterrupts.c
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/wiring_pulse.c
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/wiring.c
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/wiring_shift.c
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/wiring_analog.c
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/wiring_digital.c
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/CDC.cpp
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/HardwareSerial3.cpp
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/IPAddress.cpp
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/Print.cpp
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/PluggableUSB.cpp
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/HardwareSerial.cpp
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/HardwareSerial2.cpp
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/Stream.cpp
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/HardwareSerial1.cpp
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/abi.cpp
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/WString.cpp
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/Tone.cpp
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/new.cpp
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/main.cpp
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/HardwareSerial0.cpp
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/WMath.cpp
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/cores/arduino/USBCore.cpp
)

add_library(SPI
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/libraries/SPI/src/SPI.cpp)

include_directories(
    ${ARDUINO_HOME_DIR}/hardware/arduino/avr/libraries/SPI/src)
