#include "..\our_love_story.h"

int main()  {
    boolean quit = false;
    ScoreBoard game;
    game.game_name = "Our Love Story";
    CreateBoardEmpty(&game.board);
    while (!quit)   {
        our_love_story(&game);
        PrintScoreboard(game);
    }
    return 0;
}