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
	if (key.size() > text_and_encrypted_text[TEXT].size())//�������� �� ������ ����� � ���������� ���������
	{
		key.erase(text_and_encrypted_text[TEXT].size()); // ���� ���� > ��������� ��������� - ������� ���� �� ������� ������
	}
	else if (key.size() < text_and_encrypted_text[TEXT].size()) // ���� ���� < ��������� ��������� - ��������� ������ ����� �� ������� ������
	{
		int counter = text_and_encrypted_text[TEXT].size() - key.size(); //������� ����� �������� ���������� ��������� � �������� �����

		for (int i = 0; i < counter; i++)
		{
			key += key[i];
		}
	}
}
void pushSequence(vector<string>& text_and_encrypted_text, TextVectorStatus&& text_vector_status, vector<vector<int>>& myvector3, intVectorStatus&& int_vector_status)
{
	for (int count = 0; count < text_and_encrypted_text[text_vector_status].size(); count++) //������������������ int �� TEXT
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
	getline(cin, message);//���� ���������


	text_and_encrypted_text.push_back(message);//��������� ��������� � ������ TEXT
	text_and_encrypted_text.push_back(message);//��������� ��������� � ������ ��� �������� ENCRYPTED_TEXT

	cout << "Enter your key: ";
	getline(cin, key); //���� ���������
	std::cin.clear();

	checkKey(key, text_and_encrypted_text);

	text_and_encrypted_text.push_back(key); //������� ���� � ������ KEY



		//��� ���������� ������������ � ��������� ���������� ����� ����������� ���������� ��� int ��������������� �������� �� ASCII table
		//�������� �������� � ���������� ������� � ��������������� ������������������

	pushSequence(text_and_encrypted_text, TEXT, myvector3, sequence_int_TEXT); //������������������ int �� TEXT

	pushSequence(text_and_encrypted_text, KEY, myvector3, sequence_KEY); //������������������ int �� KEY

	xorOperation(myvector3, sequence_int_ENCRYPTED_TEXT, sequence_int_TEXT, sequence_KEY);

	
	// ����� � ������� ����������� ����������� 
	cout << "Performing CODING!~~~~~" << endl;
	cout << "MSG: " << endl;
	printSequence(myvector3, sequence_int_TEXT);

	cout << "KEY: " << endl;
	printSequence(myvector3, sequence_KEY);

	cout << "Performing XOR operation!" << endl;

	cout << "ENC: " << endl;
	printSequence(myvector3, sequence_int_ENCRYPTED_TEXT);

	//��� ����������� ���������� ����� ���� ���������� � ������������� ������������������, ��������� XOR ����� ����

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