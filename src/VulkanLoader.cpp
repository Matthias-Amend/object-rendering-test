//
// Created by Matthias Amend on 31.07.25.
//

#include "../include/VulkanLoader.h"

/**
 * Create the application info required for the creation the vulkan instance.
 * The creation of the application info is static
 * @return The application info for vulkan instance creation
 */
VkApplicationInfo VulkanLoader::createApplicationInfo() {
    VkApplicationInfo application_info{};
    application_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    application_info.pApplicationName = "Hello Triangle";
    application_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    application_info.pEngineName = "No Engine";
    application_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    application_info.apiVersion = VK_API_VERSION_1_0;
    return application_info;
}

/**
 * Create the instance create info required for creation of the vulkan instance.
 * The creation of the instance create info is static
 * @return The instance create info for the vulkan instance
 */
VkInstanceCreateInfo VulkanLoader::createInstanceCreateInfo() {
    VkInstanceCreateInfo create_info{};
    create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    VkApplicationInfo application_info = createApplicationInfo();
    create_info.pApplicationInfo = &application_info;

    uint32_t glfw_extension_count = 0;
    const char** glfw_extensions;

    glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

    create_info.enabledExtensionCount = glfw_extension_count;
    create_info.ppEnabledExtensionNames = glfw_extensions;

    create_info.enabledLayerCount = 0;
    return create_info;
}

/**
 * Create the vulkan instance.
 * Requires both application info and instance create info, which are generated in the prior functions
 * @return The vulkan instance
 */
VkInstance VulkanLoader::createVulkanInstance() {
    VkInstance vulkan_instance;
    VkInstanceCreateInfo creation_info;
    vkCreateInstance(&creation_info, nullptr, &vulkan_instance);
    return vulkan_instance;
}
