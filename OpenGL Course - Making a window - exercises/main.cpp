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
	GLFWwindow* window = glfwCreateWindow(800, 800, "I made this!", NULL, NULL);
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

	float red = 1.0f, green = 0.0f, blue = 0.0f, change, speed = 10.0f, prev_time = float(glfwGetTime());// Initial values
	bool p = 1;

	// Main while loop
	while (!glfwWindowShouldClose(window)) {
		// Making a variable for changing the colors
		change = (float(glfwGetTime()) - prev_time) / speed;

		//Changing the colors from red to green to blue to red, repeat
		if (red > 0 && p) {
			red -= change;
			green += change;
		}
		else if (green > 0) {
			green -= change;
			blue += change;
			p = 0;
		}
		else if (blue > 0 && !p) {
			blue -= change;
			red += change;
		}
		else {
			p = 1;
			prev_time = float(glfwGetTime());
		}
		// Do stuff
		glClearColor(red, green, blue, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	// Delete window
	glfwDestroyWindow(window);
	// Terminate GLFW
	glfwTerminate();
	return 0;
}