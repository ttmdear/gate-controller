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
CMAKE_SOURCE_DIR = "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/gate_controller_board.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gate_controller_board.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gate_controller_board.dir/flags.make

CMakeFiles/gate_controller_board.dir/src/Debug.cpp.o: CMakeFiles/gate_controller_board.dir/flags.make
CMakeFiles/gate_controller_board.dir/src/Debug.cpp.o: ../src/Debug.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gate_controller_board.dir/src/Debug.cpp.o"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gate_controller_board.dir/src/Debug.cpp.o -c "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/src/Debug.cpp"

CMakeFiles/gate_controller_board.dir/src/Debug.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gate_controller_board.dir/src/Debug.cpp.i"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/src/Debug.cpp" > CMakeFiles/gate_controller_board.dir/src/Debug.cpp.i

CMakeFiles/gate_controller_board.dir/src/Debug.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gate_controller_board.dir/src/Debug.cpp.s"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/src/Debug.cpp" -o CMakeFiles/gate_controller_board.dir/src/Debug.cpp.s

CMakeFiles/gate_controller_board.dir/src/main.cpp.o: CMakeFiles/gate_controller_board.dir/flags.make
CMakeFiles/gate_controller_board.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gate_controller_board.dir/src/main.cpp.o"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gate_controller_board.dir/src/main.cpp.o -c "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/src/main.cpp"

CMakeFiles/gate_controller_board.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gate_controller_board.dir/src/main.cpp.i"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/src/main.cpp" > CMakeFiles/gate_controller_board.dir/src/main.cpp.i

CMakeFiles/gate_controller_board.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gate_controller_board.dir/src/main.cpp.s"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/src/main.cpp" -o CMakeFiles/gate_controller_board.dir/src/main.cpp.s

CMakeFiles/gate_controller_board.dir/src/Test.cpp.o: CMakeFiles/gate_controller_board.dir/flags.make
CMakeFiles/gate_controller_board.dir/src/Test.cpp.o: ../src/Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/gate_controller_board.dir/src/Test.cpp.o"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gate_controller_board.dir/src/Test.cpp.o -c "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/src/Test.cpp"

CMakeFiles/gate_controller_board.dir/src/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gate_controller_board.dir/src/Test.cpp.i"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/src/Test.cpp" > CMakeFiles/gate_controller_board.dir/src/Test.cpp.i

CMakeFiles/gate_controller_board.dir/src/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gate_controller_board.dir/src/Test.cpp.s"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/src/Test.cpp" -o CMakeFiles/gate_controller_board.dir/src/Test.cpp.s

CMakeFiles/gate_controller_board.dir/src/RemoteController.cpp.o: CMakeFiles/gate_controller_board.dir/flags.make
CMakeFiles/gate_controller_board.dir/src/RemoteController.cpp.o: ../src/RemoteController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/gate_controller_board.dir/src/RemoteController.cpp.o"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gate_controller_board.dir/src/RemoteController.cpp.o -c "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/src/RemoteController.cpp"

CMakeFiles/gate_controller_board.dir/src/RemoteController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gate_controller_board.dir/src/RemoteController.cpp.i"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/src/RemoteController.cpp" > CMakeFiles/gate_controller_board.dir/src/RemoteController.cpp.i

CMakeFiles/gate_controller_board.dir/src/RemoteController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gate_controller_board.dir/src/RemoteController.cpp.s"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/src/RemoteController.cpp" -o CMakeFiles/gate_controller_board.dir/src/RemoteController.cpp.s

CMakeFiles/gate_controller_board.dir/src/GateController.cpp.o: CMakeFiles/gate_controller_board.dir/flags.make
CMakeFiles/gate_controller_board.dir/src/GateController.cpp.o: ../src/GateController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/gate_controller_board.dir/src/GateController.cpp.o"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gate_controller_board.dir/src/GateController.cpp.o -c "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/src/GateController.cpp"

CMakeFiles/gate_controller_board.dir/src/GateController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gate_controller_board.dir/src/GateController.cpp.i"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/src/GateController.cpp" > CMakeFiles/gate_controller_board.dir/src/GateController.cpp.i

CMakeFiles/gate_controller_board.dir/src/GateController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gate_controller_board.dir/src/GateController.cpp.s"
	/opt/arduino-1.8.9/hardware/tools/avr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/src/GateController.cpp" -o CMakeFiles/gate_controller_board.dir/src/GateController.cpp.s

# Object files for target gate_controller_board
gate_controller_board_OBJECTS = \
"CMakeFiles/gate_controller_board.dir/src/Debug.cpp.o" \
"CMakeFiles/gate_controller_board.dir/src/main.cpp.o" \
"CMakeFiles/gate_controller_board.dir/src/Test.cpp.o" \
"CMakeFiles/gate_controller_board.dir/src/RemoteController.cpp.o" \
"CMakeFiles/gate_controller_board.dir/src/GateController.cpp.o"

# External object files for target gate_controller_board
gate_controller_board_EXTERNAL_OBJECTS =

gate_controller_board: CMakeFiles/gate_controller_board.dir/src/Debug.cpp.o
gate_controller_board: CMakeFiles/gate_controller_board.dir/src/main.cpp.o
gate_controller_board: CMakeFiles/gate_controller_board.dir/src/Test.cpp.o
gate_controller_board: CMakeFiles/gate_controller_board.dir/src/RemoteController.cpp.o
gate_controller_board: CMakeFiles/gate_controller_board.dir/src/GateController.cpp.o
gate_controller_board: CMakeFiles/gate_controller_board.dir/build.make
gate_controller_board: libArduino_Core.a
gate_controller_board: libSPI.a
gate_controller_board: libVirtualWire.a
gate_controller_board: CMakeFiles/gate_controller_board.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable gate_controller_board"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gate_controller_board.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gate_controller_board.dir/build: gate_controller_board

.PHONY : CMakeFiles/gate_controller_board.dir/build

CMakeFiles/gate_controller_board.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gate_controller_board.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gate_controller_board.dir/clean

CMakeFiles/gate_controller_board.dir/depend:
	cd "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board" "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board" "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/cmake-build-debug" "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/cmake-build-debug" "/home/thinkpad/projects/2008 - Sterownik do bramy/src/gate-controller-board/cmake-build-debug/CMakeFiles/gate_controller_board.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/gate_controller_board.dir/depend
