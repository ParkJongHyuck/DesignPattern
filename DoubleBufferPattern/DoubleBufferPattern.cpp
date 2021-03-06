#include <iostream>

using namespace std;

class DeliveryMan
{
public:
	DeliveryMan() : currentBox(false), nextBox(false) {}
	
	void Update() {
		if (HasBox()) {
			cout << "carry out" << endl;
			next->SendBox();
		}
	}

	void Swap() {	// Reset대신 Swap을 사용
		currentBox = nextBox;
		nextBox = false;
	}

	void SetNextDeliveryMan(DeliveryMan* next_) { next = next_; }
	void SendBox() { nextBox = true; }
	bool HasBox() { return currentBox; }

private:
	DeliveryMan* next = nullptr;
	bool currentBox;	// 읽기 용도
	bool nextBox;		// 쓰기 용도
};

class Stage
{
public:
	void Add(DeliveryMan* man, int index) {
		deliveryMan[index] = man;
	}

	void Update() {
		for (int i = 0; i < NUM_MAN; ++i) {
			deliveryMan[i]->Update();
		}
		for (int i = 0; i < NUM_MAN; ++i) {
			deliveryMan[i]->Swap();
		}
		// 먼저 모든 배우를 업데이트 한 후 상태를 교체
	}
private:
	static const int NUM_MAN = 3;
	DeliveryMan* deliveryMan[NUM_MAN];
};
int main()
{
	Stage* stage = new Stage();
	DeliveryMan* tom = new DeliveryMan();
	DeliveryMan* dave = new DeliveryMan();
	DeliveryMan* cat = new DeliveryMan();

	tom->SetNextDeliveryMan(dave);
	dave->SetNextDeliveryMan(cat);
	cat->SetNextDeliveryMan(tom);

	stage->Add(tom, 0);
	stage->Add(dave, 1);
	stage->Add(cat, 2);

	cat->SendBox();

	for (int i = 0; i < 3; ++i)
	{
		cout << "[" << i << "]" << endl;
		stage->Update();
	}
	
	return 0;
}