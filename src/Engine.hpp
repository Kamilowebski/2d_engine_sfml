//
// Created by kamis on 21.10.2026.
#ifndef PRO_ENGINE_HPP
#define PRO_ENGINE_HPP
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include <string>
#include <optional>

#include "SFML/Graphics/Text.hpp"

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

    /**
     * @brief Aktualizuje logike gry.
     * @param deltaTime Czas od poprzedniej klatki w sekundach
     */
    void update(float deltaTime);

private:
    /**
     * @brief Okno renderowania biblioteki SFML.
     */
    sf::RenderWindow window;

    /**
     * @brief Czcionka do wyświetlania
     */
    sf::Font font;
    std::optional<sf::Text> fpsText;

    /**
     * @brief Pomiar FPS
     */
    sf::Clock fpsClock;
    sf::Clock deltaClock;
    float deltaTime = 0.0f;
    unsigned int frameCount = 0;
    unsigned int currentFPS = 0;
};

#endif //PRO_ENGINE_HPP
