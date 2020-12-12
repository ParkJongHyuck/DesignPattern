#pragma once
#include "pch.h"

class GameActor
{
public:
	GameActor(string name): m_name(name) {}

	virtual void Jump() { cout << m_name << " Jump!" << endl; }
	virtual void FireGun() { cout << m_name << " Fire!" << endl; }
	virtual void SwapWeapon() { cout << m_name << " Swap!" << endl; }
	virtual void Dash() { cout << m_name << " Dash!" << endl; }

private:
	string m_name;
};

class Player : public GameActor
{
public:
	Player() : GameActor("Player") {}
};

class Slime : public GameActor
{
public:
	Slime() : GameActor("Slime") {}
};