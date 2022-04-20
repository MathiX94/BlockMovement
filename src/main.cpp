/*
** PERSONAL PROJECT, 2021
** BlockMovement
** File description:
** main.cpp
*/

#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <PlayerSquare.hpp>
// #define SQUARE_SIZE(p) (p.getSprite().getTexture()->getSize())

void handle_events(sf::Event event, sf::RenderWindow &window)
{
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            window.close();
    }
}

void handle_movements(BM::PlayerSquare &player, sf::RenderWindow &window)
{
    int speed = 10;
    int x = window.getSize().x;
    int y = window.getSize().y;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        player.setMoveY(-speed);
        if (player.getY() < -30) {
            player.getSprite().setPosition(player.getX(), y);
            // std::cerr << "tp Z, x : " << player.getX() << ", y : " << player.getY() << std::endl;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        player.setMoveY(speed);
        if (player.getX() > y)
            player.getSprite().setPosition(player.getX(), -30);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        player.setMoveX(-speed);
        if (player.getX() < -30)
            player.getSprite().setPosition(x, player.getY());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.setMoveX(speed);
        if (player.getX() > x)
            player.getSprite().setPosition(-30, player.getY());
    }
    if (player.getMoveX() != 0 || player.getMoveY() != 0)
        player.update();
}

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(800,600), "BlockMovement");
    sf::Event event;
    sf::Image whiteSquare;
    sf::Texture wsTexture;
    sf::Sprite wsSprite;
    BM::PlayerSquare player;
    sf::Sprite fake;
    sf::Clock clock;
    sf::Clock pclock;
    int fps = 0;
    sf::Font defaultFont;
    sf::Text fpsText;

    window.setFramerateLimit(120);
    defaultFont.loadFromFile("fonts/Ubuntu-L.ttf");
    fpsText.setFont(defaultFont);
    fpsText.setCharacterSize(14);
    fpsText.setPosition(5,5);
    whiteSquare.create(30, 30, sf::Color::White);
    wsTexture.loadFromImage(whiteSquare);
    player.create(wsTexture);
    while (window.isOpen()) {
        handle_events(event, window);
        if (pclock.getElapsedTime().asMilliseconds() > 20) {
            handle_movements(player, window);
            pclock.restart();
        }
        if (clock.getElapsedTime().asMilliseconds() != 0)
            fps = 1000 / clock.restart().asMilliseconds();
        fpsText.setString(std::string("FPS: " + std::to_string(fps)));
        window.clear();
        window.draw(player.getSprite());
        window.draw(fpsText);
        window.display(); 
    }
    return 0;
}
