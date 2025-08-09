//
// Created by Matthias Amend on 31.07.25.
//

#include "../include/VulkanLoader.h"

VkInstance vulkan_instance;
std::vector<const char*> extension_names;

/**
 * Create the application info struct required for vulkan instance creation.
 * @return The application info struct
 */
VkApplicationInfo VulkanLoader::createApplicationInfo() {
    VkApplicationInfo application_info{};
    application_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    application_info.pApplicationName = "Hello Triangle";
    application_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    application_info.pEngineName = "No Engine";
    application_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    application_info.apiVersion = 0;
    return application_info;
}

/**
 * Create the instance create info struct required for vulkan instance creation.
 * @return The instance create info struct
 */
VkInstanceCreateInfo VulkanLoader::createInstanceCreateInfo() {
    VkInstanceCreateInfo create_info{};
    create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    create_info.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
    uint32_t glfw_extension_count = 0;
    const char** glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);
    extension_names.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
    extension_names.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
    for(int index = 0; index < glfw_extension_count; index++) {
        extension_names.push_back(glfw_extensions[index]);
    }
    create_info.enabledExtensionCount = static_cast<uint32_t>(extension_names.size());;
    create_info.ppEnabledExtensionNames = extension_names.data();
    create_info.enabledLayerCount = 0;
    return create_info;
}

/**
 * Create the vulkan instance.
 * Requires both application info and instance create info, which are generated in the prior functions
 * @return The vulkan instance
 */
void VulkanLoader::createVulkanInstance() {
    VkApplicationInfo application_info = createApplicationInfo();
    VkInstanceCreateInfo create_info = createInstanceCreateInfo();
    create_info.pApplicationInfo = &application_info;
    VkResult result = vkCreateInstance(&create_info, nullptr, &vulkan_instance);
    if (result != VK_SUCCESS) {
        std::cerr << "vkCreateInstance failed with error code: " << result << std::endl;
        throw std::runtime_error("failed to create Vulkan instance");
    }
}

/**
 * Destroy all Vulkan objects to free memory space.
 * This function is called when the program is terminated
 */
void VulkanLoader::cleanup() {
    vkDestroyInstance(vulkan_instance, nullptr);
}

/**
 * Get the vulkan instance.
 * @return The vulkan instance
 */
VkInstance VulkanLoader::getVulkanInstance() {
    return vulkan_instance;
}
