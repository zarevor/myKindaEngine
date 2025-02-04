# Устанавливаем минимальную версию CMake
cmake_minimum_required(VERSION 3.10)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")





# Задаем имя проекта
project(MyProject CXX)




# Указываем пути к заголовочным файлам
include_directories(include)
include_directories(include/glfw)
include_directories(include/glew)

include_directories(math)
include_directories(math)
include_directories(src)
include_directories(src/Graphics/glsl)

include_directories(imgui)

# Указываем пути к библиотекам
link_directories(lib)

# Добавляем исполняемый файл
add_executable(my_program src/CubeAndSphere.cpp)

# Связываем библиотеки с проектом
target_link_libraries(my_program glfw3 glew32 opengl32 gdi32 user32)





