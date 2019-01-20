#include <iostream>
#include <openssl/conf.h> // функции, структуры и константы настройки OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // сами криптогрфические функции https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // коды внутренних ошибок OpenSSL и их расшифровка
#include <openssl/aes.h>
#include <fstream>
#include <string>
#include <string.h>

#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")

// библиотеки OpenSSL (openssl.org) подключаются неявно динамически (см. конспект лаб. по библиотекам)

using namespace std;

int main()
{
	// работа с криптофункциями OpenSSL:
	// 1) создание объекта с настройками
	// 2) собственно, шифрование
	// 3) финализация
	// 4) и вывод зашифрованных данных

	// как правило, в литературе, структуры используются для хранения только данных
	// ни слова о методах и конструкторах/деструкторах
	struct name_of_my_struct // сродни классу
	{
		name_of_my_struct()
		{

		}

		int a;
		double b;
		int fnc1()
		{
			return a;
		}
	};
	string s;
	std::ifstream fp("in.txt", ios::binary|ios::in);
	std::ofstream fout("out.txt", ios::binary | ios::out);
	char nil = '\0';
	getline(fp, s, nil);
	fp.close();
	unsigned char *plaintext;// исходный текст
	int plaintext_len ; // длина текста
	unsigned char *key = (unsigned char *)"0123456789"; // пароль (ключ)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // инициализирующий вектор, рандомайзер
	unsigned char cryptedtext[256]; // зашифрованный результат
	unsigned char decryptedtext[256]; // расшифрованный результат

	// 1. Создаётся указатель на несуществующую структуру
	// структура - тип данных в C++, близка к КЛАССУ, различия минимальны
	EVP_CIPHER_CTX *ctx; // structure

	// 2. Для указателя создаётся пустая структура настроек (метод, ключ, вектор инициализации и т.д.)
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

	// 3. Структура EVP_CIPHER_CTX заполняется настройками
	EVP_EncryptInit_ex(ctx, // ссылка на объект/структуру, куда заносятся параметры
		EVP_aes_256_cbc(), // ссылка на шифрующее ядро AES 256 (функцию с алгоритмом)
		NULL,
		key, // ключ/пароль/секрет
		iv); // рандомайзер (случайный начальный вектор)

	// 4. САМ ПРОЦЕСС ШИФРОВАНИЯ - ФУКНЦИЯ EVP_EncryptUpdate
	int len;
	int cryptedtext_len;
	int cursor=0;
	//fout << s.substr(cursor, 32);
	//fout.close();
	while (cursor < s.length())
	{
		if (!(s.length() - cursor < 32))
		{
			char tab2[32];
			for (int i = 0; i < 32; i++)
			{
				tab2[i] = s[cursor + i];
			}
			unsigned char *plaintext = (unsigned char *)tab2;// исходный текст
			int plaintext_len = 32;

			EVP_EncryptUpdate(ctx, // объект с настройками
				cryptedtext, // входной параметр: ссылка, куда помещать зашифрованные данные
				&len, // выходной параметр: длина полученного шифра
				plaintext, // входной параметр: что шифровать
				plaintext_len); // входной параметр : длина входных данных
			cryptedtext_len = 32;

			for (int i = 0; i < cryptedtext_len; i++)
			{
				fout << hex << cryptedtext[i];
			}
			cursor += 32;
		}
		else
		{
			char tab2[32];
			int i;
			for ( i = 0; i < s.length()- cursor - 1; i++)
			{
				tab2[i]= s[cursor + i];
				
			}
			unsigned char *plaintext = (unsigned char *)tab2;// исходный текст
			int plaintext_len = (s.length() - cursor - 1);
			EVP_EncryptUpdate(ctx, // объект с настройками
				cryptedtext, // входной параметр: ссылка, куда помещать зашифрованные данные
				&len, // выходной параметр: длина полученного шифра
				plaintext, // входной параметр: что шифровать
				plaintext_len); // входной параметр : длина входных данных
			cryptedtext_len = (s.length() - cursor - 1);
			EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
			for (i = 0; i < (s.length() - cursor - 1); i++)
			{
				fout << hex << cryptedtext[i];

			}
			cursor += 32;
		}
	
		
	}
	/*EVP_EncryptUpdate(ctx, // объект с настройками
		cryptedtext, // входной параметр: ссылка, куда помещать зашифрованные данные
		&len, // выходной параметр: длина полученного шифра
		plaintext, // входной параметр: что шифровать
		plaintext_len); // входной параметр : длина входных данных
	cryptedtext_len = len;*/
	fout.close();
	// 6. Удаление структуры
	EVP_CIPHER_CTX_free(ctx);
	std::ifstream fps("out.txt", ios::binary | ios::in);
	std::ofstream fps_2("out_decript.txt", ios::binary | ios::out);
	getline(fps, s, nil);
	fps.close();
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

	// 2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // инициализация методом AES, ключом и вектором
	char text[2014];
	for (int i = 0; i < s.length(); i++)
	{
		text[i] = s[i];
	}
	// 3.
	cryptedtext_len = s.length();
	EVP_DecryptUpdate(ctx, decryptedtext, &len,(const unsigned char *) text, cryptedtext_len);  // СОБСТВЕННО, ШИФРОВАНИЕ

	// 4.
	int dectypted_len = len;
	EVP_DecryptFinal_ex(ctx, ((unsigned char *)text) + len, &len);

	// 5.
	dectypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[dectypted_len] = '\0';
	fps_2 << decryptedtext << endl;
	fps_2.close();
	getchar();
	return 0;
}