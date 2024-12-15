//#include <glew.h>
//#include <glfw3.h>
//#include <iostream>
//#include <cmath>
//#include <stdio.h>
//
//using namespace std;
//
//// Window dimensions
//const GLint WIDTH = 800, HEIGHT = 600;
//
//int main(){
//
//	// Initialize GLFW
//	if (!glfwInit()) {
//		printf("GLFW initialization failed!");
//		glfwTerminate();
//		return 1;
//	}
//
//	// Setup GLFW window properties
//	// OpenGL version
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//
//	// Core profile= No Backwords Compatibility
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	// Allow Forward Compatibility
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//
//	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
//
//	if (!mainWindow) {
//		printf("GLFW window creation failed");
//		glfwTerminate();
//		return 1;
//	}
//
//	// Get Buffer Size Information
//	int bufferWidth, bufferHeight;
//	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);
//
//	// Set context for GLEW to use
//	glfwMakeContextCurrent(mainWindow);
//
//	// Allow modern extension features
//	glewExperimental = GL_TRUE;
//
//	// Changed code below
//
//	/*return 0;*/
//	
//
//	// Allow modern extension features
//	glewExperimental = GL_TRUE;
//
//	if (glewInit() != GLEW_OK) {
//		printf("GLEW initialization failed!");
//		glfwDestroyWindow(mainWindow);
//		glfwTerminate();
//		return 1;
//	}
//
//	// Set up viewport size
//	glViewport(0, 0, bufferWidth, bufferHeight);
//
//	// Loop until window closed
//	while (!glfwWindowShouldClose(mainWindow)) {
//		// Get + Handle User Inputs
//		glfwPollEvents();
//
//		// Clear Window
//		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glfwSwapBuffers(mainWindow);
//	}
//
//	// Clean up
//	// Changed Code 
//	glfwDestroyWindow(mainWindow);
//	glfwTerminate();
//	return 0;
//}