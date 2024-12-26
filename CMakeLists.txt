cmake_minimum_required(VERSION 3.16)
project(CustomFontExample)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Укажите путь к SFML и FreeType
set(SFML_DIR "C:/SFML/lib/cmake/SFML") # Путь к установленной SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(Freetype REQUIRED)

# Укажите исходные файлы
add_executable(CustomFontExample main.cpp)

# Связь с библиотеками SFML и FreeType
target_link_libraries(CustomFontExample PRIVATE sfml-graphics sfml-window sfml-system Freetype::Freetype)
