# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Users/eovertoo/bin/cmake

# The command to remove a file.
RM = /Users/eovertoo/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/eovertoo/projects-advanced/computerv1cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/eovertoo/projects-advanced/computerv1cmake/build

# Include any dependencies generated for this target.
include test/CMakeFiles/roottest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/roottest.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/roottest.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/roottest.dir/flags.make

test/CMakeFiles/roottest.dir/sqrt_test.cpp.o: test/CMakeFiles/roottest.dir/flags.make
test/CMakeFiles/roottest.dir/sqrt_test.cpp.o: ../test/sqrt_test.cpp
test/CMakeFiles/roottest.dir/sqrt_test.cpp.o: test/CMakeFiles/roottest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/eovertoo/projects-advanced/computerv1cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/roottest.dir/sqrt_test.cpp.o"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/roottest.dir/sqrt_test.cpp.o -MF CMakeFiles/roottest.dir/sqrt_test.cpp.o.d -o CMakeFiles/roottest.dir/sqrt_test.cpp.o -c /Users/eovertoo/projects-advanced/computerv1cmake/test/sqrt_test.cpp

test/CMakeFiles/roottest.dir/sqrt_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roottest.dir/sqrt_test.cpp.i"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/eovertoo/projects-advanced/computerv1cmake/test/sqrt_test.cpp > CMakeFiles/roottest.dir/sqrt_test.cpp.i

test/CMakeFiles/roottest.dir/sqrt_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roottest.dir/sqrt_test.cpp.s"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/eovertoo/projects-advanced/computerv1cmake/test/sqrt_test.cpp -o CMakeFiles/roottest.dir/sqrt_test.cpp.s

# Object files for target roottest
roottest_OBJECTS = \
"CMakeFiles/roottest.dir/sqrt_test.cpp.o"

# External object files for target roottest
roottest_EXTERNAL_OBJECTS =

test/roottest: test/CMakeFiles/roottest.dir/sqrt_test.cpp.o
test/roottest: test/CMakeFiles/roottest.dir/build.make
test/roottest: test/CMakeFiles/roottest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/eovertoo/projects-advanced/computerv1cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable roottest"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/roottest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/roottest.dir/build: test/roottest
.PHONY : test/CMakeFiles/roottest.dir/build

test/CMakeFiles/roottest.dir/clean:
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/test && $(CMAKE_COMMAND) -P CMakeFiles/roottest.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/roottest.dir/clean

test/CMakeFiles/roottest.dir/depend:
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/eovertoo/projects-advanced/computerv1cmake /Users/eovertoo/projects-advanced/computerv1cmake/test /Users/eovertoo/projects-advanced/computerv1cmake/build /Users/eovertoo/projects-advanced/computerv1cmake/build/test /Users/eovertoo/projects-advanced/computerv1cmake/build/test/CMakeFiles/roottest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/roottest.dir/depend

