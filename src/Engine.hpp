//
// Created by kamis on 21.10.2026.
#ifndef PRO_ENGINE_HPP
#define PRO_ENGINE_HPP
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include <string>
#include <optional>
#include <vector>
#include <memory>

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

    /**
     * @brief Czysci ekran na podany kolor
     * @param color Kolor ktory zostanie uzyty do wypelnienia ekranu
     */
    void clear(const sf::Color& color);

    /**
     * @brief Tworzy obraz o podanym rozmiarze i kolorze
     * @param width Szerokosc obrazu w px
     * @param height Wysokosc obrazu w px
     * @param color Kolor poczatkowy dla wszystkich px
     * @return Utworzony obraz
     */
    sf::Image createImage(
        unsigned int width,
        unsigned int height,
        const sf::Color& color);

    /**
     * @brief Wypelnia cala bitmape podanym kolorem
     * @param image Obraz ktory ma byc wyczyszczony
     * @param color Kolor wypelnienia
     */
    void clearImage(
        sf::Image& image,
        const sf::Color& color);

    /**
     * @brief Wyswietla obraz w oknie silnika
     * @param image Obraz do wyswietlenia
     * @param x Pozycja pozioma
     * @param y Pozycja pionowa
     */
    void drawImage(
        const sf::Image& image,
        float x,
        float y);

    /**
     * @brief Tworzy sprita na podstawie obrazu
     * @param image Obraz zrodlowy
     * @param x Pozycja pozioma Sprita
     * @param y Pozycja pionowa Sprita
     * @return Indeks utworzonego Sprita
     */
    std::size_t createSpirte(
        const sf::Image& image,
        float x,
        float y);

    /**
     * @brief Zamyka silnik i zwalnia zasoby
     */
    void shutdown();

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

    /**
     * @brief Tekstury do przechowywania przez silnik
     */
    std::vector<std::unique_ptr<sf::Texture>> textures;

    /**
     * @brief Sprite'y korzystajace z tekstur
     */
    std::vector<std::unique_ptr<sf::Sprite>> sprites;
};

#endif //PRO_ENGINE_HPP
