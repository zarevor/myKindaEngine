#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include<Core/Application/Application.h>




int main()
{
	 // Инициализация GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
	
	glfwWindowHint(GLFW_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	

    // Создание окна
    GLFWwindow* window = glfwCreateWindow(800, 600, "3D Cube with Rotating Camera", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window); // Устанавливаем контекст для данного окна
    // Инициализация GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}