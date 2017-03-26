
template <typename T>
struct Item {
	T value;
	Item<T> *next;
};

template <typename T>
struct Data {
	Item<T> *head;
	int itemAmount = 0;
};

template <typename T>
bool insertAt(Data<T> *ls, T value, int p);

template <typename T>
bool insertLast(Data<T> *ls, T value);

template<typename T>
bool deleteAt(Data<T> *ls, int p);

template<typename T>
bool edit(Data<T> *ls, T value, int p);

template<typename T>
int getSize(Data<T> *ls);

template<typename T>
bool isEmpty(Data<T> *ls);

template<typename T>
bool clear(Data<T> *ls);

template<typename T>
T getItem(Data<T> *ls, int p);

template<typename T>
bool isFull(Data<T> *ls);
