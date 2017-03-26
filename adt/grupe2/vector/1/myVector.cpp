#include "myVector.h"

template<typename T>
T getItem(Data<T> *ls, int p) {

	if (p < 1 || p >(*ls).itemAmount)
		return 0;

	Item<T> *result = (*ls).head;

	for (int i = 1; i < p; i++)
		result = (*result).next;

	return (*result).value;

}

template<typename T>
bool clear(Data<T> *ls) {

	if (isEmpty(ls))
		return 1;
	if ((*ls).itemAmount == 1)
	{
		delete((*ls).head);
		(*ls).itemAmount = 0;
		return 1;
	}

	Item<T> *temp1 = (*ls).head;
	Item<T> *temp2 = (*temp1).next;
	(*ls).head = 0;
	(*ls).itemAmount = 0;

	while ((*temp2).next != 0) {
		delete(temp1);
		temp1 = temp2;
		temp2 = (*temp1).next;
	}
	delete(temp1);
	delete(temp2);

	return 1;

}

template<typename T>
bool isEmpty(Data<T> *ls) {

	if ((*ls).itemAmount == 0)
		return 1;
	return 0;

}

template<typename T>
bool edit(Data<T> *ls, T value, int p) {

	if (p < 1 || p >(*ls).itemAmount)
		return 0;

	Item<T> *result = (*ls).head;

	for (int i = 1; i < p; i++)
		result = (*result).next;

	(*result).value = value;

	return 1;

}

template<typename T>
int getSize(Data<T> *ls) {

	return (*ls).itemAmount;

}

template<typename T>
bool insertAt(Data<T> *ls, T value, int p) {

	Item<T> *newItem = new Item<T>;
	if (newItem == 0)
		return 0;
	(*newItem).value = value;
	(*newItem).next = 0;

	if ((*ls).head == 0 || p < 2)
	{
		(*newItem).next = (*ls).head;
		(*ls).head = newItem;
		(*ls).itemAmount++;
		return 1;
	}

	Item<T> *result = (*ls).head;

	for (int i = 2; (*result).next != 0 && i < p; i++)
		result = (*result).next;

	if ((*result).next != 0)
		(*newItem).next = (*result).next;

	(*result).next = newItem;
	(*ls).itemAmount++;

	return 1;

}

template<typename T>
bool insertLast(Data<T> *ls, T value) {

	Item<T> *newItem = new Item<T>;
	if (newItem == 0)
		return 0;
	(*newItem).value = value;
	(*newItem).next = 0;

	if ((*ls).head == 0)
	{
		(*ls).head = newItem;
		(*ls).itemAmount++;
		return 1;
	}

	Item<T> *result = (*ls).head;

	while ((*result).next != 0)
		result = (*result).next;

	//cout<<endl<<(*result).value<<endl;

	(*result).next = newItem;
	(*ls).itemAmount++;

	return 1;

}

template<typename T>
bool deleteAt(Data<T> *ls, int p) {
	if ((*ls).itemAmount < p || p < 1)
		return 0;



	if (p == 1)
	{
		Item<T> *oldHead = (*ls).head;
		(*ls).head = (*(*ls).head).next;
		delete(oldHead);
		(*ls).itemAmount--;
		return 1;
	}

	Item<T> *result = (*ls).head;

	for (int i = 2; i < p; i++)
		result = (*result).next;

	Item<T> *result2 = (*result).next;
	(*result).next = 0;
	delete(result2);
	(*ls).itemAmount--;

	return 1;
}

template<typename T>
bool isFull(Data<T> *ls)
{
	Item<T> *newItem = new Item<T>;
	if (newItem == 0)
		return 1;
	delete(newItem);
	return 0;
}
