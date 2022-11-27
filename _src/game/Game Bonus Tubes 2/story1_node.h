#include "story_tree.h"
#include "game_over_node.h"

void node1(int *score, char* player, Address *p)
{
    boolean validinput;
    char dummy;
    int input;
    printf("\"Nanti kita sekolah bareng ya!!!\"");scanf("%c", &dummy);system("cls");
    printf("aku tiba-tiba teringat kembali ke masa itu.");scanf("%c", &dummy);system("cls");
    printf("tumpukan debu meliputi buku tersebut. aku segera mengambil kain untuk membersihkan cover buku tersebut.");scanf("%c", &dummy);system("cls");
    printf("Aku sudah lama tidak menulis kembali diariku.");scanf("%c", &dummy);system("cls");
    printf("mungkin aku sudah bosan dengan hal itu.")scanf("%c", &dummy);system("cls");
    printf("kubuka halaman depan buku itu, kubaca kembali kenangan masa Sekolah Dasarku, tertulis pengalamanku bersama Miya.");scanf("%c", &dummy);system("cls");
    printf("aku dan Miya adalah teman dari masa kecil. dulu kami selalu bermain bersama.");scanf("%c", &dummy);system("cls");
    printf("perkenalan awalku dimulai ketika Bu Kumakawa datang ke tempatku. ia membawa Miya sambil memperkenalkan diri.");scanf("%c", &dummy);system("cls");
    printf("Bu Kumakawa: \"Tolong kenalin dirimu ya, Miya-chan.\"");scanf("%c", &dummy);system("cls");
    printf("Miya: \"Baik, Okaa-san\"");scanf("%c", &dummy);system("cls");
    printf("Miya: \"Halo, Namaku Miya, Kumakawa Miya. Salam Kenal\"");scanf("%c", &dummy);system("cls");
    printf("%s: \"oke, namaku %s, salam kenal ya!\"", player);scanf("%c", &dummy);system("cls");
    printf("Miya: \"Salam kenal, %s-San.\"");scanf("%c", &dummy);system("cls");
    printf("semenjak itu, kita semakin akrab. aku dan dia menikmati waktu bersama bermain di taman bermain dekat rumah, 
    bermain petak umpet bersama teman-temanku yang lain, belajar matematika bareng di rumahku, 
    kebetulan juga ayahku seorang guru matematika. dan kami juga bersekolah di sekolah yang sama.");scanf("%c", &dummy);system("cls");
    printf("saat kelulusan, kami membuat janji bersama.");scanf("%c", &dummy);system("cls");
    printf("Miya: \"Nanti kita masuk ke sekolah yang sama ya!!!\"");scanf("%c", &dummy);system("cls");
    printf("kami berusaha menepatinya bersama.");scanf("%c", &dummy);system("cls");
    printf("namun sayang hingga saat tes masuk ke SMP diumumkan, ternyata nilaiku masih kurang untuk masuk ke SMP favorit yang jadi 
    pilihan Miya, akhirnya kami berpisah saat itu karena aku pindah kota untuk mencari sekolah terbaik lain yang 
    ada di luar kota. kami pun akhirnya jarang bertemu semenjak itu.");scanf("%c", &dummy);system("cls");
    printf("Masa awal SMA pun dimulai, aku memulai kehidupan SMA biasaku.");scanf("%c", &dummy);system("cls");
    printf("aku melihat palang kelas di atasku, sembari mencari kelasku. maklum ini hari pertamaku memasuki SMA.");scanf("%c", &dummy);system("cls");
    printf("akhirnya aku melihatnya, \"kelas 10-2\".");scanf("%c", &dummy);system("cls");
    printf("Aku kemudian memasuki ruang kelas itu.");scanf("%c", &dummy);system("cls");
    printf("kupandangi wajah-wajah teman-temanku. beberapa ada yang kuingat karena merupakan teman sekelasku pada masa SD.");scanf("%c", &dummy);system("cls");
    printf("lalu kulihat wajah familiar yang sudah lama aku tidak melihat, ternyata ada Miya yang duduk sambil memandangi jendela kelas.");scanf("%c", &dummy);system("cls");
    printf("di belakang Miya terdapat kursi kosong. aku kemudian duduk di kursi tersebut.");scanf("%c", &dummy);system("cls");
    printf("begitu ku duduk di bangku, ia menyapaku");scanf("%c", &dummy);system("cls");
    printf("Miya: \"Kamu %s-kun kan?\"");scanf("%c", &dummy);system("cls");
    printf("Miya: \"Kita udah lama banget enggak ketemu.\"");scanf("%c", &dummy);system("cls");
    printf("Miya: \"Gimana Kabarmu?\"");scanf("%c", &dummy);printf("\n\n");
    validinput = false;
    printf("1. Baik\n2. apaan sih?\n\nSilakan pilih opsi dialog(1/2): ");
    while (!validinput)    {
        scanf("%d", &input);
        if ((input != 1) && (input != 2)) {
            printf("Invalid Input\n");
        }
        else    {
            validinput = true
        }
    }
    system("cls");
    //pilihan outcome
    if (input == 1) {
        *score += 300;
        printf("Score +300\n\n");
        printf("Miya: \"Oh, syukurlah. kamu udah cukup tinggi, ya.\"");scanf("%c", &dummy);system("cls");
        printf("%s: \"Namanya juga tumbuh dewasa\"", player);
    }
    else if (input == 2){
        *score -= 200;
        printf("Score -200\n\n");
        printf("Miya: \"Ih kamu, baru ketemu lagi udah songong aja.\"");scanf("%c", &dummy);system("cls");
        printf("%s  : \"Ya terserahku dong!\"", player);scanf("%c", &dummy);system("cls");      
    }
    printf("kemudian dua teman yang tidak asing datang menghampiriku.");scanf("%c", &dummy);system("cls");
    printf("ya, mereka adalah Enji dan Pina. teman bermain kami saat SD dulu.");scanf("%c", &dummy);system("cls");
    printf("Enji: \"Halo guys!\"");scanf("%c", &dummy);system("cls");
    printf("Pina: \"Halo Miya-chan, halo %s\"", player);scanf("%c", &dummy);system("cls");
    validinput = false;
    printf("1. \"Apa kabar!\"\n2. \"Halo, Pina\"\n\nSilakan pilih opsi dialog(1/2): ");
    while (!validinput)    {
        scanf("%d", &input);
        if ((input != 1) && (input != 2)) {
            printf("Invalid Input\n");
        }
        else    {
            validinput = true
        }
    }
    system("cls");
    printf("Pina: \"wah, ternyata lo inget gue juga\"");scanf("%c", &dummy);system("cls");
    printf("%s:	\"ya jelas dong, kita kan friend. ya kan?\"");scanf("%c", &dummy);system("cls");
    printf("Enji: \"eh, masa cuma Anip doang yang disapa, lha terus aku gimana?\"");scanf("%c", &dummy);system("cls");
    printf("%s: \"Hehehe, maap wwww\"", player);scanf("%c", &dummy);system("cls");
    printf("Kemudian guru pun datang, kita pun memulai kelas dengan perkenalan masing-masing");scanf("%c", &dummy);system("cls");
    printf("Pemilihan ketua kelas dimulai, aku pun maju mencalonkan diri.");scanf("%c", &dummy);system("cls");
    printf("namun di situ ada anak songong yang juga maju menjadi calon ketua kelas.");scanf("%c", &dummy);system("cls");
    printf("???: \"bisa-bisanya orang culun kaya lu maju jadi ketua kelas. malu mas\"");scanf("%c", &dummy);system("cls");
    printf("Aku menghela napas.");scanf("%c", &dummy);system("cls");
    printf("pada saat perkenalan, dia mengenalkan diri sebagai refrendt");scanf("%c", &dummy);system("cls");
    printf("Refrendt: \"Asal lo tau ya nerd, gue ini lebih menarik, dan juga menawan, huhuhuhu!!\"");scanf("%c", &dummy);system("cls");
    validinput = false;
    printf("1. \"Bisa-bisanya ni anak\"\n2. ngajak gelud\n\nSilakan pilih opsi dialog(1/2): ");
    while (!validinput)    {
        scanf("%d", &input);
        if ((input != 1) && (input != 2)) {
            printf("Invalid Input\n");
        }
        else    {
            validinput = true
        }
    }
    system("cls");
    //pilihan outcome
    if (input == 1) {
        *score += 100;
        printf("Score +100\n\n");
        printf("Refrendt: \"mari kita lihat nanti, hehe\"");scanf("%c", &dummy);system("cls");
        *p = LEFT(*p);
    }
    else if (input == 2){
        printf("kamu meninju dia.");scanf("%c", &dummy);system("cls");
        printf("Refrendt: \"Apa-apaan nih lu, dasar kurang ajar\"");scanf("%c", &dummy);system("cls");  
        printf("Refrendt mengayunkan lengannya, pertengkaran tidak dapat dihindarkan.");scanf("%c", &dummy);system("cls");
        printf("akhirnya kalian berdua saling adu tonjok, dan ternyata kamu kalah dengan refrendt.");scanf("%c", &dummy);system("cls");
        printf("akhirnya kamu masuk UKS");scanf("%c", &dummy);system("cls");
        *p = RIGHT(*p);                
    }
}