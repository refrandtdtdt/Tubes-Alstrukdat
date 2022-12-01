#include "story1_node.h"

void node1(int *score, char* player, Address *p)
{
    boolean validinput;
    char dummy;
    int input;
    Sentence word_input;
    printf("\"Nanti kita sekolah bareng ya!!!\"");START();system("cls");
    printf("aku tiba-tiba teringat kembali ke masa itu.");START();system("cls");
    printf("tumpukan debu meliputi buku tersebut. aku segera mengambil kain untuk membersihkan cover buku tersebut.");START();system("cls");
    printf("Aku sudah lama tidak menulis kembali diariku.");START();system("cls");
    printf("mungkin aku sudah bosan dengan hal itu.");START();system("cls");
    printf("kubuka halaman depan buku itu, kubaca kembali kenangan masa Sekolah Dasarku, tertulis pengalamanku bersama Megumi.");START();system("cls");
    printf("aku dan Megumi adalah teman dari masa kecil. dulu kami selalu bermain bersama.");START();system("cls");
    printf("perkenalan awalku dimulai ketika Bu Miyagawa datang ke tempatku. ia membawa Megumi sambil memperkenalkan diri.");START();system("cls");
    printf("Bu Miyagawa: \"Tolong kenalin dirimu ya, Megumi-chan.\"");START();system("cls");
    printf("Megumi: \"Baik, Okaa-san\"");START();system("cls");
    printf("Megumi: \"Halo, Namaku Megumi, Miyagawa Megumi. Salam Kenal\"");START();system("cls");
    printf("%s: \"oke, namaku %s, salam kenal ya!\"", player, player);START();system("cls");
    printf("Megumi: \"Salam kenal, %s-San.\"", player);START();system("cls");
    printf("semenjak itu, kita semakin akrab. aku dan dia menikmati waktu bersama bermain di taman bermain dekat rumah, bermain petak umpet bersama teman-temanku yang lain, belajar matematika bareng di rumahku, kebetulan juga ayahku seorang guru matematika. dan kami juga bersekolah di sekolah yang sama.");START();system("cls");
    printf("saat kelulusan, kami membuat janji bersama.");START();system("cls");
    printf("Megumi: \"Nanti kita masuk ke sekolah yang sama ya!!!\"");START();system("cls");
    printf("kami berusaha menepatinya bersama.");START();system("cls");
    printf("namun sayang hingga saat tes masuk ke SMP diumumkan, ternyata nilaiku masih kurang untuk masuk ke SMP favorit yang jadi pilihan Megumi, akhirnya kami berpisah saat itu karena aku pindah kota untuk mencari sekolah terbaik lain yang ada di luar kota. kami pun akhirnya jarang bertemu semenjak itu.");START();system("cls");
    printf("Masa awal SMA pun dimulai, aku memulai kehidupan SMA biasaku.");START();system("cls");
    printf("aku melihat palang kelas di atasku, sembari mencari kelasku. maklum ini hari pertamaku memasuki SMA.");START();system("cls");
    printf("akhirnya aku melihatnya, \"kelas 10-2\".");START();system("cls");
    printf("Aku kemudian memasuki ruang kelas itu.");START();system("cls");
    printf("kupandangi wajah-wajah teman-temanku. beberapa ada yang kuingat karena merupakan teman sekelasku pada masa SD.");START();system("cls");
    printf("lalu kulihat wajah familiar yang sudah lama aku tidak melihat, ternyata ada Megumi yang duduk sambil memandangi jendela kelas.");START();system("cls");
    printf("di belakang Megumi terdapat kursi kosong. aku kemudian duduk di kursi tersebut.");START();system("cls");
    printf("begitu ku duduk di bangku, ia menyapaku");START();system("cls");
    printf("Megumi: \"Kamu %s-kun kan?\"", player);START();system("cls");
    printf("Megumi: \"Kita udah lama banget enggak ketemu.\"");START();system("cls");
    printf("Megumi: \"Gimana Kabarmu?\"");START();printf("\n\n");
    validinput = false;
    printf("1. Baik\n2. apaan sih?\n\nSilakan pilih opsi dialog(1/2): ");
    while (!validinput)    {
        START();
        convertToArrayOfKata(&word_input, 1);
        input = StrToInt(word_input.buffer[0].TabWord);
        if ((input != 1) && (input != 2)) {
            printf("Invalid Input\n");
        }
        else    {
            validinput = true;
        }
    }
    //system("cls");
    //pilihan outcome
    if (input == 1) {
        *score += 300;
        printf("Score +300\n\n");
        printf("Megumi: \"Oh, syukurlah. kamu udah cukup tinggi, ya.\"");START();//system("cls");
        printf("%s: \"Namanya juga tumbuh dewasa\"", player);START();system("cls");
    }
    else if (input == 2){
        *score -= 200;
        printf("Score -200\n\n");
        printf("Megumi: \"Ih kamu, baru ketemu lagi udah songong aja.\"\n");START();//system("cls");
        printf("%s  : \"Ya terserahku dong!\"", player);START();system("cls");      
    }
    printf("kemudian dua teman yang tidak asing datang menghampiriku.");START();system("cls");
    printf("ya, mereka adalah Enji dan Pina. teman bermain kami saat SD dulu.");START();system("cls");
    printf("Enji: \"Halo guys!\"");START();system("cls");
    printf("Pina: \"Halo Megumi-chan, halo %s\"", player);START();system("cls");
    validinput = false;
    printf("1. \"Apa kabar!\"\n2. \"Halo, Pina\"\n\nSilakan pilih opsi dialog(1/2): ");
    while (!validinput)    {
        //scanf("%d", &input);
        START();
        convertToArrayOfKata(&word_input, 1);
        input = StrToInt(word_input.buffer[0].TabWord);
        if ((input == 1) || (input == 2)) {
            validinput = true;
        }
        else    {
            printf("Invalid Input\n");
        }
    }
    system("cls");
    printf("Pina: \"wah, ternyata lo inget gue juga\"");START();//system("cls");
    printf("%s:	\"ya jelas dong, kita kan friend. ya kan?\"", player);START();system("cls");
    printf("Enji: \"eh, masa cuma Pina doang yang disapa, lha terus aku gimana?\"");START();system("cls");
    printf("%s: \"Hehehe, maap wwww\"", player);START();system("cls");
    printf("Kemudian guru pun datang, kita pun memulai kelas dengan perkenalan masing-masing");START();system("cls");
    printf("Pemilihan ketua kelas dimulai, aku pun maju mencalonkan diri.");START();system("cls");
    printf("namun di situ ada anak songong yang juga maju menjadi calon ketua kelas.");START();system("cls");
    printf("???: \"bisa-bisanya orang culun kaya lu maju jadi ketua kelas. malu mas\"");START();system("cls");
    printf("Aku menghela napas.");START();system("cls");
    printf("pada saat perkenalan, dia mengenalkan diri sebagai refrendt");START();system("cls");
    printf("Refrendt: \"Asal lo tau ya nerd, gue ini lebih menarik, dan juga menawan, huhuhuhu!!\"");START();system("cls");
    validinput = false;
    printf("1. \"Bisa-bisanya ni anak\"\n2. ngajak gelud\n\nSilakan pilih opsi dialog(1/2): ");
    while (!validinput)    {
        //scanf("%d", &input);
        START();
        convertToArrayOfKata(&word_input, 1);
        input = StrToInt(word_input.buffer[0].TabWord);
        if ((input != 1) && (input != 2) && (input != 9)) {
            printf("Invalid Input\n");
        }
        else    {
            validinput = true;
        }
    }
    system("cls");
    //pilihan outcome
    if (input == 1) {
        *score += 100;
        printf("Score +100\n\n");
        printf("Refrendt: \"mari kita lihat nanti, hehe\"");START();//system("cls");
        *p = LEFT(*p);
    }
    else if (input == 2){
        printf("kamu meninju dia.\n");START();//system("cls");
        printf("Refrendt: \"Apa-apaan nih lu, dasar kurang ajar\"");START();system("cls");  
        printf("Refrendt mengayunkan lengannya, pertengkaran tidak dapat dihindarkan.");START();system("cls");
        printf("akhirnya kalian berdua saling adu tonjok, dan ternyata kamu kalah dengan refrendt.");START();system("cls");
        printf("akhirnya kamu masuk UKS");START();system("cls");
        *p = RIGHT(*p);                
    }
    else if (input == 9)    {
        *p = LEFT(*p);
        *p = RIGHT(*p);
        *p = LEFT(*p);
    }
}
