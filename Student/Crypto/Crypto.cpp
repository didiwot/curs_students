#include "Crypto.h"


Crypto::Crypto()
{
	//Получаем контекст крипт
	if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)) {
		cout << "CryptAcquireContext error " << GetLastError() << endl;
		return;
	}
	cout << "Crypto initialized " << endl;
	//Генерация сессионного ключа
	if (!CryptGenKey(hProv, CALG_RC4, CRYPT_EXPORTABLE, &hSessionKey)) {
		cout << "CryptGenKey error " << GetLastError() << endl;
		return;
	}
	cout << "Session key generated" << endl;

	
}

Crypto::~Crypto()
{


}


void Crypto::Encrypt(string text) {
	DWORD count = text.length();
	ofstream file("../../../database/crypt_database.txt");
	if (!file.is_open()) {
		cout << "Encrypt open file error";
			return;
	}

	if (!CryptEncrypt(hSessionKey, 0, true, 0, (BYTE*)text.c_str(), &count, text.length())) {
		cout << "Encrypt error " << GetLastError() << endl;
		return;
	}
	file << text;
	cout << "Enctypt success";
}

void Crypto::Decrypt() {
	DWORD count = text.length("../../../database/crypt_database.txt");
	ifstream inFile()
	ofstream outFile("../../../database/decrypt_database.txt");
	if (!outFile.is_open()) {
		cout << "Encrypt open file error";
		return;
	}

	if (!CryptDecrypt(hSessionKey, 0, true, 0, (BYTE*)string1, &count1)) {
		cout << "Encrypt error " << GetLastError() << endl;
		return;
	}
	outFile << text;
}

