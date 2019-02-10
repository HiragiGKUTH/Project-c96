#include <Siv3D.hpp>
#include "Game.hpp"

Game::Game(const InitData &init) : IScene(init) {
    this->dummy = Font(64);
}

void Game::update() {
    
}

void Game::draw() const {
    dummy(U"Game Scene").draw();
}
