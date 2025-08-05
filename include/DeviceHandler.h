//
// Created by Matthias Amend on 02.08.25.
//

#ifndef OBJECT_RENDERING_TEST_DEVICEHANDLER_H
#define OBJECT_RENDERING_TEST_DEVICEHANDLER_H

#include <vulkan/vulkan.h>
#include <vector>

class DeviceHandler {

private:
    struct QueueFamilyIndices;
    static bool isDeviceSuitable(VkPhysicalDevice device);
    static QueueFamilyIndices findQueueFamilies(VkPhysicalDevice physical_device);

public:
    void identifyDevices(VkInstance instance);
    void selectSuitableDevice();
    void createLogicalDevice();
    VkPhysicalDevice getPhysicalDevice();

};


#endif //OBJECT_RENDERING_TEST_DEVICEHANDLER_H
