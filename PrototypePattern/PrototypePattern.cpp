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

class Spawner 
{
public:
	Spawner(Monster* prototype) : m_prototype(prototype) {}
	~Spawner() {}
	Monster* SpawnMonster() { return m_prototype->Clone(); }

private:
	Monster* m_prototype;
};

int main()
{
	Slime* slime = new Slime();
	Spawner* spawner = new Spawner(slime);
	spawner->SpawnMonster()->Bark();
	return 0;
}