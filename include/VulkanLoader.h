//
// Created by Matthias Amend on 31.07.25.
//

#ifndef OBJECT_RENDERING_TEST_VULKANLOADER_H
#define OBJECT_RENDERING_TEST_VULKANLOADER_H

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

class VulkanLoader {

private:
    static VkApplicationInfo createApplicationInfo();
    static VkInstanceCreateInfo createInstanceCreateInfo();

public:
    static VkInstance createVulkanInstance();

};


#endif //OBJECT_RENDERING_TEST_VULKANLOADER_H
