#pragma once
#include "pch.h"

class GameActor
{
public:
	GameActor(string name): m_name(name) {}

	virtual void Jump() { cout << m_name << ") Jump!" << endl; }
	virtual void UnJump() { cout << m_name << ") UnJump!" << endl; }
	virtual void FireGun() { cout << m_name << ") Fire!" << endl; }
	virtual void UnFireGun() { cout << m_name << ") UnFire!" << endl; }
	virtual void SwapWeapon() { cout << m_name << ") Swap!" << endl; }
	virtual void UnSwapWeapon() { cout << m_name << ") UnSwap!" << endl; }
	virtual void Dash() { cout << m_name << ") Dash!" << endl; }
	virtual void UnDash() { cout << m_name << ") UnDash!" << endl; }

private:
	string m_name;
};

class Player : public GameActor
{
public:
	Player() : GameActor("Player") {}
};

class Enemy : public GameActor
{
public:
	Enemy(string name) : GameActor(name) {}
};