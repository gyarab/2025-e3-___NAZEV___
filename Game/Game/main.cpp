#include <SDL3/SDL.h>

#define EXIT_SUCCESS 0

//First test program to demostrate rendering of a basic triangle
//'WinMain' has to be used as entry point
int WinMain(int argc, char** argv)
{
	//Initialize variables 
	SDL_Window* GameWindow = nullptr;
	SDL_Renderer* TriangleRenderer = nullptr;
	__int32 Width = 600, Length = 500;
	SDL_FPoint PointA = SDL_FPoint(100.0f, 400.0f);
	SDL_FPoint PointB = SDL_FPoint(500.0f, 400.0f);
	SDL_FPoint PointC = SDL_FPoint(300.0f, 100.0f);
	SDL_Event Event = SDL_Event();

	//Initialize library, graphical windows and one renderer
	SDL_Init(SDL_INIT_VIDEO);
	GameWindow = SDL_CreateWindow("Basic Triangle", Width, Length, NULL);
	TriangleRenderer = SDL_CreateRenderer(GameWindow, NULL);

	//Main loop for poll events
	while (true)
	{
		//Get event poll and process it
		SDL_PollEvent(&Event);

		//Flip triangle if a 'K' key is pressed and flip it back if its released
		if (Event.key.scancode == SDL_SCANCODE_K)
		{
			if (Event.type == SDL_EVENT_KEY_DOWN)
			{
				PointA.y = 100.0f;
				PointB.y = 100.0f;
				PointC.y = 400.0f;
			}

			if (Event.type == SDL_EVENT_KEY_UP)
			{
				PointA.y = 400.0f;
				PointB.y = 400.0f;
				PointC.y = 100.0f;
			}
		}

		//Check if the window has to be closed
		if (Event.type == SDL_EVENT_QUIT)
			break;

		//Rendering the triangle using three points
		SDL_SetRenderDrawColor(TriangleRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(TriangleRenderer);
		SDL_SetRenderDrawColor(TriangleRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderLine(TriangleRenderer, PointA.x, PointA.y, PointB.x, PointB.y);
		SDL_RenderLine(TriangleRenderer, PointB.x, PointB.y, PointC.x, PointC.y);
		SDL_RenderLine(TriangleRenderer, PointA.x, PointA.y, PointC.x, PointC.y);
		SDL_RenderPresent(TriangleRenderer);
	}

	//Clear memory and close program
	SDL_DestroyRenderer(TriangleRenderer);
	SDL_DestroyWindow(GameWindow);
	SDL_Quit();

	return EXIT_SUCCESS;
};