// Pratham Doke... SE-1... Rollno:- 21125
// Assignent 2:- BST
#include <iostream>
#include <string>
using namespace std;

// To avoid case issue while searching as well as while storing data
string convert(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

struct node // Structure of node
{
    string data, meaning;
    node *left, *right;

    node()
    {
        data = "";
        meaning = "";
        left = NULL;
        right = NULL;
    }
};

class bst
{
    node *root;

public:
    bst()
    {
        root = nullptr;
    }

    node *return_node()
    {
        return root;
    }

    // To insert data in the tree
    // Inserting a node.. according to the value which is entered
    void insert(node *newnode)
    {

        string mean;
        if (root == NULL)
        {
            root = newnode;
            cout << "Enter meaning: ";
            // cin.ignore();
            getline(cin, mean);
            newnode->meaning = mean;
            cout << "\nData added successfully!!" << endl;
            // cout << "\nRoot Created Successfully" << endl;
        }
        else
        {
            node *temp = root; // Traversing Node
            while (true)
            {
                if (temp->data == newnode->data)
                {

                    cout << "\nDuplicate data entered!!" << endl;
                    delete newnode;
                    break;
                }
                if (newnode->data < temp->data && temp->left == nullptr)
                {
                    temp->left = newnode;
                    cout << "Enter the meaning: ";
                    // cin.ignore();
                    getline(cin, mean);
                    newnode->meaning = mean;
                    cout << "\nData added successfully!!" << endl;
                    break;
                }
                if (newnode->data > temp->data && temp->right == nullptr)
                {
                    temp->right = newnode;
                    cout << "Enter the meaning: ";
                    // cin.ignore();
                    getline(cin, mean);
                    newnode->meaning = mean;
                    cout << "\nData added successfully!!" << endl;
                    break;
                }
                if (newnode->data > temp->data && temp->right != nullptr)
                {
                    temp = temp->right;
                }
                if (newnode->data < temp->data && temp->left != nullptr)
                {
                    temp = temp->left;
                }
            }
        }
    }

    // Search and find the word in the tree
    // Code is similar to binary search used in finding element in an array
    // As data are sorted according to values in bst.. Binary search is best method to search an
    // element in the tree..
    void search_word(node *r, string word)
    {
        int count = 1;
        if (r == nullptr)
        {
            cout << "Create Tree first" << endl;
        }
        else
        {
            bool b1 = true;
            node *ptr = r;
            while (ptr != nullptr)
            {
                if (ptr->data == word)
                {
                    cout << "\nYour word: " << word << endl;
                    cout << "Meaning: " << ptr->meaning << endl;
                    cout << "\nNumber of comparision: " << count << endl;
                    b1 = false;
                    count = 0;
                    break;
                }
                if (word < ptr->data)
                {
                    ptr = ptr->left;
                    count++;
                }
                else
                {
                    ptr = ptr->right;
                    count++;
                }
            }
            if (b1)
            {
                cout << "\nNo word exists in the dictionary!!!" << endl;
                cout << "Total Number of comparison: " << count << endl;
                count = 0;
            }
        }
    }

    // Update the meaning of the word
    // Function used is searching method..
    void update(node *r, string word)
    {
        if (r == nullptr)
        {
            cout << "Create Tree first" << endl;
        }
        else
        {
            string mean;
            bool b1 = true;
            node *ptr = r;
            while (ptr != nullptr)
            {
                if (ptr->data == word)
                {
                    cout << "\n**Your Word Found**" << endl;
                    cout << "\nCurrent Meaning: " << ptr->meaning << endl;
                    cout << "\nEnter the new meaning of the word" << endl;
                    getline(cin, mean);
                    ptr->meaning = mean;
                    cout << "\nMeaning of the word, updated successfully!!!" << endl;
                    b1 = false;
                    break;
                }
                if (word < ptr->data)
                {
                    ptr = ptr->left;
                }
                else
                {
                    ptr = ptr->right;
                }
            }
            if (b1)
            {
                cout << "\n****No word exist in the dictionary!!****" << endl;
            }
        }
    }

    // Code for inorder traversal...
    // Which display BST in ascending order
    void ascending_order(node *r)
    {
        if (r == nullptr)
        {
            return;
        }
        else
        {
            ascending_order(r->left);
            cout << r->data << "::" << r->meaning << endl;
            ascending_order(r->right);
        }
    }

    // A switch function, basically we can make mirror image of binary tree and display in inorder traversal
    // So we can get our data printed in descending order
    void mirror(node *r)
    {
        if (r == nullptr)
        {
            return;
        }
        else
        {
            node *temp = r->left;
            r->left = r->right;
            r->right = temp;
            mirror(r->right);
            mirror(r->left);
        }
    }

    // A function which returns the node address which has lowest value in bst
    node *minFunction(node *r)
    {
        node *temp = r;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp;
    }

    // A function which return the node address which has highest value in bst
    node *maxFunction(node *r)
    {
        node *temp = r;
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        return temp;
    }

    //*****************To check the existence of searched word in the dictionary
    int check_word(node *r, string word)
    {
    	int count = 1;
        node *ptr = root;
        while (ptr != nullptr)
        {
            if (ptr->data == word)
            {
            	cout << "\nNumber of comparision: " << count << endl;
                return 1;
            }
            if (word < ptr->data)
            {
                ptr = ptr->left;
                count++;
            }
            else
            {
                ptr = ptr->right;
                count++;
            }
        }

        return 0;
    }

    //*********

    // ********************************To delete a node in BST.
    node *deleteNode(node *r, string value)
    {
        node *temp;
        if (r == NULL)
        {
            return r;
        }
        else if (value < r->data)
        {
            r->left = deleteNode(r->left, value);
        }
        else if (value > r->data)
        {
            r->right = deleteNode(r->right, value);
        }
        else
        {
            if (r->left == NULL)
            {
                temp = r->right;
                delete r;
                return temp;
            }
            if (r->right == NULL)
            {
                temp = temp->left;
                delete r;
                return temp;
            }
            else
            {
                temp = minFunction(r->right);
                r->data = temp->data;
                r->right = deleteNode(r->right, temp->data);
            }
        }

        return r;
    }

    // Actual delete function.. which will delete the given data's node
    void delete_a_word(node *r, string word)
    {
        if (check_word(r, word))
        {
            if(root->data == word && root->left == NULL && root->right == NULL)
            {
                node *temp = root;
                delete temp;
                root = nullptr;
            }
            else
            {
                deleteNode(r, word);
            }

            cout << "\nWord deleted Successfully!!!" << endl;

        }
        else
        {
            cout << "\nNo such word found in the dictionary!!!" << endl;
        }
    }
};

int main()
{
    bst b1;
    int option, p;
    string search;
    string val, mean;

    while (option != -1)
    {

        node *newnode = new node();
        cout << "\n1.Add a word.\n2.Search \n3.Display all Data in Ascending Order \n4.Display all Data in Descending Order." << endl;
        cout << "5.Update a word. \n6.Delete a word \n-1.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        if(option == -1){
        	break;
        }
        switch (option)
        {
        case 1:
            cout << "\nEnter the word: ";
            cin.ignore();
            getline(cin, val);
            val = convert(val);
            newnode->data = val;
            b1.insert(newnode);
            break;

        case 2: // Searching a word in dicitonary
            if (b1.return_node() == nullptr)
            {
                cout << "\nNo data Exists in the tree" << endl;
            }
            else
            {
                cout << "\nEnter the word you want to search: ";
                cin.ignore();
                getline(cin, search);
                search = convert(search);
                b1.search_word(b1.return_node(), search);
            }

            break;
        case 3: // Ascending order
            if (b1.return_node() == nullptr)
            {
                cout << "\nNo data exist in the tree to be displayed!!" << endl;
            }
            else
            {
                cout << "\n*****YOUR DATA**********" << endl;
                b1.ascending_order(b1.return_node());
            }
            break;

        case 4: // Descending Order

            if (b1.return_node() == nullptr)
            {
                cout << "\nNo data exist in the tree be displayed!!" << endl;
            }
            else
            {
                cout << endl;
                cout << "\n******YOUR DATA**********" << endl;
                b1.mirror(b1.return_node());
                b1.ascending_order(b1.return_node());
                b1.mirror(b1.return_node());
            }
            break;

        case 5: // Updating a word

            if (b1.return_node() == nullptr)
            {
                cout << "\nNo data exist in the tree to be displayed!!" << endl;
            }
            else
            {
                cout << "\nEnter the word to be searched and update it's meaning: ";
                cin.ignore();
                getline(cin, search);
                search = convert(search);
                b1.update(b1.return_node(), search);
                break;
            }
        case 6: // Deleting a word.

        if(b1.return_node() != nullptr)
        {
            cout << "\nEnter a word to be deleted: ";
            cin.ignore();
            getline(cin, search);
            search = convert(search);
            b1.delete_a_word(b1.return_node(), search);

        }
        else
        {
            cout << "\nNo data exist in the tree to be displayed!!" << endl;
        }
            break;

        default:
            cout << "\nInvalid Choice!!!" << endl;
        }
    }
    cout << "\nProgram Exited Successfully!!" << endl;

    return 0;
}