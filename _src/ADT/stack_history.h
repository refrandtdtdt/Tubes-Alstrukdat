#ifndef stackt_H
#define stackt_H

#include "../boolean.h"
#include "mesinkata_modif.h"

#define NilHistory -1
#define MaxElHistory 100

typedef Word infotypeHistory;
typedef int address;   

typedef struct {
  infotypeHistory T[MaxElHistory]; 
  address TOP;
  int NbElmt;  
} StackHistory;


#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

void CreateStackHistory(StackHistory *S);

boolean IsStackHistoryEmpty(StackHistory S);

boolean IsStackHistoryFull(StackHistory S);

void PushHistory(StackHistory * S, infotypeHistory X);

void PopHistory(StackHistory * S, infotypeHistory* X);

void InverseStackHistory(StackHistory *S);

void CopyStackHistory(StackHistory *S1, StackHistory S2);

void PrintStackHistory(StackHistory S, int banyak);

#endif