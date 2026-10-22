//
// Created by kamis on 21.10.2026.
//
#include "Engine.hpp"

#include <iostream>

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
    while (window.isOpen()) {
        while (std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
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

        window.clear(sf::Color::Black);
        if (fpsText.has_value()){
            window.draw(*fpsText);
        }
        window.display();
    }
}
