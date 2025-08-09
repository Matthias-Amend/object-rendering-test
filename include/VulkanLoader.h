//
// Created by Matthias Amend on 31.07.25.
//

#ifndef OBJECT_RENDERING_TEST_VULKANLOADER_H
#define OBJECT_RENDERING_TEST_VULKANLOADER_H

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <iostream>

class VulkanLoader {

private:
    VkApplicationInfo createApplicationInfo();
    VkInstanceCreateInfo createInstanceCreateInfo();
public:
    void createVulkanInstance();
    VkInstance getVulkanInstance();
    void cleanup();

};


#endif //OBJECT_RENDERING_TEST_VULKANLOADER_H
