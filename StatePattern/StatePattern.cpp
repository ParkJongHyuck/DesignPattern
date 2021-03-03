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

// 점프나 엎드리기, 미끄러지기는 지면에 있을 때만 가능한 상태다.
// 따라서 점프, 엎드리기, 미끄러지기의 상위 상태인 지면에 있는 상태를 만들어
// 각 하위 상태가 상속한다. 그러면 코드를 중복해서 사용할 수 있다.
class OnGroundState : public HeroState {
public:
	virtual void HandleInput(Hero& hero, Input input) {
		if (input == Input::PRESS_UP)
		{
			// 점프
		}
		else if (input == Input::PRESS_DOWN)
		{
			// 엎드리기
		}
	}

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

	HeroState* state;
	HeroState* equipment;
};

class DuckingState : public OnGroundState {
public:
	DuckingState() {}
	virtual void HandleInput(Hero& hero, Input input) {
		if (input == Input::RELEASE_DOWN) {
			//엎드린 상태에서 일어선 상태로 바꾼다.
			hero.state = &HeroState::standing;
		}
		else {
			// 따로 입력을 처리하지 않고 상위 상태로 보낸다.
			OnGroundState::HandleInput(hero, input);
		}
	}
	virtual void Update(Hero& hero) {
		// update...
	}
};

class JumpingState : public OnGroundState {
public:
	JumpingState() {}
	virtual void HandleInput(Hero& hero, Input input) {
		if (input == Input::PRESS_DOWN) {
			// 다이빙하는 상태로 바꾼다.
		}
		else {
			// 따로 입력을 처리하지 않고 상위 상태로 보낸다.
			OnGroundState::HandleInput(hero, input);
		}
	}
	virtual void Update(Hero& hero) {
		// update...
	}
};

class StandingState : public OnGroundState {
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