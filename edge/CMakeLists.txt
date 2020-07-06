# cmake needs this line
cmake_minimum_required(VERSION 3.1)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Define project name
project(opencv_example_project)

# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
find_package(OpenCV REQUIRED)

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

# Declare the executable target built from your sources
add_executable(opencv_example example.cpp)
add_executable(Sobel Sobel.cpp)
add_executable(Laplacian Laplacian.cpp)
add_executable(Canny Canny.cpp)
add_executable(Bilateralfilter Bilateralfilter.cpp)
add_executable(UnsharpMasking UnsharpMasking.cpp)
add_executable(EdgeEnhancement EdgeEnhancement.cpp)
add_executable(Bilateralfilter2 Bilateralfilter2.cpp)
add_executable(median median.cpp)
add_executable(Gaussian Gaussian.cpp)

# Link your application with OpenCV libraries
target_link_libraries(opencv_example PRIVATE ${OpenCV_LIBS})
target_link_libraries(Sobel PRIVATE ${OpenCV_LIBS})
target_link_libraries(Laplacian PRIVATE ${OpenCV_LIBS})
target_link_libraries(Canny PRIVATE ${OpenCV_LIBS})
target_link_libraries(Bilateralfilter PRIVATE ${OpenCV_LIBS})
target_link_libraries(UnsharpMasking PRIVATE ${OpenCV_LIBS})
target_link_libraries(EdgeEnhancement PRIVATE ${OpenCV_LIBS})
target_link_libraries(Bilateralfilter2 PRIVATE ${OpenCV_LIBS})
target_link_libraries(Gaussian PRIVATE ${OpenCV_LIBS})
target_link_libraries(median PRIVATE ${OpenCV_LIBS})

