# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois

# Include any dependencies generated for this target.
include CMakeFiles/rshell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rshell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rshell.dir/flags.make

CMakeFiles/rshell.dir/src/main.o: CMakeFiles/rshell.dir/flags.make
CMakeFiles/rshell.dir/src/main.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rshell.dir/src/main.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rshell.dir/src/main.o -c /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/main.cpp

CMakeFiles/rshell.dir/src/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rshell.dir/src/main.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/main.cpp > CMakeFiles/rshell.dir/src/main.i

CMakeFiles/rshell.dir/src/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rshell.dir/src/main.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/main.cpp -o CMakeFiles/rshell.dir/src/main.s

CMakeFiles/rshell.dir/src/main.o.requires:

.PHONY : CMakeFiles/rshell.dir/src/main.o.requires

CMakeFiles/rshell.dir/src/main.o.provides: CMakeFiles/rshell.dir/src/main.o.requires
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/main.o.provides.build
.PHONY : CMakeFiles/rshell.dir/src/main.o.provides

CMakeFiles/rshell.dir/src/main.o.provides.build: CMakeFiles/rshell.dir/src/main.o


CMakeFiles/rshell.dir/src/command.o: CMakeFiles/rshell.dir/flags.make
CMakeFiles/rshell.dir/src/command.o: src/command.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rshell.dir/src/command.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rshell.dir/src/command.o -c /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/command.cpp

CMakeFiles/rshell.dir/src/command.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rshell.dir/src/command.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/command.cpp > CMakeFiles/rshell.dir/src/command.i

CMakeFiles/rshell.dir/src/command.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rshell.dir/src/command.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/command.cpp -o CMakeFiles/rshell.dir/src/command.s

CMakeFiles/rshell.dir/src/command.o.requires:

.PHONY : CMakeFiles/rshell.dir/src/command.o.requires

CMakeFiles/rshell.dir/src/command.o.provides: CMakeFiles/rshell.dir/src/command.o.requires
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/command.o.provides.build
.PHONY : CMakeFiles/rshell.dir/src/command.o.provides

CMakeFiles/rshell.dir/src/command.o.provides.build: CMakeFiles/rshell.dir/src/command.o


CMakeFiles/rshell.dir/src/shell.o: CMakeFiles/rshell.dir/flags.make
CMakeFiles/rshell.dir/src/shell.o: src/shell.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/rshell.dir/src/shell.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rshell.dir/src/shell.o -c /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/shell.cpp

CMakeFiles/rshell.dir/src/shell.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rshell.dir/src/shell.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/shell.cpp > CMakeFiles/rshell.dir/src/shell.i

CMakeFiles/rshell.dir/src/shell.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rshell.dir/src/shell.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/shell.cpp -o CMakeFiles/rshell.dir/src/shell.s

CMakeFiles/rshell.dir/src/shell.o.requires:

.PHONY : CMakeFiles/rshell.dir/src/shell.o.requires

CMakeFiles/rshell.dir/src/shell.o.provides: CMakeFiles/rshell.dir/src/shell.o.requires
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/shell.o.provides.build
.PHONY : CMakeFiles/rshell.dir/src/shell.o.provides

CMakeFiles/rshell.dir/src/shell.o.provides.build: CMakeFiles/rshell.dir/src/shell.o


CMakeFiles/rshell.dir/src/and.o: CMakeFiles/rshell.dir/flags.make
CMakeFiles/rshell.dir/src/and.o: src/and.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/rshell.dir/src/and.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rshell.dir/src/and.o -c /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/and.cpp

CMakeFiles/rshell.dir/src/and.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rshell.dir/src/and.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/and.cpp > CMakeFiles/rshell.dir/src/and.i

CMakeFiles/rshell.dir/src/and.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rshell.dir/src/and.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/and.cpp -o CMakeFiles/rshell.dir/src/and.s

CMakeFiles/rshell.dir/src/and.o.requires:

.PHONY : CMakeFiles/rshell.dir/src/and.o.requires

CMakeFiles/rshell.dir/src/and.o.provides: CMakeFiles/rshell.dir/src/and.o.requires
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/and.o.provides.build
.PHONY : CMakeFiles/rshell.dir/src/and.o.provides

CMakeFiles/rshell.dir/src/and.o.provides.build: CMakeFiles/rshell.dir/src/and.o


CMakeFiles/rshell.dir/src/or.o: CMakeFiles/rshell.dir/flags.make
CMakeFiles/rshell.dir/src/or.o: src/or.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/rshell.dir/src/or.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rshell.dir/src/or.o -c /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/or.cpp

CMakeFiles/rshell.dir/src/or.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rshell.dir/src/or.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/or.cpp > CMakeFiles/rshell.dir/src/or.i

CMakeFiles/rshell.dir/src/or.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rshell.dir/src/or.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/or.cpp -o CMakeFiles/rshell.dir/src/or.s

CMakeFiles/rshell.dir/src/or.o.requires:

.PHONY : CMakeFiles/rshell.dir/src/or.o.requires

CMakeFiles/rshell.dir/src/or.o.provides: CMakeFiles/rshell.dir/src/or.o.requires
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/or.o.provides.build
.PHONY : CMakeFiles/rshell.dir/src/or.o.provides

CMakeFiles/rshell.dir/src/or.o.provides.build: CMakeFiles/rshell.dir/src/or.o


CMakeFiles/rshell.dir/src/semicolon.o: CMakeFiles/rshell.dir/flags.make
CMakeFiles/rshell.dir/src/semicolon.o: src/semicolon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/rshell.dir/src/semicolon.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rshell.dir/src/semicolon.o -c /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/semicolon.cpp

CMakeFiles/rshell.dir/src/semicolon.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rshell.dir/src/semicolon.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/semicolon.cpp > CMakeFiles/rshell.dir/src/semicolon.i

CMakeFiles/rshell.dir/src/semicolon.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rshell.dir/src/semicolon.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/src/semicolon.cpp -o CMakeFiles/rshell.dir/src/semicolon.s

CMakeFiles/rshell.dir/src/semicolon.o.requires:

.PHONY : CMakeFiles/rshell.dir/src/semicolon.o.requires

CMakeFiles/rshell.dir/src/semicolon.o.provides: CMakeFiles/rshell.dir/src/semicolon.o.requires
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/semicolon.o.provides.build
.PHONY : CMakeFiles/rshell.dir/src/semicolon.o.provides

CMakeFiles/rshell.dir/src/semicolon.o.provides.build: CMakeFiles/rshell.dir/src/semicolon.o


# Object files for target rshell
rshell_OBJECTS = \
"CMakeFiles/rshell.dir/src/main.o" \
"CMakeFiles/rshell.dir/src/command.o" \
"CMakeFiles/rshell.dir/src/shell.o" \
"CMakeFiles/rshell.dir/src/and.o" \
"CMakeFiles/rshell.dir/src/or.o" \
"CMakeFiles/rshell.dir/src/semicolon.o"

# External object files for target rshell
rshell_EXTERNAL_OBJECTS =

rshell: CMakeFiles/rshell.dir/src/main.o
rshell: CMakeFiles/rshell.dir/src/command.o
rshell: CMakeFiles/rshell.dir/src/shell.o
rshell: CMakeFiles/rshell.dir/src/and.o
rshell: CMakeFiles/rshell.dir/src/or.o
rshell: CMakeFiles/rshell.dir/src/semicolon.o
rshell: CMakeFiles/rshell.dir/build.make
rshell: CMakeFiles/rshell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable rshell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rshell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rshell.dir/build: rshell

.PHONY : CMakeFiles/rshell.dir/build

CMakeFiles/rshell.dir/requires: CMakeFiles/rshell.dir/src/main.o.requires
CMakeFiles/rshell.dir/requires: CMakeFiles/rshell.dir/src/command.o.requires
CMakeFiles/rshell.dir/requires: CMakeFiles/rshell.dir/src/shell.o.requires
CMakeFiles/rshell.dir/requires: CMakeFiles/rshell.dir/src/and.o.requires
CMakeFiles/rshell.dir/requires: CMakeFiles/rshell.dir/src/or.o.requires
CMakeFiles/rshell.dir/requires: CMakeFiles/rshell.dir/src/semicolon.o.requires

.PHONY : CMakeFiles/rshell.dir/requires

CMakeFiles/rshell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rshell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rshell.dir/clean

CMakeFiles/rshell.dir/depend:
	cd /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois /mnt/c/Users/bb860/Documents/cs100/assignments/a1/assignment-1-brownbois/CMakeFiles/rshell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rshell.dir/depend
