#include <Siv3D.hpp>
#include "Game.hpp"

Game::Game(const InitData &init) : IScene(init) {
    loadNotes();
    
    this->dummy = Font(64);
    this->board = std::make_shared<Board>();
    this->player = std::make_shared<Player>();
    this->enemyManager = std::make_shared<EnemyManager>(getData().trackInfo.bpm, getData().trackInfo.frac, getData().trackInfo.denom, this->notes);
    this->trackAudio = Audio(getData().trackInfo.musicPath);
    this->gameTimer.start();
}

void Game::update() {
    player->update();
    board->update();
    collisionAll();
    
    if (gameTimer.sF() < beginTime)
        return;
    
    if (!trackTimer.isRunning()) {
        trackTimer.start();
        enemyManager->beginTimer();
        trackAudio.play();
    }
    
    
    enemyManager->update();
    
    
    // dbg messages
    Print << U"begin " << trackTimer.sF() << U" s.";
    Print << U"bpm " << getData().trackInfo.bpm;
    Print << U"wav file " << getData().trackInfo.musicPath;
    Print << U"csv file " << getData().trackInfo.scorePath;
    
}

void Game::draw() const {
    dummy(U"Game Scene").draw();

    player->draw();
    enemyManager->draw();
    board->draw();
}

bool Game::loadNotes() {
    CSVData csv;

    if (csv.load(getData().trackInfo.scorePath)) {
        Logger << U"On Game Scene, fail to load score data";
        return false;
    }
    
    for (auto& row : csv.getData()) {
        std::pair<double, GameDefine::ePlayerPos> note;
        note.first = ParseFloat<double>(row[0]);
        note.second = static_cast<GameDefine::ePlayerPos>(ParseInt<int>(row[1]));
        notes.push_back(note);
    }
    return true;
}

void Game::collisionAll() {
    Circle* playerCollision = player->getCollision();
    Array<Circle*> playerShotCollisions = player->getShotCollisions();
    
    Array<Circle*> enemyCollisions = enemyManager->getCollisions();
    Array<Circle*> enemyBulletCollisions = enemyManager->getBulletCollisions();
    
    collisionEnemyToPlayer(playerCollision, enemyBulletCollisions);
    collisionPlayerToEnemy(playerShotCollisions, enemyCollisions);
}

void Game::collisionEnemyToPlayer(Circle* pCol, Array<Circle*> eBulletCols) {
    for (auto& eBulletCol : eBulletCols) {
        if (pCol->intersects(*eBulletCol)) {
            player->hit();
            break;
        }
    }
}

void Game::collisionPlayerToEnemy(Array<Circle*> pShotCols, Array<Circle*> eCols) {
    for (auto& pShotCol : pShotCols) {
        for (auto& eCol : eCols) {
            if (eCol->intersects(*pShotCol)) {
                Print << U"Player to Enemy Hit";
                break;
            }
        }
    }
}
