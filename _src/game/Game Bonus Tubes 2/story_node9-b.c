#include "story_node9-b.h"
#include "gachapon.h"

void node9(int *score, char* player, Address *p)
{
    Sentence word_input;
    boolean validinput;
    int input;
    printf("Megumi: \"Aku kelihatan sedih ya?\"");START();system("cls");
    printf("%s: \"Aku lihat kok, kamu pas sampai ke game cafe tadi kamu habis nangis\"", player);START();system("cls");
    printf("%s: \"Kamu kalo ada masalah apa gitu, ceritain aja\"", player);START();system("cls");
    printf("Megumi: \"uuun, enggak apa-apa kok, tadi sebelum ke sini, aku nonton drakor sedih\"");START();system("cls");
    printf("(aku tahu bahwa dia sedang berbohong)");START();system("cls");
    printf("%s: \"Oke deh, kalo gitu sepertinya masih baik-baik aja\"", player);START();system("cls");
    printf("%s: \"Gimana nilai matematikamu?\"", player);START();system("cls");
    printf("Megumi: \"untungnya dapet bagus. makasih buat tutornya kemarin hehehe.\"");START();system("cls");
    printf("Megumi: \"Enaknya punya temen pinter kaya kamu\"");START();system("cls");
    printf("Megumi: \"T-Tapi bukan berarti aku cuma manfaatin kamu ya, ingat itu\"");START();system("cls");
    printf("%s: \"Iya, iya. Aku paham kok\"", player);START();system("cls");
    printf("Kita membicarakan banyak hal selama perjalanan pulang");START();system("cls");
    printf("Akhirnya tiba di rumah");START();system("cls");
    printf("Megumi: \"%s, aku duluan ya. Selamat Malam\"", player);START();system("cls");
    printf("%s: \"Selamat malam, Megumi.\"", player);START();system("cls");
    printf("Keesokannya, kita berangkat bersama ke Game center");START();system("cls");
    printf("kami pertama kali mencoba Mesin Gachapon");START();system("cls");
    printf("Megumi: \"Ayo main gacha\"");START();system("cls");
    printf("%s: \"Oke, tapi 5 koin aja ya. Kecanduan gacha tidak baik ya, Megumi.\"", player);START();system("cls");
    printf("Megumi: \"baik, baik\"");START();system("cls");
    gachapon(score);
    printf("%s: \"Mayan nih hadiahnya. dua buat aku, tiga sisanya buat kamu\"", player);START();system("cls");
    printf("Megumi: \"M-m-makasih, %s.\"", player);START();system("cls");
    printf("%s: \"Lanjut main balapan mobil.\"");START();system("cls");
    printf("Megumi: \"Gas!!\"");START();system("cls");
    printf("setelah itu..");START();system("cls");
    printf("Megumi: \"Main Dance Dance Revolution yuk\"");START();system("cls");
    printf("Aku kesusahan mengimbangi skill Megumi yang sudah jago");START();system("cls");
    printf("%s: \"Kamu terlalu jago\"", player);START();system("cls");
    printf("Megumi: \"Lho, aku baru main 3 bulan yang lalu.\"");START();system("cls");
    printf("%s: \"ya tapi aku baru main sekarang njir.\"", player);START();system("cls");
    printf("kami bermain banyak permainan, kemudian dilanjutkan dengan makan-makan.");START();system("cls");
    printf("akhirnya waktu sore pun tiba.");START();system("cls");
    printf("Megumi: \"Uwoooghh, hari ini sangat menyenangkan.\"");START();system("cls");
    printf("%s: \"Bener banget.\"", player);START();system("cls");
    printf("Megumi: \"Makasih ya buat hari ini.\"");START();system("cls");
    printf("Megumi: \"Oh ya, kamu pulang duluan enggak apa-apa. Aku ada urusan.\"");START();system("cls");
    printf("(hmmm, urusan. apa aku harus ikut juga ya...?)");START();system("cls");
    validinput = false;
    while (!validinput) {
        printf("Opsi Dialog:\n1. \"Oh yaudah kalo gitu. aku duluan ya!\"\n2. \"Emangnya urusan apa sih? Bisa gak kalau aku ikut?\"\n\n");
        START();convertToArrayOfKata(&word_input, 1);
        input = StrToInt(word_input.buffer[0].TabWord);
        if (input == 1) {
            validinput = true;
            *p = LEFT(*p);
        }
        else if (input == 2)   {
            validinput = true;
            *p = RIGHT(*p);
        }
        else    {
            system("cls");
            printf("Invalid Input\n");
        }

    }
    system("cls");
    /*
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    */
}

void nodeA(int *score, char* player, Address *p)    {
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");
    printf("");START();system("cls");  
}

void nodeB(int *score, char* player, Address *p)    {
    printf("Megumi: \"Cuma belanja-belanja doang, hahahaha\"");START();system("cls");
    printf("%s: \"Yaelah, kirain apa.\"", player);START();system("cls");
    printf("Megumi: \"Ayo sini ikut aku.\"");START();system("cls");
    printf("kita pun jalan bareng.");START();system("cls");
    printf("kemudian sesaat kita hendak menyeberang, ia mulai maju ke depan, dengan muka ceria.");START();system("cls");
    printf("Megumi: \"Jadi, aku mau ngungkapin perasaanku.\"");START();system("cls");
    printf("dengan wajah dibalut matahari sore, menyinari semyum manisnya, ia berkata kepadaku.");START();system("cls");
    printf("Megumi: \"Aku menyukaimu, maukah kamu jadi pacarku?\"");START();system("cls");
    printf("%s: \"(Really, aku ditembak??\?)\"", player);START();system("cls");
    printf("sesaat sebelum aku menjawab confession dia, aku menyadari ada truk yang melaju kencang sedang menuju ke arah Megumi berdiri.");START();system("cls");
    printf("tanpa berpikir panjang aku segera bertindak.");START();system("cls");
    printf("%s: \"MEGUMIII, AWASSSSS!!!!!\"", player);START();system("cls");
    printf("Megumi: \"Apa!\"");START();system("cls");
    printf("aku segera menarik tangan Megumi dan menarik tubuhnya ke belakang.");START();system("cls");
    printf("namun sial, justru truk itu akan segera menghantam tubuhku.");START();system("cls");
    printf("Megumi: \"%s!!!!!!!\"", player);START();system("cls");
    printf("(Brakk)");START();system("cls");
    printf("Tubuhku mati rasa.");START();system("cls");
    printf("Aku masih dapat melihat wajah Megumi.");START();system("cls");
    printf("Ia menangis di atasku.");START();system("cls");
    printf("Ahhh, aku bisa mendengar suaranya.");START();system("cls");
    printf("Megumi: \"Tolong, Ambulans. Ada orang tertabrak. cepat segera!!\"");START();system("cls");
    printf("Megumi: \"%s, %s, Tolong bertahanlah\"", player, player);START();system("cls");
    printf("lama-lama aku kehilangan kendali tubuhku");START();system("cls");
    printf("napasku makin melambat.");START();system("cls");
    printf("kesadaranku sebentar lagi akan hilang.");START();system("cls");
    printf("Megumi: \"Ya Tuhan, selamatkan %s.\"", player);START();system("cls");
    printf("sepertinya aku akan segera mati.");START();system("cls");
    printf("sebelum mati, mungkin aku ingin mengungkapkan permintaanku.");START();system("cls");
    printf("%s: \"Andai reinkarnasi itu nyata, aku ingin terlahir sebagai seorang anak petani biasa yang super kuat, tak terkalahkan, dan bisa melakukan apa saja, agar aku dapat melindungi keluargaku di dunia itu nanti, dan menikmati hari-hari damai di pedesaan.\"", player);START();system("cls");
    printf("%s: \"heh, walaupun kedengarannya konyol, tapi bisa saja harapan ini terkabulkan\"", player);START();system("cls");
    printf("%s: \"Sudah saatnya aku beristirahat dengan tenang\"", player);START();system("cls");
    printf("Kupejamkan mata terakhirku.");START();system("cls");
    printf("dua hari kemudian.");START();system("cls");
    printf("ini adalah hari pemakaman %s.", player);START();system("cls");
    printf("Aku tidak menyangka ia akan meninggalkanku duluan.");START();system("cls");
    printf("Keluargaku dan keluarganya berkumpul untuk mengirim dia ke peristirahatan terakhirnya.");START();system("cls");
    printf("Megumi: \"Semoga kamu tenang di sana ya, %s. Setidaknya aku sudah mengungkapkan perasaanku padamu.\"", player);START();system("cls");
    printf("Megumi: \"Sekarang keinginan terbesar dalam hidupku sudah terwujud\"");START();system("cls");
    printf("Megumi: \"%s, bila kamu mendengar doa ini, tolong berikan kekuatanmu padaku untuk menghadapi operasi besok.\"", player);START();system("cls");
    printf("Hari operasi pun tiba.");START();system("cls");
    printf("Aku sangat deg-degan dengan hal ini.");START();system("cls");
    printf("Bu Miyagawa: \"Berdoalah, semoga kali ini lancar ya, dan kamu bisa sembuh\"");START();system("cls");
    printf("Megumi: \"humm, baik bu\"");START();system("cls");
    printf("akhirnya aku dibawa ke ruang operasi.");START();system("cls");
    printf("dan aku mulai kehilangan kesadaranku.");START();system("cls");
    printf("tiba-tiba aku terbangun di atas sebuah awan.");START();system("cls");
    printf("cahaya sore melingkupiku.");START();system("cls");
    printf("warna itu sama seperti waktu itu.");START();system("cls");
    printf("di depan aku melihat seseorang yang sedang berdiri dari jauh.");START();system("cls");
    printf("aku pun menghapiri sosok itu.");START();system("cls");
    printf("ternyata sosok itu adalah %s.", player);START();system("cls");
    printf("%s: \"Megumi.\"", player);START();system("cls");
    printf("Megumi: \"Iya, %s?\"", player);START();system("cls");
    printf("%s: \"Mungkin tidak banyak yang akan aku ucapkan.\"", player);START();system("cls");
    printf("%s: \"Namun sebagai penutup, aku ingin memjawab pertanyaanmu saat itu.\"", player);START();system("cls");
    printf("Air mataku mengalir, aku pun mengusapnya.");START();system("cls");
    printf("%s: \"Maukah kamu jadi pacarku, ya? Jawabanku dari pertanyaanmu itu adalah: Ya!\"", player);START();system("cls");
    printf("%s: \"Aku juga menyukaimu.\"", player);START();system("cls");
    printf("%s: \"Sekarang kita sudah resmi jadi pacar ya, hahahaha.\"", player);START();system("cls");
    printf("%s: \"Tapi aku gak bisa selamanya bersamamu.\"", player);START();system("cls");
    printf("%s: \"mungkin untuk sementara waktu, aku tidak akan bisa bersamamu.\"", player);START();system("cls");
    printf("%s: \"Tapi aku yakin suatu saat, kita akan bertemu kembali, di dunia yang berbeda\"", player);START();system("cls");
    printf("%s: \"Berjuanglah, tetaplah hidup. Aku tahu hidupmu berat dengan penyakitmu itu.\"", player);START();system("cls");
    printf("%s: \"Sekarang, bangunlah! dan wujudkan impianmu, dan mungkin juga impianku\"", player);START();system("cls");
    printf("%s: \"Terima kasih banyak, Megumi. Sampai jumpa di lain waktu\"", player);START();system("cls");
    printf("Bayangannya pun menghilang");START();system("cls");
    printf("Aku pun Menangis tersedu-sedu");START();system("cls");
    printf("Meratapi kepergiannya");START();system("cls");
    printf("Tiba-tiba terdengar suara.");START();system("cls");
    printf("???: \"Megumi-chan, apakah kamu bisa dengar suaraku?\"");START();system("cls");
    printf("Aku pun langsung membuka mataku.");START();system("cls");
    printf("Pak Miyagawa: \"Syukurlah kamu selamat.\"");START();system("cls");
    printf("Megumi: \"Apa yang terjadi?\"");START();system("cls");
    printf("Bu Miyagawa: \"Operasinya lancar, Megu-chan!\"");START();system("cls");
    printf("Aku pun menangis terharu, bahagia mendengarnya.");START();system("cls");
    printf("ternyata aku masih diberi kesempatan hidup.");START();system("cls");
    printf("Terima kasih, Tuhan. dan terima kasih juga, %s.", player);START();system("cls");
    printf("Aku tidak akan pernah melupakanmu.");START();system("cls");
    printf("..........");START();system("cls");
    printf("tiba-tiba aku merasakan hawa dingin di sekitarku.");START();system("cls");
    printf("saat ku membuka mataku, aku melihat bahwa diriku berada di kedalaman yang gelap.");START();system("cls");
    printf("Aku melihat sekilas cahaya tampak yang kecil.");START();system("cls");
    printf("%s: \"Aku di mana?\"", player);START();system("cls");
    printf("Tiba-tiba aku mendengar suara yang menggema");START();system("cls");
    printf("???: \"Wahai Makhluk yang fana, balaslah seruan ini!!\"");START();system("cls");
    printf("%s: \"Siapa itu?\"", player);START();system("cls");
    printf("???: \"Kau tidak perlu tahu siapa aku, namun aku akan memberimu suatu misi penting\"");START();system("cls");
    printf("%s: \"Apaan tuh kira-kira?\"", player);START();system("cls");
    printf("???: \"Tolong selamatkan Semesta Hebiora dari kehancuran. kamu adalah orang terpilih yang akan menjadi pahlawan untuk menyelamatkannya\"");START();system("cls");
    printf("(wait, apakah ini tandanya aku Ter-isekai?)");START();system("cls");
    printf("%s: \"Wait, What??\"", player);START();system("cls");
    printf("%s: \"ISEKAIIIIIIIII, ISEKAI IS REALLLLLLLLLLL!!!!\"", player);START();
    printf("Ende\n");
    *p = RIGHT(*p);
}