cmake_minimum_required(VERSION 3.25)
project(object_rendering_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(object_rendering_test src/main.cpp src/Window.cpp include/Window.h src/VulkanLoader.cpp include/VulkanLoader.h src/DeviceHandler.cpp include/DeviceHandler.h)

find_package(glfw3 REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Vulkan REQUIRED)

target_link_libraries(object_rendering_test PRIVATE glfw glm::glm Vulkan::Vulkan)
