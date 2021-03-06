#pragma once
#include <SFML\Graphics.hpp>

const int HEIGHT_MAP = 9;
const int WIDTH_MAP = 16;

sf::String TileMap[HEIGHT_MAP] = {
	"ssssssssssssssss",
	"ssssssssssssssss",
	"ssssssssssssssss",
	"gggggggggggggggg",
	"gggggggggggggggg",
	"gggggggggggggggg",
	"ffffffffffffffff",
	"ffffffffffffffff",
	"ffffffffffffffff"
};

sf::String ShopMap[HEIGHT_MAP] = {
	"ggggggggggggffff",
	"ffffffffffffffff",
	"gggggggggggggggg",
	"ffffffffffffffff",
	"ffffffffffffffff",
	"ffffffffffffffff",
	"gggggggggggggggg",
	"ffffffffffffffff",
	"fffgggggggggggff"
};