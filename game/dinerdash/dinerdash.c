# include "dinerdash.h"

int rng(int lower, int upper) {
    int num;
    srand(time(0));
    num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void CreateMakanan(Makanan* food, int id)   {
    food->ID = id;
    food->durasi = rng(1,5);
    food->ketahanan = rng(1,5);
    food->harga = rng(10000, 15000);
}

void Table(Queue antrean, Queue cooking, Queue serving) {
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi Memasak | Ketahanan | Harga\n");
    printf("-------------------------------------------------\n");
    int i,j,k;
    //menampilkan antrean
    if (!isEmpty(antrean)); {
        for (i = antrean.idxHead; i <= antrean.idxTail; i++)  {
            printf("M%d", antrean.buffer[i].ID);
            printf("     ");
            printf("| %d              |", antrean.buffer[i].durasi);
            printf("| %d              |", antrean.buffer[i].ketahanan);
            printf("| %d          |", antrean.buffer[i].harga);
            printf("\n");
        }
    }
    //menampilkan cooking
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa Durasi Memasak \n");
    if (!isEmpty(cooking))  {
        for (j = cooking.idxHead; j <= cooking.idxTail; j++)  {
            printf("M%d       ", cooking.buffer[j].ID);
            printf("| %d              |", cooking.buffer[j].durasi);
            printf("\n");
        }
    }
    //menampilkan serving
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    if (!isEmpty(serving))  {
        for (k = serving.idxHead; k <= serving.idxTail; k++)  {
            printf("M%d       ", serving.buffer[k].ID);
            printf("| %d              |", serving.buffer[k].ketahanan);
            printf("\n");
        }
    }
    printf("\n");
}

void DinerDash()    {
    printf("Selamat datang di game Diner Dash!\n\n");
    int saldo = 0;      //uang yang diterima pemain
    printf("SALDO: %d\n\n", saldo);

    int on_cook = 0;
    int on_queue = 0;
    int served = 0;

    //masukkan default
    Queue antrean, cooking, serving;
    Makanan pesanan;
    CreateQueue(&antrean);
    CreateQueue(&cooking);
    CreateQueue(&serving);
    for (int st = 0; st < 3; st++)  {
        CreateMakanan(&pesanan, st);
        enqueue(&antrean, pesanan);
    }
    char* command;
    char* id_food;
    Makanan food;
    int idx_cook, idx_serve;
    while ((length(antrean) <= 7) && (served < 15))  {
        DeleteZero(&serving);
        while (HEAD(cooking).durasi != 0)   {
            if (HEAD(cooking).durasi == 0)  {
                sort_enqueue(&serving, HEAD(cooking));
            }
        }

        // print tabel
        Table(antrean, cooking, serving);

        //input command
        while (!((Eqstr(command, "COOK")) || (Eqstr(command, "COOK  "))))  {
            printf("MASUKKAN COMMAND: ");
            command = (char*) malloc (20*sizeof(char));
            id_food = (char*) malloc (10*sizeof(char));
            scanf("%s %s", command, id_food);
            if (!((command == "COOK") || (command == "SERVE")))  {
                printf("Command Tidak Valid, ulangi.\n");
            }
        }

        if (!isEmpty(cooking))  {
            for (idx_cook = 0; idx_cook < length(cooking); idx_cook++)  {
                cooking.buffer[idx_cook].durasi--;
            }
        }
        if (!isEmpty(serving))  {
            for (idx_serve = 0; idx_serve < length(cooking); idx_serve++)  {
                cooking.buffer[idx_serve].ketahanan--;
            } 
        }


        //cek input
        
        if (command == "COOK")    {
            if (on_cook <= 5)   {
                sort_enqueue(&cooking, food);
                on_cook++;
            }
        }
        else if (command == "SERVE")    {
            
        }
    }
}