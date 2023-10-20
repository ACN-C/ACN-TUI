cmake_minimum_required (VERSION 3.27)

project(ACNTUI 
  LANGUAGES CXX
  VERSION 0.0.0.1
  )

SET(PROJECT_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/)

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
  ${ACNTUI_SOURCE_DIR}/main.cpp
  )
add_executable( ${CMAKE_PROJECT_NAME} ${ACNTUI_SOURCES})
target_include_directories(ACNTUI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_link_libraries(${CMAKE_PROJECT_NAME} 
  #PRIVATE ftxui::screen
  #PRIVATE ftxui::dom
  #PRIVATE ftxui::component
)
