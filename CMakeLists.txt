cmake_minimum_required(
  VERSION
  3.12
)

project(
  SippetBox
  VERSION
  1.0.0
)

add_executable(
  SippetBox
  source/main.c
)

set_target_properties(
  SippetBox
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY
  "${CMAKE_SOURCE_DIR}"
)

set(
  GLFW_LIBRARY
  "${CMAKE_SOURCE_DIR}/dependencies/GLFW/lib/libglfw.3.dylib"
)

if(
  NOT
  EXISTS
  ${GLFW_LIBRARY}
)

message(
  FATAL_ERROR
  "GLFW library not found"
)

else()

message(
  STATUS
  "Using GLFW library: ${GLFW_LIBRARY}"
)

endif()

target_include_directories(
  SippetBox
  PUBLIC
  "${CMAKE_SOURCE_DIR}/dependencies/GLFW/include"
)

target_link_libraries(
  SippetBox
  PUBLIC
  ${GLFW_LIBRARY}
)

set(
  VULKAN_LIBRARY
  "${CMAKE_SOURCE_DIR}/dependencies/Vulkan/lib/libvulkan.1.dylib"
)

if(
  NOT
  EXISTS
  ${VULKAN_LIBRARY}
)

message(
  FATAL_ERROR
  "Vulkan library not found"
)

else()

message(
  STATUS
  "Using Vulkan library: ${VULKAN_LIBRARY}"
)

endif()

target_include_directories(
  SippetBox
  PUBLIC
  "${CMAKE_SOURCE_DIR}/dependencies/Vulkan/include"
)

target_link_libraries(
  SippetBox
  PUBLIC
  ${VULKAN_LIBRARY}
)

set_target_properties(
  SippetBox
  PROPERTIES
  BUILD_WITH_INSTALL_RPATH
  TRUE
  INSTALL_RPATH
  "@executable_path/dependencies/GLFW/lib;@executable_path/dependencies/Vulkan/lib"
  CMAKE_BUILD_RPATH
  "@executable_path/dependencies/GLFW/lib;@executable_path/dependencies/Vulkan/lib"
)