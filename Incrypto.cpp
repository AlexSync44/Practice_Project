//#include <winsock2.h>
//#include <windows.h>
//#include "Incrypto.h"
//#include <openssl/aes.h>
//#include <openssl/rand.h>
//
//void test()
//{
//	const int maxLen = 1024;
//
//	char name[maxLen]{};
//	char login[maxLen]{};
//	char psw[maxLen]{};
//
//	std::cout << "��� �����: " << name << std::endl;
//	std::cout << "�����: " << login << std::endl;
//	std::cout << "������: " << psw << std::endl;
//
//	unsigned char k[] = "0JDQu9C10LrRgdC1";
//	uint8_t* key = (uint8_t*)k;
//	uint8_t iv[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '1', '2', '3', '4', '5', '6' };
//
//	struct AES_ctx ctx;
//	AES_init_ctx_iv(&ctx, key, iv);
//	AES_CBC_encrypt_buffer(&ctx, (uint8_t*)name, strlen(name));
//	AES_CBC_encrypt_buffer(&ctx, (uint8_t*)login, strlen(login));
//	AES_CBC_encrypt_buffer(&ctx, (uint8_t*)psw, strlen(psw));
//
//	std::cout << "������ �����������\n";
//
//	std::cout << "��� �����: " << name << std::endl;
//	std::cout << "�����: " << login << std::endl;
//	std::cout << "������: " << psw << std::endl;
//	std::cout << "----------------------\n";
//
//	// � ������ ����� �����������
//
//	struct AES_ctx ctx2;
//	AES_init_ctx_iv(&ctx2, key, iv);
//	AES_CBC_decrypt_buffer(&ctx2, (uint8_t*)name, strlen(name));
//	AES_CBC_decrypt_buffer(&ctx2, (uint8_t*)login, strlen(login));
//	AES_CBC_decrypt_buffer(&ctx2, (uint8_t*)psw, strlen(psw));
//
//	std::cout << "������ ������������\n";
//	std::cout << "��� �����: " << name << std::endl;
//	std::cout << "�����: " << login << std::endl;
//	std::cout << "������: " << psw << std::endl;
//	std::cout << "----------------------\n";
//}
