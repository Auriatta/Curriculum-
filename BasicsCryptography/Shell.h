#pragma once
#include"Includes.h"
#include "sha256.h"
#include "aes256.h"
#include "AnimWindow.h"


class Shell
{
public:
	Shell();
	~Shell();

	string MemoryKeyGen();
	
	bool NatagoInput(string* result, WindowTools *wt);
	string GenerateString(bool Special, string SpecialList, bool Numbers, bool bigChars, bool smallChars, int len);
	string MakeHash(string input);
	string NatagoEncryptor(string data); // do pswd
	string NatagoDecryptor(string data);
	string EncryptionAdvanced(string data, string key);
	string DecryptionAdvanced(string data, string key, bool cutAtNULL);
	string EncryptionSimple(string data); // do pswd
	string DecryptionSimple(string data);
	string getDNA();
	void stringToUint8_t(string data, uint8_t* buf);
	friend class Main;
	friend class FileIO;

protected:
	

private:
	string SimpleEncyptor(string data, int a, int b, int c, int d, int e);
	string SimpleDecryptor(string data, int a, int b, int c, int d, int e);
	
	string H_TableEncrypt(string data);
	string H_TableDecrypt(string data);

	void GenerateSeeds();

	//MEMKeyGen
	int mn, sc, dy, no, ac;
	string seed;
	string *p_seed;
	string ns;
	string no2;

	string *DNA;
};

