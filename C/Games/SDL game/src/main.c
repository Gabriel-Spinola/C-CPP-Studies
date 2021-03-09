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
	SDL_Renderer *renderer; // Declare a renderer

	SDL_Init(SDL_INIT_VIDEO); // Initialize SDL2

	// Create an application window with the following settings:
	window = SDL_CreateWindow(
		"Game Window",			 // Window title
		SDL_WINDOWPOS_UNDEFINED, // Initial x position
		SDL_WINDOWPOS_UNDEFINED, // Initial y position
		800,					 // Width of the window, in pixels
		600,					 // Height of the window, in pixels
		0						 // Flags
	);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// The window is open: enter program loop (see SDL_PollEvent)
	int done = 0;

	SDL_Event event;

	// Event loop
	while (!done) {
		// Check for events
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_WINDOWEVENT_CLOSE:
				{
					if (window) {
						SDL_DestroyWindow(window);

						window = NULL;
					}
				}
				break;

				case SDL_KEYDOWN:
				{
					switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
					{
						done = 1;
					}
					break;
					}
				}
				break;

				case SDL_QUIT:
				{
					// quit out of the game
					done = 1;
				}
				break;
			}
		}
	}

	// Set the drawing color to blue
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	// Clear the screen (to blue)
	SDL_RenderClear(renderer);

	// Set the drawing color to white
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_Rect rect = {32, 32, 32, 32};
	SDL_RenderFillRect(renderer, &rect);

	// we are done drawing, "present" or show to the screen what we've drawn
	SDL_RenderPresent(renderer);

	SDL_Delay(100);

	// Close and destroy the window
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	// Clean up
	SDL_Quit();
}
