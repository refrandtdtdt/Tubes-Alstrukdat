# include "dinerdash.h"

int rng(int lower, int upper) {
    int num;
    srand(time(0));
    num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void CreateMakanan(Makanan* food, int id)   {
    food->ID = "M";
    char str_id[3];
    int temp = id;
    int len  = floor(log(id)) + 1; //panjang digit id 
    int degree = len;
    int i;
    int j = 0;
    int k = 1;
    for(i = 0; i < len; i++)    {
        str_id[i] = temp/(pow(10, degree));
        degree--;
    }
    while (str_id[j] != '\0')   {
        food->ID[k] = str_id[j];
        j++;
        k++;
    }
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
        for (i = 0; i <= antrean.idxTail; i++)  {
            printf("%s", antrean.buffer[i].ID);
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
        for (j = 0; j <= cooking.idxTail; j++)  {
            printf("%s       ", cooking.buffer[j].ID);
            printf("| %d              |", cooking.buffer[j].durasi);
            printf("\n");
        }
    }
    //menampilkan serving
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    if (!isEmpty(serving))  {
        for (k = 0; k <= cooking.idxTail; k++)  {
            printf("%s       ", cooking.buffer[k].ID);
            printf("| %d              |", cooking.buffer[k].ketahanan);
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
    Makanan food;
    int idx_cook, idx_serve;
    while ((length(antrean) > 7) && (served < 15))  {
        //print tabel
        Table(antrean, cooking, serving);

        //input command
        while (!((command == "COOK") || (command == "SERVE")))  {
            printf("MASUKKAN COMMAND: ");
            command = (char*) malloc (20*sizeof(char));
            scanf("%s %s", &command, &food);
            if (!((command == "COOK") || (command == "SERVE"))  {
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
                enqueue(&cooking, food);
                on_cook++;
            }
        }
    }
}