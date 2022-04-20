/*
** EPITECH PROJECT, 2021
** BlockMovement
** File description:
** PlayerSquare.cpp
*/

#include <PlayerSquare.hpp>
#include <iostream>

BM::PlayerSquare::PlayerSquare()
{
    _move_x = 0;
    _move_y = 0;
}

BM::PlayerSquare::PlayerSquare(sf::Texture &texture)
{
    _sprite.setTexture(texture);
    _sprite.setPosition(30, 30);
    _move_x = 0;
    _move_y = 0;
}

void BM::PlayerSquare::create(sf::Texture &texture)
{
    _sprite.setTexture(texture);
    _sprite.setPosition(30, 30);
}

sf::Sprite BM::PlayerSquare::getSprite()
{
    return _sprite;
}

float BM::PlayerSquare::getX()
{
    return _sprite.getPosition().x;
}

float BM::PlayerSquare::getY()
{
    return _sprite.getPosition().y;
}

float BM::PlayerSquare::getMoveX()
{
    return _move_x;
}

float BM::PlayerSquare::getMoveY()
{
    return _move_y;
}

void BM::PlayerSquare::update()
{
    _sprite.move(_move_x, _move_y);
    if (_move_x > 0)
        _move_x -= 1;
    if (_move_y > 0)
        _move_y -= 1;
    if (_move_x < 0)
        _move_x += 1;
    if (_move_y < 0)
        _move_y += 1;
}

void BM::PlayerSquare::setMoveX(float moveX)
{
    _move_x = moveX;
}

void BM::PlayerSquare::setMoveY(float moveY)
{
    _move_y = moveY;
}

BM::PlayerSquare::~PlayerSquare()
{}
