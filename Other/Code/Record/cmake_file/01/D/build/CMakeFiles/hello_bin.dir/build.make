# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/g/cmake_file/01/D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/g/cmake_file/01/D/build

# Include any dependencies generated for this target.
include CMakeFiles/hello_bin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hello_bin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello_bin.dir/flags.make

CMakeFiles/hello_bin.dir/src/main.cpp.o: CMakeFiles/hello_bin.dir/flags.make
CMakeFiles/hello_bin.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g/cmake_file/01/D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hello_bin.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hello_bin.dir/src/main.cpp.o -c /mnt/g/cmake_file/01/D/src/main.cpp

CMakeFiles/hello_bin.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello_bin.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/cmake_file/01/D/src/main.cpp > CMakeFiles/hello_bin.dir/src/main.cpp.i

CMakeFiles/hello_bin.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello_bin.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/cmake_file/01/D/src/main.cpp -o CMakeFiles/hello_bin.dir/src/main.cpp.s

# Object files for target hello_bin
hello_bin_OBJECTS = \
"CMakeFiles/hello_bin.dir/src/main.cpp.o"

# External object files for target hello_bin
hello_bin_EXTERNAL_OBJECTS =

hello_bin: CMakeFiles/hello_bin.dir/src/main.cpp.o
hello_bin: CMakeFiles/hello_bin.dir/build.make
hello_bin: libhello_shared.so
hello_bin: CMakeFiles/hello_bin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/g/cmake_file/01/D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hello_bin"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello_bin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello_bin.dir/build: hello_bin

.PHONY : CMakeFiles/hello_bin.dir/build

CMakeFiles/hello_bin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello_bin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello_bin.dir/clean

CMakeFiles/hello_bin.dir/depend:
	cd /mnt/g/cmake_file/01/D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/g/cmake_file/01/D /mnt/g/cmake_file/01/D /mnt/g/cmake_file/01/D/build /mnt/g/cmake_file/01/D/build /mnt/g/cmake_file/01/D/build/CMakeFiles/hello_bin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello_bin.dir/depend
