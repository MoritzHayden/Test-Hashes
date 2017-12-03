#include<iostream>
#include<string>
using namespace std;

unsigned int RSHash(const std::string& str)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;

	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash = hash * a + str[i];
		a = a * b;
	}

	return hash;
}

unsigned int BKDRHash(const std::string& str)
{
	unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
	unsigned int hash = 0;

	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash = (hash * seed) + str[i];
	}

	return hash;
}

unsigned int weakHash(const std::string& str)
{
	unsigned int b = 3751;
	unsigned int a = 689;
	unsigned int hash = 0;

	for (std::size_t i = str.length() - 4; i < str.length() - 1; i++)
	{
		hash = hash * a + str[i];
		a = a * b;
	}
	//Convert hash to string
	return (hash);
}

int main()
{
	string hashStr;
	unsigned int rsResult = 0;
	unsigned int bkdrResult = 0;
	unsigned int weakResult = 0;
	cout << "Input to be hashed: ";
	cin >> hashStr;
	cout << '\n';

	rsResult = RSHash(hashStr);
	bkdrResult = BKDRHash(hashStr);
	weakResult = weakHash(hashStr);

	cout << "RS Hash Result: " << rsResult << '\n';
	cout << "BKDR Hash Result: " << bkdrResult << '\n';
	cout << "Weak Hash Result: " << weakResult << '\n';

	system("pause");
	return 0;
}