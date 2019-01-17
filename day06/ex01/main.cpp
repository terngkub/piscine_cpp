#include <iostream>
#include <string>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void * serialize( void )
{
	std::string alnum = "abcdefghijklmnopqrstqvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char * raw = new char[20];

 	srand(time(NULL));

	for (int i = 0; i < 8; i++)
		raw[i] = alnum[rand() % alnum.length()];

	int * raw_int = reinterpret_cast<int *>(raw);
	raw_int[2] = rand();

	raw = reinterpret_cast<char *>(raw);
	for (int i = 12; i < 20; i++)
		raw[i] = alnum[rand() % alnum.length()];

	return reinterpret_cast<void *>(raw);
}

Data * deserialize( void * raw )
{
	std::string str(reinterpret_cast<char *>(raw));
	Data * data = new Data;
	data->s1 = str.substr(0, 8);
	data->s2 = str.substr(12, 20);
	data->n = *reinterpret_cast<int *>(const_cast<char *>(str.substr(8, 12).c_str()));
	return data;
}


int main()
{
	void * raw = serialize();
	Data * data = deserialize(raw);

	std::cout << data->s1 << "\n"
		<< data->n << "\n"
		<< data->s2 << "\n";

	delete reinterpret_cast<char *>(raw);
	delete data;

	return 0;
}