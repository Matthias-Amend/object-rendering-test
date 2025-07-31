//
// Created by Matthias Amend on 31.07.25.
//

#ifndef OBJECT_RENDERING_TEST_WINDOW_H
#define OBJECT_RENDERING_TEST_WINDOW_H

#include <GLFW/glfw3.h>

class Window {

private:
    GLFWwindow* window_object;

public:
    Window(int width, int height, const char *title);
    void destroyWindowObject();
    GLFWwindow* getWindowObject();

};


#endif //OBJECT_RENDERING_TEST_WINDOW_H
