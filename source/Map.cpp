#include "Map.h"
#include "Game.h"
#include <fstream>

Map::Map(){}

Map::~Map(){}

void Map::loadMap(std::string filePath, int mapSizeX, int mapSizeY){
	char tile;
	std::fstream mapFile;
	mapFile.open(filePath);
	for (int y{ 0 }; y < mapSizeY; y++) {
		for (int x{ 0 }; x < mapSizeX; x++) {
			mapFile.get(tile);
			Game::addTile(atoi(&tile), x*32, y*32);
			mapFile.ignore();
		}
		mapFile.ignore();
	}
	mapFile.close();
}
