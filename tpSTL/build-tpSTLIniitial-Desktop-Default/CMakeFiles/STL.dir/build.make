# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/leo/Desktop/PRALG/tpSTL/tpSTLIniitial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leo/Desktop/PRALG/tpSTL/build-tpSTLIniitial-Desktop-Default

# Include any dependencies generated for this target.
include CMakeFiles/STL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/STL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/STL.dir/flags.make

CMakeFiles/STL.dir/main.cpp.o: CMakeFiles/STL.dir/flags.make
CMakeFiles/STL.dir/main.cpp.o: /home/leo/Desktop/PRALG/tpSTL/tpSTLIniitial/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/Desktop/PRALG/tpSTL/build-tpSTLIniitial-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/STL.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/STL.dir/main.cpp.o -c /home/leo/Desktop/PRALG/tpSTL/tpSTLIniitial/main.cpp

CMakeFiles/STL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/STL.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/Desktop/PRALG/tpSTL/tpSTLIniitial/main.cpp > CMakeFiles/STL.dir/main.cpp.i

CMakeFiles/STL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/STL.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/Desktop/PRALG/tpSTL/tpSTLIniitial/main.cpp -o CMakeFiles/STL.dir/main.cpp.s

CMakeFiles/STL.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/STL.dir/main.cpp.o.requires

CMakeFiles/STL.dir/main.cpp.o.provides: CMakeFiles/STL.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/STL.dir/build.make CMakeFiles/STL.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/STL.dir/main.cpp.o.provides

CMakeFiles/STL.dir/main.cpp.o.provides.build: CMakeFiles/STL.dir/main.cpp.o


CMakeFiles/STL.dir/eleve.cpp.o: CMakeFiles/STL.dir/flags.make
CMakeFiles/STL.dir/eleve.cpp.o: /home/leo/Desktop/PRALG/tpSTL/tpSTLIniitial/eleve.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/Desktop/PRALG/tpSTL/build-tpSTLIniitial-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/STL.dir/eleve.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/STL.dir/eleve.cpp.o -c /home/leo/Desktop/PRALG/tpSTL/tpSTLIniitial/eleve.cpp

CMakeFiles/STL.dir/eleve.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/STL.dir/eleve.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/Desktop/PRALG/tpSTL/tpSTLIniitial/eleve.cpp > CMakeFiles/STL.dir/eleve.cpp.i

CMakeFiles/STL.dir/eleve.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/STL.dir/eleve.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/Desktop/PRALG/tpSTL/tpSTLIniitial/eleve.cpp -o CMakeFiles/STL.dir/eleve.cpp.s

CMakeFiles/STL.dir/eleve.cpp.o.requires:

.PHONY : CMakeFiles/STL.dir/eleve.cpp.o.requires

CMakeFiles/STL.dir/eleve.cpp.o.provides: CMakeFiles/STL.dir/eleve.cpp.o.requires
	$(MAKE) -f CMakeFiles/STL.dir/build.make CMakeFiles/STL.dir/eleve.cpp.o.provides.build
.PHONY : CMakeFiles/STL.dir/eleve.cpp.o.provides

CMakeFiles/STL.dir/eleve.cpp.o.provides.build: CMakeFiles/STL.dir/eleve.cpp.o


# Object files for target STL
STL_OBJECTS = \
"CMakeFiles/STL.dir/main.cpp.o" \
"CMakeFiles/STL.dir/eleve.cpp.o"

# External object files for target STL
STL_EXTERNAL_OBJECTS =

STL: CMakeFiles/STL.dir/main.cpp.o
STL: CMakeFiles/STL.dir/eleve.cpp.o
STL: CMakeFiles/STL.dir/build.make
STL: CMakeFiles/STL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leo/Desktop/PRALG/tpSTL/build-tpSTLIniitial-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable STL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/STL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/STL.dir/build: STL

.PHONY : CMakeFiles/STL.dir/build

CMakeFiles/STL.dir/requires: CMakeFiles/STL.dir/main.cpp.o.requires
CMakeFiles/STL.dir/requires: CMakeFiles/STL.dir/eleve.cpp.o.requires

.PHONY : CMakeFiles/STL.dir/requires

CMakeFiles/STL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/STL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/STL.dir/clean

CMakeFiles/STL.dir/depend:
	cd /home/leo/Desktop/PRALG/tpSTL/build-tpSTLIniitial-Desktop-Default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leo/Desktop/PRALG/tpSTL/tpSTLIniitial /home/leo/Desktop/PRALG/tpSTL/tpSTLIniitial /home/leo/Desktop/PRALG/tpSTL/build-tpSTLIniitial-Desktop-Default /home/leo/Desktop/PRALG/tpSTL/build-tpSTLIniitial-Desktop-Default /home/leo/Desktop/PRALG/tpSTL/build-tpSTLIniitial-Desktop-Default/CMakeFiles/STL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/STL.dir/depend
