# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/quentin/Documents/L3/Robotique/tracking_camera/Experience

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/quentin/Documents/L3/Robotique/tracking_camera/Experience

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/test.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/test.cpp.o: test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/quentin/Documents/L3/Robotique/tracking_camera/Experience/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/test.cpp.o -c /Users/quentin/Documents/L3/Robotique/tracking_camera/Experience/test.cpp

CMakeFiles/test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/quentin/Documents/L3/Robotique/tracking_camera/Experience/test.cpp > CMakeFiles/test.dir/test.cpp.i

CMakeFiles/test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/quentin/Documents/L3/Robotique/tracking_camera/Experience/test.cpp -o CMakeFiles/test.dir/test.cpp.s

CMakeFiles/test.dir/test.cpp.o.requires:

.PHONY : CMakeFiles/test.dir/test.cpp.o.requires

CMakeFiles/test.dir/test.cpp.o.provides: CMakeFiles/test.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/test.cpp.o.provides

CMakeFiles/test.dir/test.cpp.o.provides.build: CMakeFiles/test.dir/test.cpp.o


# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS = \
"/Users/quentin/Documents/L3/Robotique/tracking_camera/include/serial.o"

test: CMakeFiles/test.dir/test.cpp.o
test: /Users/quentin/Documents/L3/Robotique/tracking_camera/include/serial.o
test: CMakeFiles/test.dir/build.make
test: /usr/local/lib/libopencv_dnn.3.3.1.dylib
test: /usr/local/lib/libopencv_ml.3.3.1.dylib
test: /usr/local/lib/libopencv_objdetect.3.3.1.dylib
test: /usr/local/lib/libopencv_shape.3.3.1.dylib
test: /usr/local/lib/libopencv_stitching.3.3.1.dylib
test: /usr/local/lib/libopencv_superres.3.3.1.dylib
test: /usr/local/lib/libopencv_videostab.3.3.1.dylib
test: /usr/local/lib/libopencv_calib3d.3.3.1.dylib
test: /usr/local/lib/libopencv_features2d.3.3.1.dylib
test: /usr/local/lib/libopencv_flann.3.3.1.dylib
test: /usr/local/lib/libopencv_highgui.3.3.1.dylib
test: /usr/local/lib/libopencv_photo.3.3.1.dylib
test: /usr/local/lib/libopencv_video.3.3.1.dylib
test: /usr/local/lib/libopencv_videoio.3.3.1.dylib
test: /usr/local/lib/libopencv_imgcodecs.3.3.1.dylib
test: /usr/local/lib/libopencv_imgproc.3.3.1.dylib
test: /usr/local/lib/libopencv_core.3.3.1.dylib
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/quentin/Documents/L3/Robotique/tracking_camera/Experience/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test

.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/requires: CMakeFiles/test.dir/test.cpp.o.requires

.PHONY : CMakeFiles/test.dir/requires

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /Users/quentin/Documents/L3/Robotique/tracking_camera/Experience && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/quentin/Documents/L3/Robotique/tracking_camera/Experience /Users/quentin/Documents/L3/Robotique/tracking_camera/Experience /Users/quentin/Documents/L3/Robotique/tracking_camera/Experience /Users/quentin/Documents/L3/Robotique/tracking_camera/Experience /Users/quentin/Documents/L3/Robotique/tracking_camera/Experience/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend

