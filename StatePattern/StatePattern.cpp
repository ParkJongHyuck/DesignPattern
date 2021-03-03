#include <iostream>

using namespace std;

enum class Input {PRESS_DOWN, PRESS_UP, RELEASE_DOWN};
enum class State { STATE_STANDING, STATE_JUMPING, STATE_DUCKING };

class HeroState {
public:
	virtual ~HeroState() {}
	// [1] 상태에 의존하는 모든 코드를 가상함수로 만든다.
	virtual void HandleInput(Hero& hero, Input input) {}
	virtual void Update(Hero& hero) {}

	// [4] 각 상태들을 정적 인스턴스로 둔다.
	static DuckingState ducking;
	static JumpingState jumping;
	static StandingState standing;
};


class Hero
{
public:
	// [3] 상태 객체에 동작을 위임한다.
	void HandleInput(Input input)
	{
		state->HandleInput(*this, input);
	}

	void Update() 
	{
		state->Update(*this);
	}

	HeroState* state;
};

// [2] case 별로 있었던 상태들을 클래스로 정의한다.
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