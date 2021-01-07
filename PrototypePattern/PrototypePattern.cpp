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

class Spawner 
{
public:
	Spawner() {}
	~Spawner() {}
	virtual Monster* SpawnMonster() = 0;

private:
};

template<class T>
class SpawnerFor : public Spawner {
public:
	virtual Monster* SpawnMonster() { return new T(); }
};
int main()
{
	Spawner* spawner = new SpawnerFor<Slime>();
	spawner->SpawnMonster()->Bark();
	return 0;
}