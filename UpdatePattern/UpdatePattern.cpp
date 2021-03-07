#include <iostream>
#include <vector>

using namespace std;

class Entity
{
public:
	virtual void Update() = 0;
};

class Slime : public Entity
{
public:
	virtual void Update() {

	}
};

class Player : public Entity
{
public:
	virtual void Update() {

	}
};
int main()
{
	vector<Entity*> gameEntity;

	while (true)	// 게임 루프
	{
		// 유저 입력 처리

		for (Entity* entity : gameEntity)
		{
			entity->Update();
		}

		// 화면 랜더링
	}

	return 0;
}