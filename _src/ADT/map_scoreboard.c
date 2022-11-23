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
        if (M.el[i].Key == k)
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

void InsertScore(ScoreMap *M, keytype k, valuetype v)
{
    //delete jika sudah ada dan lebih kecil dari v
    if (IsMemberScore(*M, k))
    {
        if (ValueScore(*M, k) < v)  {
            DeleteScore(M, k);
        }   
    }
    //insert nilai terbaru dengan sort menggunakan binary search lalu insert di index itu + 1
    int l, h, m, idxfound;
    infotype temp;
    if (!IsMemberScore(*M, k))   {
        if (!IsBoardEmpty(*M))
        {
            l = 0;
            h = M->Count - 1;
            while (l != h)
            {
                m = (l + h)/2;
                if (v == M->el[m].Value)
                {
                    break;
                }
                else if (v > M->el[m].Value)
                {
                    l = m + 1;
                }
                else    {
                    h = m - 1;
                }
            }
            //tempat ketemunya diinsert
            if (v <= M->el[l].Value) {
                idxfound = l + 1;
            }
            else
            {
                idxfound = l;
            }
            
            address n;
            for (n = M->Count-1; n >= idxfound ; n--)
            {
                M->el[n+1] = M->el[n];
            }
            M->el[idxfound].Key = k;
            M->el[idxfound].Value = v;
        }
        else    {
            M->el[0].Key = k;
            M->el[0].Value = v;
        }
        M->Count++;
    }
}

void DeleteScore(ScoreMap *M, keytype k)    
{
    int i;
    if (IsMemberScore(*M, k)) {
        int idx = 0;
        while (idx < M->Count)  {
            if (M->el[idx].Key == k)   {
                for (i = idx; i < M->Count; i++)    {
                    M->el[i].Key = M->el[i+1].Key;
                    M->el[i].Value = M->el[i+1].Value;
                }
                M->Count--;
            }
            idx++;
        }
    }
}

boolean IsMemberScore(ScoreMap M, keytype k)
{
    boolean found = false;
    int i = 0;
    while (!found && (i < M.Count))    {
        if (M.el[i].Key == k) {
            found = true;
        }
        i++;
    }
    return found;
}

void sortScoreboard(ScoreMap *M, int length)
{
    /* Menggunakan Insertion Sort*/
    int i, j;
    infotype k;
    for (i = 1; i < length; i++)
    {
        k = M->el[i];
        j = i - 1;
        while (j >= 0 && M->el[j].Value > k.Value)
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
    printf("**** SCOREBOARD GAME %s ****\n", papanskor.game_name);
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
        M->el[i] = NULL;
    }
    M->Count = 0;
}

void ResetArrayScore(ScoreBoard *sb)
{
    ResetScoreboard(sb->board);
    printf("Scoreboard berhasil di-reset\n");
}
