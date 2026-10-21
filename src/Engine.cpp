//
// Created by kamis on 21.10.2026.
//
#include "Engine.hpp"

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
            sf::State::Windowed);
    }
    window.setFramerateLimit(fpsLimit);
}

void Engine::run() {
    while (window.isOpen()) {
        while (std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.display();
    }
}
