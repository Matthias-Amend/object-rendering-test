//
// Created by Matthias Amend on 31.07.25.
//

#include "../include/Window.h"
#include <GLFW/glfw3.h>

GLFWwindow* window_object;

Window::Window(int width, int height, const char *title) {
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window_object = glfwCreateWindow(width, height, title, nullptr, nullptr);
}

void Window::destroyWindowObject() {
    glfwDestroyWindow(Window::window_object);
}

GLFWwindow* Window::getWindowObject() {
    return window_object;
}