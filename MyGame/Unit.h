#pragma once
#include "Smiley.h"
class Unit
{
public:
	Unit() = delete;
	Unit(const std::string& imageFile, int xPos, int yPos, int speed);
	int GetUnitWidth() const;
	int GetUnitHeight() const;
	void SetPosX(int newX);
	void SetPosY(int newY);
	int GetPosX() const;
	int GetPosY() const;
	int GetSpeed() const;
	bool CollideWith(const Unit &other) const;
	void Draw(Smiley::Shader& shader);
	
	enum class Direction {
		None, Up, Down, Left, Right
	};
	Unit::Direction GetDirection() const;
	void SetDirection(Unit::Direction newDirection);
	void UpdatePosition();
	void SetPower(const std::string& imageFile, int xPos, int yPos, int speed,Unit::Direction newDirection);
	void UsePower(Smiley::Shader& shader);
	bool IsPositionPossible(int newX, int newY) const;
	Unit* mPower;
private:
	Smiley::Sprite mImage;
	int mPosX;
	int mPosY;
	int mSpeed;
	Direction mDirection;
};

