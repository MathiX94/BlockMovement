/*
** EPITECH PROJECT, 2021
** BlockMovement
** File description:
** PlayerSquare.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>

namespace BM
{
    class PlayerSquare
    {
    private:
        sf::Sprite _sprite;
        float _move_x;
        float _move_y;
    public:
        PlayerSquare();
        PlayerSquare(sf::Texture &texture);
        void create(sf::Texture &texture);
        sf::Sprite getSprite();
        float getX();
        float getY();
        float getMoveX();
        float getMoveY();
        void update();
        void setMoveX(float moveX);
        void setMoveY(float moveY);
        ~PlayerSquare();
    };
} // namespace BlockMovement

