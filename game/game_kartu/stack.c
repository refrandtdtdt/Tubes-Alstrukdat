# include "stack.h"

void CreateEmpty(Stack *S)  {
    Top(*S) = Nil;
}

boolean IsEmpty(Stack S)    {
    return (Top(S) == Nil);
}

boolean IsFull(Stack S)     {
    return (Top(S) == MaxEl-1);
}

void Push(Stack * S, Kartu X)    {
    Top(*S)++;
    InfoTop(*S) = X;
}

void Pop(Stack * S, Kartu* X)    {
    *X = InfoTop(*S);
    Top(*S)--;
}