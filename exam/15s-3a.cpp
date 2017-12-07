


struct Node {
	int ID;
	Node* left;
	Node* right;
	Node (int id, Node* l, Node* r)
		{ ID = id; left = l; right = r; }
};

Node* rot = nullptr;
const int MIN = 0, MAX = 9999;

int findMin(Node* n) {
	if (n == nullptr) return MAX; 

	int min = n->ID;
	int newMin;

	if ( (newMin = findMin(n->left)) < min )
		min = newMin;

	if ( (newMin = findMin(n->right)) < min )
		min = newMin;

	return min;
}

int findMax(Node* n) {
	if (n == nullptr) return MIN; 

	int max = n->ID;
	int newMax;

	if ( (newMax = findMax(n->left)) > max )
		max = newMax;

	if ( (newMax = findMax(n->right)) > max )
		max = newMax;

	return max;
}

int main() {

} 