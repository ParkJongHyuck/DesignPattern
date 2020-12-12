#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Command {
public:
	virtual ~Command() {}
	virtual void execute() = 0;
};

class JumpCommand : public Command {
public:
	virtual void execute() { Jump(); }
	void Jump() { cout << "Jump!" << endl; }
	
};

class FireCommand : public Command {
public:
	virtual void execute() { FireGun(); }
	void FireGun() { cout << "Fire!" << endl; }
	
};

class SwapCommand : public Command {
public:
	virtual void execute() { SwapWeapon(); }
	void SwapWeapon() { cout << "Swap!" << endl; }
	
};

class DashCommand : public Command {
public:
	virtual void execute() { Dash(); }
	void Dash() { cout << "Dash!" << endl; }
};

class InputHandler {
public:
	InputHandler() : buf{}, buttonW(new JumpCommand()), buttonA(new FireCommand()),
		buttonS(new SwapCommand()), buttonD(new DashCommand()) {}

	void Update() {
		if (KeyboardInput())
		{
			handleInput();
		}
	}

private:
	const char ButtonW = 'w';
	const char ButtonA = 'a';
	const char ButtonS = 's';
	const char ButtonD = 'd';

	int KeyboardInput() {
		if (_kbhit() != 0)
		{
			buf = _getch();
			cout << "Input Key : " << buf << endl;
			return 1;
		}
		return 0;
	}

	void handleInput() {
		if (buf == ButtonW) buttonW->execute();
		else if (buf == ButtonA) buttonA->execute();
		else if (buf == ButtonS) buttonS->execute();
		else if (buf == ButtonD) buttonD->execute();
	}

private:
	char buf;
	Command* buttonW;
	Command* buttonA;
	Command* buttonS;
	Command* buttonD;
};

class Player
{
public:
	Player() : inputHanlder(new InputHandler()) {}
	
	void Update() {
		inputHanlder->Update();
	}

private:
	InputHandler* inputHanlder;
};
int main() {
	Player* player = new Player();

	while (true)
	{
		player->Update();
	}
	return 0;
}