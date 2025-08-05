#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include "../include/Window.h"
#include "../include/VulkanLoader.h"
#include "../include/DeviceHandler.h"

Window* window;
VkInstance vulkan_instance;
DeviceHandler device_handler;

void init() {
    glfwInit();
    window = new Window(800, 600, "Hello World");
    vulkan_instance = VulkanLoader::createVulkanInstance();
    device_handler.identifyDevices(vulkan_instance);
    device_handler.selectSuitableDevice();
}

void mainLoop() {
    GLFWwindow* window_object = window->getWindowObject();
    while(!glfwWindowShouldClose(window_object)) {
        glfwPollEvents();
    }
}

void cleanup() {
    vkDestroyInstance(vulkan_instance, nullptr);
    window->destroyWindowObject();
    glfwTerminate();
}

int main() {
    init();
    mainLoop();
    cleanup();
    return 0;
}
