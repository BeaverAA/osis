# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/newboba/Desktop/labs/sp1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/newboba/Desktop/labs/sp1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sp1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sp1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sp1.dir/flags.make

CMakeFiles/sp1.dir/main.cpp.o: CMakeFiles/sp1.dir/flags.make
CMakeFiles/sp1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/newboba/Desktop/labs/sp1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sp1.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sp1.dir/main.cpp.o -c /Users/newboba/Desktop/labs/sp1/main.cpp

CMakeFiles/sp1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sp1.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/newboba/Desktop/labs/sp1/main.cpp > CMakeFiles/sp1.dir/main.cpp.i

CMakeFiles/sp1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sp1.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/newboba/Desktop/labs/sp1/main.cpp -o CMakeFiles/sp1.dir/main.cpp.s

# Object files for target sp1
sp1_OBJECTS = \
"CMakeFiles/sp1.dir/main.cpp.o"

# External object files for target sp1
sp1_EXTERNAL_OBJECTS =

sp1: CMakeFiles/sp1.dir/main.cpp.o
sp1: CMakeFiles/sp1.dir/build.make
sp1: CMakeFiles/sp1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/newboba/Desktop/labs/sp1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sp1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sp1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sp1.dir/build: sp1

.PHONY : CMakeFiles/sp1.dir/build

CMakeFiles/sp1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sp1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sp1.dir/clean

CMakeFiles/sp1.dir/depend:
	cd /Users/newboba/Desktop/labs/sp1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/newboba/Desktop/labs/sp1 /Users/newboba/Desktop/labs/sp1 /Users/newboba/Desktop/labs/sp1/cmake-build-debug /Users/newboba/Desktop/labs/sp1/cmake-build-debug /Users/newboba/Desktop/labs/sp1/cmake-build-debug/CMakeFiles/sp1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sp1.dir/depend

