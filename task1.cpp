#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>

double red = 1.0;
double green = 1.0;
double blue = 1.0;

double v1_x = -0.3, v1_y = -0.5;
double v2_x = -0.3, v2_y = 0.5;
double v3_x = 0.5, v3_y = 0.5;



// Window dimensions
const GLuint WIDTH = 1280, HEIGHT = 720;

// The MAIN function, from here we start the application and run the game loop
int main()
{
    std::cout << "Starting GLFW context, OpenGL 3.1" << std::endl;

    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "glskeleton", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Set the required callback functions
    //glfwSetKeyCallback(window, key_callback);
   // glfwSetMouseButtonCallback(window, mouse_button_callback);
    //glfwSetCursorPosCallback(window, cursor_position_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }

    // Define the viewport dimensions
    glViewport(0, 0, WIDTH, HEIGHT);

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        // Render
        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        double time = glfwGetTime();
        double red_time = sin(time);
        double green_time = cos(time);
        double blue_time = tan(time);

        double v1_new_x = v1_x * cos(time) - v1_y * sin(time);
        double v1_new_y = v1_x * sin(time) + v1_y * sin(time);

        double v2_new_x = v2_x * cos(time) - v2_y * sin(time);
        double v2_new_y = v2_x * sin(time) + v2_y * sin(time);

        double v3_new_x = v3_x * cos(time) - v3_y * sin(time);
        double v3_new_y = v3_x * sin(time) + v3_y * sin(time);


        glBegin(GL_TRIANGLES);
        glColor3d(red_time, green_time, blue_time);
        glVertex2d(v1_new_x, v1_new_y);
        glVertex2d(v2_new_x, v2_new_y);
        glVertex2d(v3_new_x, v3_new_y);
        glEnd();

        // Swap the screen buffers
        glfwSwapBuffers(window);
    }

    // Terminates GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}