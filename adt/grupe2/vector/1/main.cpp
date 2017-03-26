#include <stdlib.h>
#include <iostream>
#include "myVector.h"

using namespace std;

int main()
{
	Data<int> myList;
	int aws = 0;
	int a, p;
	Item<int> *n;

	cout << "1. Insert last" << endl;
	cout << "2. Insert at" << endl;
	cout << "3. Delete at" << endl;
	cout << "4. Edit" << endl;
	cout << "5. Delete list" << endl;
	cout << "6. Get item" << endl;
	cout << "7. Get size" << endl;
	cout << "8. Is vector empty" << endl;
	cout << "0. Exit" << endl;


	while (true)
	{
		cin >> aws;

		switch (aws)
		{
		case 1:
			cin >> a;
			if (!insertLast(&myList, a))
				cout << "Err" << endl;

			break;

		case 2:
			cin >> a >> p;
			if (!insertAt(&myList, a, p))
				cout << "Err" << endl;

			break;

		case 3:
			cin >> p;
			if (!deleteAt(&myList, p))
				cout << "Err" << endl;

			break;

		case 4:
			cin >> a >> p;
			if (!edit(&myList, a, p))
				cout << "Err" << endl;

			break;

		case 5:
			if (!clear(&myList))
				cout << "Err" << endl;

			break;

		case 6:
			cin >> p;
			cout << getItem(&myList, p);

			break;

		case 7:
			cout << getSize(&myList)<<endl;

			break;

		case 8:
			cout << isEmpty(&myList)<<endl;

			break;

		default:
			return 0;


		}
		n = myList.head;

		while((*n).next != NULL)
		{
		cout<<"|"<<(*n).value;
		n = (*n).next;
		}
		cout << "|" << (*n).value<<endl;

		aws = NULL;
	}


	return 0;
}

