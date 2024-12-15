#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <chrono>

using namespace std;

// Car Parking project

// Define M_PI if not already defined
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Car parameters
float carX = 0.0f, carY = 0.0f; // Position
float carAngle = 0.0f;          // Orientation

// Timer variables
auto startTime = std::chrono::high_resolution_clock::now();
float timeLimit = 60.0f; // 60 seconds

// Parking status
bool isParked = false;


// Callback for car movement
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        float newCarX = carX, newCarY = carY;

        if (key == GLFW_KEY_UP) {
            newCarX += 0.1f * cos(carAngle);
            newCarY += 0.1f * sin(carAngle);
        }
        else if (key == GLFW_KEY_DOWN) {
            newCarX -= 0.1f * cos(carAngle);
            newCarY -= 0.1f * sin(carAngle);
        }
        else if (key == GLFW_KEY_LEFT) {
            carAngle += 0.1f;
        }
        else if (key == GLFW_KEY_RIGHT) {
            carAngle -= 0.1f;
        }

        // Check if new position is within boundaries
        if (newCarX > -0.9f && newCarX < 0.9f && newCarY > -0.9f && newCarY < 0.9f) {
            carX = newCarX;
            carY = newCarY;
        }
    }
}

// Function to draw the parking lot
void drawParkingLot(int targetSlot) {
    // Parking lot boundary
    glColor3f(0.3f, 0.3f, 0.3f); // Dark grey background
    glBegin(GL_QUADS);
    glVertex2f(-0.9f, -0.9f);
    glVertex2f(0.9f, -0.9f);
    glVertex2f(0.9f, 0.9f);
    glVertex2f(-0.9f, 0.9f);
    glEnd();

    // Slot coordinates
    float slotX[] = { -0.7f, 0.7f }; // Left and right column
    float slotY[] = { -0.8f, -0.5f, -0.2f, 0.1f, 0.4f, 0.7f }; // Rows

    int slotNumber = 1;
    for (int x = 0; x < 2; ++x) {          // Columns
        for (int y = 0; y < 6; ++y) {      // Rows
            if (slotNumber == targetSlot) {
                glColor3f(0.0f, 1.0f, 0.0f); // Green for target slot
            }
            else {
                glColor3f(1.0f, 1.0f, 1.0f); // White for other slots
            }

            // Draw slot
            glBegin(GL_LINE_LOOP);
            glVertex2f(slotX[x] - 0.1f, slotY[y] - 0.1f);
            glVertex2f(slotX[x] + 0.1f, slotY[y] - 0.1f);
            glVertex2f(slotX[x] + 0.1f, slotY[y] + 0.1f);
            glVertex2f(slotX[x] - 0.1f, slotY[y] + 0.1f);
            glEnd();

            ++slotNumber; // Increment slot number
        }
    }
}

// Function to draw the car
void drawCar() {
    glPushMatrix();
    glTranslatef(carX, carY, 0.0f);
    glRotatef(carAngle * 180.0f / M_PI, 0.0f, 0.0f, 1.0f);

    // Front part (red)
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, -0.05f);
    glVertex2f(0.1f, -0.05f);
    glVertex2f(0.1f, 0.05f);
    glVertex2f(0.0f, 0.05f);
    glEnd();

    // Back part (blue)
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, -0.05f);
    glVertex2f(0.0f, -0.05f);
    glVertex2f(0.0f, 0.05f);
    glVertex2f(-0.1f, 0.05f);
    glEnd();

    glPopMatrix();
}

// Function to draw obstacles
void drawObstacles() {
    // Draw a parked car
    glColor3f(0.5f, 0.0f, 0.0f); // Dark red
    glBegin(GL_QUADS);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.2f, -0.3f);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(-0.4f, -0.1f);
    glEnd();

    // Draw a cone
    glColor3f(1.0f, 0.5f, 0.0f); // Orange
    glBegin(GL_TRIANGLES);
    glVertex2f(0.3f, 0.4f);
    glVertex2f(0.25f, 0.35f);
    glVertex2f(0.35f, 0.35f);
    glEnd();
}

// Function to check collision
bool checkCollision(float carX, float carY, float obsX, float obsY, float obsWidth, float obsHeight) {
    float carWidth = 0.2f, carHeight = 0.1f;

    return (carX - carWidth / 2 < obsX + obsWidth / 2 &&
        carX + carWidth / 2 > obsX - obsWidth / 2 &&
        carY - carHeight / 2 < obsY + obsHeight / 2 &&
        carY + carHeight / 2 > obsY - obsHeight / 2);
}

// Function to check if car is parked
void checkParkingSlot(int targetSlot) {
    float slotX[] = { -0.7f, 0.7f }; // Left and right column
    float slotY[] = { -0.8f, -0.5f, -0.2f, 0.1f, 0.4f, 0.7f }; // Rows

    int slotIndex = targetSlot - 1;
    int xIndex = slotIndex / 6;
    int yIndex = slotIndex % 6;

    float slotCenterX = slotX[xIndex];
    float slotCenterY = slotY[yIndex];
    float slotWidth = 0.2f, slotHeight = 0.2f;

    // Check if car is within the target slot
    if (fabs(carX - slotCenterX) < slotWidth / 2 && fabs(carY - slotCenterY) < slotHeight / 2) {
        isParked = true;
        std::cout << "Car parked successfully in slot " << targetSlot << "!\n";
        glfwSetWindowShouldClose(glfwGetCurrentContext(), GLFW_TRUE);
    }
}


// Function to display remaining time
void displayTimer(float elapsedTime, float timeLimit) {
    std::cout << "Time Remaining: " << (timeLimit - elapsedTime) << " seconds\r";
}

// Main function
int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Car Parking Challenge", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    glfwSetKeyCallback(window, keyCallback);

    int targetSlot = 6; // Slot number to park the car

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Timer
        auto currentTime = std::chrono::high_resolution_clock::now();
        float elapsedTime = std::chrono::duration<float>(currentTime - startTime).count();
        if (elapsedTime > timeLimit) {
            std::cout << "Time's up! You failed to park.\n";
            break;
        }
        displayTimer(elapsedTime, timeLimit);

        // Draw scene
        drawParkingLot(targetSlot);
        drawObstacles();
        checkParkingSlot(targetSlot);

        // Check collisions
        if (checkCollision(carX, carY, -0.3f, -0.2f, 0.2f, 0.2f)) {
            std::cout << "Collision with parked car!\n";
        }
        if (checkCollision(carX, carY, 0.3f, 0.4f, 0.1f, 0.1f)) {
            std::cout << "Collision with cone!\n";
        }

        drawCar();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}



