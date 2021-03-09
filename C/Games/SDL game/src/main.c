#include "SDL2/SDL.h"
#include <stdio.h>

typedef struct
{
	int x, y;
	short life;
	char *name;
} Man;

int processEvents(SDL_Window *window, Man *man) {
	// The window is open: enter program loop (see SDL_PollEvent)
	int done = 0;

	SDL_Event event;

	// Check for events
	while(SDL_PollEvent(&event)) {
		switch(event.type) 
		{
		case SDL_WINDOWEVENT_CLOSE:
		{
			if(window) {
				SDL_DestroyWindow(window);

				window = NULL;
				done = 1;
			}
		}
		break;

		case SDL_KEYDOWN:
		{
			switch (event.key.keysym.sym) 
			{
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

	// Get the keyboard states
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	// Moves the character to the left
	if(state[SDL_SCANCODE_LEFT]) {
		man->x -= 10;
	}

	// Moves the character to the right
	if(state[SDL_SCANCODE_RIGHT]) {
		man->x += 10;
	}
	
	return done;
}

void render(SDL_Renderer *renderer, Man *man) {
	// Set the drawing color to blue
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	// Clear the screen (to blue)
	SDL_RenderClear(renderer);

	// Set the drawing color to white
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_Rect rect = {man->x, man->y, 32, 32};
	SDL_RenderFillRect(renderer, &rect);

	// we are done drawing, "present" or show to the screen what we've drawn
	SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[])
{
	SDL_Window *window;		// Declare a Window
	SDL_Renderer *renderer; // Declare a renderer

	Man man;

	man.x = 32;
	man.y = 32;

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
	
	int done = 0;
	
	while(!done) {
		// Check for events
		done = processEvents(window, &man);

		// Render dispay
		render(renderer, &man);

		SDL_Delay(10);
	}

	// Close and destroy the window
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}
