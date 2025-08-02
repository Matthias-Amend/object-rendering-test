//
// Created by Matthias Amend on 02.08.25.
//

#ifndef OBJECT_RENDERING_TEST_DEVICEHANDLER_H
#define OBJECT_RENDERING_TEST_DEVICEHANDLER_H

#include <vulkan/vulkan.h>
#include <vector>

class DeviceHandler {

private:
    VkPhysicalDevice physical_device;
    std::vector<VkPhysicalDevice> device_list;
    bool isDeviceSuitable(VkPhysicalDevice device);

public:
    void identifyDevices(VkInstance instance);
    void selectSuitableDevice();
    VkPhysicalDevice getPhysicalDevice();

};


#endif //OBJECT_RENDERING_TEST_DEVICEHANDLER_H
