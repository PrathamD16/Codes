/*
    Name: Pratham Doke
    Roll no: 21125
    SE1 F1
*/

#include <iostream>
#define SIZE 10
using namespace std;

class node
{
    long int key;
    string name;
    node *next;

public:
    node()
    {
        key = 0;
        name = "HEADER";
        next = nullptr;
    }

    node(long int key, string name)
    {
        this->key = key;
        this->name = name;
        next = nullptr;
    }

    friend class dictionary;
};

class dictionary
{
    node *arr_headers[SIZE];

public:
    // Allocation space for header nodes
    //Basically all the header nodes will be empty nodes
    dictionary()
    {
        for (int i = 0; i < SIZE; i++)
        {
            arr_headers[i] = new node();
        }
    }

    // A hash function
    int hash_function(long int key)
    {
        return key % SIZE;
    }

    // To insert new data in the hashtable
    void insert(long int key, string name)
    {
        int hcode = hash_function(key);
        node *obj = new node(key, name);
        node *curr = arr_headers[hcode];
        while (curr->next != nullptr)
        {
            if (curr->key == key)
            {
                cout << "\nDuplicate data inserted!!!" << endl;
                delete obj;
                return;
            }
            curr = curr->next;
        }
        if (curr->key == key) // Exception only for the lastmost node of chain.. if there are same key value
        {
            cout << "\nDuplicate data inserted!!!" << endl;
            delete obj;
            return;
        }
        else
        {
            curr->next = obj;
        }
    }

    // To search for the element in the hashtable
    void search(long int key)
    {
    	int cmp = 0;
        int code = hash_function(key);
        node *ptr = arr_headers[code];
        bool b1 = true;
        while (ptr != NULL)
        {
            if (ptr->key == key)
            {
                cout << "\nKEY: " << ptr->key << "----" << ptr->name << endl;
                cout << "Number of comparisions: " << cmp << endl;
                b1 = false;
                break;
            }
            ptr = ptr->next;
            cmp++;
        }
        if (b1)
        {
            cout << "\nNo data was found in the table" << endl;
        }
    }

    // To check the element present in the hashtable or not
    int check(long int key)
    {
        int code = hash_function(key);
        node *ptr = arr_headers[code];
        bool b1 = true;
        while (ptr != NULL)
        {
            if (ptr->key == key)
            {
                return 1;
            }
            ptr = ptr->next;
        }
        if (b1)
        {
            return 0;
        }
    }

    void delete_data(long int key)
    {
        if (check(key))
        {
            int code = hash_function(key);
            node *ptr = arr_headers[code]->next;
            node *pre = arr_headers[code];
            while(ptr->key != key)
            {
                ptr = ptr->next;
                pre = pre->next;
            }
            pre->next = ptr->next;
            delete ptr;
            cout << "\nData deleted successfully!!!" << endl;
        }
        else
        {
            cout << "\nNo such data found to delete the element!!!" << endl;
        }
    }

    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            node *curr = arr_headers[i];
            cout << "ROW: " << i << "\t---->>>";
            while (curr != nullptr)
            {
                cout << "| " << curr->key << "  " << curr->name << " |--->";
                curr = curr->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    dictionary d1;
    int choice;
    while (true)
    {
        // hashdata *h = new hashdata();
        cout << "\n1.To insert new data \n2.To seaach data \n3.To delete data.\n4.Display All" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            string name;
            long int key;
            cout << "\nEnter the number: ";
            cin >> key;
            cout << "Enter the name: ";
            cin.ignore();
            getline(cin, name);
            d1.insert(key, name);
        }
        if (choice == 2)
        {
            long int search;
            cout << "Enter the key: ";
            cin >> search;
            d1.search(search);
        }
        if (choice == 3)
        {
            long int key;
            cout << "\nEnter the key to be deleted: ";
            cin >> key;
            d1.delete_data(key);
        }
        if (choice == 4)
        {
            cout << endl;
            d1.display();
        }
        if (choice == -1)
        {
            cout << "\nProgram Exited Successfully!!" << endl;
            break;
        }
    }
    return 0;
}