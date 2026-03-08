#pragma once

namespace GameConstants{
    // Window
    constexpr int HEIGHT = 800;
    constexpr int WIDTH = 600;
    constexpr bool DEFAULT_FULL_SCREEN_STATUS = false;

    // Music
    constexpr int DEFAULT_MUSIC_VOLUME = 30;
    constexpr bool DEFAULT_MUSIC_STATUS = true;

    // Map
    constexpr int MAP_HEIGHT = 160;
    constexpr int MAP_WIDTH = 160;
    constexpr float TILE_SIZE = 64.f;

    // Player
    constexpr float SPEED = 5.f;
    constexpr float PLAYER_HEALTH = 300.f;
    constexpr float PLAYER_SIZE = 64.f;
    constexpr float BASE_ATTACK_SPEED = 4.f;

    // Knockback
    constexpr float KNOCKBACK_DISTANCE = 20.f;
    constexpr float KNOCKBACK_DECAY = 0.9f;
    constexpr float KNOCKBACK_COOLDOWN = 0.2f;
    

    // Cards
    constexpr float INCREASE_HEALTH_CARD = 300;
    constexpr float INCREASE_SPEED_CARD = 5.f;
    constexpr float INCREASE_DAMAGE_CARD = 40.f;

    // Enemy
        // Enemy Speed
    constexpr float ENEMYSPEED = 3.f;
    constexpr float TROLL_SPEED = 2.5;
    constexpr float HUMONGOUS_SPEED = 3.f;
    constexpr float GOBLIN_SPEED = 3.5f;
        // Enemy Spawn Timer
    constexpr float ENEMY_SPAWN_TIME = 3.f;
    constexpr float ENEMYINITPOSITION_X = 100.f;
    constexpr float ENEMYINITPOSITION_Y = 100.f;
    constexpr float ENEMYSIZE = 64.f;
    constexpr float ENEMY_DAMAGE = 20.f;
        // Enemy Hit Timer
    constexpr float ENEMY_HIT_FRAME = 1.f;
        // Enemy I frame
    constexpr float ENEMY_I_FRAME = 0.3f;
        // Enemy Health
    constexpr float TROLL_HEALTH = 60;
    constexpr float HUMONGOUS_HEALTH = 80;
    constexpr float GOBLIN_HEALTH = 40;
        // Enemy HitBox
    constexpr float TROLL_HITBOX_SIZE = 64.f;
    constexpr float HUMONGOUS_HITBOX_SIZE = 64.f;
    constexpr float GOBLIN_HITBOX_X = 48.f;
    constexpr float GOBLIN_HITBOX_Y = 42.f;
        // Enemy XP
    constexpr float TROLL_XP = 50;
    constexpr float HUMONGOUS_XP = 80;
    constexpr float GOBLIN_XP = 25;
    // Sword
    constexpr float BASIC_SWORD_DAMAGE = 20;
    constexpr float SWORD_SIZE = 64.f;
}