#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include<Core/Application/Application.h>
#include<imgui.h>

std::vector<glm::vec3> verticesS;
std::vector<unsigned int> indicesS;


void generateSphere(float radius, int slices, int stacks, std::vector<glm::vec3> &vertices, std::vector<unsigned int> &indices) {
    // Генерация вершин
    for (int i = 0; i <= stacks; ++i) {
        float theta = i * glm::pi<float>() / stacks; // Полярный угол
        float sinTheta = sin(theta);
        float cosTheta = cos(theta);

        for (int j = 0; j <= slices; ++j) {
            float phi = j * 2 * glm::pi<float>() / slices; // Азимутальный угол
            float sinPhi = sin(phi);
            float cosPhi = cos(phi);

            // Вычисляем координаты (x, y, z)
            float x = radius * sinTheta * cosPhi;
            float y = radius * cosTheta;
            float z = radius * sinTheta * sinPhi;
			
			
			unsigned int first = (i * (slices + 1)) + j;
            unsigned int second = first + slices + 1;
			if(i<stacks&&j<slices){

            // Добавляем два треугольника на каждую "квадратную" часть сферы
            indices.push_back(first);
            indices.push_back(second);
            indices.push_back(first + 1);

            indices.push_back(second);
            indices.push_back(second + 1);
            indices.push_back(first + 1);
			}

            // Добавляем координаты в массив вершин
            vertices.push_back(glm::vec3(x, y, z));
        }
    }

    // Генерация индексов для триангуляции
    //for (int i = 0; i < stacks; ++i) {
    //    for (int j = 0; j < slices; ++j) {
    //        unsigned int first = (i * (slices + 1)) + j;
    //        unsigned int second = first + slices + 1;
	//
    //        // Добавляем два треугольника на каждую "квадратную" часть сферы
    //        indices.push_back(first);
    //        indices.push_back(second);
    //        indices.push_back(first + 1);
	//
    //        indices.push_back(second);
    //        indices.push_back(second + 1);
    //        indices.push_back(first + 1);
    //    }
    //}
}

// Вершины куба
GLfloat vertices[] = {
    -0.5f, -0.5f,  0.5f,  // 0 передняя нижняя левая
     0.5f, -0.5f,  0.5f,  // 1 передняя нижняя правая
     0.5f,  0.5f,  0.5f,  // 2 передняя верхняя правая
    -0.5f,  0.5f,  0.5f,  // 3 передняя верхняя левая
    -0.5f, -0.5f, -0.5f,  // 4 задняя нижняя левая
     0.5f, -0.5f, -0.5f,  // 5 задняя нижняя правая
     0.5f,  0.5f, -0.5f,  // 6 задняя верхняя правая
    -0.5f,  0.5f, -0.5f   // 7 задняя верхняя левая
};

// Индексы для отрисовки куба
GLuint indices[] = {
    0, 1, 2, 2, 3, 0,  // Передняя грань
    4, 5, 6, 6, 7, 4,  // Задняя грань
    3, 2, 6, 6, 7, 3,  // Верхняя грань
    0, 1, 5, 5, 4, 0,  // Нижняя грань
    0, 3, 7, 7, 4, 0,  // Левая грань
    1, 2, 6, 6, 5, 1   // Правая грань
};

float angle = 0.0f; // Угол вращения
static float delta = 0.f;

void display() {
	
	
	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Очистка буферов

    glEnableClientState(GL_VERTEX_ARRAY); // Включаем массив вершин
    glVertexPointer(3, GL_FLOAT, 0, verticesS.data()); // Указываем массив вершин
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glDrawElements(GL_TRIANGLES, indicesS.size(), GL_UNSIGNED_INT, indicesS.data()); // Рисуем куб

    glDisableClientState(GL_VERTEX_ARRAY); // Отключаем массив вершин
}

void setup() {
    glEnable(GL_DEPTH_TEST); // Включаем тест глубины
}

int main() {
	
	Some some;
	std::cout<<some.x<<std::endl;
	
	
    // Инициализация GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

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
	       
        float radius = 1.f;
        //int slices = 24; // число долгих разрезов
        //int stacks = 16; // число вертикальных разрезов
		
		int slices = 44;
        int stacks = 34;		
		
        generateSphere(radius, slices, stacks, verticesS, indicesS);

		

    setup(); // Установка параметров OpenGL
	static bool open = true;

    // Основной цикл
    while (!glfwWindowShouldClose(window)) {
        glLoadIdentity();
		setup();
				
        glfwSetWindowSizeCallback(window,[](GLFWwindow* window, int width, int height){});
		glfwSetWindowRefreshCallback(window, [](GLFWwindow* window){ std::cout<<"changed"<<std::endl;});
		glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int xscale, int yscale){std::cout<<xscale<<std::endl;});
		
				

        // Обновление угла вращения
        angle += 0.5f; // Увеличиваем угол, чтобы вращать камеру

        // Матрица вида
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.0f)); // Перемещение камеры назад
        view = glm::rotate(view, glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.0f)); // Вращение вокруг оси Y
        glLoadMatrixf(glm::value_ptr(view)); // Загрузка матрицы вида

        // Матрица проекции
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f); // Перспективная проекция
        glMatrixMode(GL_PROJECTION);
        glLoadMatrixf(glm::value_ptr(projection)); // Загрузка матрицы проекции
        glMatrixMode(GL_MODELVIEW);

        display(); // Отрисовка

        glfwSwapBuffers(window); // Обмен буферов
        glfwPollEvents(); // Обработка событий
    }

    glfwTerminate(); // Завершение работы GLFW
    return 0;
}