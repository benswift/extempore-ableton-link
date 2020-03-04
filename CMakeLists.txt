cmake_minimum_required(VERSION 3.1)

project(xtmlink)

add_library(xtmlink SHARED xtmlink.cpp)


# tell the project about Link
include(link/AbletonLinkConfig.cmake)
target_link_libraries(xtmlink Ableton::Link)

# this is dangerous - it would be much better to use dynamic lookup for
# llvm_zone_malloc_from_current_zone *only* but I can't find the magic
# cmake flags for that
if(APPLE)
  target_compile_definitions(xtmlink PRIVATE -DLINK_PLATFORM_MACOSX=1)
elseif(WIN32)
  target_compile_definitions(xtmlink PRIVATE -DLINK_PLATFORM_WINDOWS=1)
elseif(UNIX)
  target_compile_definitions(xtmlink PRIVATE -DLINK_PLATFORM_LINUX=1)
else()
  message(FATAL_ERROR "Unsupported platform")
endif()

install(TARGETS xtmlink
  RUNTIME DESTINATION lib
  ARCHIVE DESTINATION lib # for .lib files on Windows
  LIBRARY DESTINATION lib)
