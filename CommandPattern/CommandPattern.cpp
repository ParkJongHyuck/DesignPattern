#include "pch.h"
#include "GameActor.h"

class Command {
public:
	Command(GameActor* target) : m_target(target) {}
	virtual ~Command() {}
	virtual void Execute() = 0;
	virtual void Undo() = 0;
	void Log() { Execute(); }
	GameActor* m_target;
};

class JumpCommand : public Command {
public:
	JumpCommand(GameActor* target) : Command(target) {}
	virtual void Execute() { m_target->Jump(); }
	virtual void Undo() { m_target->UnJump(); }
};

class FireCommand : public Command {
public:
	FireCommand(GameActor* target) : Command(target) {}
	virtual void Execute() { m_target->FireGun(); }
	virtual void Undo() { m_target->UnFireGun(); }
};

class SwapCommand : public Command {
public:
	SwapCommand(GameActor* target) : Command(target) {}
	virtual void Execute() { m_target->SwapWeapon(); }
	virtual void Undo() { m_target->UnSwapWeapon(); }
};

class DashCommand : public Command {
public:
	DashCommand(GameActor* target) : Command(target) {}
	virtual void Execute() { m_target->Dash(); }
	virtual void Undo() { m_target->UnDash(); }
};

static vector<GameActor*> actorPool;
GameActor* GetGameActor(int id) {
	if (id < actorPool.size())
		return actorPool[id];
	else
		return actorPool[0];
}
constexpr char ButtonW = 'w';
constexpr char ButtonA = 'a';
constexpr char ButtonS = 's';
constexpr char ButtonD = 'd';
constexpr char ShowLogQ = 'q';
constexpr char UndoE = 'e';
constexpr char RedoR = 'r';

class InputHandler {
public:
	InputHandler() {}

	int KeyboardInput(char& buf) {
		if (_kbhit() != 0)
		{
			buf = _getch();
			cout << "Input Key : " << buf << endl;
			return 1;
		}
		return 0;
	}
};

class CommandList
{
public:
	CommandList() : m_head{ m_list.begin() } { }
	void Push(Command* command) {
		command->Execute();
		if (m_list.end() != m_head)
		{
			for (auto ed = m_head; ed != m_list.end();)
			{
				ed = m_list.erase(ed);
			}
		}
		m_list.emplace_back(command);
		m_head = m_list.end();
	}

	void Undo() {
		if (m_list.begin() != m_head)
		{
			--m_head;
			(*m_head)->Undo();
		}
	}

	void Log() {
		int i = 0;
		for (auto bg = m_list.begin(); bg != m_head; ++bg)
		{
			cout << i++ << "] ";
			(*bg)->Log();
		}
	}

	void Redo() {
		if (m_head != m_list.end())
		{
			(*m_head)->Execute();
			++m_head;
		}
	}
private:
	list<Command*> m_list;
	list<Command*>::iterator m_head;

};
int main() {
	actorPool.emplace_back(new Player());
	actorPool.emplace_back(new Enemy("Slime"));
	actorPool.emplace_back(new Enemy("Dog"));
	actorPool.emplace_back(new Enemy("Cat"));

	InputHandler* inputHandler = new InputHandler();
	CommandList* commandList = new CommandList();
	Command* command;
	char buf;
	int targetId = 0;

	cout << "[w] Jump, [a] Fire, [s] Swap, [d] Dash | [q] Log, [e] Undo, [r] Redo | [0~3] Character, [z] exit" << endl << endl;
	
	while (true)
	{
		if (inputHandler->KeyboardInput(buf))
		{
			switch (buf)
			{
			case ButtonW:
				commandList->Push(new JumpCommand(GetGameActor(targetId)));
				break;
			case ButtonA:
				commandList->Push(new FireCommand(GetGameActor(targetId)));
				break;
			case ButtonS:
				commandList->Push(new SwapCommand(GetGameActor(targetId)));
				break;
			case ButtonD:
				commandList->Push(new DashCommand(GetGameActor(targetId)));
				break;
			case ShowLogQ:
				commandList->Log();
				break;
			case UndoE:
				commandList->Undo();
				break;
			case RedoR:
				commandList->Redo();
				break;
			case 'z':
				return 0;
			default:
				targetId = atoi(const_cast<char*>(&buf));
				break;
			}

			cout << endl << "[w] Jump, [a] Fire, [s] Swap, [d] Dash, [q] Log, [e] Undo, [r] Redo, [0~3] Character, [z] exit" << endl << endl;
		}
	}
	return 0;
}