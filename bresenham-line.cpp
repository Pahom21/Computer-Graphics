//#include <glew.h>
//#include <glfw3.h>
//#include <iostream>
//#include <cmath>
//#include <stdio.h>
//
//using namespace std;
//
//// Lab 3 on Bresenham's Line Drawing Algorithm
//
//// Window dimensions
//const GLint WIDTH = 800, HEIGHT = 600;
//
//// Function to draw a line using Bresenham's line drawing algorithm
//void drawLineBresenham(int x1, int y1, int x2, int y2) {
//    int dx = abs(x2 - x1);
//    int dy = abs(y2 - y1);
//    int sx = (x1 < x2) ? 1 : -1;
//    int sy = (y1 < y2) ? 1 : -1;
//    bool steep = dy > dx;
//
//    if (steep) {
//        swap(dx, dy);
//    }
//
//    int err = dx / 2;
//
//    int x = x1;
//    int y = y1;
//
//    glBegin(GL_POINTS);
//    for (int i = 0; i <= dx; i++) {
//        if (steep) {
//            glVertex2f(y, x);
//        }
//        else {
//            glVertex2f(x, y);
//        }
//
//        err -= dy;
//        if (err < 0) {
//            y += sy;
//            err += dx;
//        }
//        x += sx;
//    }
//    glEnd();
//}
//
//int main() {
//    // Get input from the user for line coordinates
//    int x1, y1, x2, y2;
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
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Bresenham Line Drawing", NULL, NULL);
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
//    glOrtho(0.0, WIDTH, 0.0, HEIGHT, -1.0, 1.0);  // Setting the coordinate system
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
//        // Call the Bresenham line drawing function with user-input coordinates
//        drawLineBresenham(x1, y1, x2, y2);
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