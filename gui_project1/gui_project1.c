#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdlib.h>
#include <time.h>

void draw_button(const char* text, SDL_Renderer* renderer, TTF_Font* font, SDL_Color color, SDL_Rect* btnRect, bool isHovered)
{
    // Draw the button's rectangle
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, btnRect);

    // Draw the button's border if hovered
    if (isHovered) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, btnRect);
    }

    // Draw the button's text
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { btnRect->x + (btnRect->w - texW) / 2, btnRect->y + (btnRect->h - texH) / 2, texW, texH };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void draw_mouse_coords(SDL_Renderer* renderer, TTF_Font* font, SDL_Color color, int mouseX, int mouseY)
{
    char coords[32];
    snprintf(coords, sizeof(coords), "mouse_x: %d  mouse_y: %d", mouseX, mouseY);

    SDL_Surface* surface = TTF_RenderText_Solid(font, coords, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

    int winW, winH;
    SDL_GetWindowSize(SDL_GetWindowFromID(1), &winW, &winH);
    SDL_Rect dstrect = { 10, winH - texH - 30, texW, texH };

    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void draw_text(SDL_Renderer* renderer, TTF_Font* font, SDL_Color color, const char* message, int x, int y)
{
    SDL_Surface* surface = TTF_RenderText_Solid(font, message, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { x, y, texW, texH };

    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    srand((unsigned int)time(NULL));

    int windowWidth = 800;
    int windowHeight = 600;
    SDL_Window* window = SDL_CreateWindow(
        "CLICKED RANDOM APP",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    TTF_Font* font = TTF_OpenFont("arial.ttf", 25);
    if (!font) {
        printf("Failed to load font: %s\n", TTF_GetError());
        return -1;
    }
    SDL_Color textColor = { 0, 0, 0 };

    bool isRunning = true;
    SDL_Event event;

    SDL_Rect btnRect = { 50, 50, 150, 75 };
    bool wasClicked = false;
    bool isHovered = false;

    while (isRunning)
    {
        while (SDL_PollEvent(&event) > 0)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                isRunning = false;
                break;

            case SDL_MOUSEMOTION:
                isHovered = SDL_PointInRect(&(SDL_Point) { event.motion.x, event.motion.y }, & btnRect);
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (SDL_PointInRect(&(SDL_Point) { event.button.x, event.button.y }, & btnRect))
                    {
                        wasClicked = !wasClicked;
                        btnRect.x = rand() % (windowWidth - btnRect.w);
                        btnRect.y = rand() % (windowHeight - btnRect.h);
                    }
                }
                break;
            }
        }

        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        draw_button(wasClicked ? "Clicked" : "Click me", renderer, font, textColor, &btnRect, isHovered);
        draw_mouse_coords(renderer, font, textColor, mouseX, mouseY);
        draw_text(renderer, font, textColor, "Click inside rectangle", 10, windowHeight - 30);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
