#include "textfield.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <algorithm>

Textfield::Textfield(int x, int y, int w, int h) : _x(x), _y(y), _w(w), _h(h) {
	_font = TTF_OpenFont("E:/Projects/C++/king2020-4/x64/Debug/SLC_.ttf", 16);

	if (!_font) {
		SDL_Log("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
	}

}

void Textfield::render(SDL_Renderer* renderer) {
	SDL_Color color = { 0,0,0 };
	SDL_Surface* textSurface;

	int line = 0;

	int offset = std::max<int>(0, _textLines.size() - 5);


	for (int i = offset; i < _textLines.size(); i++) {

		std::string text = _textLines[i];
		if (!(textSurface = TTF_RenderText_Solid(_font, text.c_str(), color))) {
			//handle error here, perhaps print TTF_GetError at least
			SDL_Log(TTF_GetError());
		}
		else {
			SDL_Rect dr;
			SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
			SDL_QueryTexture(texture, NULL, NULL, &dr.w, &dr.h);

			dr.x = 10;
			dr.y = line * 20;

			SDL_RenderCopy(renderer, texture, NULL, &dr);

			SDL_DestroyTexture(texture);
			SDL_FreeSurface(textSurface);
		}
		line++;

	}

}

void Textfield::addTextLine(std::string text) {
	_textLines.push_back(text);
}