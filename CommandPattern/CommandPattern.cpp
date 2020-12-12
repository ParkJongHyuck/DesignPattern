#include "pch.h"
#include "GameActor.h"

class Command {
public:
	virtual ~Command() {}
	virtual void execute(GameActor& actor) = 0;
};

class JumpCommand : public Command {
public:
	virtual void execute(GameActor& actor) { actor.Jump(); }
};

class FireCommand : public Command {
public:
	virtual void execute(GameActor& actor) { actor.FireGun(); }
};

class SwapCommand : public Command {
public:
	virtual void execute(GameActor& actor) { actor.SwapWeapon(); }	
};

class DashCommand : public Command {
public:
	virtual void execute(GameActor& actor) {
		actor.Dash();
	}
};

class InputHandler {
public:
	InputHandler() : buf {}, buttonW(new JumpCommand()), buttonA(new FireCommand()),
		buttonS(new SwapCommand()), buttonD(new DashCommand()) {}

	int KeyboardInput() {
		if (_kbhit() != 0)
		{
			buf = _getch();
			cout << "Input Key : " << buf << endl;
			return 1;
		}
		return 0;
	}

	Command* handleInput() {
		if (buf == ButtonW) return buttonW;
		else if (buf == ButtonA) return buttonA;
		else if (buf == ButtonS) return buttonS;
		else if (buf == ButtonD) return buttonD;
		return nullptr;
	}

private:
	const char ButtonW = 'w';
	const char ButtonA = 'a';
	const char ButtonS = 's';
	const char ButtonD = 'd';	

	char buf;
	Command* buttonW;
	Command* buttonA;
	Command* buttonS;
	Command* buttonD;
};

int main() {
	Player* player = new Player();
	GameActor* Enemy = new Slime();
	InputHandler* inputHandler = new InputHandler();
	Command* command;

	while (true)
	{
		if (inputHandler->KeyboardInput())
		{
			command = inputHandler->handleInput();
			if (command)
				command->execute(*Enemy);
		}
	}
	return 0;
}