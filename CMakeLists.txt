cmake_minimum_required(VERSION 2.8)
project( Tracking )
find_package( OpenCV REQUIRED )
add_executable( track track.cpp include/serial.o )
target_link_libraries( track ${OpenCV_LIBS} )