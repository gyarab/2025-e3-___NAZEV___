#include <SDL3/SDL.h>

#define EXIT_SUCCESS 0

enum TriagleVerticesNames : unsigned __int64
{
	A = 0,
	B = 1,
	C = 2
};

//First test program to demostrate rendering of a basic triangle
//'WinMain' has to be used as entry point
int WinMain(int argc, char** argv)
{
	//Initialize variables 
	SDL_Window* GameWindow = nullptr;
	constexpr __int32 Width = 600, Length = 500;
	SDL_Renderer* TriangleRenderer = nullptr;
	SDL_Event Event = SDL_Event();
	
	//Initialize triangle's vertices
	constexpr __int64 TriangleVerticesCount = 3;
	SDL_Vertex TriangleVertices[TriangleVerticesCount] =
	{
		SDL_Vertex(SDL_FPoint(100.0f, 400.0f), SDL_FColor(255, 255, 255, SDL_ALPHA_OPAQUE), SDL_FPoint()), //Vertex A
		SDL_Vertex(SDL_FPoint(500.0f, 400.0f), SDL_FColor(255, 255, 255, SDL_ALPHA_OPAQUE), SDL_FPoint()), //Vertex B
		SDL_Vertex(SDL_FPoint(300.0f, 100.0f), SDL_FColor(255, 255, 255, SDL_ALPHA_OPAQUE), SDL_FPoint())  //Vertex C
	};

	//Initialize library, graphical window and one renderer
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
				TriangleVertices[A].position.y = 100.0f;
				TriangleVertices[B].position.y = 100.0f;
				TriangleVertices[C].position.y = 400.0f;
			}

			if (Event.type == SDL_EVENT_KEY_UP)
			{
				TriangleVertices[A].position.y = 400.0f;
				TriangleVertices[B].position.y = 400.0f;
				TriangleVertices[C].position.y = 100.0f;
			}
		}

		//Check if the window has to be closed
		if (Event.type == SDL_EVENT_QUIT)
			break;

		//Rendering the triangle using three vertices
		SDL_SetRenderDrawColor(TriangleRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(TriangleRenderer);
		SDL_SetRenderDrawColor(TriangleRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderGeometry(TriangleRenderer, NULL, TriangleVertices, TriangleVerticesCount, NULL, NULL);
		SDL_RenderPresent(TriangleRenderer);
	}

	//Clear memory and close program
	SDL_DestroyRenderer(TriangleRenderer);
	SDL_DestroyWindow(GameWindow);
	SDL_Quit();

	return EXIT_SUCCESS;
};