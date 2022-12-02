# include "game_kartu.h"

Pemain CreatePlayer(Word nama, int id)   {
    Pemain ret;
    ret.id_player = id;
    ret.pegangan = MakeList();
    int i = 0;
    while (i < nama.Length) {
        ret.nama[i] = nama.TabWord[i];
        i++;
    }
    return ret;
}

void SetPlayers(Queue* pemain, int jumlah)   {
    Sentence player;
    Pemain player1;
    for (int i = 0; i < jumlah; i++)    {
        printf("Masukkan Nama P%d (hanya sekata): ", (i+1));
        START();
        convertToArrayOfKata(&player, 1);
        player1 = CreatePlayer(player.buffer[0], i);
        enqueueCard(pemain, player1);
    }
}

boolean Stronger(Kartu c1, Kartu c2)    {
    if (c1.Suits == c2.Suits)   {
        return RanksToInt(c1) > RanksToInt(c2);
    }
}

int RanksToInt(Kartu c) {
    if ((StrToInt(c.Ranks) >= 2) && (StrToInt(c.Ranks) <= 10)) {
        return StrToInt(c.Ranks);
    }
    else if (Eqstr(c.Ranks, "J"))   {
        return 11;
    }
    else if (Eqstr(c.Ranks, "Q"))   {
        return 12;
    }
    else if (Eqstr(c.Ranks, "K"))   {
        return 13;
    }
    else if (Eqstr(c.Ranks, "A"))   {
        return 14;
    }
}

boolean CheckSuitsEqual(Kartu c1, Kartu c2) {
    return c1.Suits == c2.Suits;
}

void CreateDeck(List* cards)    {
    *cards = MakeList();
    char* ranks[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    char suits[4] = {'S', 'H', 'C', 'D'};
    //create the list
    int idx = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++)    {
            cards->A[idx].Suits = suits[i];
            cards->A[idx].Ranks = ranks[j];
            idx++;   
        }
    }
}

void Shuffle(List* cards, Stack* card_stack)    { 
    int len = LengthCard(*cards);
    //printf("%d\n", len);
    Kartu val;
    shuffle(cards, len);
    while (!IsListEmpty(*cards))    {
        val = cards->A[len-1];
        DeleteLast(cards);
        Push(card_stack, val);
        len--;
    }
}

void Draw(List* cards, Kartu pick, DrawnCard* draw, int id_pemain) {
    //search pick
    Kartu card;
    int i = 0;
    while ((card.Ranks != pick.Ranks) || (card.Suits != pick.Suits))    {
        card = cards->A[i];
        if ((card.Ranks != pick.Ranks) || (card.Suits != pick.Suits))   {
            i++;
        }
    }

    draw->card = card;
    draw->id_player = id_pemain;
    DeleteAtCard(cards, i);
}

void Take(List *cards, Stack* card_stack)   {
    Kartu card;
    Pop(card_stack, &card);
    InsertFirstCard(cards, card);
}

boolean SearchSuits(List card, Kartu c) {
    boolean found = false;
    int i = 0;
    while (!found && (card.A[i].Suits != Tanda))  {
        if (CheckSuitsEqual(card.A[i], c))  {
            found = true;
        }
        i++;
    }
    return found;
}

void PrintCard(Kartu card)  {
    printf("(%c:%s)", card.Suits, card.Ranks);
}

void PrintPlayerCards(Pemain pemain)    {
    for (int i = 1; i < LengthCard(pemain.pegangan);i++)    {
        printf("%d.", i);
        PrintCard(pemain.pegangan.A[i-1]);
        if ((i-1) % 2 != 0) {

            printf(",");
        }
        else    {
            printf("\n");
        }

    }
    int j = LengthCard(pemain.pegangan);
    printf("%d.", j);
    PrintCard(pemain.pegangan.A[j-1]);
    printf("\n");
}

void PrintCardList(List card)   {
    for (int i = 0; i < LengthCard(card)-1;i++)    {
        PrintCard(card.A[i]);
        printf(",");
    }
    int j = Length(card)-1;
    PrintCard(card.A[j]);
    printf("\n");    
}

void PrintDrawnCardList(DrawnList drawn)    {
    for (int i = 0; i < LengthDrawn(drawn)-1;i++)    {
        printf("%d.", drawn.round[i].id_player);
        PrintCard(drawn.round[i].card);
        printf(",");
    }
    int j = LengthDrawn(drawn)-1;
    printf("%d.", drawn.round[j].id_player);
    PrintCard(drawn.round[j].card);
    printf("\n");        
}

void PrintStackCard(Stack card_stack)   {
    for (int i = 0; i < Top(card_stack);i++)    {
        PrintCard(card_stack.T[i]);
        printf(",");
    }
    int j = Top(card_stack);
    PrintCard(card_stack.T[j]);
    printf("\n");     
}

DrawnCard Max(DrawnList cards)  {
    DrawnCard max = cards.round[0];
    for (int i = 0; i < LengthDrawn(cards); i++) {
        if (RanksToInt(cards.round[i].card) > RanksToInt(max.card))   {
            max = cards.round[i];
        }
    }
    return max;
}

