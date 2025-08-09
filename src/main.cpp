#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include "../include/Window.h"
#include "../include/VulkanLoader.h"
#include "../include/DeviceHandler.h"

Window* window;
DeviceHandler device_handler;
VulkanLoader vulkan_loader;

void init() {
    if(!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }
    window = new Window(800, 600, "Hello World");
    vulkan_loader.createVulkanInstance();
    device_handler.identifyDevices(vulkan_loader.getVulkanInstance());
    device_handler.selectSuitableDevice();
    device_handler.createLogicalDevice();
}

void mainLoop() {
    GLFWwindow* window_object = window->getWindowObject();
    while(!glfwWindowShouldClose(window_object)) {
        glfwPollEvents();
    }
}

void cleanup() {
    vulkan_loader.cleanup();
    device_handler.cleanup();
    window->destroyWindowObject();
    glfwTerminate();
}

int main() {
    init();
    mainLoop();
    cleanup();
    return 0;
}
