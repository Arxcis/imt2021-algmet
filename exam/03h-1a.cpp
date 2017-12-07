
#include <iostream>

const int M = 11;

using KeyType  		 = char;
const KeyType KeyNIL = KeyType{};
using ValueType 		  = int;
const ValueType ValueNIL  = ValueType{};

int hash1(int key) { return (key % M); 	   }
int hash2(int key) { return (7 - (key % 7)); }

struct Node {
	KeyType   key{};
	ValueType value{};
};

void insert(Node* a, KeyType key, ValueType value) {

	int x = hash1(key);
	int u = hash2(key);

	// Finn en node som er NIL
	while (a[x].value != ValueNIL) 
		x = (x+u) % M;
	
	// Sett vedi til noden
	a[x].key = key; 
	a[x].value = value;
}

void display(Node* a) {
	for(int i = 0; i < M; ++i) {
		std::cout << "Key: " << a[i].key << "-"<< int(a[i].key) 
				  << "\tValue: " << a[i].value << '\n';
	}
}

int main(){
	const char keys[M+1] = "TEGNESERIER";
	const int  values[M] = {0,1,2,3,4,5,6,7,8,9,10}; 
	Node data[M];

	for(int i = 0; i < M; ++i)
		insert(data, keys[i], values[i]);

	display(data);
}



/*

char T E G N E S E R I E R

*/
