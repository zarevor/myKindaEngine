# ������������� ����������� ������ CMake
cmake_minimum_required(VERSION 3.10)

# ������������� �������� C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")





# ������ ��� �������
project(MyProject CXX)




# ��������� ���� � ������������ ������
include_directories(include)
include_directories(include/glfw)
include_directories(include/glew)

include_directories(math)
include_directories(math)
include_directories(src)
include_directories(src/Graphics/glsl)

include_directories(imgui)

# ��������� ���� � �����������
link_directories(lib)

# ��������� ����������� ����
add_executable(my_program src/CubeAndSphere.cpp)

# ��������� ���������� � ��������
target_link_libraries(my_program glfw3 glew32 opengl32 gdi32 user32)





