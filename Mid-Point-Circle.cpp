//#include <glew.h>
//#include <glfw3.h>
//#include <iostream>
//#include <cmath>
//#include <stdio.h>
//
//using namespace std;
//
//// Lab 4 on Mid-Point Circle Drawing Algorithm
//
//const int WIDTH = 800;
//const int HEIGHT = 600;
//
//// Function to plot a point and its symmetric counterparts
//void plotCirclePoints(int xc, int yc, int x, int y) {
//    glBegin(GL_POINTS);
//    glVertex2i(xc + x, yc + y);
//    glVertex2i(xc - x, yc + y);
//    glVertex2i(xc + x, yc - y);
//    glVertex2i(xc - x, yc - y);
//    glVertex2i(xc + y, yc + x);
//    glVertex2i(xc - y, yc + x);
//    glVertex2i(xc + y, yc - x);
//    glVertex2i(xc - y, yc - x);
//    glEnd();
//}
//
//// Midpoint Circle Drawing Algorithm
//void drawCircle(int xc, int yc, int radius) {
//    int x = 0, y = radius;
//    int p = 1 - radius;
//
//    plotCirclePoints(xc, yc, x, y);
//
//    while (x < y) {
//        x++;
//        if (p < 0) {
//            p += 2 * x + 1;
//        }
//        else {
//            y--;
//            p += 2 * (x - y) + 1;
//        }
//        plotCirclePoints(xc, yc, x, y);
//    }
//}
//
//void initOpenGL() {
//    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
//    glColor3f(1.0, 1.0, 1.0);          // Set drawing color to white
//    glPointSize(2.0);                  // Set point size for better visibility
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);  // The coordinate system
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//}
//
//int main() {
//    if (!glfwInit()) {
//        std::cerr << "Failed to initialize GLFW" << std::endl;
//        return -1;
//    }
//
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Midpoint Circle", NULL, NULL);
//    if (!window) {
//        std::cerr << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//
//    glfwMakeContextCurrent(window);
//    glewInit();
//
//    initOpenGL();
//
//    int xc = WIDTH / 2;
//    int yc = HEIGHT / 2;
//    int radius = 200;
//
//    while (!glfwWindowShouldClose(window)) {
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        drawCircle(xc, yc, radius);
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//    return 0;
//}