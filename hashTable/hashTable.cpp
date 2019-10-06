#include <iostream>
#include <string>

unsigned long hash(std::string str) {
	unsigned long hashed = 0;

	for (size_t it = 0; it < str.size(); ++it) {
		hashed += int(str[it]);
	}

	return hashed;
}

template<typename K, typename V>
class HashNode {
public:
	V value;
	K key;

	HashNode(K key, V value) {
		this->key = key;
		this->value = value;
	}
};

template<typename K,  typename V>
class HashMap {
private:
	// hash element array
	HashNode<K, V>** arr;
	int capacity;
	// current size
	int size;
	// dummy node -1
	HashNode<K, V>* dummy;

public:
	HashMap() {
		// set initial capacity of hash array
		this->capacity = 20;
		this->size = 0;
		arr = new HashNode<K, V>* [capacity];

		// initialize all the elements of the HashNode array
		for (size_t it = 0; it < capacity; ++it) {
			arr[it] = NULL;
		}

		// create a dummy HashNode with key-value pair -1, and -1, resembles a deleted element
		dummy = new HashNode<K, V>(-1, -1);
	}

	// hash function
	long hashCode(K key) {
		return key % this->capacity;
	}

	void insertNode(K key, V value) {
		HashNode<K, V>* temp = new HashNode<K, V>(key, value);

		// apply hash function to the key, with this we determine the index of the specific value in the HashNode array
		int hashIndex = hashCode(key);

		// find the next free space
		while (arr[hashIndex] != NULL && arr[hashIndex]->key != key && arr[hashIndex]->key != -1) {
			hashIndex++;
			hashIndex %= capacity;
		}

		if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1) {
			this->size++;
			arr[hashIndex] = temp;
		}
	}

	V deleteNode(int key) {
		// apply hash function to find the index of the value
		int hashIndex = hashCode(key);

		while (arr[hashIndex] != NULL) {
			if (arr[hashIndex]->key == key) {
				HashNode<K, V>* temp = arr[hashIndex];

				arr[hashIndex] = dummy;

				size--;
				return temp->value;
			}

			hashIndex++;
			hashIndex %= capacity;
		}

		return NULL;
	}

	V get(int key) {
		// apply the hash function to find the index of the value
		int hashIndex = hashCode(key);

		int counter = 0;

		while (arr[hashIndex] != NULL) {
			if (counter++ > capacity) {
				return NULL;
			}

			if (arr[hashIndex]->key == key) {
				return arr[hashIndex]->value;
			}

			hashIndex++;
			hashIndex %= capacity;
		}

		return NULL;
	}

	int sizeofMap() {
		return this->size;
	}

	bool isEmpty() {
		return this->size == 0;
	}

	void display()
	{
		for (int i = 0; i < capacity; i++)
		{
			if (arr[i] != NULL && arr[i]->key != -1)
				std::cout << "key = " << arr[i]->key
				<< "  value = " << arr[i]->value << std::endl;
		}
	}
};

int main() {
	using namespace std;

	HashMap<int, int>* h = new HashMap<int, int>;
	h->insertNode(1, 1);
	h->insertNode(2, 2);
	h->insertNode(2, 3);
	h->display();
	cout << h->sizeofMap() << endl;
	cout << h->deleteNode(2) << endl;
	cout << h->sizeofMap() << endl;
	cout << h->isEmpty() << endl;
	cout << h->get(2);

	return 0;
}
