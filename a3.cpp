//============================================================================
// Name        : assignment3.cpp
// Author      : Pratham Doke
// Version     : Final
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node
{
    node *left, *right;
    int data;
    bool lb, rb;

public:
    node()
    {
        left = NULL;
        right = NULL;
        data = 0;
        lb = false;
        rb = false;
    }

    node(int m)
    {
        left = NULL;
        right = NULL;
        data = m;
        lb = false;
        rb = false;
    }

    friend class TBT;
};

class TBT
{
    node *header, *Newnode, *root;
    //header will be out dummy node.. which will carry out root node
    //Newnode is the node which will be created for adding data
    //root node is out node... attached to dummy node.. which is header node

public:
    TBT()
    {
    	header = nullptr;
        root = nullptr;
        Newnode = nullptr;
    }

    node *return_node()
    {
        return root;
    }

    void create();
    void insert(node *, node *);

    void display();
    void inOrder(node *, node *);

    void display2();
    void preOrder(node *, node *);


    int check(node *ptr, node *end, int key)
    {
    	bool b1 = false;
    	bool b2 = false;

    	while(ptr != end)
    	{
    			if(ptr->data == key)
    			{
    				return 1;
    			}
    			while(ptr->lb == 1)			//Print all the node.. with left bit value as 1
    			{
    				ptr = ptr->left;
    				if(ptr->data == key)
    				{
    					b1 = true;
    					break;
    				}
    			}
    			if(b1)
    			{
    				return 1;
    			}

    			while(ptr->rb == 0)			//Traverse the node.. until we find a node whose right bit is 1
    			{
    				ptr = ptr->right;

    				if(ptr == end)			//Break condition
    				{
    					b2 = false;
    					break;
    				}
    			}
    			if(b2)
    			{
    				return 1;
    			}

    			ptr = ptr->right;

    }



};



void TBT::create()
{
    int num;
    cout << "\nEnter the data: ";
    cin >> num;
    Newnode = new node(num);        //A node which will be created for storing our data

    if (root == nullptr)            //initial condition while creating a tree
    {
        header = new node(-99);     //creating a header(dummy node)
        header->right = header;
        header->left = header;
        root = Newnode;
        root->left = header;
        root->right = header;
        header->left = root;
        header->lb = 1;
        cout << "\nHeader node and the root is created Successfully!!" << endl;
        cout << "\nYour root node is: " << root->data << endl;
    }
    else
    {
        insert(root, Newnode);
    }
}

void TBT::insert(node *curr, node *new_node)
{
    if (curr->data == new_node->data)           //check if there is same data or not
    {
        cout << "\nCannot insert as value is already present!!" << endl;
    }
    else
    {
        int choice;
        cout << "\nYou are at node: " << curr->data << endl;
        cout << "\n1.Insert at left. \n2.insert at right" << endl;
        cin >> choice;
        if (choice == 1)
        {
            if (curr->lb == 0)
            {
                new_node->left = curr->left; // Root left points toward header
                new_node->right = curr;
                curr->left = new_node;
                curr->lb = 1;
                cout << "\n"
                     << new_node->data << " is now the left child of " << curr->data << endl;
            }
            else
            {
                cout << "\nNode is already present there... moving to next left node..." << endl;
                insert(curr->left, new_node);
            }
        }
        if (choice == 2)
        {
            if (curr->rb == 0)
            {
                new_node->right = curr->right;
                new_node->left = curr;
                curr->right = new_node;
                curr->rb = 1;
                cout << "\n"
                     << new_node->data << " is now the right child of " << curr->data << endl;
            }
            else
            {
                cout << "\nNode is already present there... moving to next right node..." << endl;
                insert(curr->right, new_node);
            }
        }
    }
}

//InOrder display of Threaded Binary Tree
void TBT::display()
{
    if (root == nullptr)
    {
        cout << "\nNo tree is created!!" << endl;
    }
    else
    {
        inOrder(root, header);
    }
}

//Inorder Traversal
void TBT::inOrder(node *a, node *r)
{
    while (a != r)
    {
        while (a->lb == 1)
        {
            a = a->left; // We will go towards the leftmost node in BT
        }

        cout << a->data << "\t"; // Print the left most data

        while (a->rb == 0) // Check for threaded right-link
        {
            a = a->right; // follow the threader link towards right
            if (a == r)
            {
                return; // If out traversing pointer points toward header node
            }

            cout << a->data << "\t";
        }

        a = a->right;
    }
}


//Preorder Display of Threader Binary Tree
void TBT::display2()
{
	if(root == nullptr)
	{
		cout << "\nTree is not created!!!" << endl;
	}
	else
	{
		preOrder(root,header);
	}
}


//PreOrder traversal in TBT
void TBT::preOrder(node *ptr, node *end)
{
	while(ptr != end)
	{
		cout << ptr->data << "\t";
		while(ptr->lb == 1)			//Print all the node.. with left bit value as 1
		{
			ptr = ptr->left;
			cout << ptr->data << "\t";
		}

		while(ptr->rb == 0)			//Traverse the node.. until we find a node whose right bit is 1
		{
			ptr = ptr->right;

			if(ptr == end)			//Break condition
			{
				break;
			}
		}

		ptr = ptr->right;			//When we reach a node with its right bit 1 ... again repeat
									//The same procedure
	}

}
};



int main()
{
    TBT t1;
    int choice;
    char p;
    while (choice != -1)
    {
        cout << "\n1.Create TBT. \n2.Display(InOrder). \n3.Display(PreOrder). \n-1.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            while (p != 'n' && p != 'N')
            {
                t1.create();
                cout << "\nEnter (N or n) to Exit or Press any key to continue: ";
                cin >> p;
            }
        }
        if (choice == 2)
        {
            cout << "\n*******Your In-order Traversal*********" << endl;
            t1.display();
            cout << endl;
        }
        if(choice == 3)
        {
        	cout << "\n*******Your Pre-Order Traversal********" << endl;
        	t1.display2();
        	cout << endl;
        }
        else
        {
        	cout << "\nEnter the right choice" << endl;
        }
    }

    return 0;
}