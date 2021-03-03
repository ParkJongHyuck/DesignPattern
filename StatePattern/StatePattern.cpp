#include <iostream>

using namespace std;

enum class Input {PRESS_DOWN, PRESS_UP, RELEASE_DOWN};

class Hero
{
public:
	void HandleInput(Input input)
	{
		if (input == Input::PRESS_UP)
		{
			if (!isJumping) 
			{
				isJumping = true;
				// 점프
			}
		}
		else if (input == Input::PRESS_DOWN)
		{
			if (!isJumping)
			{
				// 엎드리기
			}
		}
		else if (input == Input::RELEASE_DOWN)
		{
			// 기본상태
		}
	}

private:
	bool isJumping = false;
};

int main()
{

	return 0;
}