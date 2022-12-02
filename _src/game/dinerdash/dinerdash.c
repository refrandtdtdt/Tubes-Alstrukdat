# include "dinerdash.h"
# include <stdlib.h>

int rng1(int lower, int upper) {
    int num,num1;
    srand(time(NULL));
    num = rand() % ((rand() + 3) % 50000);
    num1 = (rand() % (upper - lower + 1)) + lower;
    return num1;
}

int rng2(int lower, int upper) {
    int num,num1;
    srand(time(NULL));
    num = rand() % ((rand()) % 25000);
    num1 = ((rand() + 2) % (upper - lower + 1)) + lower;
    return num1;
}

void CreateMakanan(Makanan* food, int id)   {
    food->ID = id;
    food->durasi = rng1(1,5);
    food->ketahanan = rng2(1,5);
    food->harga = rng1(10000, 15000);
}

void Table(QueueFood antrean, QueueFood cooking, ListPesanan serving) {
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi Memasak | Ketahanan | Harga     |\n");
    printf("-------------------------------------------------\n");
    int i,j,k;
    //menampilkan antrean
    if (!isEmptyfood(antrean)); {
        for (i = antrean.idxHead; i <= antrean.idxTail; i++)  {
            printf("M%d", antrean.buffer[i].ID);
            printf("     ");
            printf("| %d              |", antrean.buffer[i].durasi);
            printf(" %d          |", antrean.buffer[i].ketahanan);
            printf(" %d     |", antrean.buffer[i].harga);
            printf("\n");
        }
    }
    printf("\n");
    //menampilkan cooking
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa Durasi Memasak |\n");
    printf("-------------------------------\n");
    if (!isEmptyfood(cooking))  {
        for (j = cooking.idxHead; j <= cooking.idxTail; j++)  {
            printf("M%d      ", cooking.buffer[j].ID);
            printf("| %d                  |", cooking.buffer[j].durasi);
            printf("\n");
        }
    }
    printf("\n");
    //menampilkan serving
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan |\n");
    printf("----------------------------------\n");
    if (!IsEmptyPesanan(serving))  {
        for (k = FirstIdxPesanan(serving); k <= LastIdxPesanan(serving); k++)  {
            printf("M%d      ", serving.A[k].ID);
            printf("| %d                   |", serving.A[k].ketahanan);
            printf("\n");
        }
    }
    printf("\n");
}

void DinerDash(ScoreBoard *scoreboard)    {
    FILE* aturan;
    char ch;
    char ret;
    CHARMACHINE("_src/game/dinerdash/dinerdash_ui.txt");
    printf("Selamat datang di game Diner Dash!\n\n");
    int saldo = 0;      //uang yang diterima pemain
    int on_cook = 0;
    int served = 0;
    int idx_served;
    int st = 0;
    Sentence main_menu_comm;
    boolean start = false;
    while (!start)  {
        printf("Silakan pilih command (START/ATURAN)\n");
        START();
        convertToArrayOfKata(&main_menu_comm, 1);
        if (Eqstr(kataToString(main_menu_comm.buffer[0]), "ATURAN"))  {
            CHARMACHINE("_src/game/dinerdash/aturan_diner_dash.txt");
        }
        else if (Eqstr(kataToString(main_menu_comm.buffer[0]), "START")) {
            start = true;
        }
        else    {
            printf("Invalid Command\n");
        }
    }

    printf("Mohon Tunggu Sebentar, sedang memproses...\n");
    //masukkan default
    QueueFood antrean, cooking;
    ListPesanan serving;
    Makanan pesanan;
    FoodType head_antrean;
    Sentence input;
    CreateQueueFood(&antrean);
    CreateQueueFood(&cooking);
    serving = MakeListPesanan();
    while (st < 3)  {
        CreateMakanan(&pesanan, st);
        enqueuefood(&antrean, pesanan);
        st++;
        delay(20500);
    }
    printf("\n");
    char* command;
    char* id_food_str1;
    char* id_food_str2;
    Makanan food, gain;
    int idx_cook, idx_serve, id_food;
    int xx;
    int cap = 1000;
    command = (char*) malloc (cap*sizeof(char));
    id_food_str1 = (char*) malloc (cap*sizeof(char));
    id_food_str2 = (char*) malloc (cap*sizeof(char));
    boolean success = false;
    boolean input_success;
    while ((lengthfood(antrean) <= 7) && (served < 15))  {
        printf("SALDO: %d\n\n", saldo);
        
        input_success = false;
        // print tabel
        Table(antrean, cooking, serving);
        //input command
        while (!input_success)  {
            printf("MASUKKAN COMMAND: ");
            START();
            convertToArrayOfKata(&input, 2);
            command = kataToString(input.buffer[0]);
            id_food_str1 = kataToString(input.buffer[1]);
            getcommParameter(id_food_str1, "M", id_food_str2);
            id_food = StrToInt(id_food_str2);
            Search_queuefood (antrean, id_food, &xx);
            if (Eqstr(command, "SKIP")) {
                printf("Berhasil Skip\n");
                input_success = true;
                break;
            }
            if (!((Eqstr(command, "COOK")) || (Eqstr(command, "SERVE"))))  {
                printf("Command Tidak Valid, ulangi.\n");
            }
            else if (id_food == -999){
                printf("ID makanan tidak valid.\n");
            }
            else if (xx == IDX_UNDEF) {
                printf("Gagal Memasak M%d. Makanan M%d tidak terdaftar.\n", id_food, id_food);
            }
            else    {
                input_success = true;
            }
        }

        if (Eqstr(command, "SERVE"))    {
            head_antrean =  HEAD(antrean);
            if (id_food == head_antrean.ID)    {
                SearchPesanan(serving, head_antrean, &idx_served);
                if (idx_served != InvalidIdx)   {
                    DeleteAtPesanan(&serving, idx_served);
                    served++;
                    dequeuefood(&antrean, &gain);
                    saldo += gain.harga;
                    printf("Berhasil mengantar M%d.\n", gain.ID);
                    success = true;
                }
                else    {
                    printf("Makanan M%d Belum jadi.\n", id_food);
                    success = false;
                }
            }
            else    {
                printf("Belum bisa dihidangin, Makanan M%d belum dihidangin!\n", head_antrean.ID);
                success = false;
            }
        }

        if (Eqstr(command, "SKIP")) {
            success = true;
        }
        //kurangi 1 setiap round jika success
        if (success)    {
            if (!isEmptyfood(cooking))  {
                for (idx_cook = IDX_HEAD(cooking); idx_cook <= IDX_TAIL(cooking); idx_cook++)  {
                    cooking.buffer[idx_cook].durasi--;
                }
            }
            if (!IsEmptyPesanan(serving))  {
                for (idx_serve = FirstIdxPesanan(serving); idx_serve <= LastIdxPesanan(serving); idx_serve++)  {
                    serving.A[idx_serve].ketahanan--;
                } 
            }

            //cari apabila ada yang sudah selesai dimasak
            while (HEAD(cooking).durasi == 0)   {
                if (HEAD(cooking).durasi == 0)  {
                    dequeuefood(&cooking, &food);
                    InsertLastPesanan(&serving, food);
                    printf("Makanan M%d telah selesai dimasak.\n", food.ID);
                }
            }
            //cari yang sudah tidak tahan
            delete_zero_durability(&serving);
        }

        //cek input    
        if (Eqstr(command, "COOK"))    {
            if (on_cook <= 5)   {
                sort_enqueuefood(&cooking, antrean.buffer[xx]);
                on_cook++;
                printf("Berhasil memasak M%d.\n", id_food);
                success = true;
            }
            else    {
                printf("antrian masak penuh! Gagal memasak M%d.\n", id_food);
                success = false;
            }
        }

        if (success)    {
            //tambah pesanan baru
            CreateMakanan(&pesanan, st);
            enqueuefood(&antrean, pesanan);
            st++;
        }
        id_food = -1;
        printf("===========================================================================\n");
    }
    free(command);
    free(id_food_str1);
    free(id_food_str2);
    printf("\nPermainan Selesai!!\nTotal Pendapatan yang didapat: %d\n", saldo);
    Sentence player_name_sent;
    char* player_name;
    printf("Masukkan Nama Pemain (tanpa spasi): ");
    START();
    convertToArrayOfKata(&player_name_sent, 1);
    player_name = kataToString(player_name_sent.buffer[0]);
    InsertScore(&(scoreboard->board), player_name, saldo);
}
