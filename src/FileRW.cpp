

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

int main()
{
	
	
	std::string s; // сюда будем класть считанные строки
	std:: string text;
    std::ifstream file("../src/Graphics/glsl/v_shader.glsl"); // файл из которого читаем (для линукс путь будет выглядеть по другому)
    while(getline(file, s)){ // пока не достигнут конец файла класть очередную строку в переменную (s)
        //std::cout << s << std::endl; // выводим на экран
        text += s + "\n"; // что нибудь делаем со строкой например я добавляю 
    }
    file.close();
	
	std::cout<<text<<std::endl;
	system("pause");
	
	return 0;
}