#include <iostream>

using namespace std;

bool QueueFull(int tail, int head, int len)
{
	if (tail == len - 1)
		return (head == 0);
	else
		return (tail + 1 == head);
}

bool QueueEmpty(int tail, int head, int len)
{
	return (head == tail);
}


void Enqueue(char Q[], int& tail, int& head, int len, char in_chr)
{
	if (QueueFull(tail, head, len))
		return; //error - overflow
	Q[tail] = in_chr;
	if (tail + 1 == len)
		tail = 0;
	else
		tail++;
}

char Dequeue(char Q[], int& tail, int& head, int len)
{
	if (QueueEmpty(tail, head, len))
		return ' '; //error - underflow
	char result = Q[head];
	if (head + 1 < len)
		head++;
	else
		head = 0;
	return result;
}

int main()
{
	//use const

	//Define Stack
	char Q[5];
	int head = 0;
	int tail = 0;
	int len = 5;

	bool res1 = QueueEmpty(tail, head, len);

	Enqueue(Q, tail, head, len, 'a');
	char chr = Dequeue(Q, tail, head, len);
	printf("%c", chr);

	bool res2 = QueueEmpty(tail, head, len);

	if (res1 && !res2)
		printf("all is good");
}