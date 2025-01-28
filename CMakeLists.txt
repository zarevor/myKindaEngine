# Устанавливаем минимальную версию CMake
cmake_minimum_required(VERSION 3.10)

# Задаем имя проекта
project(MyProject)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем пути к заголовочным файлам
include_directories(include)
include_directories(include/glfw)
include_directories(include/glew)

include_directories(math)
include_directories(math)
include_directories(src)

# Указываем пути к библиотекам
link_directories(lib)

# Добавляем исполняемый файл
add_executable(my_program src/hello2.cpp)

# Связываем библиотеки с проектом
target_link_libraries(my_program glfw3 glew32 opengl32 gdi32 user32)


