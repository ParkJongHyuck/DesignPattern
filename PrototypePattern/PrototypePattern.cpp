#include <iostream>

using namespace std;

class Monster 
{
public:
	virtual void Bark() = 0;
};

class Ghost : public Monster 
{
public:
	virtual void Bark() {
		cout << "Ghoooooooooost" << endl;
	}
};
class Slime : public Monster 
{
public:
	virtual void Bark() {
		cout << "slim slim slimmeeee" << endl;
	}
};
class Demon : public Monster 
{
public:
	virtual void Bark() {
		cout << "DEMON!@!!!!" << endl;
	}
};

class Spawner 
{
public:
	virtual ~Spawner() {}
	virtual Monster* SpawnMonster() = 0;
};

class GhostSpawner : public Spawner
{
public:
	virtual Monster* SpawnMonster() {
		return new Ghost();
	}
};

class SlimeSpawner : public Spawner
{
public:
	virtual Monster* SpawnMonster() {
		return new Slime();
	}
};

class DemonSpawner : public Spawner
{
public:
	virtual Monster* SpawnMonster() {
		return new Demon();
	}
};

int main()
{
	GhostSpawner* gs = new GhostSpawner();
	Ghost* ghost = reinterpret_cast<Ghost*>(gs->SpawnMonster());
	ghost->Bark();
	return 0;
}