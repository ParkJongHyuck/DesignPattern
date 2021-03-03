#include <iostream>

using namespace std;

enum class Input {PRESS_DOWN, PRESS_UP, RELEASE_DOWN};
enum class State { STATE_STANDING, STATE_JUMPING, STATE_DUCKING };

class HeroState {
public:
	virtual ~HeroState() {}
	virtual void HandleInput(Hero& hero, Input input) {}
	virtual void Update(Hero& hero) {}

	static DuckingState ducking;
	static JumpingState jumping;
	static StandingState standing;
};


class Hero
{
public:
	void HandleInput(Input input)
	{
		state->HandleInput(*this, input);
		equipment->HandleInput(*this, input);
	}

	void Update() 
	{
		state->Update(*this);
		equipment->Update(*this);
	}

	// 캐릭터가 만약 무기를 든다고 하면 어떻게 해야할까.
	// 비무장 상태 m개, 무장 상태 m개 ... 매우 많은 상태의 정의가 필요하다.
	// 그러나 이를 상태 기계를 2개를 둔다면 해결할 수 있다.
	// 아래와 같이 하나의 상태 기계는 '무엇을 하는가'를 다루고 다른 하나는 '무엇을 들고 있는가'를 다룬다.
	// 따라서 상태는 m + n 개만 있으면 된다.
	HeroState* state;
	HeroState* equipment;
};

class DuckingState : public HeroState {
public:
	DuckingState() {}
	virtual void HandleInput(Hero& hero, Input input) {
		if (input == Input::RELEASE_DOWN) {
			//엎드린 상태에서 일어선 상태로 바꾼다.
			hero.state = &HeroState::standing;
		}
	}
	virtual void Update(Hero& hero) {
		// update...
	}
};

class JumpingState : public HeroState {
public:
	JumpingState() {}
	virtual void HandleInput(Hero& hero, Input input) {
		if (input == Input::PRESS_DOWN) {
			// 다이빙하는 상태로 바꾼다.
		}
	}
	virtual void Update(Hero& hero) {
		// update...
	}
};

class StandingState : public HeroState {
public:
	StandingState() {}

	virtual void HandleInput(Hero& hero, Input input) {
		if (input == Input::PRESS_UP) {
			hero.state = &HeroState::jumping;
		}
		else if (input == Input::PRESS_DOWN) {
			hero.state = &HeroState::ducking;
		}
	}
};

int main()
{

	return 0;
}