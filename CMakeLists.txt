cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set the project name
project(ProgressTracker)

# set executables
set(THIS_PROJECT_SRC_DIRECTORIES
)
set(THIS_PROJECT_TESTS_DIRECTORIES
)

# set flags
set(THIS_PROJECT_FLAGS
    -Wall
    -Werror 
    -Weffc++
    -Wextra
    -pedantic
    -Wconversion 
    -O3
)

# add all executables
add_executable(${PROJECT_NAME}
    source/main.cpp
    ${THIS_PROJECT_SRC_DIRECTORIES}
)
add_executable(${PROJECT_NAME}-ut 
    source/catch_main.cpp
    ${THIS_PROJECT_SRC_DIRECTORIES}
    ${THIS_PROJECT_TESTS_DIRECTORIES}
)
    
# specify compile options for target
target_compile_options(${PROJECT_NAME} PRIVATE ${THIS_PROJECT_FLAGS})

# enable standard cpp17
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

# link ncurses static lib
target_link_libraries(${PROJECT_NAME} ncurses)

