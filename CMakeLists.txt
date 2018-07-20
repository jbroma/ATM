cmake_minimum_required(VERSION 2.6)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)

set(PROJECT_NAME ATM)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

# set(HEADER
#    src/Dispatcher.h
#    src/Component.h
#    src/Bank.h
#    src/Message.h
#	  src/MessagePort.h
#  )

# set(SOURCE
#    Bank.cpp
# )

file(GLOB_RECURSE HEADER "src/*.h" "src/.hpp")
file(GLOB_RECURSE SOURCE "src/*.cpp")

add_executable(${PROJECT_NAME} src/main.cpp ${HEADER} ${SOURCE})

target_link_libraries(${PROJECT_NAME} pthread gtest gmock)
