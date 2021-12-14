#include <stdio.h>
#include <GL/glfw.h>
#include <emscripten/emscripten.h>

double lastSceneRendered, currentSceneRendered;

typedef void (*renderFunc)();

void doRenderingLoop(renderFunc doRendering) {
    emscripten_set_main_loop(doRendering, 0, 1);
}

void renderGlScene(double delta) {
    
}

void renderFrame() {
    currentSceneRendered = glfwGetTime();
    renderGlScene(currentSceneRendered - lastSceneRendered);
    lastSceneRendered = currentSceneRendered;
    glfwSwapBuffers();
}

int main(void)
{
    /* Initialize the library */
    if (!glfwInit()) {
        printf("Could not initialize library\n");
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    if(glfwOpenWindow(640, 480, 0,0,0,0,16,0, GLFW_WINDOW) != GL_TRUE)
    {
        printf("Could not create OpenGL window\n");
        glfwTerminate();
        return -1;
    }

    lastSceneRendered = glfwGetTime();

    doRenderingLoop(&renderFrame);

    glfwTerminate();
    return 0;
}