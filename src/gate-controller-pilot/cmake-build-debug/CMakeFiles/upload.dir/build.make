# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2019.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.3.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thinkpad/projects/gate-controller/src/gate-controller-pilot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thinkpad/projects/gate-controller/src/gate-controller-pilot/cmake-build-debug

# Utility rule file for upload.

# Include the progress variables for this target.
include CMakeFiles/upload.dir/progress.make

CMakeFiles/upload:
	avr-objcopy -j .text -j .data -O ihex gate_controller_pilot gate_controller_pilot.hex
	avr-size --mcu=atmega328p -C gate_controller_pilot
	avrdude -p atmega328p -c arduino -U flash:w:gate_controller_pilot.hex:i -b57600 -D -v -P /dev/ttyUSB0 -C /opt/arduino-1.8.9/hardware/tools/avr/etc/avrdude.conf

upload: CMakeFiles/upload
upload: CMakeFiles/upload.dir/build.make

.PHONY : upload

# Rule to build all files generated by this target.
CMakeFiles/upload.dir/build: upload

.PHONY : CMakeFiles/upload.dir/build

CMakeFiles/upload.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/upload.dir/cmake_clean.cmake
.PHONY : CMakeFiles/upload.dir/clean

CMakeFiles/upload.dir/depend:
	cd /home/thinkpad/projects/gate-controller/src/gate-controller-pilot/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thinkpad/projects/gate-controller/src/gate-controller-pilot /home/thinkpad/projects/gate-controller/src/gate-controller-pilot /home/thinkpad/projects/gate-controller/src/gate-controller-pilot/cmake-build-debug /home/thinkpad/projects/gate-controller/src/gate-controller-pilot/cmake-build-debug /home/thinkpad/projects/gate-controller/src/gate-controller-pilot/cmake-build-debug/CMakeFiles/upload.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/upload.dir/depend
