# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Program Files (x86)\JetBrains\CLion 2016.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files (x86)\JetBrains\CLion 2016.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\sun\Desktop\zl_threadpool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\sun\Desktop\zl_threadpool\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/zl_threadpool.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zl_threadpool.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zl_threadpool.dir/flags.make

CMakeFiles/zl_threadpool.dir/main.cpp.obj: CMakeFiles/zl_threadpool.dir/flags.make
CMakeFiles/zl_threadpool.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sun\Desktop\zl_threadpool\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zl_threadpool.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\zl_threadpool.dir\main.cpp.obj -c C:\Users\sun\Desktop\zl_threadpool\main.cpp

CMakeFiles/zl_threadpool.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zl_threadpool.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\sun\Desktop\zl_threadpool\main.cpp > CMakeFiles\zl_threadpool.dir\main.cpp.i

CMakeFiles/zl_threadpool.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zl_threadpool.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\sun\Desktop\zl_threadpool\main.cpp -o CMakeFiles\zl_threadpool.dir\main.cpp.s

CMakeFiles/zl_threadpool.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/zl_threadpool.dir/main.cpp.obj.requires

CMakeFiles/zl_threadpool.dir/main.cpp.obj.provides: CMakeFiles/zl_threadpool.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\zl_threadpool.dir\build.make CMakeFiles/zl_threadpool.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/zl_threadpool.dir/main.cpp.obj.provides

CMakeFiles/zl_threadpool.dir/main.cpp.obj.provides.build: CMakeFiles/zl_threadpool.dir/main.cpp.obj


# Object files for target zl_threadpool
zl_threadpool_OBJECTS = \
"CMakeFiles/zl_threadpool.dir/main.cpp.obj"

# External object files for target zl_threadpool
zl_threadpool_EXTERNAL_OBJECTS =

zl_threadpool.exe: CMakeFiles/zl_threadpool.dir/main.cpp.obj
zl_threadpool.exe: CMakeFiles/zl_threadpool.dir/build.make
zl_threadpool.exe: CMakeFiles/zl_threadpool.dir/linklibs.rsp
zl_threadpool.exe: CMakeFiles/zl_threadpool.dir/objects1.rsp
zl_threadpool.exe: CMakeFiles/zl_threadpool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\sun\Desktop\zl_threadpool\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable zl_threadpool.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\zl_threadpool.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zl_threadpool.dir/build: zl_threadpool.exe

.PHONY : CMakeFiles/zl_threadpool.dir/build

CMakeFiles/zl_threadpool.dir/requires: CMakeFiles/zl_threadpool.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/zl_threadpool.dir/requires

CMakeFiles/zl_threadpool.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\zl_threadpool.dir\cmake_clean.cmake
.PHONY : CMakeFiles/zl_threadpool.dir/clean

CMakeFiles/zl_threadpool.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\sun\Desktop\zl_threadpool C:\Users\sun\Desktop\zl_threadpool C:\Users\sun\Desktop\zl_threadpool\cmake-build-debug C:\Users\sun\Desktop\zl_threadpool\cmake-build-debug C:\Users\sun\Desktop\zl_threadpool\cmake-build-debug\CMakeFiles\zl_threadpool.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zl_threadpool.dir/depend

