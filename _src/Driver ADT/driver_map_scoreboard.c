# include "..\ADT\map_scoreboard.h"
# include "..\ADT\functions.h"

int main()  {
    ScoreMap S;
    CreateBoardEmpty(&S);
    int len;
    keytype key;
    valuetype val;
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        key = (keytype) malloc(1000*sizeof(char));
        printf("masukkan nama player %d: ", i);
        scanf("%s", key);
        printf("masukkan skor %d: ", i);
        //printf("%u\n", IsMemberScore(S, key));
        scanf("%d", &val);
        InsertScore(&S, key, val);
    }
    sortScoreboard(&S);
    ScoreBoard sb;
    sb.board = S;
    sb.game_name.Length = 5;
    sb.game_name.TabWord[0] = 'G';
    sb.game_name.TabWord[1] = 'A';
    sb.game_name.TabWord[2] = 'M';
    sb.game_name.TabWord[3] = 'E';
    sb.game_name.TabWord[4] = 'E';
    PrintScoreboard(sb);
    printf("\n");
    ResetArrayScore(&sb);
    PrintScoreboard(sb);
    return 0;
}