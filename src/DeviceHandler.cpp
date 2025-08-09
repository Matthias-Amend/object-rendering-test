//
// Created by Matthias Amend on 02.08.25.
//

#include "../include/DeviceHandler.h"
#include <iostream>

VkPhysicalDevice selected_physical_device = VK_NULL_HANDLE;
VkDevice selected_logical_device;
VkQueue graphics_queue;

std::vector<VkPhysicalDevice> device_list;

struct DeviceHandler::QueueFamilyIndices{
    std::optional<uint32_t> graphics_family;
};

/**
 * Identify all GPU devices.
 * The List of all system GPUs is then used to select a suitable GPU for rendering
 * @param instance The vulkan instance
 */
void DeviceHandler::identifyDevices(VkInstance instance) {
    uint32_t device_count = 0;
    vkEnumeratePhysicalDevices(instance, &device_count, nullptr);
    device_list = std::vector<VkPhysicalDevice>(device_count);
    vkEnumeratePhysicalDevices(instance, &device_count, device_list.data());
}

/**
 * Select the first suitable GPU selected_logical_device in the device_list.
 * The selected selected_logical_device does not have to be the best suited, just the first
 */
void DeviceHandler::selectSuitableDevice() {
    for(const auto& device : device_list) {
        if(isDeviceSuitable(device)) {
            selected_physical_device = device;
            std::cout << "Suitable Device Found";
            break;
            //TODO implement score mechanic, so that selected physical selected_logical_device is the best suited and not just the first
        }
    }
}

/**
 * Check a devices queue families.
 * All relevant queue family indices are logged in a QueueFamilyIndices struct und are then returned
 * @param physical_device The physical selected_logical_device
 * @return The QueueFamilyIndices of the current physical selected_logical_device
 */
DeviceHandler::QueueFamilyIndices DeviceHandler::findQueueFamilies(VkPhysicalDevice physical_device) {
    QueueFamilyIndices queue_family_indices;
    uint32_t queue_family_count = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(physical_device, &queue_family_count, nullptr);
    std::vector<VkQueueFamilyProperties> queue_families(queue_family_count);
    vkGetPhysicalDeviceQueueFamilyProperties(physical_device, &queue_family_count, queue_families.data());
    int index = 0;
    for(const auto& queue_family : queue_families) {
        if(queue_family.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            queue_family_indices.graphics_family = index;
        }
        index++;
    }
    return queue_family_indices;
}

/**
 * Check if a specific selected_logical_device has the desired features to run the program.
 * @param device The selected_logical_device
 * @return True if the selected_logical_device possesses the desired features, false otherwise
 */
bool DeviceHandler::isDeviceSuitable(VkPhysicalDevice device) {
    QueueFamilyIndices queue_family_indices = findQueueFamilies(device);
    return queue_family_indices.graphics_family.has_value();
}

/**
 * Create the logical device.
 */
void DeviceHandler::createLogicalDevice() {
    QueueFamilyIndices queue_family_indices = findQueueFamilies(selected_physical_device);
    VkDeviceQueueCreateInfo queue_create_info{};
    queue_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queue_create_info.queueFamilyIndex = queue_family_indices.graphics_family.value();
    queue_create_info.queueCount = 1;
    float queue_priority = 1.0f;
    queue_create_info.pQueuePriorities = &queue_priority;
    VkPhysicalDeviceFeatures physical_device_features{};
    VkDeviceCreateInfo create_info{};
    create_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    create_info.pQueueCreateInfos = &queue_create_info;
    create_info.queueCreateInfoCount = 1;
    create_info.pEnabledFeatures = &physical_device_features;
    vkCreateDevice(selected_physical_device, &create_info, nullptr, &selected_logical_device);
    vkGetDeviceQueue(selected_logical_device, queue_family_indices.graphics_family.value(), 0, &graphics_queue);
}

/**
 * Destroy all Vulkan objects to free memory space.
 * This function is called when the program is terminated
 */
void DeviceHandler::cleanup() {
    vkDestroyDevice(selected_logical_device, nullptr);
}

/**
 * Get the selected physical device.
 * @return The physical device
 */
VkPhysicalDevice DeviceHandler::getPhysicalDevice() {
    return selected_physical_device;
}

/**
 * Get the selected logical device.
 * @return The logical device
 */
VkDevice DeviceHandler::getLogicalDevice() {
    return selected_logical_device;
}

/**
 * Get the graphics queue.
 * @return The graphics queue
 */
VkQueue DeviceHandler::getGraphicsQueue() {
    return graphics_queue;
}