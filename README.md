Лабораторная работа по курсу Информационная безопасноть, Шифр XOR(Гаммирование).  В качестве ключа принимается СЛОВО без пробелов и прочих знаков, например: LEMON, APPLE, orange, low... В программе реализовано шифрование символов по таблице ASCII.
Программа предназначена для ознакомления с процессом шифрования/дешифрования методом Гаммирования. Сообщение и ключ представляются в виде целочисленной последовательности чисел.

Оператор XOR чрезвычайно распространен в качестве компонента в более сложных шифрах. Сам по себе, используя постоянный повторяющийся ключ, простой шифр XOR может быть тривиально взломан с помощью частотного анализа. Если содержание любого сообщения может быть угадано или иным образом известно, тогда ключ может быть раскрыт. Его основное достоинство заключается в том, что он прост в реализации и что операция XOR является недорогой с точки зрения вычислений. Поэтому простой повторяющийся шифр XOR (т.Е. использующий один и тот же ключ для операции xor со всеми данными) иногда используется для сокрытия информации в случаях, когда не требуется особой безопасности. Шифр XOR часто используется в компьютерных вредоносных программах для усложнения обратного проектирования.

Если ключ случайный и по крайней мере такой же длины, как и сообщение, шифр XOR намного более безопасен, чем при повторении ключа в сообщении.Когда ключевой поток генерируется генератором псевдослучайных чисел, результатом является потоковый шифр. С ключом, который является действительно случайным, результатом является одноразовый блокнот, который теоретически невозможно взломать.

Оператор XOR в любом из этих шифров уязвим для атаки с использованием заведомо открытого текста, поскольку шифротекст  открытого текста = ключ. Также тривиально переворачивать произвольные биты в расшифрованном открытом тексте, манипулируя зашифрованным текстом. Это называется гибкостью.

~~~DATA
VECTOR text_and_encrypted_text Вектор содержит 3 строки(ТЕКСТ, ЗАШИФРОВАННЫЙ ТЕКСТ, КЛЮЧ).
vector<vector<int>> sequences_text_key_enc содержит 3 последовательности представленных чисел в соотстветсвии с ASCII
enum vectorStatus используется для упрощения итераций по элементам вектора.
enum intVectorStatus используется для упрощения итераций по элементам последовательностей чисел.
~~~FUNC
функция checkKey принимает на вход ключ вектор.
       внутри реализована проверка ключа на размер
функция pushSequence принимает на вход вектор текста, элемент перечисления исп.вектор текста, вектор последовательностей, элемент перечисления исп.вектор последовательностей.
        помещает в вектор последовательностей числа из таблицы ASCII
функция xorOperation принимает на вход вектор последовательностИ, элемент перечисления исп.вектор последовательностей, объект 1 для операции XOR, объект 1 для операции XOR.        
        выполняет операцию XOR от двух переданных значений
функция printSequence принимает на вход вектор последовательностей, элемент перечисления исп.вектор последовательностей
        выводит последовательность чисел
GammaCypher принимает на вход вектор последовательностей, вектор текста
             выполняет все перечисленные выше функции

~~~FILES

Source.cpp - основной файл с кодом.
