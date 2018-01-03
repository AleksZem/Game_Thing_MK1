#pragma once
#include <string>

class Map {
public:
	Map();
	~Map();
	static void loadMap(std::string filePath, int mapSizeX, int mapSizeY);
private:
};