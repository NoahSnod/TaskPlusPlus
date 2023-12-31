cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")

add_subdirectory(googletest)

add_executable(testingView
    viewTest.cpp
)

add_executable(testingHome
    homeTest.cpp
)

add_executable(testingPrompt
    promptTest.cpp
)

add_executable(testingTask
    taskTest.cpp
)

add_executable(testingTaskList
    taskListTest.cpp
)

add_executable(runAllTests
    taskTest.cpp
    taskListTest.cpp
    homeTest.cpp
    promptTest.cpp
    viewTest.cpp
)



target_link_libraries(testingTask gmock gtest gtest_main)
target_link_libraries(testingTask simpleLibrary)
target_link_libraries(testingTaskList gmock gtest gtest_main)
target_link_libraries(testingTaskList simpleLibrary)
target_link_libraries(runAllTests gmock gtest gtest_main)
target_link_libraries(runAllTests simpleLibrary)
target_link_libraries(testingHome gmock gtest gtest_main)
target_link_libraries(testingHome simpleLibrary)
target_link_libraries(testingPrompt gmock gtest gtest_main)
target_link_libraries(testingPrompt simpleLibrary)
target_link_libraries(testingView gmock gtest gtest_main)
target_link_libraries(testingView simpleLibrary)
