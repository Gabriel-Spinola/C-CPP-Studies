#include "SDL2/SDL.h"
#include <stdio.h>

typedef struct
{
	int x, y;
	short life;
	char *name;
} Man;

int main(int argc, char *argv[]) 
{
	SDL_Window *window;		// Declare a Window
	SDL_Renderer *renderer;	// Declare a renderer

	SDL_Init(SDL_INIT_VIDEO); // Initialize SDL2

	// Create an application window with the following settings:
	window = SDL_CreateWindow(
		"Game Window",				// Window title
		SDL_WINDOWPOS_UNDEFINED,	// Initial x position
		SDL_WINDOWPOS_UNDEFINED,	// Initial y position
		800,						// Width of the window, in pixels	
		600,						// Height of the window, in pixels
		0 							// Flags								
	);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	// Clear the screen (to blue)
	SDL_RenderClear(renderer);

	// Set the drawing color to white
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	// Create a rect
	SDL_Rect rect = { 32, 32, 32, 32 }; // 32 x 32 pixels rect
	SDL_RenderFillRect(renderer, &rect); // fill this rectangle with the white color

	// We are done drawing, "present" or show to the screen what we've drawn
	SDL_RenderPresent(renderer);

	// Wait a few seconds before quitting
	SDL_Delay(2000);

	// Close and destroy the window 
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	// Clean up
	SDL_Quit();
}
