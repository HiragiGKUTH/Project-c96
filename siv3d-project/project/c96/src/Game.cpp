#include <Siv3D.hpp>
#include "Game.hpp"

Game::Game(const InitData &init) : IScene(init) {
    this->dummy = Font(64);
    this->player = std::make_shared<Player>();
    this->enemyManager = std::make_shared<EnemyManager>();
}

void Game::update() {
    player->update();
    enemyManager->update();
    collisionAll();
}

void Game::draw() const {
    dummy(U"Game Scene").draw();
    Print << getData().difficulty;
    
    player->draw();
    enemyManager->draw();
}

void Game::collisionAll() {
    Circle* playerCollision = player->getCollision();
    Array<Circle*> enemyCollisions = enemyManager->getEnemyCollisions();
    for (auto& enemyCollision : enemyCollisions) {
        if (playerCollision->intersects(*enemyCollision)) {
            player->hit();
        }
    }
}
