# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "E:\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Andrei.DESKTOP-LTDSDE0\CLionProjects\computational methods\integration"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Andrei.DESKTOP-LTDSDE0\CLionProjects\computational methods\integration\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/integration.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/integration.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/integration.dir/flags.make

CMakeFiles/integration.dir/main.cpp.obj: CMakeFiles/integration.dir/flags.make
CMakeFiles/integration.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Andrei.DESKTOP-LTDSDE0\CLionProjects\computational methods\integration\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/integration.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\integration.dir\main.cpp.obj -c "C:\Users\Andrei.DESKTOP-LTDSDE0\CLionProjects\computational methods\integration\main.cpp"

CMakeFiles/integration.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/integration.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Andrei.DESKTOP-LTDSDE0\CLionProjects\computational methods\integration\main.cpp" > CMakeFiles\integration.dir\main.cpp.i

CMakeFiles/integration.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/integration.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Andrei.DESKTOP-LTDSDE0\CLionProjects\computational methods\integration\main.cpp" -o CMakeFiles\integration.dir\main.cpp.s

# Object files for target integration
integration_OBJECTS = \
"CMakeFiles/integration.dir/main.cpp.obj"

# External object files for target integration
integration_EXTERNAL_OBJECTS =

integration.exe: CMakeFiles/integration.dir/main.cpp.obj
integration.exe: CMakeFiles/integration.dir/build.make
integration.exe: CMakeFiles/integration.dir/linklibs.rsp
integration.exe: CMakeFiles/integration.dir/objects1.rsp
integration.exe: CMakeFiles/integration.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Andrei.DESKTOP-LTDSDE0\CLionProjects\computational methods\integration\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable integration.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\integration.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/integration.dir/build: integration.exe

.PHONY : CMakeFiles/integration.dir/build

CMakeFiles/integration.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\integration.dir\cmake_clean.cmake
.PHONY : CMakeFiles/integration.dir/clean

CMakeFiles/integration.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Andrei.DESKTOP-LTDSDE0\CLionProjects\computational methods\integration" "C:\Users\Andrei.DESKTOP-LTDSDE0\CLionProjects\computational methods\integration" "C:\Users\Andrei.DESKTOP-LTDSDE0\CLionProjects\computational methods\integration\cmake-build-debug" "C:\Users\Andrei.DESKTOP-LTDSDE0\CLionProjects\computational methods\integration\cmake-build-debug" "C:\Users\Andrei.DESKTOP-LTDSDE0\CLionProjects\computational methods\integration\cmake-build-debug\CMakeFiles\integration.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/integration.dir/depend

