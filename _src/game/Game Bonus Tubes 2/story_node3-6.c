#include "story_node3-6.h"

void node3(int *score, char* player, Address *p)
{
    char dummy;
    Sentence word_input;
    int input;
    boolean validinput;
    printf("Kamu menang batu-gunting-kertas");START();system("cls");
    printf("%s: \"Hore!!, aku menang!!\"", player);START();system("cls");
    printf("Miya: \"aahh, dahlah\"");START();system("cls");
    printf("%s: \"Janji harus ditepati, ya\"", player);START();system("cls");
    printf("Miya: \"Ya ya, Aku tahu.\"");START();system("cls");
    printf("Miya berpikir sejenak...");START();system("cls");
    printf("Miya: \"Ayo makan di Ayam Takol\"");START();system("cls");
    printf("%s: \"Baiklah, oke sampai jumpa minggu depan\"", player);START();system("cls");
    printf("Miya: \"Oke, %s. sampai jumpaaaa!!\"", player);START();system("cls");
    printf("Pada akhir pekannya...");START();system("cls");
    printf("kami akhirnya makan bersama");START();system("cls");
    printf("di tengah-tengah makan, Miya memberiku sebuah tebak-tebakan");START();system("cls");
    printf("Miya: \"betewe, aku mau kasih kamu tebak-tebakan. kalo bisa jawab ya.\"");START();system("cls");
    printf("aku cuma ngangguk-ngangguk aja");START();system("cls");
    printf("Miya: \"Oke, pertanyaannya, ini kita lagi makan nasi kan?\"");START();system("cls");
    printf("%s: \"...iya?\"", player);START();system("cls");
    printf("Miya: \"Nah tau gak kenapa kok dinamakan nasi?\"");START();system("cls");
    validinput = false;
    while (!validinput) {
        printf("Opsi Dialog:\n1. \"Enggak Tahu\"\n2. Karena...\n\n");
        START(); convertToArrayOfKata(&word_input, 1);
        input = StrToInt(word_input.buffer[0].TabWord);
        if ((input == 1) || (input == 2))   {
            validinput = true;
        }
        else    {
            printf("Invalid Input\n");
        }
    }
    system("cls");
    if (input == 2) {
        score_change(score, 80);
        printf("%s: \"Karena dina lapar, wkwkwkkw.\"", player);START();system("cls");
        printf("Miya: \"HAHAHAHAHA, betul jawabannya.\"");START();system("cls");
        printf("Miya: \"keren banget, kamu :)\"");START();system("cls");
        printf("%s: \"hahaha, makasih.\"", player);START();system("cls");
    }
    else if (input == 1)    {
        score_change(score, -50);
        printf("Miya: \"Oke, karena kamu gak tahu aku kasih tau jawabannya.\"");START();system("cls");
        printf("Miya: \"Jawabannya adalah karena dina lapar, lmaoooo\"");START();system("cls");
        printf("Aku berpikir sebentar, kemudian mengerti maksudnya.");START();system("cls");
        printf("%s: \"ealah, bisa aja kamu.\"", player);START();system("cls");
    }
    validinput = false;
    while (!validinput) {
        printf("Miya: \"Oke, sekarang ini pertanyaan berikutnya. tinggiku berapa?\"");START();
        printf("Opsi Dialog:\n1. \"150 cm\"\n2. \"152 cm\"\n3. \"154 cm\"\n4. \"156 cm\"\n5. \"158 cm\"\n\n");
        START(); convertToArrayOfKata(&word_input, 1);
        input = StrToInt(word_input.buffer[0].TabWord);
        if ((input >= 1) && (input <= 5))   {
            if (input == 2) {
                validinput = true;
            }
            else    {
                system("cls");
                score_change(score, -40);
                printf("Miya: \"tet tot, salah\"");START();system("cls");
            }
            
        }
        else    {
            printf("Invalid Input\n");
        }
    }
    printf("Miya: \"betul wkwkwkwk\"");START();system("cls");
    printf("Miya: \"Okay, next question!\"");START();system("cls");
    validinput = false;
    while (!validinput) {
        printf("Miya: \"Siapa artis favoritku?\"");START();
        printf("Opsi Dialog:\n1. BTS\n2. TREASURE\n3. YOASOBI\n4. HigeDan\n5. Eve\n6. aespa\n\n");
        START(); convertToArrayOfKata(&word_input, 1);input = StrToInt(word_input.buffer[0].TabWord);
        if ((input >= 1) && (input <= 6))   {
            if (input == 2) {
                system("cls");
                score_change(score, 200);
                printf("Miya: \"Betul, kamu tau banget aku\"");START();system("cls");
                validinput = true;
            }
            else if (input == 1)    {
                system("cls");
                score_change(score, -70);
                printf("Miya: \"Bukan. iya sih aku suka BTS, tapi bukan BTS ya favoritku wkwkkwkw\"");START();system("cls");
            }
            else    {
                system("cls");
                score_change(score, -100);
                printf("Miya: \"bukan, salah\"");START();system("cls");
            }
            
        }
        else    {
            printf("Invalid Input\n");
        }
    }
    printf("Miya: \"oke pertanyaan terakhir.\"");START();system("cls");
    validinput = false;
    while (!validinput) {
        printf("Miya: \"Kapan hari ulang tahunku?\"");START();
        printf("Opsi Dialog:\n1. \"10 April\"\n2. \"11 April\"\n3. \"12 April\"\n4. \"13 April\"\n5. \"14 April\"\n\n");
        START(); convertToArrayOfKata(&word_input, 1);input = StrToInt(word_input.buffer[0].TabWord);
        if ((input >= 1) && (input <= 6))   {
            if (input == 4) {
                system("cls");
                score_change(score, 200);
                printf("Miya: \"Betul banget.\"");START();system("cls");
                validinput = true;
            }
            else    {
                score_change(score, -60);
                printf("Miya: \"Jawabannya.......Bukan hahahaha. coba tebak lagi.\"");START();system("cls");
            }
            
        }
        else    {
            printf("Invalid Input\n");
        }
    }
    printf("setelah menjawab pertanyaan, makanan pun datang. kami akhirnya makan dengan lahap. kemudian hari berakhir.");START();system("cls");
    printf("1 bulan pun berjalan, aku mulai ikut lomba Matematika.");START();system("cls");
    printf("hari-hariku sibuk dengan belajar matematika, 2 hari lagi adalah hari-h lomba, aku tak ingin menyia-nyiakan hal tersebut.");START();system("cls");
    printf("sehabis pulang sekolah, Miya mencoba membahas sesuatu denganku, muka dia terlihat muram.");START();system("cls");
    printf("Miya: \"anu, %s. aku mau minta sesuatu.\"", player);START();system("cls");
    printf("Miya: \"maukah kita pergi ke taman bermain, bareng?\"");START();system("cls");
    printf("aku gugup, apakah ini sebuah date?!!");START();system("cls");
    printf("tapi, aku bingung. aku sebentar lagi ada lomba. aku tidak ingin menyia-nyiakan waktu belajar.");START();
    validinput = false;
    while (!validinput) {
        printf("Opsi Dialog:\n1. \"Maaf, Miya. tapi sepertinya aku sibuk besok.\"\n2. \"Baiklah, kalau itu Miya, aku gak bakal nolak.\"\n\n");
        START(); convertToArrayOfKata(&word_input, 1);
        input = StrToInt(word_input.buffer[0].TabWord);
        if ((input == 1) || (input == 2))   {
            validinput = true;
        }
        else    {
            printf("Invalid Input\n");
        }
    }
    system("cls");
    if (input == 1) {
        printf("Miya: \"Kamu sibuk? masa bener-bener sibuk? MASA KAMU GAK ADA WAKTU SIH!\"");START();system("cls");
        printf("%s: \"Maaf, Miya. aku harus belajar buat lomba. kita bisa kok main kapan-kapan.\"", player);START();system("cls");
        printf("Miya: \"UDAH TELAT!. UDAH GAK ADA WAKTU LAGI.\"");START();system("cls");
        printf("dia menangis histeris. baru pertama kali aku melihat dia menangis seperti ini.");START();system("cls");
        printf("Miya: \"MAAF, %s. aku terlalu emosional sekarang.\"", player);START();system("cls");
        printf("%s: \"gpp, Miya. aku janji bakal nemenim kamu setelah selesai lomba\"", player);START();system("cls");
        printf("Miya: \"semoga kamu bisa menepati janjimu :).\"");START();system("cls");
        *p = LEFT(*p);   
    }
    else if (input == 2){
        printf("dia menangis sambil berkata kepadaku,");START();system("cls");
        printf("Miya: \"hmmmpph terima kasih, %s. ini hadiah terbaik yang pernah diberikan kepadaku.\"", player);START();system("cls");
        printf("Miya: \"Sampai jumpa besok.\"");START();system("cls");
        *p = RIGHT(*p);
    }
    /*
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

void node4(int *score, char* player, Address *p)    {
    *p = RIGHT(*p);
}

void node5(int *score, char* player, Address *p)    {
    Sentence word_input;
    int input;
    boolean validinput;
    printf("Lusa, Aku mengikuti Lomba matematika di Osaka selama 3 hari");START();system("cls");
    printf("Aku mematikan Smartphoneku untuk 3 hari ini agar aku tetap fokus pada lomba");START();system("cls");
    printf("akhirnya lomba selesai.");START();system("cls");
    printf("hari-hari yang normal pun berjalan kembali.");START();system("cls");
    printf("namun aku jarang melihat Miya di kelas.");START();system("cls");
    printf("aku bertanya pada Miho");START();system("cls");
    printf("%s: \"Miho, kamu tau kenapa Miya sering tidak masuk?\"", player);START();system("cls");
    printf("Miho: \"Kudengar dia sakit\"");START();system("cls");
    printf("%s: \"Oh, begitu rupanya\"", player);START();system("cls");
    printf("Aku khawatir, bisa saja ia terkena penyakit yang serius.");START();system("cls");
    printf("waktu pulang sekolah tiba, aku langsung menelpon Bu Kumakawa.");START();system("cls");
    printf("(ring ring ring)");START();system("cls");
    printf("Kumakawa: Halo, %s. ada apa kok nelpon.", player);START();system("cls");
    printf("%s: \"maaf bila Saya lancang. Saya ingin tahu kondisi Miya.\"", player);START();system("cls");
    printf("Kumakawa: Coba kamu ke Rumah Sakit Tanigawa, Miya juga ingin ngomong sama kamu");START();system("cls");
    printf("%s: \"Baik bu.\"", player);START();system("cls");
    printf("Aku menutup telpon dan segera pergi ke Rumah Sakit.");START();system("cls");
    printf("Akhirnya ku tiba di rumah sakit. Aku menghampiri administrasi.");START();system("cls");
    printf("%s: \"Permisi, Ruangan pasien Atas Nama Kumakawa Miya di mana ya?\"", player);START();system("cls");
    printf("Administrator: \"di Ruangan 1063.\"");START();system("cls");
    printf("%s: \"Baik, Terima Kasih.\"", player);START();system("cls");
    printf("Aku segera pergi ke ruangan tersebut");START();system("cls");
    printf("Aku pun sampai. lalu mengetuk pintu");START();system("cls");
    printf("%s: \"Permisi\"", player);START();system("cls");
    printf("Kumakawa: \"Ya, Silakan masuk.\"");START();system("cls");
    printf("Aku pun membuka pintu.");START();system("cls");
    printf("%s: \"Selamat malam, Bu Kumakawa\"", player);START();system("cls");
    printf("Kumakawa: \"Selamat malam, %s. Gimana sekolahmu?\"", player);START();system("cls");
    printf("%s: \"Cukup baik, beberapa hari yang lalu habis ikut Lomba Matematika.\"");START();system("cls");
    printf("Kumakawa: \"%s gitu loh, tetep pinter dari dulu hahaha.\"", player);START();system("cls");
    printf("%s: \"Jadi saya mau tanya terkait Miya.\"", player);START();system("cls");
    printf("Kumakawa: \"Jadi begini.\"");START();system("cls");
    printf("Kumakawa: \"Dia sebenarnya punya penyakit Kanker.\"");START();system("cls");
    printf("Kumakawa: \"sebelumnya dia baik-baik saja, namun 2 tahun yang lalu baru terdeteksi.\"");START();system("cls");
    printf("Kumakawa: \"ia sudah menjalani terapi rutin. saat awal masuk SMA, dia sebenarnya sudah segar, namun entah kenapa kambuh lagi.\"");START();system("cls");
    printf("Kumakawa: \"dan beginilah, sekarang ia dirawat di rumah sakit.\"");START();system("cls");
    printf("%s: \"Oh begitu ya.\"", player);START();system("cls");
    printf("Miya menyapaku dari bed rumah sakit.");START();system("cls");
    printf("Miya: \"Halo %s, lombamu lancar-lancar aja kan?\"", player);START();system("cls");
    printf("%s: \"Lancar kok\"", player);START();system("cls");
    printf("%s: \"Maaf aku menolak permintaanmu kemarin, aku nggak tahu kalo kamu sakit begini\"", player);START();system("cls");
    printf("Miya: \"Enggak kok, ini salahku karena tidak pernah bilang padamu\"");START();system("cls");
    printf("Miya: \"Jadi sebentar lagi, aku akan menjalankan operasi. doakan semoga operasinya berhasil.\"");START();system("cls");
    printf("Miya: \"kalau gagal, ya mungkin saja aku sudah pergi dari dunia ini\"");START();system("cls");
    printf("%s: \"jangan bilang gitu\"", player);START();system("cls");
    printf("Miya: \"hahahaha. becanda doang kok.\"");START();system("cls");
    printf("Miya: \"aku tunggu pengumuman hasil lombamu. saat hari itu tiba, aku akan memberimu sesuatu.\"");START();system("cls");
    printf("%s: \"Oke, Miya. Aku doakan semoga operasinya lancar\"", player);START();system("cls");
    printf("Miya: \"Amin. terima kasih banyak, %s.\"", player);START();system("cls");
    printf("%s: \"Kalau gitu aku pulang dulu ya\"", player);START();system("cls");
    printf("Miya: \"Okay.\"");START();system("cls");
    printf("Miya: \"Bye Bye\"");START();system("cls");
    printf("%s: \"Saya permisi duluan, Bu Kumakawa\"", player);START();system("cls");
    printf("Kumakawa: \"Oke, sampai jumpa lagi ya\"");START();system("cls");
    printf("Seminggu kemudian...");START();system("cls");
    printf("Akhirnya hasil lomba diumumnkan.");START();system("cls");
    printf("Aku ternyata dapat juara 1.");START();system("cls");
    printf("Aku segera ke rumah sakit untuk memberi tahu Miya. Semoga saja operasinya sukses.");START();system("cls");
    printf("Aku melihat Bu Kumakawa yang menangis. aku tahu yang pasti terjadi.");START();system("cls");
    printf("Kumakawa: \"Operasinya tidak berhasil.\"");START();system("cls");
    printf("Aku pun berlinang air mata. rasa sedih menyeliputi hati ini.");START();system("cls");
    printf("setelah itu, Bu Kumakawa memberiku sebuah surat.");START();system("cls");
    printf("Kumakawa: \"Ini surat dari Miya. katanya ia akan berikan pada hari ini.\"");START();system("cls");
    printf("Aku pun membaca isi surat itu.");START();system("cls");
    CHARMACHINE("surat.txt");START();system("cls");
    printf("Aku pun larut dalam kesedihan bersama Keluarga Kumakawa.");START();system("cls");
    printf("Aku tidak sempat untuk mengungkapkan perasaanku ke Miya. aku baru sadar bahwa aku mencintai Miya saat ku membaca surat itu.");START();system("cls");
    printf("%s: \"AAAAAAAAAAAAAAAAAAAAAAAAAA\"", player);START();system("cls");
    printf("Dua hari berikutnya.");START();system("cls");
    printf("Aku mengiringi Perjalanan terakhir kali Miya menuju Nirwana.");START();system("cls");
    printf("Aku mempersembahkan medali emasku untuk Miya.");START();system("cls");
    printf("%s: \"Miya, terima kasih untuk segalanya.\"", player);START();system("cls");
    printf("%s: \"Maafkan diriku ini yang sok paling akademik.\"", player);START();system("cls");
    printf("%s: \"Kamu adalah bagian terbaik dalam hidupku\"", player);START();system("cls");
    printf("%s: \"Sayonara\"", player);START();system("cls");
    printf("Fin");START();
    *p = LEFT(*p);
}

void node6(int *score, char* player, Address *p)    {
    Sentence word_input;
    int input;
    boolean validinput;
    printf("keesokan harinya.. aku menunggu di taman bermain, hingga Miya pun datang.");START();system("cls");
    printf("Miya: \"Maaf, aku terlambat.\"");START();system("cls");
    printf("%s: \"tidak apa-apa kok, cuma dua menit doang.\"", player);START();system("cls");
    printf("Miya: \"uhh.. Kita main komedi putar dulu ya\"");START();system("cls");
    printf("aku mengangguk, lalu berjalan dengannya.");START();system("cls");
    printf("tiba-tiba dia menggenggam tanganku.");START();system("cls");
    printf("muka dia memerah.");START();system("cls");
    printf("Miya: \"uuhh, i-i-ini biar kita gak mencar aja ya!\"");START();system("cls");
    printf("aku cuma bisa mengiyakan, namun wajahnya saat itu lucu sekali, dan manis.");START();system("cls");
    printf("Kami pun bermain komedi putar bersama.");START();system("cls");
    printf("Miya: \"selanjutnya Roller Coaster\"");START();system("cls");
    printf("Kami pun bermain Roller Coaster bersama. kami berteriak ketakuan dicampur rasa bahagia.");START();system("cls");
    printf("Kami mencoba wahana satu persatu, hingga waktu telah mencapai sore. kami menutup kegiatan kami dengan menaiki gondala.");START();system("cls");
    printf("Miya: \"untuk mengakhiri dat- uhhm main-main kita, kita main gondala!\"");START();system("cls");
    printf("kami pun menaiki gondala bersama.");START();system("cls");
    printf("saat berada di dalam gondala, tiba-tiba dia berbicara sesuatu.");START();system("cls");
    printf("Miya: \"%s, aku mau ngungkapin sesuatu\"", player);START();system("cls");
    printf("Muka dia memerah, aku menelan ludah karena gugup.");START();system("cls");
    printf("%s: \"Apa, Miya-chan?\"", player);START();system("cls");
    printf("Miya: \"A-a-a-a\"");START();system("cls");
    printf("%s: \"Asu?\"", player);START();system("cls");
    printf("Miya: \"Apaan sih?\"");START();system("cls");
    printf("%s: \"maaf, bercanda.\"", player);START();system("cls");
    printf("Miya: \"Aku sebenarnya.... suka sama kamu\"");START();system("cls");
    printf("aku grogi");START();system("cls");
    printf("Miya: \"Maukah kamu menjadi pacarku?\"");START();system("cls");
    printf("aku harus menjawabnya");START();system("cls");
    validinput = false;
    while (!validinput) {
        printf("Opsi Dialog:\n1. \"Ya, Aku mau!\"\n2. \"Maaf, aku menyukai cewek lain.\"\n\n");
        START(); convertToArrayOfKata(&word_input, 1);
        input = StrToInt(word_input.buffer[0].TabWord);
        if ((input == 1) || (input == 2))   {
            validinput = true;
        }
        else    {
            printf("Invalid Input\n");
        }
    }
    if (input == 1) {
        *p = LEFT(*p);
    }
    else if (input == 2)    {
        *p = RIGHT(*p);
    }
}