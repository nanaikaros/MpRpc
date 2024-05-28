# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Project/MpRpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Project/MpRpc/bin

# Include any dependencies generated for this target.
include example/Callee/CMakeFiles/provider.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include example/Callee/CMakeFiles/provider.dir/compiler_depend.make

# Include the progress variables for this target.
include example/Callee/CMakeFiles/provider.dir/progress.make

# Include the compile flags for this target's objects.
include example/Callee/CMakeFiles/provider.dir/flags.make

example/Callee/CMakeFiles/provider.dir/userservice.cc.o: example/Callee/CMakeFiles/provider.dir/flags.make
example/Callee/CMakeFiles/provider.dir/userservice.cc.o: /Project/MpRpc/example/Callee/userservice.cc
example/Callee/CMakeFiles/provider.dir/userservice.cc.o: example/Callee/CMakeFiles/provider.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Project/MpRpc/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object example/Callee/CMakeFiles/provider.dir/userservice.cc.o"
	cd /Project/MpRpc/bin/example/Callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT example/Callee/CMakeFiles/provider.dir/userservice.cc.o -MF CMakeFiles/provider.dir/userservice.cc.o.d -o CMakeFiles/provider.dir/userservice.cc.o -c /Project/MpRpc/example/Callee/userservice.cc

example/Callee/CMakeFiles/provider.dir/userservice.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/provider.dir/userservice.cc.i"
	cd /Project/MpRpc/bin/example/Callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Project/MpRpc/example/Callee/userservice.cc > CMakeFiles/provider.dir/userservice.cc.i

example/Callee/CMakeFiles/provider.dir/userservice.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/provider.dir/userservice.cc.s"
	cd /Project/MpRpc/bin/example/Callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Project/MpRpc/example/Callee/userservice.cc -o CMakeFiles/provider.dir/userservice.cc.s

example/Callee/CMakeFiles/provider.dir/__/user.pb.cc.o: example/Callee/CMakeFiles/provider.dir/flags.make
example/Callee/CMakeFiles/provider.dir/__/user.pb.cc.o: /Project/MpRpc/example/user.pb.cc
example/Callee/CMakeFiles/provider.dir/__/user.pb.cc.o: example/Callee/CMakeFiles/provider.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Project/MpRpc/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object example/Callee/CMakeFiles/provider.dir/__/user.pb.cc.o"
	cd /Project/MpRpc/bin/example/Callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT example/Callee/CMakeFiles/provider.dir/__/user.pb.cc.o -MF CMakeFiles/provider.dir/__/user.pb.cc.o.d -o CMakeFiles/provider.dir/__/user.pb.cc.o -c /Project/MpRpc/example/user.pb.cc

example/Callee/CMakeFiles/provider.dir/__/user.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/provider.dir/__/user.pb.cc.i"
	cd /Project/MpRpc/bin/example/Callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Project/MpRpc/example/user.pb.cc > CMakeFiles/provider.dir/__/user.pb.cc.i

example/Callee/CMakeFiles/provider.dir/__/user.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/provider.dir/__/user.pb.cc.s"
	cd /Project/MpRpc/bin/example/Callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Project/MpRpc/example/user.pb.cc -o CMakeFiles/provider.dir/__/user.pb.cc.s

# Object files for target provider
provider_OBJECTS = \
"CMakeFiles/provider.dir/userservice.cc.o" \
"CMakeFiles/provider.dir/__/user.pb.cc.o"

# External object files for target provider
provider_EXTERNAL_OBJECTS =

provider: example/Callee/CMakeFiles/provider.dir/userservice.cc.o
provider: example/Callee/CMakeFiles/provider.dir/__/user.pb.cc.o
provider: example/Callee/CMakeFiles/provider.dir/build.make
provider: /Project/MpRpc/lib/libmprpc.a
provider: example/Callee/CMakeFiles/provider.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Project/MpRpc/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../provider"
	cd /Project/MpRpc/bin/example/Callee && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/provider.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example/Callee/CMakeFiles/provider.dir/build: provider
.PHONY : example/Callee/CMakeFiles/provider.dir/build

example/Callee/CMakeFiles/provider.dir/clean:
	cd /Project/MpRpc/bin/example/Callee && $(CMAKE_COMMAND) -P CMakeFiles/provider.dir/cmake_clean.cmake
.PHONY : example/Callee/CMakeFiles/provider.dir/clean

example/Callee/CMakeFiles/provider.dir/depend:
	cd /Project/MpRpc/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Project/MpRpc /Project/MpRpc/example/Callee /Project/MpRpc/bin /Project/MpRpc/bin/example/Callee /Project/MpRpc/bin/example/Callee/CMakeFiles/provider.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : example/Callee/CMakeFiles/provider.dir/depend
