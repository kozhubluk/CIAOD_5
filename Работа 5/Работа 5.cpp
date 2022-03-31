#include <iostream>
using namespace std;

struct Node
{
	int info; // информационный узел 
	Node* next;  // указатель на соедующий элемент
};

void create_list(Node*& L, int& n) // Создание списка 
{
	Node *new_L;
	Node* temp_L = nullptr;
	cout << "Enter list's size: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{;
		new_L = new Node; // new_L - хранит указатель на i-ый элемент списка
		cin >> new_L->info;
		new_L->next = nullptr;
		if (L == NULL) 
		{
			L = new_L;
		}
		else
		{
			temp_L->next = new_L; // Полю next прошлого элемента присваивавем указатель на текущий элемент
		}
		temp_L = new_L;
	}
}

void out(Node* L) // Вывод списка
{
	if (L == NULL) // Ситуация, когда список пуст 
	{
		cout << "List is empty!\n";
		return;
	}
	Node* q = L;
	while (q != nullptr) 
	{
		cout << q->info  << "  ";
		q = q->next; // Присваиваем q указатель на следующий элемент списка
	}
	cout << endl;
}

void delete_pos(Node*& L) // Удаление из списка элементов, стоящих на четных позициях
{
	Node* q = L;
	while (q != nullptr && q->next != nullptr)
	{
		q->next = (q->next)->next; // Полю next элемента, стоящего на нечетной позиции, присваиваем указатель на элемент, стоящий через один от него   
		q = q->next;
	}
}

void add_sum(Node*& L, int &n) // Добавлять в список после каждой пары элементов их сумму 
{
	Node* q = L;
	Node* sum = new Node; // sum будет хранить указатель на добавляемый элемент
	sum->info = 0;
	int new_n = n;
	int end = n - (n % 2);
	for (int i = 1; i <= end; i++)
	{
		sum->info += q->info;
		if (i % 2 == 0) 
		{
			sum->next = q->next; // изменяем поле next второго элемента в паре складываемых 
			q->next = sum;
			q = q->next;
			sum = new Node;
			sum->info = 0;
			new_n++;
		}
		q = q->next;
	}
	n = new_n;
}

bool f(Node* L, int k) // Проверяет, встречается ли число k в списке
{
	if (L == NULL)
	{
		return false;
	}
	Node* q = L;
	while (q != nullptr) 
	{
		if (q->info == k)
		{
			return true;
		}
		q = q->next;
	}
	return false;
}

void create_l3(Node*& L3, Node* L2, Node* L1) // Создание нового списка на основе 2-х существующих
{
	Node* new_L;
	Node* temp_L = nullptr;
	Node* q;
	for (int i = 0; i < 2; i++)
	{
		q = L1;
		if (i == 1)
		{
			q = L2;
		}
		while (q != nullptr)
		{
			if (!(f(L3, q->info)))
			{
				new_L = new Node;
				new_L->info = q->info;
				new_L->next = nullptr;
				if (L3 == NULL)
				{
					L3 = new_L;
				}
				else
				{
					temp_L->next = new_L; // Полю next прошлого элемента присваивавем указатель на текущий элемент
				}
				temp_L = new_L;
			}
			q = q->next;
		}
	}
}

int main()
{
	Node *List1 = NULL, *List2 = NULL, *List3 = NULL;
	int size1, size2, size3;
	cout << "Fill in the list#1:\n";
	create_list(List1, size1);
	cout << "Fill in the list#2:\n";
	create_list(List2, size2);
	cout << "List#1: ";
	out(List1);
	cout << "List#2: ";
	out(List2);
	cout << "____________________________________________\n";
	delete_pos(List1);
	add_sum(List2, size2);
	cout << endl << "New list#1: ";
	out(List1);
	cout << "New list#2: ";
	out(List2);
	create_l3(List3, List2, List1);
	cout << endl << "Creating a new list#3: ";
	out(List3);
	

}

 