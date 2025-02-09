#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <optional>

int main() {
    // Create the window
    sf::RenderWindow window(sf::VideoMode({200, 200}), "SFML 3.0 works!");

    // Create a green circle with radius 100
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // Main loop
    while (window.isOpen()) {
        while (std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            // Add more event handling here if needed

            else if (event->is<sf::Event::Resized>()) {
                if (const auto* resized = event->getIf<sf::Event::Resized>()) {
                    std::cout << "new width: " << resized->size.x << std::endl;
                    std::cout << "new height: " << resized->size.y << std::endl;
                }
            }
        }

        // Clear the window
        window.clear();

        // Draw the circle
        window.draw(shape);

        // Display the frame
        window.display();
    }

    return 0;
}
