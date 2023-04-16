#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what versioan of OpenGL we are using
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile (meaning modern functions only)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFW object
	GLFWwindow* window = glfwCreateWindow(400, 225, "I made this!", NULL, NULL);
	// Check if window was created, return -1 otherwise
	if (window == NULL) {
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return -1;
	}
	// Add the window to the current context
	glfwMakeContextCurrent(window);

	// Load GLAD so it configures OpenGL
	gladLoadGL();

	// Specify the viewport of OpenGL in the window
	// In this case the viewport goes from x = 0, y = 0 to x = 800, y = 800 
	glViewport(0, 0, 400, 225);

	// Specify the color of the background
	glClearColor(0.75f, 0.25f, 0.0f, 1.0f);
	// Clean the back buffer and assign the new	color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Main while loop
	while (!glfwWindowShouldClose(window)) {
		// Do all GLFW events
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	// Delete window
	glfwDestroyWindow(window);
	// Terminate GLFW
	glfwTerminate();
	return 0;
}