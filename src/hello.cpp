#include<iostream>
#include<vector>
#include<map>
 #include <GL/glew.h>
   #include <GLFW/glfw3.h>
   #include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



 

// Вершинный шейдер
const char* vertexShaderSource = R"(
#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
out vec3 vertexColor;

void main() {
    gl_Position = vec4(position, 1.0);
    vertexColor = color;
}
)";

// Фрагментный шейдер
const char* fragmentShaderSource = R"(
#version 330 core
in vec3 vertexColor;
out vec4 fragColor;

void main() {
    fragColor = vec4(vertexColor, 1.0);
}
)";

// Функция для компиляции шедеров
GLuint compileShader(GLenum type, const char* source) {
    GLuint shaderID = glCreateShader(type);
    glShaderSource(shaderID, 1, &source, nullptr);
    glCompileShader(shaderID);
    
    // Проверка на ошибки компиляции
    GLint success;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar infoLog[512];
        glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << "\n";
    }
    return shaderID;
}

int main() {
    // Инициализация GLFW
    if (!glfwInit()) {
        std::cerr << "ERROR::GLFW::INIT_FAILED" << std::endl;
        return -1;
    }
	

    // Создание окна
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Modern OpenGL Triangle", nullptr, nullptr);
    if (!window) {
        std::cerr << "ERROR::WINDOW::CREATION_FAILED" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Инициализация GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "ERROR::GLEW::INIT_FAILED" << std::endl;
        return -1;
    }

    // Определим координаты треугольника
    float vertices[] = {
        // координаты    // цвета
        0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // Вершина 1: (x, y, z) с красным цветом
       -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // Вершина 2: (x, y, z) с зеленым цветом
        0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // Вершина 3: (x, y, z) с синим цветом
    };

    // Генерируем и связываем VAO, VBO
    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    // Устанавливаем параметры вершинного атрибута
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Компилируем шейдеры
    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    
    // Создаем шейдерную программу
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Основной цикл
	while (!glfwWindowShouldClose(window)) {
        // Обработка событий
        glfwPollEvents();

        // Отображение
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Использование шейдерной программы
        glUseProgram(shaderProgram);

        // Рисование треугольника
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        // Обмен кадров
        glfwSwapBuffers(window);
    }

    // Очистка ресурсов
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Завершение работы GLFW
    glfwTerminate();
    return 0;
}




