cmake_minimum_required (VERSION 3.27)

project(ACNTUI 
  LANGUAGES CXX
  VERSION 0.0.0.1
  )

if (UNIX)
  set (CMAKE_CXX_FLAGS "--debug -g3 -Wall -O0")
endif ()

include_directories (${ACNTUI_SOURCE_DIR}/src)

include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)


FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v5.0.0 
  )

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

FetchContent_MakeAvailable(ftxui)

set (ACNTUI_SOURCES
  ${ACNTUI_SOURCE_DIR}/src/main.cpp
  ${ACNTUI_SOURCE_DIR}/src/Welcome.cpp
  )

add_executable(${CMAKE_PROJECT_NAME} ${ACNTUI_SOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME} 
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)
