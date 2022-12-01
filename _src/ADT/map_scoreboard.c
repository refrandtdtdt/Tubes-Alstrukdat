#include "map_scoreboard.h"

void CreateBoardEmpty(ScoreMap *M)   {
    M->Count = NIL;
}

boolean IsBoardEmpty(ScoreMap M)    {
    return M.Count == NIL;
}

valuetype ValueScore(ScoreMap M, keytype k)  {
    valuetype ret = mapUndef;
    int i = 0;
    boolean found = false;
    while ((i < M.Count) && !found)
    {
        if (Eqstr(M.el[i].Key, k))
        {
            ret = M.el[i].Value;
            found = true;
        }
        else
        {
            i++;
        }
    }
    return ret;
}

void DeleteScore(ScoreMap *M, keytype k)    
{
    int i;
    if (IsMemberScore(*M, k)) {
        int idx = 0;
        while (idx < M->Count)  {
            if (M->el[idx].Key == k)   {
                break;
            }
            else    {
                idx++;
            }
        }
        for (i = idx; i < M->Count; i++)    {
            M->el[i].Key = M->el[i+1].Key;
            M->el[i].Value = M->el[i+1].Value;
        }
        M->Count--;
    }
}

void InsertScore(ScoreMap *M, keytype k, valuetype v)
{
    //delete jika sudah ada dan lebih kecil dari v
    //cari max
    valuetype max = -9999;
    for (int i = 0; i < M->Count; i++)
    {
        if (Eqstr(M->el[i].Key, k) && (M->el[i].Value > max))
        {
            max = M->el[i].Value;
        }
    }
    if (!IsMemberScore(*M, k))
    {
        M->el[M->Count].Key = k;
        M->el[M->Count].Value = v;
        M->Count++;
    }
    else    {
        if (v > max)
        {
            DeleteScore(M, k); 
            M->el[M->Count].Key = k;
            M->el[M->Count].Value = v;
            M->Count++;      
        }
    }
    //insert nilai terbaru
}

boolean IsMemberScore(ScoreMap M, keytype k)
{
    boolean found = false;
    int i = 0;
    while (!found && (i < M.Count))    {
        if (Eqstr(M.el[i].Key, k)) {
            found = true;
        }
        else    {
            i++;
        }
    }
    return found;
}

void sortScoreboard(ScoreMap *M)
{
    /* Menggunakan Insertion Sort*/
    int i, j;
    infotypemap k;
    for (i = 1; i < M->Count; i++)
    {
        k = M->el[i];
        j = i - 1;
        while (j >= 0 && M->el[j].Value < k.Value)
        {
            M->el[j+1] = M->el[j];
            j = j - 1;
        }
        M->el[j+1] = k;
    }
}

void PrintScoreboard(ScoreBoard papanskor)
{
    int i;
    printf("**** SCOREBOARD GAME ");
    for(int j = 0; j < papanskor.game_name.Length; j++)
    {
        printf("%c", papanskor.game_name.TabWord[j]);
    }
    printf(" ****\n");
    printf("|     NAMA    |   SKOR    |\n");
    if (papanskor.board.Count == 0)
    {
        printf("---- SCOREBOARD KOSONG ----\n");
    }
    else
    {
        for (i = 0; i < papanskor.board.Count; i++)
        {
            printf("| %s   |", papanskor.board.el[i].Key);
            //buat nyesuaiin batas (nanti)
            printf(" %d     ", papanskor.board.el[i].Value);
            //buat nyesuaiin batas (nanti)
            printf("|\n");
        }
    }
}

void ResetScoreboard(ScoreMap *M)
{
    int i;
    for (i = 0; i < M->Count; i++)
    {
        M->el[i].Key = NULL;
        M->el[i].Value = -9999;
    }
    M->Count = NIL;
}

void ResetArrayScore(ScoreBoard *sb)
{
    //ScoreMap* board = sb->board;
    ResetScoreboard(&(sb->board));
    //printf("Scoreboard berhasil di-reset\n");
}

void DeleteScoreofGame(ScoreBoardList *gamelist,int gameidx)
{
    for(int i=gameidx;i<gamelist->Neff; i++)
    {
        gamelist->List[i] = gamelist->List[i+1];
    }
}