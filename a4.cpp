//============================================================================
// Name        : assignment4.cpp
// Author      : Pratham Doke
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#define size 5
using namespace std;

string convert(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}

class hashdata
{
private:
    long int telephone;
    string name;

public:
    hashdata()
    {
        telephone = 0;
        name = "";
    }

    hashdata(string name, long int contact)
    {
        this->name = name;
        telephone = contact;
    }

    friend class hashtable;
};

class hashtable
{
    hashdata table[size];
    int cnt = 0; // To count the number of element present in the hashtable

public:
    // generate a key
    int hash_key(long int key)
    {
        return key % size;
    }

    // To insert the data without replacement
    void insert(string name, long int contact)
    {

        if (cnt < size)
        {
            int collisons = 0;
            hashdata obj(name, contact);
            int h_code = hash_key(contact);
            int start = h_code;
            if (table[h_code].telephone != 0)
            {

                while (table[h_code].telephone != 0)
                {
                    h_code++;
                    collisons++;
                    if (h_code == size)
                    {
                        h_code = 0;
                    }
                    if (h_code == start)
                    {
                        cout << "\nTable is Full" << endl;
                        break;
                    }
                }

                table[h_code] = obj;
                cnt++;
                cout << "\nData entered successfully!!!" << endl;
                cout << "Total collisions: " << collisons << endl;
            }
            else
            {
                table[h_code] = obj;
                cnt++;
                cout << "\nData entered successfully!!!" << endl;
                cout << "Total collisions: " << collisons << endl;
            }
        }
        else
        {
            cout << "\nHash Table is full!!!" << endl;
        }
    }

    // To insert the element with replacement
    void insert_replace(string name, long int contact)
    {

        if (cnt < size)
        {
            hashdata temp;             // This will store the previously presented data
            hashdata h(name, contact); // New data to be inserted

            int hcode = hash_key(contact);
            int start = hcode;
            int pre_code; // To store the hascode of the already present data
            int collisions = 0;

            if (table[hcode].telephone != 0)
            {
                int b1 = true;
                pre_code = hash_key(table[hcode].telephone);
                if (pre_code == hcode)
                {
                    while (table[hcode].telephone != 0)
                    {
                        hcode++;
                        collisions++;
                        if (hcode == size)
                        {
                            hcode = 0;
                        }
                        if (hcode == start)
                        {
                            cout << "\nTable is Full" << endl;
                            b1 = false;
                            break;
                        }
                    }

                    if (b1)
                    {
                        table[hcode] = h;
                        cnt++;
                        cout << "\nData successfully inserted" << endl;
                        cout << "\nCOLLISION: " << collisions << endl;
                    }
                }
                else
                {
                    int b1 = true;
                    temp = table[hcode];
                    table[hcode] = h;
                    while (table[hcode].telephone != 0)
                    {
                        hcode++;
                        collisions++;
                        if (hcode == size)
                        {
                            hcode = 0;
                        }
                        if (hcode == start)
                        {
                            cout << "\nTable is Full!!" << endl;
                            b1 = false;
                            break;
                        }
                    }
                    if (b1)
                    {
                        table[hcode] = temp;
                        cnt++;
                        cout << "\nData successfully inserted" << endl;
                        cout << "\nCOLLISION: " << collisions << endl;
                    }
                }
            }
            else
            {
                table[hcode] = h;
                cnt++;
                cout << "\nData successfully inserted" << endl;
            }
        }
        else
        {
            cout << "\nHashTable is full!!!" << endl;
        }
    }

    // To search the element
    void search(long int key)
    {
        int cmp = 1;
        int code = hash_key(key);
        int start = code;
        bool b1 = true;
        if (table[code].telephone == key)
        {
            cout << code << "\t"
                 << "Telephone number: " << table[code].telephone << "\t"
                 << "Name: " << table[code].name << endl;
            cout << "Number of comparisions: " << cmp << endl;
        }
        else
        {
            while (table[code].telephone != key)
            {
                code++;
                cmp++;
                if (code == size)
                {
                    code = 0;
                }
                if (code == start)
                {
                    b1 = false;
                    break;
                }
            }
            if (b1)
            {
                cout << code << "\t"
                     << "Telephone number: " << table[code].telephone << "\t"
                     << "Name: " << table[code].name << endl;
                cout << "Number of comparisions: " << cmp << endl;
            }
            else
            {
                cout << "\nNo Such Telephone number Exist!!!" << endl;
            }
        }
    }

    // Displays all the data
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i].telephone != 0)
            {
                cout << i << "----->" << table[i].telephone << "  :  " << table[i].name << endl;
            }
        }
    }
};

int main()
{

    long int key;
    string name;
    int choice;
    hashtable h1; // For insertion without replacement
    hashtable h2; // For insertion with replacement

    while (true)
    {
        // hashdata *h = new hashdata();
        hashdata obj;
        cout << "\n1.To insert without replacement. \n2.To insert with replacement \n3.To display all the data .\n4.To search. \n-1.To exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "\nEnter the contact number: ";
            cin >> key;
            cout << "Enter the name of the person: ";
            cin >> name;
            name = convert(name);
            h1.insert(name, key);
        }
        if (choice == 2)
        {
            cout << "\nEnter the contact number: ";
            cin >> key;
            cout << "Enter the name of the person: ";
            cin >> name;
            name = convert(name);
            h2.insert_replace(name, key);
        }
        if (choice == 3)
        {
            cout << "\n****HashTable (Without replacement)" << endl;
            h1.display();
            cout << "\n****HashTable (With Replacement)" << endl;
            h2.display();
        }
        if (choice == 4)
        {
            cout << "\nSearch in which Table" << endl;
            cout << "\n1.HashTable (Without Replacement)" << endl;
            cout << "2.HashTable (With Replacement)" << endl;
            cin >> key;
            if (key == 1)
            {
                cout << "\nEnter the key to be searched: ";
                cin >> key;
                h1.search(key);
            }
            if (key == 2)
            {
                cout << "\nEnter the key to be searched: ";
                cin >> key;
                h2.search(key);
            }
        }
        if (choice == -1)
        {
            cout << "\nProgram Exited Successfully!!" << endl;
            break;
        }
    }

    return 0;
}