#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum TextVectorStatus
{
	TEXT,
	ENCRYPTED_TEXT,
	KEY
};

enum intVectorStatus
{
	sequence_int_TEXT,
	sequence_int_ENCRYPTED_TEXT,
	sequence_KEY
};

void checkKey(string& key, vector<string>& text_and_encrypted_text)
{
	if (key.size() > text_and_encrypted_text[TEXT].size())//Проверка на размер ключа и текстового сообщения
	{
		key.erase(text_and_encrypted_text[TEXT].size()); // Если ключ > текстовое сообщение - очищаем ключ до размера текста
	}
	else if (key.size() < text_and_encrypted_text[TEXT].size()) // Если ключ < текстовое сообщение - дополняем размер ключа до размера текста
	{
		int counter = text_and_encrypted_text[TEXT].size() - key.size(); //Разница между размером текстового сообщения и размером ключа

		for (int i = 0; i < counter; i++)
		{
			key += key[i];
		}
	}
}
void pushSequence(vector<string>& text_and_encrypted_text, TextVectorStatus&& text_vector_status, vector<vector<int>>& myvector3, intVectorStatus&& int_vector_status)
{
	for (int count = 0; count < text_and_encrypted_text[text_vector_status].size(); count++) //Последовательность int от TEXT
	{
		myvector3[int_vector_status].push_back(int(text_and_encrypted_text[text_vector_status][count]));
	}
}
void xorOperation(vector<vector<int>>& myvector3, intVectorStatus&& resultSequenceXored, intVectorStatus&& obj1, intVectorStatus&& obj2)
{
	for(int count =0;count < myvector3[obj1].size(); count++)
	{ 
		myvector3[resultSequenceXored].push_back(myvector3[obj1][count] ^ myvector3[obj2][count]);
	}
	
}
void printSequence(vector<vector<int>>& myvector3, intVectorStatus&& int_vector_status)
{
	for (int count = 0; count < myvector3[int_vector_status].size(); count++)
	{
		cout << "\t" << myvector3[int_vector_status][count] << "\t";
	}
	cout << "" << endl;
}
void GammaCypher(vector<string>& text_and_encrypted_text, vector<vector<int>>& myvector3)
{
	string message, key;

	std::cin.clear();
	cout << "Enter your message: ";
	getline(cin, message);//Ввод сообщения


	text_and_encrypted_text.push_back(message);//Занесение сообщения в вектор TEXT
	text_and_encrypted_text.push_back(message);//Занесение сообщения в вектор для будущего ENCRYPTED_TEXT

	cout << "Enter your key: ";
	getline(cin, key); //Ввод сообщения
	std::cin.clear();

	checkKey(key, text_and_encrypted_text);

	text_and_encrypted_text.push_back(key); //Заносим ключ в вектор KEY



		//Для подробного ознакомления с процессом шифрования будем производить вычисления над int представлениями символов из ASCII table
		//Поместим элементы в подвекторы вектора в соответствующие последовательности

	pushSequence(text_and_encrypted_text, TEXT, myvector3, sequence_int_TEXT); //Последовательность int от TEXT

	pushSequence(text_and_encrypted_text, KEY, myvector3, sequence_KEY); //Последовательность int от KEY

	xorOperation(myvector3, sequence_int_ENCRYPTED_TEXT, sequence_int_TEXT, sequence_KEY);

	
	// ВЫВОД В КОНСОЛЬ СОДЕРЖИМОГО ПОДВЕКТОРОВ 
	cout << "Performing CODING!~~~~~" << endl;
	cout << "MSG: " << endl;
	printSequence(myvector3, sequence_int_TEXT);

	cout << "KEY: " << endl;
	printSequence(myvector3, sequence_KEY);

	cout << "Performing XOR operation!" << endl;

	cout << "ENC: " << endl;
	printSequence(myvector3, sequence_int_ENCRYPTED_TEXT);

	//ДЛЯ РАСШИФРОВКИ НЕОБХОДИМО ЗНАТЬ КЛЮЧ ШИФРОВАНИЯ И ЗАШИФРОВАННУЮ ПОСЛЕДОВАТЕЛЬНОСТЬ, ПРОИЗВЕДЯ XOR МЕЖДУ НИМИ

	cout << "Performing DECODING!~~~~" << endl;

	myvector3[sequence_int_TEXT].clear();

	xorOperation(myvector3, sequence_int_TEXT, sequence_int_ENCRYPTED_TEXT, sequence_KEY);


	cout << "ENC: " << endl;
	printSequence(myvector3, sequence_int_ENCRYPTED_TEXT);

	cout << "KEY: " << endl;
	printSequence(myvector3, sequence_KEY);

	cout << "Performing XOR operation!" << endl;

	cout << "MSG: " << endl;
	printSequence(myvector3, sequence_int_TEXT);
}



int main()
{
	vector<string> text_and_encrypted_text;
	vector<vector<int>> sequences_text_key_enc{ {}, {}, {} };

	sequences_text_key_enc[sequence_int_TEXT].reserve(100);
	sequences_text_key_enc[sequence_int_ENCRYPTED_TEXT].reserve(100);
	sequences_text_key_enc[sequence_KEY].reserve(100);

	GammaCypher(text_and_encrypted_text, sequences_text_key_enc);

	return 0;
}