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
    if (!IsMemberScore(*M, k))   {
        M->el[M->Count].Key = k;
        M->el[M->Count].Value = v;
        M->Count++;
    }
}

void DeleteScore(ScoreMap *M, keytype k)    
{
    int i;
    if (IsMember(*M, k)) {
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
