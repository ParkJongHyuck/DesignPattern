#include <iostream>

using namespace std;

class Texture {};

class Terrain {
public:
	Terrain() {}
	Terrain(int movementCost, bool isWater, Texture texture) : 
		m_movementCost(movementCost), m_isWater(isWater), m_texture(texture) {}

	int GetMovementCost() { return m_movementCost; }
	bool IsWater() { return m_isWater; }
	const Texture& GetTexture() const { return m_texture; }
private:
	int m_movementCost;
	bool m_isWater;
	Texture m_texture;
};

constexpr int kWidth = 10;
constexpr int kHeight = 10;

class World
{
public:
	World() : 
		kGrassTerrain(1, false, grassTexture),
		kRiverTerrain(2, true, riverTexture),
		kHillTerrain(3, false, hillTexture)	{}

	void GenerateTerrain() {
		for (int i = 0; i < kWidth; ++i)
		{
			for (int j = 0; j < kHeight; ++j)
			{
				if (rand() % 10 == 0)
					tiles[i][j] = &kHillTerrain;
				else if (j == kHeight * 0.5)
					tiles[i][j] = &kRiverTerrain;
				else
					tiles[i][j] = &kGrassTerrain;
			}
		}
	}

	const Terrain& GetTile(int x, int y) const {
		return *tiles[x][y];
	}
private:
	Terrain kGrassTerrain;
	Terrain kRiverTerrain;
	Terrain kHillTerrain;
	Terrain* tiles[kWidth][kHeight];

	Texture grassTexture;
	Texture riverTexture;
	Texture hillTexture;
};
int main()
{

	return 0;
}