
struct Node {
	int ID;
	Node* left;
	Node* right;
	Node(int id) { ID = id; left = right = nullptr; }
};

Node* root = nullptr;
int height = 0;

// void insert() i binært søketre
// Bruker globale variable
// @global rot
// @global height
//
void insert(int id) {	
	// 0. Lag rot om den ikke finnes
	if (root == nullptr) {
		root = new Node(id);
		height = 1;
		return;
	}

	// 1. Blar høyre/ventre helt til ledig plass
	Node* it 	  = root;
	Node* parent  = nullptr;
	int   level   = 1;

	while (true) {
		parent = it;
		level++;
		if (id >= it->ID) {
			it = it->right;
			if (it == nullptr)
				parent->right = new Node(id); break;
		}
		else  {
			it = it->left;		
			if (it == nullptr)
				parent->left = new Node(id); break;
		}
	}
	if (level > height) height = level;
}


int main() {

	return 0;
}