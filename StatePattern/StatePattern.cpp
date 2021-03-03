#include <iostream>

using namespace std;

enum class Input {PRESS_DOWN, PRESS_UP, RELEASE_DOWN};
enum class State { STATE_STANDING, STATE_JUMPING, STATE_DUCKING };
class Hero
{
public:
	void HandleInput(Input input)
	{
		switch (state)
		{
		case State::STATE_STANDING:
			if (input == Input::PRESS_DOWN) 
			{
				state = State::STATE_DUCKING;
				// 엎드리기
			}
			else if (input == Input::PRESS_UP) 
			{
				state = State::STATE_JUMPING;
				// 점프하기
			}
			break;
		case State::STATE_JUMPING:
			// ...
			break;
		case State::STATE_DUCKING:
			// ...
			break;
		default:
			break;
		}
	}

private:
	State state;
};

int main()
{

	return 0;
}