#include "AnimWindow.h"
#include "Shell.h"

#define SPACE_TABLE_SIZE 18
#define H_TABLE_SIZEF 6
#define H_TABLE_SIZES 11

Shell::Shell()
{
	p_seed = &seed;
	// SETTING
	GenerateSeeds();
	DNA = new string(EncryptionAdvanced("84265743879637460611", MemoryKeyGen()));

}


Shell::~Shell()
{
	delete DNA;

	p_seed = nullptr;
}
/*
ikey[1] = (i + 3) / 1;
		ikey[2] = ikey[1] + 14 / 6;
		ikey[1] = ikey[2] + 3;
		*/


bool Shell::NatagoInput(string* result, WindowTools *wt)
{
	string input;
	while (true)
	{
		input = _getch();

		if (input == "\x1b") // ESC wylacza program
		{
			wt->AnimWindowOut(100,false);
			exit(0);
		}
		else
			if (input == "\b") {
				system("cls");
				return 0;
			}
			else
				if (input == "\r") { return 1; }
				else
				{
					*result += input;
					cout << "*";
				}
	}
	return 1;
}

string Shell::GenerateString(bool Special, string SpecialList, bool Numbers, bool bigChars, bool smallChars, int len)
{
	string raw_alphanum = "";
	string specials = "!@#$%^&*()_+{}:'|<>?/.,\\';][=-";

	if (smallChars == true)
		raw_alphanum += "qwertyuiopasdfghjklzxcvbnm";

	if (bigChars == true)
		raw_alphanum += "QWERTYUIOPASDFGHJKLZXCVBNM";

	if (Numbers == true)
		raw_alphanum += "1234567890";

	if (SpecialList != "")
	{
		raw_alphanum += SpecialList;
	}
	else
	{
		if (Special == true)
			raw_alphanum += specials;
	}
	
	string alphanum = "";
	bool* alphanum_is = new bool[raw_alphanum.length()];
	for (int i = 0; i < raw_alphanum.length(); i++)
		alphanum_is[i] = false;

	int randint = 0;
	for (int i = 0; i < raw_alphanum.length(); i++)
	{
		randint = rand() % raw_alphanum.length();

		if (randint > -1 && randint < raw_alphanum.length())
		{
			if (alphanum_is[randint] == false)
			{
				alphanum_is[randint] = true;
				alphanum += raw_alphanum[randint];
			}
			else
				i -= 1;
		}
		else
			i -= 1;
	}
	
	string pswd="";
	for (int i = 0; i < len; i++)
	{
		pswd += alphanum[rand() % alphanum.length()];
	}

	return pswd;
}

string Shell::getDNA()
{
	return DecryptionAdvanced(*DNA, MemoryKeyGen(),true);
}

void Shell::stringToUint8_t(string data, uint8_t* buf)
{
	for (int i = 0; i < data.length(); i++)
	{
		buf[i] = uint8_t(data[i]);
	}
}

void Shell::GenerateSeeds()
{
	mn = rand() % (6 - 2 + 1) + 2;
	sc = rand() % (6 - 2 + 1) + 2;
	dy = rand() % (8 - 1 + 1) + 1;
	no = rand() % (13 - 2 + 1) + 2;
	ac = rand() % (5 - 1 + 1) + 1;
	string alphanum = 
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char s[5] = {0};
	p_seed->clear();
	ns.clear();
	no2.clear();

	for (int i = 0; i < 4; i++)
	{
		s[i] = alphanum[rand() % alphanum.length()];
		*p_seed += s[i];
	}

	for (int i = 0; i < 5; i++)
	{
		s[i] = alphanum[rand() % alphanum.length()];
		ns += s[i];
	}

	for (int i = 0; i < 4; i++)
	{
		s[i] = alphanum[rand() % alphanum.length()];
		no2 += s[i];
	}
}


// salted!!
string Shell::MakeHash(string input)
{
	return sha256(input); // SALTED!!
}

string Shell::EncryptionSimple(string data)
{
	return SimpleEncyptor(data, 3, 1, 14, 6, 3);
}
string Shell::DecryptionSimple(string data)
{
	return SimpleDecryptor(data, 3, 1, 14, 6, 3);
}

string Shell::EncryptionAdvanced(string indata, string key)
{
	uint8_t u_key[1024] = { 0 };
	stringToUint8_t(key, u_key);
	
	uint8_t buf[1024] = { 0 };
	stringToUint8_t(indata, buf);

	aes256_context ctx;
	aes256_init(&ctx, u_key);
	aes256_encrypt_ecb(&ctx, buf);
	aes256_done(&ctx);

	string data = "";//string((char *)buf);
	for (int i = 0; i < 1024; i++)
	{
		//if (buf[i] == NULL)
		//	break;
		data += buf[i];
	}

	return data;
}
string Shell::DecryptionAdvanced(string indata, string key, bool CutAtNULL)
{
	uint8_t u_key[1024] = { 0 };
	stringToUint8_t(key, u_key);

	uint8_t buf[1024] = { 0 };
	stringToUint8_t(indata, buf);

	aes256_context ctx;
	aes256_init(&ctx, u_key);
	aes256_decrypt_ecb(&ctx, buf);
	aes256_done(&ctx);
	string data = "";//string((char *)buf);
	 
	for (int i = 0; i < 1024; i++)
	{
		if (CutAtNULL == true)
		{
			if (buf[i] == NULL)
				break;
		}
		data += buf[i];
	}


	return data;
}

string Shell::MemoryKeyGen()
{
	// aktualny czas
	string key="";
	int *d = &mn;
	int c = 0;
	int *e = &dy;
	string alphanum =
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 7; i++)
	{
		c += *e;
		key += alphanum[c];
		if (i == *d)
			key += *p_seed;
	}
	d = nullptr;
	e = nullptr;

	return key;
}

string Shell::SimpleEncyptor(string data, int a,int f, int c,int d, int e)
{
	
	int b = 0;
	int l = 3;
	
	char *crtpy = new char[data.length()];
	strcpy(crtpy, data.c_str());
	for (int i = 0; i < data.length(); i++)
	{
		int ikey[3];
		ikey[1] = (i+a) / f;
		ikey[2] = ikey[1] + c / d;
		ikey[1] = ikey[2] + e;
		b = crtpy[i];
		if (l == i) 
		{ 
			b = b + ikey[1]; 
			l = l + 3;
		}
		else 
		{ 
			b = b + ikey[2]; 
		}
		crtpy[i] = b;
	}
	return crtpy;
	delete[] crtpy;
}

string Shell::SimpleDecryptor(string data, int a, int f, int c, int d, int e)
{
	int b = 0;
	int l = 3;

	char crtpy[100] = {};
	strcpy_s(crtpy, data.c_str());
	for (int i = 0; i < data.length(); i++)
	{
		int ikey[3];
		ikey[1] = (i + a) / f;
		ikey[2] = ikey[1] + c / d;
		ikey[1] = ikey[2] + e;
		b = crtpy[i];
		if (l == i)
		{
			b = b - ikey[1];
			l = l + 3;
		}
		else
		{
			b = b - ikey[2];
		}
		crtpy[i] = b;
	}
	return crtpy;
}

string Shell::NatagoEncryptor(string data)
{
	char space_Table[SPACE_TABLE_SIZE] = { 'Y','a','H','k','I','_','}','1','X','#','A','m','S','$','o','i','U','d' };


	string l_data = "";
	string conv = "";

	for (int i = 0; i < data.length();i++)
	{
		conv = data[i];
		l_data += H_TableEncrypt(conv);
		l_data += space_Table[rand()% (SPACE_TABLE_SIZE-1)];
		
	}

	return l_data;
}

string Shell::H_TableEncrypt(string data)
{
	// HideTable Here!
	char h_table[H_TABLE_SIZEF][H_TABLE_SIZES] = {
{'2','!','p','&','z','>','*','q','-','b',';',},
{'s','W','n','M','E','8','9','R','4','B','T',},
{'V','L','j','=','?','w',')','x',']','/','@',},
{'0','h','t','Q','5','.','G','v','r','J','N',},
{'{','^','(','l','C','c','Z','+','%','F','3',},
{'e',',','D','O','[','g','P',':','f','6','y',} };

	string conv = "";
	string h_data = "";
	char sign;
	int dec = 0;
	for (int i = 0; i < data.length(); i++)
	{

		sign = data[i];
		dec = (int)sign;
		//cout << dec << " ";
		if (dec < 0)
		{
			h_data += h_table[rand() % (H_TABLE_SIZEF - 1)][10];
			dec *= -1;
		}
		
		conv = to_string(dec);
		
		for (int l = 0; l < conv.length(); l++)
		{
			dec = conv[l] - '0';
			h_data += h_table[rand() % (H_TABLE_SIZEF - 1)][dec];
			
		}
	}
	//cout << " " << h_data<< endl;
	return h_data;
}

string Shell::H_TableDecrypt(string data)
{
	char h_table[H_TABLE_SIZEF][H_TABLE_SIZES] = {
{'2','!','p','&','z','>','*','q','-','b',';',},
{'s','W','n','M','E','8','9','R','4','B','T',},
{'V','L','j','=','?','w',')','x',']','/','@',},
{'0','h','t','Q','5','.','G','v','r','J','N',},
{'{','^','(','l','C','c','Z','+','%','F','3',},
{'e',',','D','O','[','g','P',':','f','6','y',} };


	string conv = "";
	bool b_break = 0;
	for (int i = 0; i < data.length(); i++)
	{
		for (int f = 0; f < H_TABLE_SIZEF; f++)
		{
			if (b_break == true)
			{
				b_break = 0;
				break;
			}
			for (int s = 0; s < H_TABLE_SIZES; s++)
			{
				if (h_table[f][s] == data[i])
				{
					if (s == 10)
						conv += "-";
					else
						conv += to_string(s);
					b_break = true;
					break;
				}
			}
		}
	}
	int dec = atoi(conv.c_str());
	char sign = dec;
	//cout << dec << " ";
	conv = sign;
	//cout << conv << endl;
	return conv;
}

string Shell::NatagoDecryptor(string data)
{
	char space_Table[SPACE_TABLE_SIZE] = { 'Y','a','H','k','I','_','}','1','X','#','A','m','S','$','o','i','U','d' };


	string conv = "";
	string comp_data = "";
	bool space = 0;
	//cout << "----------------------------" << endl;
	//cout << data << endl;
	for (int i = 0; i < data.length(); i++)
	{
		space = false;
		for (int f = 0; f < SPACE_TABLE_SIZE; f++)
		{
			if (space_Table[f]==data[i])
			{
				comp_data += H_TableDecrypt(conv);
				conv = "";
				space = true;
				break;
			}
				
		}
		if(space==false)
			conv += data[i];
	}
	//cout << "----------------------------" << endl;
	return comp_data;
}