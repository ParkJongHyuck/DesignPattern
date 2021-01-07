#include <iostream>

using namespace std;

class Monster 
{
public:
	virtual Monster* Clone() = 0;
	virtual void Bark() = 0;
};

class Ghost : public Monster 
{
public:
	virtual Monster* Clone() {
		return new Ghost();
	}
	virtual void Bark() {
		cout << "Ghoooooooooost" << endl;
	}
};
class Slime : public Monster 
{
public:
	virtual Monster* Clone() {
		return new Slime();
	}
	virtual void Bark() {
		cout << "slim slim slimmeeee" << endl;
	}
};
class Demon : public Monster 
{
public:
	virtual Monster* Clone() {
		return new Demon();
	}
	virtual void Bark() {
		cout << "DEMON!@!!!!" << endl;
	}
};

Monster* SpawnGhost() {
	return new Ghost();
}

typedef Monster* (*SpawnCallback)();
class Spawner 
{
public:
	Spawner(SpawnCallback spawn) : m_spawn(spawn) {}
	~Spawner() {}
	Monster* SpawnMonster() { return m_spawn(); }

private:
	SpawnCallback m_spawn;
};

int main()
{
	Spawner* spawner = new Spawner(SpawnGhost);
	spawner->SpawnMonster()->Bark();
	return 0;
}