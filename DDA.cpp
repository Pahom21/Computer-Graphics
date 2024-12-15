//#include <glew.h>
//#include <glfw3.h>
//#include <iostream>
//#include <cmath>
//#include <stdio.h>
//
//using namespace std;
//
//// Question  1 on the line drawing
//// Window dimensions
//const GLint WIDTH = 800, HEIGHT = 600;
//
//void drawLineDDA(float x1, float y1, float x2, float y2) {
//
//    // Calculate dx and dy
//    float dx = x2 - x1;
//    float dy = y2 - y1;
//
//    // Calculate the number of steps
//    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
//
//    // Calculate the increment in x and y for each step
//    float xIncrement = dx / (float)steps;
//    float yIncrement = dy / (float)steps;
//
//    // Starting point (x1, y1)
//    float x = x1;
//    float y = y1;
//
//    // Draw points using DDA
//    glBegin(GL_POINTS);  // Start specifying points
//    for (int i = 0; i <= steps; i++) {
//        glVertex2f(x, y);  // Plot the point
//        x += xIncrement;
//        y += yIncrement;
//    }
//    glEnd();  // End point specification
//}
//
//int main() {
//    // Get input from the user for line coordinates
//    float x1, y1, x2, y2;
//    cout << "Enter the coordinates for the first point (x1, y1): ";
//    cin >> x1 >> y1;
//    cout << "Enter the coordinates for the second point (x2, y2): ";
//    cin >> x2 >> y2;
//
//    // Initialize GLFW
//    if (!glfwInit()) {
//        cout << "Failed to initialize GLFW" << endl;
//        return -1;
//    }
//
//    // Create a GLFW window
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "DDA Line Drawing", NULL, NULL);
//    if (!window) {
//        cout << "Failed to create GLFW window" << endl;
//        glfwTerminate();
//        return -1;
//    }
//
//    // Make the window's context current
//    glfwMakeContextCurrent(window);
//
//    // Initialize GLEW
//    if (glewInit() != GLEW_OK) {
//        cout << "Failed to initialize GLEW" << endl;
//        return -1;
//    }
//
//    // Set the viewport size
//    glViewport(0, 0, WIDTH, HEIGHT);
//
//    // Set orthographic projection matrix to match window coordinates
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(0.0, WIDTH, 0.0, HEIGHT, -1.0, 1.0);  // Set coordinate system
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
//    // Main loop
//    while (!glfwWindowShouldClose(window)) {
//        // Clear the window
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        // Set the drawing color to white
//        glColor3f(1.0f, 1.0f, 1.0f);
//
//        // Call the DDA line drawing function with user-input coordinates
//        drawLineDDA(x1, y1, x2, y2);
//
//        // Swap buffers
//        glfwSwapBuffers(window);
//
//        // Poll for and process events
//        glfwPollEvents();
//    }
//
//    // Terminate GLFW
//    glfwTerminate();
//    return 0;
//}