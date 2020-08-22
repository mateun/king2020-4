#pragma once
#include <string>
#include <SDL_ttf.h>
#include <vector>


class SDL_Renderer;


class Textfield {

public:
	Textfield(int x, int y, int w, int h);


	void render(SDL_Renderer* renderer);

	void addTextLine(std::string text);

private:
	int _x;
	int _y;
	int _w;
	int _h;
	TTF_Font* _font;
	std::vector<std::string> _textLines;
	
};
