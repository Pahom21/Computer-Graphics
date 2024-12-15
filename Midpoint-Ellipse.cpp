#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

// Lab 5 on Midpoint Ellipse Drawing Algorithm
const int WIDTH = 800;
const int HEIGHT = 600;
const float PI = 3.14159265358979323846;

// Draws an ellipse using parametric equations
void drawEllipse(float xc, float yc, float radiusX, float radiusY) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 360; i++) {
        float theta = i * PI / 180.0;
        float x = xc + radiusX * cos(theta);
        float y = yc + radiusY * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

// Function to draw the wireframe globe
void drawGlobe(int xc, int yc, int radius) {
    int numLatitudes = 10;  // Number of horizontal ellipses (latitude lines)
    int numLongitudes = 10; // Number of vertical ellipses (longitude lines)

    // Draw latitude circles
    for (int i = 0; i <= numLatitudes; i++) {
        float angle = i * PI / numLatitudes;
        float r = radius * sin(angle);       // Radius of each latitude ellipse
        float zOffset = radius * cos(angle); // Offset for each latitude
        drawEllipse(xc, yc + zOffset, r, r);
    }

    // Draw longitude lines
    for (int i = 0; i < numLongitudes; i++) {
        float angle = i * 2 * PI / numLongitudes;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glBegin(GL_LINE_STRIP);
        for (int j = -radius; j <= radius; j += 20) {
            float r = sqrt(radius * radius - j * j); // Radius for each longitude
            float px = xc + r * cos(angle);
            float py = yc + j;
            glVertex2f(px, py);
        }
        glEnd();
    }
}

void initOpenGL() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Background color black
    glColor3f(1.0, 1.0, 1.0);          // Drawing color white
    glPointSize(1.0);                  // Smaller point size for wireframe
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1); // Set coordinate system
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Wireframe Globe", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    initOpenGL();

    int xc = WIDTH / 2;
    int yc = HEIGHT / 2;
    int radius = 200;

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        drawGlobe(xc, yc, radius);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}