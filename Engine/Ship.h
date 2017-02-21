#pragma once
#include "Graphics.h"
#include "BulletManager.h"
#include "Health.h"
#include "Keyboard.h"
#include "RectF.h"
#include "Sound.h"
#include "Vec2.h"
#include "Animation.h"

class Ship
{
public:
	Ship(BulletManager& Manager, Surface& ShipSurface, 
		Surface& red, AnimationFrames& shiprekt, Surface& rektsurface, 
		AnimationFrames& holeAnim, AnimationFrames& holeRektAnim, AnimationFrames& shipexplo, AnimationFrames& exhaustAnim);
	void HandleCollision(int Damage);
	void Draw(Graphics& gfx);
	void Update(Keyboard& wnd, float dt);
	void Restore(int restore);
	bool HasHealth() const;
	RectF GetCollisionRect();
	
	float GetX() const;
	float GetWidth() const;
	float GetY() const;
	float GetHeight() const;
	int GetHealth() const;
	
	void SethitTarget(bool hit);
	void AddGravity(Vec2& gravity);
	void SetY(float Y);
	void SetX(float X);
	int GetDmg() const;
	void CollidesWithHole(bool collides);
	void Reset();
	bool IsDead() const;

private:
	void PlayerInput(Keyboard& wnd, float dt);
	void ClampScreen();

private:
	bool hitTarget = false;
	Vec2 pos = Vec2(300.0f, 300.0f);
	static constexpr float canonX = 45.0f;
	static constexpr float canonY = 20.0f;
	float speed = 360.0f;
	float width = 90.0f;
	float height = 90.0f;
	Health health;
	bool healthChanging = false;
	float padding = 35.0f;
	BulletManager& bManager;
	Surface& shipSurface;
	Surface& redSurface;
	Surface& rektSurface;
	bool isMoving = false;
	static constexpr int dmg = 60;
	bool isHit = false;
	int isHitCounter = 0;
	Animation shipRekt;
	static constexpr int lowHealth = 75;

	bool collidesWithHole = false;
	Animation blackHole;
	Animation blackHoleRekt;
	Animation shipExplo;
	Animation exhaust;
	bool isDead = false;
	static constexpr int exploX = 196;
	static constexpr int exploY = 239;
};