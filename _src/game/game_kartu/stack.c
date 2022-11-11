# include "stack.h"

void CreateEmptyStack(Stack *S)  {
    Top(*S) = Nil;
}

boolean IsEmptyStack(Stack S)    {
    return (Top(S) == Nil);
}

boolean IsFullStack(Stack S)     {
    return (Top(S) == MaxCard-1);
}

void Push(Stack * S, Kartu X)    {
    Top(*S)++;
    InfoTop(*S) = X;
}

void Pop(Stack * S, Kartu* X)    {
    *X = InfoTop(*S);
    Top(*S)--;
}