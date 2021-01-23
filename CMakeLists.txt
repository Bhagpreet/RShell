CMAKE_MINIMUM_REQUIRED(VERSION 1.0)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)
INCLUDE_DIRECTORIES(
  src
  ${CMAKE_SOURCE_DIR}/assignment-1-brownbois/src
)

ADD_EXECUTABLE(rshell
  src/main.cpp
  src/command.cpp
  src/shell.cpp
  src/and.cpp
  src/or.cpp
  src/semicolon.cpp
)

ADD_EXECUTABLE(test
  tests/test.cpp
  src/command.cpp
  src/shell.cpp
  src/and.cpp
  src/or.cpp
  src/semicolon.cpp
)

TARGET_LINK_LIBRARIES(test gtest)