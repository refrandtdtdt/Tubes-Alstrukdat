# include "main_game_card.h"

void CardGame(ScoreBoard *Scoreboard)  {
    /*KAMUS*/
    List deck;
    char* input;
    int num_of_players, num_of_cards, turn, chosen_card;
    int idx_winner;
    DrawnList drawn_card;
    Kartu currentCard;
    DrawnCard currentDrawnCard;
    DrawnCard currentPlayerDraw;
    Pemain round_winner, temp;
    Stack tumpukan;
    Sentence sent_pl, sent_card, selected_card;
    QueuePemain player;
    boolean valid;
    boolean game_over;
    boolean winner;

    /*kode program utama*/
    CreateSentence(&sent_pl);
    CreateSentence(&sent_card);
    CreateEmptyStackCard(&tumpukan);
    CreateQueuePemain(&player);
    printf("Welcome to Card Game!\n");
    printf("How many players do you want to play with?\nEnter: ");
    START();
    convertToArrayOfKata(&sent_pl, 1);
    num_of_players = StrToInt(kataToString(sent_pl.buffer[0]));
    printf("Default number of cards that each player will get at the start of the game:\n");
    START();
    convertToArrayOfKata(&sent_card, 1);
    num_of_cards = StrToInt(kataToString(sent_card.buffer[0]));

    //create the deck
    /*aturan*/
    //pakai mesin kata buat ngeprint aturannya
    CHARMACHINE("aturan.txt");
    CreateDeck(&deck);
    printf("Tunggu Sebentar, sedang dikocok...\n");
    shuffle(&deck, LengthCard(deck));
    Shuffle(&deck, &tumpukan);
    //set the player
    SetPlayers(&player, num_of_players);

    /*mengisi kartu masing-masing player*/
    for (int l = 0; l < num_of_cards*num_of_players; l++)   {
        Take(&(player.buffer[l%num_of_players+IDX_HEADQ(player)].pegangan), &tumpukan);
    }

    system("cls");

    /* Start Permainan */
    printf("Permainan Dimulai!!\n");
    drawn_card = MakeDrawnList();
    PopStackCard(&tumpukan, &currentCard);
    currentDrawnCard.card = currentCard;
    currentDrawnCard.id_player = -1;
    InsertLastDrawn(&drawn_card, currentDrawnCard);
    turn = 0;
    
    /*Perjalanan permainan*/
    game_over = false;
    while (!game_over)  {
        //queue main
        printf("Kartu pembukaan round: ");
        PrintCard(currentCard);
        printf("\n");
        while (turn < num_of_players)   {
            chosen_card = -1;
            valid = false;
            //cek validitas
            while (!valid)  {
                printf("Giliran %s, pilih kartu: \n", HEADQ(player).nama);

                //cek apabila pemain punya suitsnya
                if (!SearchSuits(HEADQ(player).pegangan,currentCard))    {
                    printf("Tidak ada suit ini pada kartu anda, secara otomatis akan mencari kartu dari stack\n");
                }
                while (!SearchSuits(HEADQ(player).pegangan,currentCard)) {
                    Take(&(HEADQ(player).pegangan), &tumpukan);
                    //ketika stack sudah empty
                    if (IsEmptyStackCard(tumpukan))  {
                        printf("tumpukan kartu habis. Mohon tunggu, Sedang dikocok ulang...\n");
                        Shuffle(&deck, &tumpukan);
                    }
                }
                printf("Silakan pilih Kartunya: ");
                PrintPlayerCards(HEADQ(player));
                START();
                convertToArrayOfKata(&selected_card, 1);
                chosen_card = StrToInt(selected_card.buffer[0].TabWord);
                if (chosen_card < 0 && chosen_card > LengthCard(HEADQ(player).pegangan)) {
                    printf("index invalid, ulangi.\n");
                }
                else if (!CheckSuitsEqual(currentCard, HEADQ(player).pegangan.A[chosen_card-1]))    {
                    printf("suits tidak cocok!\n");
                }
                else    {
                    valid = true;
                }
            }
            system("cls");
            Draw(&(HEADQ(player).pegangan), HEADQ(player).pegangan.A[chosen_card-1], &currentPlayerDraw, HEADQ(player).id_player);
            InsertLastDrawn(&drawn_card, currentPlayerDraw);
            printf("Drawn Cards: \n");
            PrintDrawnCardList(drawn_card);
            dequeuePemain(&player, &temp);
            enqueuePemain(&player, temp);
            turn++;
        }
        valid = false;
        /*membandingkan kartu siapa yang paling kuat*/
        idx_winner = 0;
        boolean pemenang_putaran = false;
        while(!pemenang_putaran && (idx_winner < LengthDrawn(drawn_card))) {
            if (player.buffer[idx_winner].id_player == Max(drawn_card).id_player)   {
                pemenang_putaran = true;
            }
            idx_winner++;
        }
        if (!pemenang_putaran)  {
            InsertLastCard(&deck, drawn_card.round[FirstIdxDrawn(drawn_card)].card);
            DeleteFirstDrawn(&drawn_card);
            idx_winner = 0;
        }
        while(!pemenang_putaran) {
            if (player.buffer[idx_winner].id_player == Max(drawn_card).id_player)   {
                pemenang_putaran = true;
                break;
            }
            idx_winner++;
        }
        /*pindah turn ke pemenang*/
        boolean win_round_player = false;
        Pemain round_winner; //penampung sementara untuk geser HEADQ dan TAILQ
        while (!win_round_player) {
            if (HEADQ(player).id_player == Max(drawn_card).id_player) {
                win_round_player = true;
                break;
            }
            dequeuePemain(&player, &round_winner);
            enqueuePemain(&player, round_winner);
        }
        round_winner = HEADQ(player);
        printf("\n");
        printf("pemenang round ini: %s\n", HEADQ(player).nama);

        //kartu di drawn list dikembalikan ke deck;
        for (int k = 0; k < LengthDrawn(drawn_card); k++)   {
            InsertLastCard(&deck, drawn_card.round[k].card);
        }
        drawn_card = MakeDrawnList();
        //cek apabila sudah ada yang menang
        int idx_winner = 0;
        while (idx_winner < num_of_players)    {
            if (IsListEmpty(HEADQ(player).pegangan))    {
                game_over = true;
                break;
            }
            else    {
                dequeuePemain(&player, &temp);
                enqueuePemain(&player, temp);
            }
            idx_winner ++;
        }
        if (idx_winner >= num_of_players)   {
            idx_winner = IDX_UNDEF;
        }
        if (game_over)  {
            printf("Permainan Selesai, Pemenang adalah: ");
            printf("%s\n", HEADQ(player).nama);
            continue;
        }

        //mulai putaran berikutnya oleh pemenang
        system("cls");
        while (!valid && !game_over)  {
            printf("Pemenang putaran ini adalah %s, silahkan pilih kartu: \n", HEADQ(player).nama);

            //cek apabila pemain punya suitsnya
            PrintPlayerCards(HEADQ(player));
            printf("\n");
            printf("Silakan pilih Kartunya: \n");
            START();
            convertToArrayOfKata(&selected_card, 1);
            chosen_card = StrToInt(selected_card.buffer[0].TabWord);
            if (chosen_card < 0 && chosen_card > LengthCard(HEADQ(player).pegangan)) {
                printf("index invalid, ulangi.\n");
            }
            else    {
                valid = true;
            }
        }
        currentCard = HEADQ(player).pegangan.A[chosen_card-1];
        Draw(&(HEADQ(player).pegangan), HEADQ(player).pegangan.A[chosen_card-1], &currentPlayerDraw, HEADQ(player).id_player);       
        InsertLastDrawn(&drawn_card, currentPlayerDraw);
        system("cls");
        if (!game_over) {
            printf("Drawn Cards: \n");
            dequeuePemain(&player, &round_winner);
            enqueuePemain(&player, round_winner);
            turn = 1;
        }
    }
    int score_value;
    if (!IsMemberScore(Scoreboard->board, HEADQ(player).nama))  {
        InsertScore(&(Scoreboard->board), HEADQ(player).nama, 1);
    }
    else    {
        score_value = ValueScore(Scoreboard->board, HEADQ(player).nama);
        score_value++;
        InsertScore(&(Scoreboard->board), HEADQ(player).nama, score_value);
    }
}