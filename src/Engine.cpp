//
// Created by kamis on 21.10.2026.
//
#include "Engine.hpp"

#include <iostream>

#include "SFML/Graphics/Sprite.hpp"

Engine::Engine(
    unsigned int width,
    unsigned int height,
    const std::string& title,
    bool fullscreen,
    unsigned int fpsLimit) {
    if (fullscreen) {
        window.create(sf::VideoMode({width, height}),
            title,
            sf::State::Fullscreen);
    } else {
        window.create(sf::VideoMode({width, height}),
            title,
            sf::Style::Default,
            sf::State::Windowed);
    }
    window.setFramerateLimit(fpsLimit);

    //wczytanie czcionki
    if (font.openFromFile("arial.ttf")) {
        fpsText.emplace(font, "FPS: 0", 18);
        fpsText->setPosition({10.f, 10.f});
        fpsText->setFillColor(sf::Color::White);
    } else {
        std::cerr << "Nie udalo sie wczytac cziocnki!\n";
    }
}

void Engine::run() {

    //TEST CZY DZIALA TWORZENIE
    sf::Image testImage(
        sf::Vector2u(100, 100),
        sf::Color::Red);

    while (window.isOpen()) {
        while (std::optional event = window.pollEvent()) {
            // zamknięcie okna
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            //nacisniecie klawisza
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::Escape) {
                    window.close();
                }
                if (keyPressed->code == sf::Keyboard::Key::W) {
                    std::cout << "Nacisnieto W";
                }
                if (keyPressed->code == sf::Keyboard::Key::Space) {
                    std::cout << "Nacisnieto Space";
                }
            }

            //puszczenie klawisza
            if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
                if (keyReleased->code == sf::Keyboard::Key::W) {
                    std::cout << "Puszczono W";
                }
            }

            //Klikniecie klawisza myszy
            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mousePressed->button == sf::Mouse::Button::Left) {
                    std::cout << "Nacisnieto L" << mousePressed->position.x << ", " << mousePressed->position.y << std::endl;
                }
            }


            //Ruch myszy
            if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) {
                std::cout << mouseMoved->position.x << ", " << mouseMoved->position.y << std::endl;
            }
        }
        frameCount++;
        if (fpsClock.getElapsedTime() >= sf::seconds(1)) {
            currentFPS = frameCount;
            frameCount = 0;

            fpsClock.restart();

            if (fpsText.has_value()) {
                fpsText->setString("FPS: " + std::to_string(currentFPS));
            }
        }

        //Pomiar czasu od poprzedniej klatki
        deltaTime = deltaClock.restart().asSeconds();
        //Aktualizacja logiki gry
        update(deltaTime);

        //Rysowanie klatki
        clear(sf::Color::Black);
        drawImage(testImage, 100.0f, 100.0f);
        if (fpsText.has_value()){
            window.draw(*fpsText);
        }
        window.display();
    }
}

void Engine::update(float deltaTime) {

}

void Engine::clear(const sf::Color &color) {
    window.clear(color);
}

sf::Image Engine::createImage(unsigned int width, unsigned int height, const sf::Color &color) {
    sf::Image image(
        sf::Vector2u(width, height),
        color);
    return image;
}

void Engine::clearImage(sf::Image &image, const sf::Color &color) {
    sf::Vector2u size = image.getSize();
    for (unsigned int y = 0; y < size.y; y++) {
        for (unsigned int x = 0; x < size.x; x++) {
            image.setPixel(
                sf::Vector2u(x, y),
                color);
        }
    }
}

void Engine::drawImage(const sf::Image &image, float x, float y) {
    sf::Texture texture(image);
    sf::Sprite sprite(texture);
    sprite.setPosition({x, y});
    window.draw(sprite);
}

std::size_t Engine::createSpirte(const sf::Image &image, float x, float y) {
    //Tworzenie tekstury
    sf::Texture texture(image);

    //Przenoszenie tekstury do zasobow silnika
    textures.push_back(texture);

    //Tworzenie sprita korzystajacego z zapisanej tekstury
    auto sprite = std::make_unique<sf::Sprite>(textures.back());

    //Ustalanie pozycji
    sprite->setPosition({x, y});

    //Zapisanie sprite w silniku
    sprites.push_back(std::move(sprite));

    //Zwraca indeks spirta
    return sprites.size() - 1;
}
