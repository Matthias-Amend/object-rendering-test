//
// Created by Matthias Amend on 31.07.25.
//

#include "../include/Window.h"

GLFWwindow* window_object;

Window::Window(int width, int height, const char *title) {
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window_object = glfwCreateWindow(width, height, title, nullptr, nullptr);
}

/**
 * Destroy the window object.
 * Function called after the program has ended to free up resources
 */
void Window::destroyWindowObject() {
    glfwDestroyWindow(Window::window_object);
}

/**
 * Get the window object.
 * @return The window object
 */
GLFWwindow* Window::getWindowObject() {
    return window_object;
}