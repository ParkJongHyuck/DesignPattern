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
		cout << "Im slime" << endl;
	}
};

class Player : public Entity
{
public:
	virtual void Update() {
		cout << "Im Player" << endl;
	}
};
int main()
{
	vector<Entity*> gameEntity;
	Entity* slime = new Slime();
	Entity* slime2 = new Slime();
	Entity* player = new Player();

	gameEntity.emplace_back(slime);
	gameEntity.emplace_back(slime2);
	gameEntity.emplace_back(player);

	//while (true)	// 게임 루프
	{
		// 유저 입력 처리

		for (Entity* entity : gameEntity)
		{
			entity->Update();
			// [?] Update 순서에 따라서 결과가 달라지기 때문에
			// 순서를 보장해야 한다면 어떻게 해야할까?
			// 예) 플레이어가 몬스터를 먼저 공격하기 때문에 몬스터는 플레이어를 공격 할 수 없다.
			// 그러나 gameEntity 안에는 몬스터가 플레이어보다 순서가 먼저라서
			// 몬스터는 자신이 죽게될지를 모른다.
			//
			// 이때는 이중 버퍼 패턴을 이용하여 Update 결과값을 따로 저장하고
			// 해당 결과를 적용 할지에 대한 플래그 값으로 비교하여 갱신하면 될 것 같다.

			// [?] Collection을 순회하다가 뒤에 객체가 삭제되어
			// 의도하지 않는 동작이 일어나게 될 수 있다.
			// Collection 순회 중 객체 삽입과 삭제에 대해서는 어떻게 대응할까?
			//
			// 삽입은 현재 Update 해야하는 객체 수 만큼만
			// 순회 하도록 하여 삽입된 객체 바로 전에 멈추게 하는 방법이 있다.
			// 삭제는 순회중에는 죽었는지 체크만 하고, 나중에 GC와 같이 객체의 활성상태를
			// 파악하여 제거하는 방법이 있다.

			// [?] Update 패턴은 어떤 방법으로 쓰는게 좋을까?
			// 지금과 같은 상속으로 Update를 쓰는 것은 추천하지 않는다.
			// 상속 자체가 매우 강한 결합이여서 유지보수하기 어려우며,
			// 나중에 단일 상속으로 할 수 없는 시기가 오면 다 바꿔야한다.
			// 따라서 컴포넌트 패턴을 이용중이라면 컴포넌트 중 하나로 취급하는게 좋으며,
			// 위임 클래스가 있다면 Update 또한 위임 객체에 포워딩 시키는 방식으로
			// 제공하는 것이 좋다.
		}

		// 화면 랜더링
	}

	return 0;
}