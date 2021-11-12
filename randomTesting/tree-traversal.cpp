/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
using namespace std;

class BST
{
private:
	int data;
	BST *left, *right, *m_parent;

public:
	// Default constructor.
	BST();

	// Parameterized constructor.
	BST(int, BST* = NULL);

	// Insert function.
	BST* Insert(BST*, int, BST* = NULL);

	// Inorder traversal.
	void InorderS2L(BST*);
	void InorderL2S(BST*);

	// Search by key
	BST* search(int key);

	// Sibling search
	BST* getSibling();

	// Getter functions
	int getValue() const{return data;}
	BST* getRightChild() const{return right;}
	BST* getLeftChild() const{return left;}

	// Overload for insertion operator for ease of access
	friend ostream& operator<<(ostream& out, const BST& bst);
};

ostream& operator<<(ostream& out, const BST& bst){
	out << bst.data;
	return out;
}

// Default Constructor definition.
BST ::BST()
	: data(0)
	, left(NULL)
	, right(NULL)
	, m_parent(NULL)
{
}

// Parameterized Constructor definition.
BST ::BST(int value, BST* parent)
{
	data = value;
	left = right = NULL;
	m_parent = parent;
}

// Insert function definition.
BST* BST ::Insert(BST* root, int value, BST* parent)
{
	if (!root)
	{
		// Insert the first node, if root is NULL.
		return new BST(value, parent);
	}

	// Insert data.
	if (value > root->data)
	{
		// Insert right node data, if the 'value'
		// to be inserted is greater than 'root' node data.

		// Process right nodes.
		root->right = Insert(root->right, value, root);
	}
	else
	{
		// Insert left node data, if the 'value'
		// to be inserted is greater than 'root' node data.

		// Process left nodes.
		root->left = Insert(root->left, value, root);
	}

	// Return 'root' node, after insertion.
	return root;
}

// Inorder traversal function.
// This gives data in sorted order.
void BST ::InorderS2L(BST* root)
{
	if (!root) {
		return;
	}
	InorderS2L(root->left);
	cout << root->data << endl;
	InorderS2L(root->right);
}

void BST ::InorderL2S(BST* root)
{
	if (!root) {
		return;
	}
	InorderL2S(root->right);
	cout << root->data << endl;
	InorderL2S(root->left);
}

BST* BST::search(int key){
	if(key == data)
		return this;
	else if(key < data)
		return left ? left->search(key) : NULL;
	else
		return right ? right->search(key) : NULL;
}

BST* BST::getSibling(){
	if(m_parent){
		if(m_parent->right == this && m_parent->left)
			return m_parent->left;
		else if(m_parent->left == this && m_parent->right)
			return m_parent->right;
	}

	return NULL;
}

// Driver code
int main()
{
	BST b, *root = NULL;
	root = b.Insert(root, 1);
	b.Insert(root, 0);
	b.Insert(root, 2);

	cout << "Root node value: " << *root << endl;
	cout << "Left child value: " << *(root->getLeftChild()) << endl;
	cout << "Right child value: " << *(root->getRightChild()) << endl;
	cout << "Finding sibling of left child..." << endl;

	BST* test = root->search(0);
	BST* testSibling = test->getSibling();

	if(testSibling)
		cout << "The value of the left child's sibling is " << *testSibling << endl;
	else
		cout << "There is no sibling" << endl;

	return 0;
}

// This code is contributed by pkthapa


