//#include <glew.h>
//#include <glfw3.h>
//#include <iostream>
//#include <cmath>
//#include <stdio.h>
//
//using namespace std;
//
//// Question 2 on chess
//const int WINDOW_WIDTH = 600;
//const int WINDOW_HEIGHT = 600;
//const int BOARD_SIZE = 8;
//const float SQUARE_SIZE = 2.0f / BOARD_SIZE;
//float scale = 0.5f; // Scaling factor for the chessboard size
//
//void DDA(float x1, float y1, float x2, float y2) {
//    float dx = x2 - x1;
//    float dy = y2 - y1;
//
//    int steps = std::max(std::abs(dx), std::abs(dy)) * 100; // Increase accuracy
//
//    float x_inc = dx / steps;
//    float y_inc = dy / steps;
//
//    float x = x1;
//    float y = y1;
//
//    glBegin(GL_POINTS);
//    for (int i = 0; i < steps; i++) {
//        glVertex2f(x, y);
//        x += x_inc;
//        y += y_inc;
//    }
//    glEnd();
//}
//
//void drawChessBoard() {
//    bool isWhite = false;
//
//    // Draw the board by alternating colors and drawing squares
//    for (int i = 0; i < BOARD_SIZE; ++i) {
//        for (int j = 0; j < BOARD_SIZE; ++j) {
//            if (isWhite) {
//                glColor3f(1.0f, 1.0f, 1.0f); // White color
//            }
//            else {
//                glColor3f(0.0f, 0.0f, 0.0f); // Black color
//            }
//            isWhite = !isWhite;
//
//            float x1 = -scale + j * SQUARE_SIZE * scale;
//            float y1 = -scale + i * SQUARE_SIZE * scale;
//            float x2 = x1 + SQUARE_SIZE * scale;
//            float y2 = y1 + SQUARE_SIZE * scale;
//
//            glBegin(GL_QUADS); // Draw filled square
//            glVertex2f(x1, y1);
//            glVertex2f(x2, y1);
//            glVertex2f(x2, y2);
//            glVertex2f(x1, y2);
//            glEnd();
//        }
//        isWhite = !isWhite; // Alternate starting color for each row
//    }
//
//    // Draw grid lines using the DDA algorithm
//    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the lines
//    for (int i = 0; i <= BOARD_SIZE; ++i) {
//        float pos = -scale + i * SQUARE_SIZE * scale;
//        DDA(-scale, pos, scale, pos);  // Horizontal lines
//        DDA(pos, -scale, pos, scale);  // Vertical lines
//    }
//}
//
//int main() {
//    // Initialize GLFW
//    if (!glfwInit()) {
//        std::cerr << "Failed to initialize GLFW!" << std::endl;
//        return -1;
//    }
//
//    // Create a windowed mode window and its OpenGL context
//    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chessboard with DDA", NULL, NULL);
//    if (!window) {
//        glfwTerminate();
//        return -1;
//    }
//
//    // Make the window's context current
//    glfwMakeContextCurrent(window);
//
//    // Initialize GLEW
//    glewExperimental = GL_TRUE;
//    if (glewInit() != GLEW_OK) {
//        std::cerr << "Failed to initialize GLEW!" << std::endl;
//        return -1;
//    }
//
//    // Set the viewport
//    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
//
//    // Set the background color
//    glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
//
//    // Main loop
//    while (!glfwWindowShouldClose(window)) {
//        // Clear the screen
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        // Draw the chessboard
//        drawChessBoard();
//
//        // Swap front and back buffers
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
//
