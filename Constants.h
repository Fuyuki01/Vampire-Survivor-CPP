#pragma once

namespace GameConstants{
    // Window
    constexpr int HEIGHT = 800;
    constexpr int WIDTH = 600;

    // Map
    constexpr int MAP_HEIGHT = 160;
    constexpr int MAP_WIDTH = 160;
    constexpr float TILE_SIZE = 64.f;

    // Player
    constexpr float SPEED = 5.f;
    constexpr float PLAYER_HEALT = 300.f;
    constexpr float PLAYER_SIZE = 64.f;
    constexpr float BASE_ATTACK_SPEED = 4.f;

    // Enemy
        // Enemy Speed
    constexpr float ENEMYSPEED = 3.f;
    constexpr float TROLL_SPEED = 2.5;
    constexpr float GOBLIN_SPEED = 3.f;
        // Enemy Spawn Timer
    constexpr float ENEMY_SPAWN_TIME = 3.f;
    constexpr float ENEMYINITPOSITION_X = 100.f;
    constexpr float ENEMYINITPOSITION_Y = 100.f;
    constexpr float ENEMYSIZE = 64.f;
    constexpr float ENEMY_DAMAGE = 20.f;
    constexpr float ENEMY_HIT_FRAME = 1.f;
        // Enemy Health
    constexpr float TROLL_HEALTH = 300;
    constexpr float GOBLIN_HEALTH = 100;
        // Enemy XP
    constexpr float TROLL_XP = 50;
    constexpr float GOBLIN_XP = 25;

    // Sword
    constexpr float BASIC_SWORD_DAMAGE = 20;
    constexpr float SWORD_SIZE = 64.f;
}