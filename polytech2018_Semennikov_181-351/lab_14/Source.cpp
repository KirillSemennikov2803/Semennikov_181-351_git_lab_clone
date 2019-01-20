#include <iostream>
#include <openssl/conf.h> // �������, ��������� � ��������� ��������� OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // ���� ���������������� ������� https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // ���� ���������� ������ OpenSSL � �� �����������
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

// ���������� OpenSSL (openssl.org) ������������ ������ ����������� (��. �������� ���. �� �����������)

using namespace std;

int main()
{
	// ������ � ��������������� OpenSSL:
	// 1) �������� ������� � �����������
	// 2) ����������, ����������
	// 3) �����������
	// 4) � ����� ������������� ������

	// ��� �������, � ����������, ��������� ������������ ��� �������� ������ ������
	// �� ����� � ������� � �������������/������������
	struct name_of_my_struct // ������ ������
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
	unsigned char *plaintext;// �������� �����
	int plaintext_len ; // ����� ������
	unsigned char *key = (unsigned char *)"0123456789"; // ������ (����)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // ���������������� ������, �����������
	unsigned char cryptedtext[256]; // ������������� ���������
	unsigned char decryptedtext[256]; // �������������� ���������

	// 1. �������� ��������� �� �������������� ���������
	// ��������� - ��� ������ � C++, ������ � ������, �������� ����������
	EVP_CIPHER_CTX *ctx; // structure

	// 2. ��� ��������� �������� ������ ��������� �������� (�����, ����, ������ ������������� � �.�.)
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������

	// 3. ��������� EVP_CIPHER_CTX ����������� �����������
	EVP_EncryptInit_ex(ctx, // ������ �� ������/���������, ���� ��������� ���������
		EVP_aes_256_cbc(), // ������ �� ��������� ���� AES 256 (������� � ����������)
		NULL,
		key, // ����/������/������
		iv); // ����������� (��������� ��������� ������)

	// 4. ��� ������� ���������� - ������� EVP_EncryptUpdate
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
			unsigned char *plaintext = (unsigned char *)tab2;// �������� �����
			int plaintext_len = 32;

			EVP_EncryptUpdate(ctx, // ������ � �����������
				cryptedtext, // ������� ��������: ������, ���� �������� ������������� ������
				&len, // �������� ��������: ����� ����������� �����
				plaintext, // ������� ��������: ��� ���������
				plaintext_len); // ������� �������� : ����� ������� ������
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
			unsigned char *plaintext = (unsigned char *)tab2;// �������� �����
			int plaintext_len = (s.length() - cursor - 1);
			EVP_EncryptUpdate(ctx, // ������ � �����������
				cryptedtext, // ������� ��������: ������, ���� �������� ������������� ������
				&len, // �������� ��������: ����� ����������� �����
				plaintext, // ������� ��������: ��� ���������
				plaintext_len); // ������� �������� : ����� ������� ������
			cryptedtext_len = (s.length() - cursor - 1);
			EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
			for (i = 0; i < (s.length() - cursor - 1); i++)
			{
				fout << hex << cryptedtext[i];

			}
			cursor += 32;
		}
	
		
	}
	/*EVP_EncryptUpdate(ctx, // ������ � �����������
		cryptedtext, // ������� ��������: ������, ���� �������� ������������� ������
		&len, // �������� ��������: ����� ����������� �����
		plaintext, // ������� ��������: ��� ���������
		plaintext_len); // ������� �������� : ����� ������� ������
	cryptedtext_len = len;*/
	fout.close();
	// 6. �������� ���������
	EVP_CIPHER_CTX_free(ctx);
	std::ifstream fps("out.txt", ios::binary | ios::in);
	std::ofstream fps_2("out_decript.txt", ios::binary | ios::out);
	getline(fps, s, nil);
	fps.close();
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������

	// 2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // ������������� ������� AES, ������ � ��������
	char text[2014];
	for (int i = 0; i < s.length(); i++)
	{
		text[i] = s[i];
	}
	// 3.
	cryptedtext_len = s.length();
	EVP_DecryptUpdate(ctx, decryptedtext, &len,(const unsigned char *) text, cryptedtext_len);  // ����������, ����������

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