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
include src/CMakeFiles/computor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/computor.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/computor.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/computor.dir/flags.make

src/CMakeFiles/computor.dir/main.cpp.o: src/CMakeFiles/computor.dir/flags.make
src/CMakeFiles/computor.dir/main.cpp.o: ../src/main.cpp
src/CMakeFiles/computor.dir/main.cpp.o: src/CMakeFiles/computor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/eovertoo/projects-advanced/computerv1cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/computor.dir/main.cpp.o"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/computor.dir/main.cpp.o -MF CMakeFiles/computor.dir/main.cpp.o.d -o CMakeFiles/computor.dir/main.cpp.o -c /Users/eovertoo/projects-advanced/computerv1cmake/src/main.cpp

src/CMakeFiles/computor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/computor.dir/main.cpp.i"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/eovertoo/projects-advanced/computerv1cmake/src/main.cpp > CMakeFiles/computor.dir/main.cpp.i

src/CMakeFiles/computor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/computor.dir/main.cpp.s"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/eovertoo/projects-advanced/computerv1cmake/src/main.cpp -o CMakeFiles/computor.dir/main.cpp.s

src/CMakeFiles/computor.dir/polynomial.cpp.o: src/CMakeFiles/computor.dir/flags.make
src/CMakeFiles/computor.dir/polynomial.cpp.o: ../src/polynomial.cpp
src/CMakeFiles/computor.dir/polynomial.cpp.o: src/CMakeFiles/computor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/eovertoo/projects-advanced/computerv1cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/computor.dir/polynomial.cpp.o"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/computor.dir/polynomial.cpp.o -MF CMakeFiles/computor.dir/polynomial.cpp.o.d -o CMakeFiles/computor.dir/polynomial.cpp.o -c /Users/eovertoo/projects-advanced/computerv1cmake/src/polynomial.cpp

src/CMakeFiles/computor.dir/polynomial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/computor.dir/polynomial.cpp.i"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/eovertoo/projects-advanced/computerv1cmake/src/polynomial.cpp > CMakeFiles/computor.dir/polynomial.cpp.i

src/CMakeFiles/computor.dir/polynomial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/computor.dir/polynomial.cpp.s"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/eovertoo/projects-advanced/computerv1cmake/src/polynomial.cpp -o CMakeFiles/computor.dir/polynomial.cpp.s

src/CMakeFiles/computor.dir/utils.cpp.o: src/CMakeFiles/computor.dir/flags.make
src/CMakeFiles/computor.dir/utils.cpp.o: ../src/utils.cpp
src/CMakeFiles/computor.dir/utils.cpp.o: src/CMakeFiles/computor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/eovertoo/projects-advanced/computerv1cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/computor.dir/utils.cpp.o"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/computor.dir/utils.cpp.o -MF CMakeFiles/computor.dir/utils.cpp.o.d -o CMakeFiles/computor.dir/utils.cpp.o -c /Users/eovertoo/projects-advanced/computerv1cmake/src/utils.cpp

src/CMakeFiles/computor.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/computor.dir/utils.cpp.i"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/eovertoo/projects-advanced/computerv1cmake/src/utils.cpp > CMakeFiles/computor.dir/utils.cpp.i

src/CMakeFiles/computor.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/computor.dir/utils.cpp.s"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/eovertoo/projects-advanced/computerv1cmake/src/utils.cpp -o CMakeFiles/computor.dir/utils.cpp.s

src/CMakeFiles/computor.dir/validate.cpp.o: src/CMakeFiles/computor.dir/flags.make
src/CMakeFiles/computor.dir/validate.cpp.o: ../src/validate.cpp
src/CMakeFiles/computor.dir/validate.cpp.o: src/CMakeFiles/computor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/eovertoo/projects-advanced/computerv1cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/computor.dir/validate.cpp.o"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/computor.dir/validate.cpp.o -MF CMakeFiles/computor.dir/validate.cpp.o.d -o CMakeFiles/computor.dir/validate.cpp.o -c /Users/eovertoo/projects-advanced/computerv1cmake/src/validate.cpp

src/CMakeFiles/computor.dir/validate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/computor.dir/validate.cpp.i"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/eovertoo/projects-advanced/computerv1cmake/src/validate.cpp > CMakeFiles/computor.dir/validate.cpp.i

src/CMakeFiles/computor.dir/validate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/computor.dir/validate.cpp.s"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/eovertoo/projects-advanced/computerv1cmake/src/validate.cpp -o CMakeFiles/computor.dir/validate.cpp.s

# Object files for target computor
computor_OBJECTS = \
"CMakeFiles/computor.dir/main.cpp.o" \
"CMakeFiles/computor.dir/polynomial.cpp.o" \
"CMakeFiles/computor.dir/utils.cpp.o" \
"CMakeFiles/computor.dir/validate.cpp.o"

# External object files for target computor
computor_EXTERNAL_OBJECTS =

src/computor: src/CMakeFiles/computor.dir/main.cpp.o
src/computor: src/CMakeFiles/computor.dir/polynomial.cpp.o
src/computor: src/CMakeFiles/computor.dir/utils.cpp.o
src/computor: src/CMakeFiles/computor.dir/validate.cpp.o
src/computor: src/CMakeFiles/computor.dir/build.make
src/computor: src/CMakeFiles/computor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/eovertoo/projects-advanced/computerv1cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable computor"
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/computor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/computor.dir/build: src/computor
.PHONY : src/CMakeFiles/computor.dir/build

src/CMakeFiles/computor.dir/clean:
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build/src && $(CMAKE_COMMAND) -P CMakeFiles/computor.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/computor.dir/clean

src/CMakeFiles/computor.dir/depend:
	cd /Users/eovertoo/projects-advanced/computerv1cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/eovertoo/projects-advanced/computerv1cmake /Users/eovertoo/projects-advanced/computerv1cmake/src /Users/eovertoo/projects-advanced/computerv1cmake/build /Users/eovertoo/projects-advanced/computerv1cmake/build/src /Users/eovertoo/projects-advanced/computerv1cmake/build/src/CMakeFiles/computor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/computor.dir/depend
