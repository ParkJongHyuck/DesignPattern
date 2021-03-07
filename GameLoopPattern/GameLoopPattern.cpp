#include <iostream>

using namespace std;

double GetCurrentTime() {
	return 0;
}

void ProcessInput() {

}

void Render() {

}

void Update() {

}
constexpr double MS_PER_UPDATE = 0.016;

int main()
{
	// [2] 고정 시간 간격
	// 가변 시간 간격에서는 PC 성능에 따라서 물리 계산의 빈도가 달라지고
	// 이에 따라 부동 소수점 반올림 오류가 축적될 수 있다.
	// 그래서 AI, 물리 계산을 담당하는 Update 부분을 고정된 간격으로 업데이트 한다.
	// 이로 인해서 여러 하드웨어에서 일정한 속도로 시뮬레이션이 가능해진다.
	// 유니티의 FixedUpdate와 동일하다.

	double previous = GetCurrentTime();
	double lag = 0.0;
	while (true) {
		double current = GetCurrentTime();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;
		ProcessInput();
		while (lag >= MS_PER_UPDATE) {
			Update();
			lag -= MS_PER_UPDATE;
		}
		Render();
	}
	return 0;
}