#include "Crypto.h"


Crypto::Crypto()
{
	//Получаем контекст крипт
	if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)) {
		cout << "CryptAcquireContext" << GetLastError() << endl;
		return;
	}
	cout << "Crypto initialized" << endl;
	//Генерация сессионного ключа
	if (!CryptGenKey(hProv, CALG_RC4, CRYPT_EXPORTABLE, &hSessionKey)) {
		cout << "CryptGenKey" << GetLastError() << endl;
		return;
	}
	cout << "Session key generated" << endl;
}

Crypto::~Crypto()
{


}


