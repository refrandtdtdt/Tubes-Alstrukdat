#include "..\our_love_story.h"

int main()  {
    boolean quit = false;
    ScoreBoard game;
    game.game_name.Length = 0;
    int i = 0;
    char *str = "Our Love Story";
    while (str[i] != '\0')  {
        game.game_name.TabWord[i] = str[i];
        i++;
        game.game_name.Length++;
    }
    CreateBoardEmpty(&game.board);
    while (!quit)   {
        our_love_story(&game);
        PrintScoreboard(game);
    }
    return 0;
}