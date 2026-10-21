//
// Created by kamis on 21.10.2026.
#ifndef PRO_ENGINE_HPP
#define PRO_ENGINE_HPP
#include "SFML/Graphics/RenderWindow.hpp"
#include <string>

/**
 * @brief Główna klasa silnika 2D
 * Odpowiada za uruchomienie i utworzenie okna aplikacji.
 */
class Engine {
public:
    /**
     * @brief Tworzy silnik i konfiguruje okno.
     * @param width Szerokość okna
     * @param height Wysokość okna
     * @param title Tytuł okna
     * @param fullscreen Określa czy okno ma się uruchomić w trybie pełnoekranowym
     * @param fpsLimit Maksymalna ilość FPS, 0 - bez limitu
     */
    Engine(
        unsigned int width,
        unsigned int height,
        const std::string& title,
        bool fullscreen,
        unsigned int fpsLimit);

    /**
     * @brief Uruchamia główną pętle silnika.
     */
    void run();

private:
    /**
     * @brief Okno renderowania biblioteki SFML.
     */
    sf::RenderWindow window;
};

#endif //PRO_ENGINE_HPP
