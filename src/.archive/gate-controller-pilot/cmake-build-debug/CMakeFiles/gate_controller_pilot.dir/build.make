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

# Include any dependencies generated for this target.
include CMakeFiles/gate_controller_pilot.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gate_controller_pilot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gate_controller_pilot.dir/flags.make

CMakeFiles/gate_controller_pilot.dir/src/main.cpp.o: CMakeFiles/gate_controller_pilot.dir/flags.make
CMakeFiles/gate_controller_pilot.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thinkpad/projects/gate-controller/src/gate-controller-pilot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gate_controller_pilot.dir/src/main.cpp.o"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gate_controller_pilot.dir/src/main.cpp.o -c /home/thinkpad/projects/gate-controller/src/gate-controller-pilot/src/main.cpp

CMakeFiles/gate_controller_pilot.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gate_controller_pilot.dir/src/main.cpp.i"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thinkpad/projects/gate-controller/src/gate-controller-pilot/src/main.cpp > CMakeFiles/gate_controller_pilot.dir/src/main.cpp.i

CMakeFiles/gate_controller_pilot.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gate_controller_pilot.dir/src/main.cpp.s"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thinkpad/projects/gate-controller/src/gate-controller-pilot/src/main.cpp -o CMakeFiles/gate_controller_pilot.dir/src/main.cpp.s

# Object files for target gate_controller_pilot
gate_controller_pilot_OBJECTS = \
"CMakeFiles/gate_controller_pilot.dir/src/main.cpp.o"

# External object files for target gate_controller_pilot
gate_controller_pilot_EXTERNAL_OBJECTS =

gate_controller_pilot: CMakeFiles/gate_controller_pilot.dir/src/main.cpp.o
gate_controller_pilot: CMakeFiles/gate_controller_pilot.dir/build.make
gate_controller_pilot: libArduino_Core.a
gate_controller_pilot: libSPI.a
gate_controller_pilot: libVirtualWire.a
gate_controller_pilot: CMakeFiles/gate_controller_pilot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thinkpad/projects/gate-controller/src/gate-controller-pilot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gate_controller_pilot"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gate_controller_pilot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gate_controller_pilot.dir/build: gate_controller_pilot

.PHONY : CMakeFiles/gate_controller_pilot.dir/build

CMakeFiles/gate_controller_pilot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gate_controller_pilot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gate_controller_pilot.dir/clean

CMakeFiles/gate_controller_pilot.dir/depend:
	cd /home/thinkpad/projects/gate-controller/src/gate-controller-pilot/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thinkpad/projects/gate-controller/src/gate-controller-pilot /home/thinkpad/projects/gate-controller/src/gate-controller-pilot /home/thinkpad/projects/gate-controller/src/gate-controller-pilot/cmake-build-debug /home/thinkpad/projects/gate-controller/src/gate-controller-pilot/cmake-build-debug /home/thinkpad/projects/gate-controller/src/gate-controller-pilot/cmake-build-debug/CMakeFiles/gate_controller_pilot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gate_controller_pilot.dir/depend

