#include "story_node3-6.h"

void node3(int *score, char* player, Address *p)
{
    char dummy;
    Sentence word_input;
    int input;
    boolean validinput;
    printf("Kamu menang batu-gunting-kertas");START();system("cls");
    printf("%s: \"Hore!!, aku menang!!\"", player);START();system("cls");
    printf("Megumi: \"aahh, dahlah\"");START();system("cls");
    printf("%s: \"Janji harus ditepati, ya\"", player);START();system("cls");
    printf("Megumi: \"Ya ya, Aku tahu.\"");START();system("cls");
    printf("Megumi berpikir sejenak...");START();system("cls");
    printf("Megumi: \"Ayo makan di Ayam Takol\"");START();system("cls");
    printf("%s: \"Baiklah, oke sampai jumpa minggu depan\"", player);START();system("cls");
    printf("Megumi: \"Oke, %s. sampai jumpaaaa!!\"", player);START();system("cls");
    printf("Pada akhir pekannya...");START();system("cls");
    printf("kami akhirnya makan bersama");START();system("cls");
    printf("di tengah-tengah makan, Megumi memberiku sebuah tebak-tebakan");START();system("cls");
    printf("Megumi: \"betewe, aku mau kasih kamu tebak-tebakan. kalo bisa jawab ya.\"");START();system("cls");
    printf("aku cuma ngangguk-ngangguk aja");START();system("cls");
    printf("Megumi: \"Oke, pertanyaannya, ini kita lagi makan nasi kan?\"");START();system("cls");
    printf("%s: \"...iya?\"", player);START();system("cls");
    printf("Megumi: \"Nah tau gak kenapa kok dinamakan nasi?\"");START();system("cls");
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
        printf("Megumi: \"HAHAHAHAHA, betul jawabannya.\"");START();system("cls");
        printf("Megumi: \"keren banget, kamu :)\"");START();system("cls");
        printf("%s: \"hahaha, makasih.\"", player);START();system("cls");
    }
    else if (input == 1)    {
        score_change(score, -50);
        printf("Megumi: \"Oke, karena kamu gak tahu aku kasih tau jawabannya.\"");START();system("cls");
        printf("Megumi: \"Jawabannya adalah karena dina lapar, lmaoooo\"");START();system("cls");
        printf("Aku berpikir sebentar, kemudian mengerti maksudnya.");START();system("cls");
        printf("%s: \"ealah, bisa aja kamu.\"", player);START();system("cls");
    }
    validinput = false;
    while (!validinput) {
        printf("Megumi: \"Oke, sekarang ini pertanyaan berikutnya. tinggiku berapa?\"");START();
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
                printf("Megumi: \"tet tot, salah\"");START();system("cls");
            }
            
        }
        else    {
            printf("Invalid Input\n");
        }
    }
    printf("Megumi: \"betul wkwkwkwk\"");START();system("cls");
    printf("Megumi: \"Okay, next question!\"");START();system("cls");
    validinput = false;
    while (!validinput) {
        printf("Megumi: \"Siapa artis favoritku?\"");START();
        printf("Opsi Dialog:\n1. BTS\n2. TREASURE\n3. YOASOBI\n4. HigeDan\n5. Eve\n6. aespa\n\n");
        START(); convertToArrayOfKata(&word_input, 1);input = StrToInt(word_input.buffer[0].TabWord);
        if ((input >= 1) && (input <= 6))   {
            if (input == 2) {
                system("cls");
                score_change(score, 200);
                printf("Megumi: \"Betul, kamu tau banget aku\"");START();system("cls");
                validinput = true;
            }
            else if (input == 1)    {
                system("cls");
                score_change(score, -70);
                printf("Megumi: \"Bukan. iya sih aku suka BTS, tapi bukan BTS ya favoritku wkwkkwkw\"");START();system("cls");
            }
            else    {
                system("cls");
                score_change(score, -100);
                printf("Megumi: \"bukan, salah\"");START();system("cls");
            }
            
        }
        else    {
            printf("Invalid Input\n");
        }
    }
    printf("Megumi: \"oke pertanyaan terakhir.\"");START();system("cls");
    validinput = false;
    while (!validinput) {
        printf("Megumi: \"Kapan hari ulang tahunku?\"");START();
        printf("Opsi Dialog:\n1. \"10 April\"\n2. \"11 April\"\n3. \"12 April\"\n4. \"13 April\"\n5. \"14 April\"\n\n");
        START(); convertToArrayOfKata(&word_input, 1);input = StrToInt(word_input.buffer[0].TabWord);
        if ((input >= 1) && (input <= 6))   {
            if (input == 4) {
                system("cls");
                score_change(score, 200);
                printf("Megumi: \"Betul banget.\"");START();system("cls");
                validinput = true;
            }
            else    {
                score_change(score, -60);
                printf("Megumi: \"Jawabannya.......Bukan hahahaha. coba tebak lagi.\"");START();system("cls");
            }
            
        }
        else    {
            printf("Invalid Input\n");
        }
    }
    printf("setelah menjawab pertanyaan, makanan pun datang. kami akhirnya makan dengan lahap. kemudian hari berakhir.");START();system("cls");
    printf("1 bulan pun berjalan, aku mulai ikut lomba Matematika.");START();system("cls");
    printf("hari-hariku sibuk dengan belajar matematika, 2 hari lagi adalah hari-h lomba, aku tak ingin menyia-nyiakan hal tersebut.");START();system("cls");
    printf("sehabis pulang sekolah, Megumi mencoba membahas sesuatu denganku, muka dia terlihat muram.");START();system("cls");
    printf("Megumi: \"anu, %s. aku mau minta sesuatu.\"", player);START();system("cls");
    printf("Megumi: \"maukah kita pergi ke taman bermain, bareng?\"");START();system("cls");
    printf("aku gugup, apakah ini sebuah date?!!");START();system("cls");
    printf("tapi, aku bingung. aku sebentar lagi ada lomba. aku tidak ingin menyia-nyiakan waktu belajar.");START();
    validinput = false;
    while (!validinput) {
        printf("Opsi Dialog:\n1. \"Maaf, Megumi. tapi sepertinya aku sibuk besok.\"\n2. \"Baiklah, kalau itu Megumi, aku gak bakal nolak.\"\n\n");
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
        printf("Megumi: \"Kamu sibuk? masa bener-bener sibuk? MASA KAMU GAK ADA WAKTU SIH!\"");START();system("cls");
        printf("%s: \"Maaf, Megumi. aku harus belajar buat lomba. kita bisa kok main kapan-kapan.\"", player);START();system("cls");
        printf("Megumi: \"UDAH TELAT!. UDAH GAK ADA WAKTU LAGI.\"");START();system("cls");
        printf("dia menangis histeris. baru pertama kali aku melihat dia menangis seperti ini.");START();system("cls");
        printf("Megumi: \"MAAF, %s. aku terlalu emosional sekarang.\"", player);START();system("cls");
        printf("%s: \"gpp, Megumi. aku janji bakal nemenim kamu setelah selesai lomba\"", player);START();system("cls");
        printf("Megumi: \"semoga kamu bisa menepati janjimu :).\"");START();system("cls");
        *p = LEFT(*p);   
    }
    else if (input == 2){
        printf("dia menangis sambil berkata kepadaku,");START();system("cls");
        printf("Megumi: \"hmmmpph terima kasih, %s. ini hadiah terbaik yang pernah diberikan kepadaku.\"", player);START();system("cls");
        printf("Megumi: \"Sampai jumpa besok.\"");START();system("cls");
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
    Sentence word_input;
    int input;
    boolean validinput;
    printf("Megumi: \"Yeyy, aku menang\"");START();system("cls");
    printf("%s: \"Asem tenan ik\"", player);START();system("cls");
    printf("Megumi: \"Sesuai janji, kamu yang nentuin tempatnya ya\"");START();system("cls");
    printf("%s: \"OK\"", player);START();system("cls");
    validinput = false;
    while (!validinput) {
        printf("Opsi Dialog:\n1. \"Aku mau ke Game Cafe\"\n\n");
        START(); convertToArrayOfKata(&word_input, 1);
        input = StrToInt(word_input.buffer[0].TabWord);
        if (input == 1)   {
            validinput = true;
        }
        else    {
            printf("Invalid Input\n");
        }
    }
    printf("Megumi: \"Wahh, boleh juga tuh\"");START();system("cls");
    printf("%s: \"next week, ya!\"", player);START();system("cls");
    printf("Megumi: \"Okie Dokie\"");START();system("cls");
    printf("aku pulang jam 7 malam, karena menyiapkan lombaku.");START();system("cls");
    printf("saat pulang, aku melihat Bu Miyagawa yang tampak sedih, aku pun sempatkan tuk menghapiri beliau.");START();system("cls");
    printf("%s: \"Selamat malam, Bu Miyagawa.\"", player);START();system("cls");
    printf("Bu Miyagawa: \"Ara, ada %s-chan rupanya.\"", player);START();system("cls");
    printf("%s: \"Bagaimana kabar Ibu?\"", player);START();system("cls");
    printf("Bu Miyagawa: \"Baik, cuma capek sedikit karena pekerjaan.\"");START();system("cls");
    printf("%s: \"Mengapa wajah ibu sangat sedih?\"", player);START();system("cls");
    printf("Bu Miyagawa: \"Mungkin bakal ibu ceritain di taman saja. ayo ke sana.\"");START();system("cls");
    printf("Aku pun mengikuti Bu Miyagawa sampai ke taman, lalu beliau mulai bercerita.");START();system("cls");
    printf("Bu Miyagawa: \"Jadi begini, 1 minggu lagi Megumi-chan akan menjalankan perawatan untuk penyakitnya, namun bisa saja ini akan menyebabkan Megumi meninggal dunia.\"");START();system("cls");
    printf("%s: \"Ngomong-ngomong, dia sakit apa?\"", player);START();system("cls");
    printf("Bu Miyagawa: \"Ia punya kanker. 1 minggu lagi akan dilaksanakan kemoterapi kembali, semoga operasi nanti bisa berhasil, dan dia bisa hidup sehat.\"");START();system("cls");
    printf("%s: \"Amin, semoga hal itu terwujud.\"", player);START();system("cls");
    printf("Bu Miyagawa: \"Terima kasih nak, oh benar juga, mau ikut makan malam dengan kami?\"");START();system("cls");
    printf("Aku enggak enak menolak");START();system("cls");
    printf("%s: \"Oke bu, saya terima. Terima kasih banyak, Bu Miyagawa.\"", player);START();system("cls");
    printf("Akhirnya aku pergi ke rumah Keluarga Miyagawa bersama Ibunya Megumi.");START();system("cls");
    printf("Sesampainya di rumah tersebut. Megumi dan Pak Miyagawa sudah menyambutku.");START();system("cls");
    printf("Pak Miyagawa: \"Oi, %s rupanya, ayo silakan makan!\"", player);START();system("cls");
    printf("Megumi: \"Wah, %s. gak nyangka kamu bakal mampir ke sini.\"");START();system("cls");
    printf("%s: \"Hehehe, tadi enggak sengaja ketemu sama Ibu pas di jalan, sekalian diajak ke sini.\"", player);START();system("cls");
    printf("Bu Miyagawa: \"Hihihihi. ya sudah, silakan ambil makanan.\"");START();system("cls");
    printf("%s: \"Terima kasih banyak semuanya, maaf apabila merepotkan.\"", player);START();system("cls");
    printf("Semuanya: \"Selamat Makan!!\"");START();system("cls");
    printf("Setelah selesai makan, Tiba-tiba Megumi mengajakku ke atap rumahnya.");START();system("cls");
    printf("Megumi: \"%s, ikut aku ke atap yuk\"", player);START();system("cls");
    printf("%s: \"Mau ngapain?\"", player);START();system("cls");
    printf("Megumi: \"Ya ngobrol-ngobrol santai, hehe.\"");START();system("cls");
    printf("%s: \"OK lah, aku turutin\"", player);START();system("cls");
    printf("kami berdua pun duduk bersebelahan, sambil menatap langit malam.");START();system("cls");
    printf("Megumi: \"Andai saja tidak ada polusi cahaya, kita udah pasti bisa lihat bintang-bintang indah dari sini\"");START();system("cls");
    printf("%s: \"Ya gimana lagi, lampu udah jadi bagian dari kehidupan kita\"", player);START();system("cls");
    printf("Megumi: \"Sebenarnya ada upaya lho buat ngurangin itu. misalnya tidak memakai lampu yang merambat ke arah langit\"");START();system("cls");
    printf("%s: \" oh begitu ternyata, dapet ilmu baru dari Megumi nih wkwkwkwk\"", player);START();system("cls");
    printf("Megumi: \"imba jangan merendah dong. justru aku butuh ilmu Matematika dari kamu nih. Nilai matematikaku akhir-akhir ini menurutku kurang memuaskan.\"");START();system("cls");
    printf("%s: \"Ya kalo kamu pingin belajar bareng aku, tinggal bilang aja sih.\"", player);START();system("cls");
    printf("Megumi: \"Oke deh.\"");START();system("cls");
    printf("%s: \"Anyway, kamu suka bintang ya?\"", player);START();system("cls");
    printf("Megumi: \"Ya, aku suka bintang. dari kecil aku udah tertarik sama hal berbau langit dan astronomi.\"");START();system("cls");
    printf("%s: \"ohh, begitu rupanya. ngomongin soal Bintang. aku suka rasi bintang Virgo. ya karena zodiakku Virgo sih hahaha.\"", player);START();system("cls");
    printf("Megumi: \"Kalau aku suka banyak rasi bintang. Ursa Mayor, Ursa Minor, Orion, Centaur, Pegasus, Aries, Taurus, Gemini, dan masih banyak lagi.\"");START();system("cls");
    printf("%s: \"Ampun suhu.\"", player);START();system("cls");
    printf("Kita terus mengobrol banyak hal hingga larut malam, dan akhirnya aku pulang ke rumah");START();system("cls");
    printf("seminggu kemudian...");START();system("cls");
    printf("%s: \"Kita mau main apa nih?\"", player);START();system("cls");
    printf("Megumi: \"Kita Main UNO yuk\"");START();system("cls");
    printf("kita pun bermain UNO");START();system("cls");
    printf("Megumi: \"Next kita main Ludo\"");START();system("cls");
    printf("setelah selesai main ludo...");START();system("cls");
    printf("Megumi: \"Ayo habis ini main kartu!\"");START();system("cls");
    printf("kami pun main games-games yang lain.");START();system("cls");
    printf("%s: \"ajak Enji, Pina, Hanrey, dan Dariah juga dong. biar seru\"", player);START();system("cls");
    printf("Megumi: \"Oke\"");START();system("cls");
    printf("kita menghabiskan waktu menyenangkan. kita juga mengajak Enji, Pina, Hanrey, dan Dariah untuk ikut main juga.");START();system("cls");
    printf("setelah bermain sampai malam, Enji, Pina, Hanrey, dan Dariah memutuskan untuk meninggalkan kami berdua.");START();system("cls");
    printf("Pina: \"Eh, kita pulang duluan ya. udah malam hahaha\"");START();system("cls");
    printf("Megumi: \"Oke, gak papa\"");START();system("cls");
    printf("Hanrey: \"kita duluan ya\"");START();system("cls");
    printf("Radiah: \"Hati-hati ya kalian\"");START();system("cls");
    printf("%s: \"Oke, kalian juga hati-hati di jalan ya\"", player);START();system("cls");
    printf("Enji: \"Bye, guys\"");START();system("cls");
    printf("%s, Megumi: \"Byee\"", player);START();system("cls");
    printf("%s: \"Eh Megumi, aku punya permintaan nih.\"", player);START();system("cls");
    printf("Megumi: \"Apa, %s?\"", player);START();system("cls");
    printf("%s: \"Minggu depan mau aku ajak pergi ke game center. mau?\"");START();system("cls");
    printf("Megumi: \"Haah?\"");START();system("cls");
    printf("Megumi: \"(Aku gak nyangka kalo bakal %s yang ngajak date. aku seneng banget)\"", player);START();system("cls");
    printf("Megumi: \"A-a-a-aku mau kok.\"");START();system("cls");
    printf("%s: \"Oke, berarti udah diputusin ya.\"", player);START();system("cls");
    printf("%s: \"Gimana kalo kita pulang bareng?\"", player);START();system("cls");
    printf("Megumi: \"B-b-baik\"");START();system("cls");
    printf("Akhirnya kita berdua pulang bersama.");START();system("cls");
    printf("Megumi: \"Eh, aku mau tanya sesuatu.\"");START();system("cls");
    printf("%s: \"Ada apa, Megumi?\"", player);START();system("cls");
    printf("Megumi: \"Kenapa hari ini kamu beda banget sama biasanya?\"");START();system("cls");
    printf("%s: \"Beda Gimana maksudnya?\"", player);START();system("cls");
    printf("Megumi: \"Kamu biasanya lebih kalem, tapi entah kenapa kamu kok perhatian banget hari-hari ini\"");START();system("cls");
    printf("Megumi: \"Emangnya ada sesuatu?\"");START();system("cls");
    printf("%s: \"Enggak ada sih, aku emang orangnya begini.\"", player);START();system("cls");
    printf("Megumi: \"Yakin cuma gitu doang? aku gak percaya. kamu orangnya cenderung cuek begitu. kok bisa-bisanya berubah. apa maksudmu?\"");START();system("cls");
    validinput = false;
    while (!validinput) {
        printf("Opsi Dialog:\n1. \"Soalnya aku lihat wajahmu sedih akhir-akhir ini\"\n2. \"Udah dibilangin, aku ngelakuin karena aku baik sama semua orang\"\n\n");
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
    else if (input == 2)
    {
        printf("Megumi: \"Bohong kamu.\"");START();system("cls");
        printf("%s: \"Apa maksudmu?\"", player);START();system("cls");
        printf("Megumi: \"Pokoknya aku kesel sama kamu\"");START();system("cls");
        printf("Megumi: \"dah, jangan deket-deket aku\"");START();system("cls");
        printf("Megumi: \"Gak usah sok baik kamu\"");START();system("cls");
        printf("dia berlari");START();system("cls");
        printf("%s: \"Megumi, oi Megumi\"", player);START();system("cls");
        printf("ia pun lari meninggalkanku, seperti dia marah kepadaku.");START();system("cls");
        *p = RIGHT(*p);
    }
}

void node5(int *score, char* player, Address *p)    {
    Sentence word_input;
    int input;
    boolean validinput;
    printf("Lusa, Aku mengikuti Lomba matematika di Osaka selama 3 hari");START();system("cls");
    printf("Aku mematikan Smartphoneku untuk 3 hari ini agar aku tetap fokus pada lomba");START();system("cls");
    printf("akhirnya lomba selesai.");START();system("cls");
    printf("hari-hari yang normal pun berjalan kembali.");START();system("cls");
    printf("namun aku jarang melihat Megumi di kelas.");START();system("cls");
    printf("aku bertanya pada Miho");START();system("cls");
    printf("%s: \"Miho, kamu tau kenapa Megumi sering tidak masuk?\"", player);START();system("cls");
    printf("Miho: \"Kudengar dia sakit\"");START();system("cls");
    printf("%s: \"Oh, begitu rupanya\"", player);START();system("cls");
    printf("Aku khawatir, bisa saja ia terkena penyakit yang serius.");START();system("cls");
    printf("waktu pulang sekolah tiba, aku langsung menelpon Bu Miyagawa.");START();system("cls");
    printf("(ring ring ring)");START();system("cls");
    printf("Miyagawa: Halo, %s. ada apa kok nelpon.", player);START();system("cls");
    printf("%s: \"maaf bila Saya lancang. Saya ingin tahu kondisi Megumi.\"", player);START();system("cls");
    printf("Miyagawa: Coba kamu ke Rumah Sakit Tanigawa, Megumi juga ingin ngomong sama kamu");START();system("cls");
    printf("%s: \"Baik bu.\"", player);START();system("cls");
    printf("Aku menutup telpon dan segera pergi ke Rumah Sakit.");START();system("cls");
    printf("Akhirnya ku tiba di rumah sakit. Aku menghampiri administrasi.");START();system("cls");
    printf("%s: \"Permisi, Ruangan pasien Atas Nama Miyagawa Megumi di mana ya?\"", player);START();system("cls");
    printf("Administrator: \"di Ruangan 1063.\"");START();system("cls");
    printf("%s: \"Baik, Terima Kasih.\"", player);START();system("cls");
    printf("Aku segera pergi ke ruangan tersebut");START();system("cls");
    printf("Aku pun sampai. lalu mengetuk pintu");START();system("cls");
    printf("%s: \"Permisi\"", player);START();system("cls");
    printf("Miyagawa: \"Ya, Silakan masuk.\"");START();system("cls");
    printf("Aku pun membuka pintu.");START();system("cls");
    printf("%s: \"Selamat malam, Bu Miyagawa\"", player);START();system("cls");
    printf("Miyagawa: \"Selamat malam, %s. Gimana sekolahmu?\"", player);START();system("cls");
    printf("%s: \"Cukup baik, beberapa hari yang lalu habis ikut Lomba Matematika.\"");START();system("cls");
    printf("Miyagawa: \"%s gitu loh, tetep pinter dari dulu hahaha.\"", player);START();system("cls");
    printf("%s: \"Jadi saya mau tanya terkait Megumi.\"", player);START();system("cls");
    printf("Miyagawa: \"Jadi begini.\"");START();system("cls");
    printf("Miyagawa: \"Dia sebenarnya punya penyakit Kanker.\"");START();system("cls");
    printf("Miyagawa: \"sebelumnya dia baik-baik saja, namun 2 tahun yang lalu baru terdeteksi.\"");START();system("cls");
    printf("Miyagawa: \"ia sudah menjalani terapi rutin. saat awal masuk SMA, dia sebenarnya sudah segar, namun entah kenapa kambuh lagi.\"");START();system("cls");
    printf("Miyagawa: \"dan beginilah, sekarang ia dirawat di rumah sakit.\"");START();system("cls");
    printf("%s: \"Oh begitu ya.\"", player);START();system("cls");
    printf("Megumi menyapaku dari bed rumah sakit.");START();system("cls");
    printf("Megumi: \"Halo %s, lombamu lancar-lancar aja kan?\"", player);START();system("cls");
    printf("%s: \"Lancar kok\"", player);START();system("cls");
    printf("%s: \"Maaf aku menolak permintaanmu kemarin, aku nggak tahu kalo kamu sakit begini\"", player);START();system("cls");
    printf("Megumi: \"Enggak kok, ini salahku karena tidak pernah bilang padamu\"");START();system("cls");
    printf("Megumi: \"Jadi sebentar lagi, aku akan menjalankan operasi. doakan semoga operasinya berhasil.\"");START();system("cls");
    printf("Megumi: \"kalau gagal, ya mungkin saja aku sudah pergi dari dunia ini\"");START();system("cls");
    printf("%s: \"jangan bilang gitu\"", player);START();system("cls");
    printf("Megumi: \"hahahaha. becanda doang kok.\"");START();system("cls");
    printf("Megumi: \"aku tunggu pengumuman hasil lombamu. saat hari itu tiba, aku akan memberimu sesuatu.\"");START();system("cls");
    printf("%s: \"Oke, Megumi. Aku doakan semoga operasinya lancar\"", player);START();system("cls");
    printf("Megumi: \"Amin. terima kasih banyak, %s.\"", player);START();system("cls");
    printf("%s: \"Kalau gitu aku pulang dulu ya\"", player);START();system("cls");
    printf("Megumi: \"Okay.\"");START();system("cls");
    printf("Megumi: \"Bye Bye\"");START();system("cls");
    printf("%s: \"Saya permisi duluan, Bu Miyagawa\"", player);START();system("cls");
    printf("Miyagawa: \"Oke, sampai jumpa lagi ya\"");START();system("cls");
    printf("Seminggu kemudian...");START();system("cls");
    printf("Akhirnya hasil lomba diumumnkan.");START();system("cls");
    printf("Aku ternyata dapat juara 1.");START();system("cls");
    printf("Aku segera ke rumah sakit untuk memberi tahu Megumi. Semoga saja operasinya sukses.");START();system("cls");
    printf("Aku melihat Bu Miyagawa yang menangis. aku tahu yang pasti terjadi.");START();system("cls");
    printf("Miyagawa: \"Operasinya tidak berhasil.\"");START();system("cls");
    printf("Aku pun berlinang air mata. rasa sedih menyeliputi hati ini.");START();system("cls");
    printf("setelah itu, Bu Miyagawa memberiku sebuah surat.");START();system("cls");
    printf("Miyagawa: \"Ini surat dari Megumi. katanya ia akan berikan pada hari ini.\"");START();system("cls");
    printf("Aku pun membaca isi surat itu.");START();system("cls");
    //CHARMACHINE("surat.txt");START();system("cls");
    printf("Aku pun larut dalam kesedihan bersama Keluarga Miyagawa.");START();system("cls");
    printf("Aku tidak sempat untuk mengungkapkan perasaanku ke Megumi. aku baru sadar bahwa aku mencintai Megumi saat ku membaca surat itu.");START();system("cls");
    printf("%s: \"AAAAAAAAAAAAAAAAAAAAAAAAAA\"", player);START();system("cls");
    printf("Dua hari berikutnya.");START();system("cls");
    printf("Aku mengiringi Perjalanan terakhir kali Megumi menuju Nirwana.");START();system("cls");
    printf("Aku mempersembahkan medali emasku untuk Megumi.");START();system("cls");
    printf("%s: \"Megumi, terima kasih untuk segalanya.\"", player);START();system("cls");
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
    printf("keesokan harinya.. aku menunggu di taman bermain, hingga Megumi pun datang.");START();system("cls");
    printf("Megumi: \"Maaf, aku terlambat.\"");START();system("cls");
    printf("%s: \"tidak apa-apa kok, cuma dua menit doang.\"", player);START();system("cls");
    printf("Megumi: \"uhh.. Kita main komedi putar dulu ya\"");START();system("cls");
    printf("aku mengangguk, lalu berjalan dengannya.");START();system("cls");
    printf("tiba-tiba dia menggenggam tanganku.");START();system("cls");
    printf("muka dia memerah.");START();system("cls");
    printf("Megumi: \"uuhh, i-i-ini biar kita gak mencar aja ya!\"");START();system("cls");
    printf("aku cuma bisa mengiyakan, namun wajahnya saat itu lucu sekali, dan manis.");START();system("cls");
    printf("Kami pun bermain komedi putar bersama.");START();system("cls");
    printf("Megumi: \"selanjutnya Roller Coaster\"");START();system("cls");
    printf("Kami pun bermain Roller Coaster bersama. kami berteriak ketakuan dicampur rasa bahagia.");START();system("cls");
    printf("Kami mencoba wahana satu persatu, hingga waktu telah mencapai sore. kami menutup kegiatan kami dengan menaiki gondala.");START();system("cls");
    printf("Megumi: \"untuk mengakhiri dat- uhhm main-main kita, kita main gondala!\"");START();system("cls");
    printf("kami pun menaiki gondala bersama.");START();system("cls");
    printf("saat berada di dalam gondala, tiba-tiba dia berbicara sesuatu.");START();system("cls");
    printf("Megumi: \"%s, aku mau ngungkapin sesuatu\"", player);START();system("cls");
    printf("Muka dia memerah, aku menelan ludah karena gugup.");START();system("cls");
    printf("%s: \"Apa, Megumi-chan?\"", player);START();system("cls");
    printf("Megumi: \"A-a-a-a\"");START();system("cls");
    printf("%s: \"Asu?\"", player);START();system("cls");
    printf("Megumi: \"Apaan sih?\"");START();system("cls");
    printf("%s: \"maaf, bercanda.\"", player);START();system("cls");
    printf("Megumi: \"Aku sebenarnya.... suka sama kamu\"");START();system("cls");
    printf("aku grogi");START();system("cls");
    printf("Megumi: \"Maukah kamu menjadi pacarku?\"");START();system("cls");
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