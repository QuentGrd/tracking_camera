# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/quentin/Documents/L3/Robotique/tracking_camera

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/quentin/Documents/L3/Robotique/tracking_camera

# Include any dependencies generated for this target.
include CMakeFiles/track.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/track.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/track.dir/flags.make

CMakeFiles/track.dir/track.cpp.o: CMakeFiles/track.dir/flags.make
CMakeFiles/track.dir/track.cpp.o: track.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/quentin/Documents/L3/Robotique/tracking_camera/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/track.dir/track.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/track.dir/track.cpp.o -c /Users/quentin/Documents/L3/Robotique/tracking_camera/track.cpp

CMakeFiles/track.dir/track.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/track.dir/track.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/quentin/Documents/L3/Robotique/tracking_camera/track.cpp > CMakeFiles/track.dir/track.cpp.i

CMakeFiles/track.dir/track.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/track.dir/track.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/quentin/Documents/L3/Robotique/tracking_camera/track.cpp -o CMakeFiles/track.dir/track.cpp.s

CMakeFiles/track.dir/track.cpp.o.requires:

.PHONY : CMakeFiles/track.dir/track.cpp.o.requires

CMakeFiles/track.dir/track.cpp.o.provides: CMakeFiles/track.dir/track.cpp.o.requires
	$(MAKE) -f CMakeFiles/track.dir/build.make CMakeFiles/track.dir/track.cpp.o.provides.build
.PHONY : CMakeFiles/track.dir/track.cpp.o.provides

CMakeFiles/track.dir/track.cpp.o.provides.build: CMakeFiles/track.dir/track.cpp.o


# Object files for target track
track_OBJECTS = \
"CMakeFiles/track.dir/track.cpp.o"

# External object files for target track
track_EXTERNAL_OBJECTS = \
"/Users/quentin/Documents/L3/Robotique/tracking_camera/include/serial.o"

track: CMakeFiles/track.dir/track.cpp.o
track: include/serial.o
track: CMakeFiles/track.dir/build.make
track: /usr/local/lib/libopencv_dnn.3.3.1.dylib
track: /usr/local/lib/libopencv_ml.3.3.1.dylib
track: /usr/local/lib/libopencv_objdetect.3.3.1.dylib
track: /usr/local/lib/libopencv_shape.3.3.1.dylib
track: /usr/local/lib/libopencv_stitching.3.3.1.dylib
track: /usr/local/lib/libopencv_superres.3.3.1.dylib
track: /usr/local/lib/libopencv_videostab.3.3.1.dylib
track: /usr/local/lib/libopencv_calib3d.3.3.1.dylib
track: /usr/local/lib/libopencv_features2d.3.3.1.dylib
track: /usr/local/lib/libopencv_flann.3.3.1.dylib
track: /usr/local/lib/libopencv_highgui.3.3.1.dylib
track: /usr/local/lib/libopencv_photo.3.3.1.dylib
track: /usr/local/lib/libopencv_video.3.3.1.dylib
track: /usr/local/lib/libopencv_videoio.3.3.1.dylib
track: /usr/local/lib/libopencv_imgcodecs.3.3.1.dylib
track: /usr/local/lib/libopencv_imgproc.3.3.1.dylib
track: /usr/local/lib/libopencv_core.3.3.1.dylib
track: CMakeFiles/track.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/quentin/Documents/L3/Robotique/tracking_camera/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable track"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/track.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/track.dir/build: track

.PHONY : CMakeFiles/track.dir/build

CMakeFiles/track.dir/requires: CMakeFiles/track.dir/track.cpp.o.requires

.PHONY : CMakeFiles/track.dir/requires

CMakeFiles/track.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/track.dir/cmake_clean.cmake
.PHONY : CMakeFiles/track.dir/clean

CMakeFiles/track.dir/depend:
	cd /Users/quentin/Documents/L3/Robotique/tracking_camera && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/quentin/Documents/L3/Robotique/tracking_camera /Users/quentin/Documents/L3/Robotique/tracking_camera /Users/quentin/Documents/L3/Robotique/tracking_camera /Users/quentin/Documents/L3/Robotique/tracking_camera /Users/quentin/Documents/L3/Robotique/tracking_camera/CMakeFiles/track.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/track.dir/depend

