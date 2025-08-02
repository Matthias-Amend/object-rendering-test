//
// Created by Matthias Amend on 02.08.25.
//

#include "../include/DeviceHandler.h"

VkPhysicalDevice physical_device = VK_NULL_HANDLE;
std::vector<VkPhysicalDevice> device_list;

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
 * Select the first suitable GPU device in the device_list.
 * The selected device does not have to be the best suited, just the first
 */
void DeviceHandler::selectSuitableDevice() {
    for(const auto& device : device_list) {
        if(isDeviceSuitable(device)) {
            DeviceHandler::physical_device = device;
            break;
            //TODO implement score mechanic, so that selected physical device is the best suited and not just the first
        }
    }
}

/**
 * Check if a specific device has the desired features to run the program.
 * @param device The device
 * @return True if the device possesses the desired features, false otherwise
 */
bool DeviceHandler::isDeviceSuitable(VkPhysicalDevice device) {
    VkPhysicalDeviceProperties device_properties;
    VkPhysicalDeviceFeatures device_features;
    vkGetPhysicalDeviceProperties(device, &device_properties);
    vkGetPhysicalDeviceFeatures(device, &device_features);
    return device_properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU &&
           device_features.geometryShader;
}

/**
 * Get the selected physical device.
 * @return The physical device
 */
VkPhysicalDevice DeviceHandler::getPhysicalDevice() {
    return DeviceHandler::physical_device;
}