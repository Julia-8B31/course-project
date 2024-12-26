#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

int main() {
    // Инициализация окна SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Custom Font");
    window.setFramerateLimit(60);

    // Загрузка шрифта с помощью FreeType
    std::string font_path = "D:/programming2/CUUUURS/fontt/72/72.ttf"; 
    FT_Library ft;
    if (FT_Init_FreeType(&ft)) {
        std::cerr << "Could not initialize FreeType library" << std::endl;
        return -1;
    }

    FT_Face face;
    if (FT_New_Face(ft, font_path.c_str(), 0, &face)) {
        std::cerr << "Could not open font file: " << font_path << std::endl;
        FT_Done_FreeType(ft);
        return -1;
    }

    // Установка размера шрифта
    int pixel_size = 60;
    if (FT_Set_Pixel_Sizes(face, 0, pixel_size)) {
        std::cerr << "Could not set font size to " << pixel_size << " pixels." << std::endl;
        FT_Done_Face(face);
        FT_Done_FreeType(ft);
        return -1;
    }

    // Загрузка шрифта в SFML
    sf::Font font;
    if (!font.loadFromFile(font_path)) {
        std::cerr << "Failed to load font for SFML." << std::endl;
        FT_Done_Face(face);
        FT_Done_FreeType(ft);
        return -1;
    }

    // Создание текста
    sf::Text text;
    text.setFont(font);
    text.setString("Hi )))");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 100);

    // Главный цикл
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black); // Очистка окна
        window.draw(text);              // Отрисовка текста
        window.display();               // Отображение на экране
    }

    // Освобождение ресурсов FreeType
    FT_Done_Face(face);
    FT_Done_FreeType(ft);

    return 0;
}
