# include "stack.h"

void CreateEmptyStackCard(Stack *S)  {
    Top(*S) = Nil;
}

boolean IsEmptyStackCard(Stack S)    {
    return (Top(S) == Nil);
}

boolean IsFullStackCard(Stack S)     {
    return (Top(S) == MaxEl-1);
}

void PushStackCard(Stack * S, Kartu X)    {
    Top(*S)++;
    InfoTop(*S) = X;
}

void PopStackCard(Stack * S, Kartu* X)    {
    *X = InfoTop(*S);
    Top(*S)--;
}