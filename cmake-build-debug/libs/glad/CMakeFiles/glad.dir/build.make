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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\workspace\opengl-boiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\workspace\opengl-boiler\cmake-build-debug

# Include any dependencies generated for this target.
include libs/glad/CMakeFiles/glad.dir/depend.make

# Include the progress variables for this target.
include libs/glad/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include libs/glad/CMakeFiles/glad.dir/flags.make

libs/glad/CMakeFiles/glad.dir/src/glad.c.obj: libs/glad/CMakeFiles/glad.dir/flags.make
libs/glad/CMakeFiles/glad.dir/src/glad.c.obj: libs/glad/CMakeFiles/glad.dir/includes_C.rsp
libs/glad/CMakeFiles/glad.dir/src/glad.c.obj: ../libs/glad/src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\workspace\opengl-boiler\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/glad/CMakeFiles/glad.dir/src/glad.c.obj"
	cd /d C:\workspace\opengl-boiler\cmake-build-debug\libs\glad && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\glad.dir\src\glad.c.obj   -c C:\workspace\opengl-boiler\libs\glad\src\glad.c

libs/glad/CMakeFiles/glad.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glad.dir/src/glad.c.i"
	cd /d C:\workspace\opengl-boiler\cmake-build-debug\libs\glad && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\workspace\opengl-boiler\libs\glad\src\glad.c > CMakeFiles\glad.dir\src\glad.c.i

libs/glad/CMakeFiles/glad.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glad.dir/src/glad.c.s"
	cd /d C:\workspace\opengl-boiler\cmake-build-debug\libs\glad && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\workspace\opengl-boiler\libs\glad\src\glad.c -o CMakeFiles\glad.dir\src\glad.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/src/glad.c.obj"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

libs/glad/libgladd.a: libs/glad/CMakeFiles/glad.dir/src/glad.c.obj
libs/glad/libgladd.a: libs/glad/CMakeFiles/glad.dir/build.make
libs/glad/libgladd.a: libs/glad/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\workspace\opengl-boiler\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libgladd.a"
	cd /d C:\workspace\opengl-boiler\cmake-build-debug\libs\glad && $(CMAKE_COMMAND) -P CMakeFiles\glad.dir\cmake_clean_target.cmake
	cd /d C:\workspace\opengl-boiler\cmake-build-debug\libs\glad && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\glad.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/glad/CMakeFiles/glad.dir/build: libs/glad/libgladd.a

.PHONY : libs/glad/CMakeFiles/glad.dir/build

libs/glad/CMakeFiles/glad.dir/clean:
	cd /d C:\workspace\opengl-boiler\cmake-build-debug\libs\glad && $(CMAKE_COMMAND) -P CMakeFiles\glad.dir\cmake_clean.cmake
.PHONY : libs/glad/CMakeFiles/glad.dir/clean

libs/glad/CMakeFiles/glad.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\workspace\opengl-boiler C:\workspace\opengl-boiler\libs\glad C:\workspace\opengl-boiler\cmake-build-debug C:\workspace\opengl-boiler\cmake-build-debug\libs\glad C:\workspace\opengl-boiler\cmake-build-debug\libs\glad\CMakeFiles\glad.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : libs/glad/CMakeFiles/glad.dir/depend

