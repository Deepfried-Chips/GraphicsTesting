//
// Created by chips on 11/4/23.
//

#include "Device.h"
#include <glad/gl.h>
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

using namespace game;

bool Device::createBackend(bool forceOpenGL) {

    if (!glfwInit())
        return false;

    if (!forceOpenGL)
        Device::vulkanSupported = glfwVulkanSupported();

    return true;
}
