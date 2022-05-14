#include <queue>
#include <stack>

#include <iostream>
#define SIZE 7
using namespace std;

// Queue Data structure;
template <typename T>
class Stack
{
    struct node
    {
        T data;
        node *next;

        node()
        {
            data = '\0';
            next = nullptr;
        }

        node(T x)
        {
            data = x;
            next = nullptr;
        }
    };

    node *head;

public:
    stack()
    {
        head = nullptr;
    }

    int empty()
    {
        if (head == NULL)
        {
            return 0;
        }
        return 1;
    }

    void push(T m)
    {
        if (head == nullptr)
        {
            node *newnode = new node(m);
            head = newnode;
        }
        else
        {
            node *newnode = new node(m);
            newnode->next = head;
            head = newnode;
        }
    }

    T pop()
    {
        if (head == nullptr)
        {
            cout << "\nStack is empty!!!" << endl;
        }
        else
        {
            T val;
            node *temp = head;
            val = temp->data;
            head = temp->next;
            delete temp;
            return val;
        }
    }

    void display()
    {
        node *ptr = head;
        while (ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
};
// Queue Data Structure
template <typename X>
class Queue
{
    class Qnode
    {
        X data;
        Qnode *next;

    public:
        Qnode(X x)
        {
            data = x;
            next = NULL;
        }

        friend class Queue;
    };

    Qnode *front, *rear;
    int cnt;

public:
    Queue()
    {
        cnt = 0;
        front = rear = NULL;
    }

    int empty()
    {
        if (cnt == 0)
        {
            return 0;
        }
        return 1;
    }

    void push(X x)
    {
        Qnode *temp = new Qnode(x);
        if (rear == NULL)
        {
            front = rear = temp;
            cnt++;
        }
        else
        {
            rear->next = temp;
            rear = temp;
            cnt++;
        }
    }

    void pop()
    {
        if (cnt == 0)
        {
            cout << "\nQueue is empty!!!" << endl;
        }
        else
        {
            Qnode *temp = front;
            front = temp->next;
            delete temp;
            cnt--;
        }
    }

    X Front()
    {
        return front->data;
    }

    void display()
    {
        Qnode *temp = front;
        while (temp != nullptr)
        {
            cout << " | " << temp->data << " | ";
            temp = temp->next;
        }
    }
};
// For graph
class node
{
    int data;
    node *next;

public:
    node(int x)
    {
        data = x;
        next = NULL;
    }

    friend class graph;
};

class graph
{
    node *vertex[SIZE];

public:
    graph()
    {
        for (int i = 0; i < SIZE; i++)
        {
            vertex[i] = NULL;
        }
    }

    int check1(node *ptr, int data)
    {
        node *p1 = ptr;
        while (p1 = NULL)
        {
            if (p1->data == data)
            {
                return 0;
            }
            p1 = p1->next;
        }
        return 1;
    }

    void insert(int srs)
    {
        int des, td;
        int cnt = 0;
        if (srs < SIZE)
        {
            cout << "\nHow many points you want to add: ";
            cin >> td;
            while (td != cnt)
            {
                cout << "\nEnter the point: ";
                cin >> des;
                node *point = new node(des);

                if (vertex[srs] == NULL)
                {
                    vertex[srs] = point;
                    cnt++;
                }
                else
                {
                    bool b1 = true;
                    node *p = vertex[srs];
                    while (p->next != NULL)
                    {
                        if (p->data == des)
                        {
                            b1 = false;
                            break;
                        }
                        p = p->next;
                    }
                    if (b1)
                    {
                        p->next = point;
                        cnt++;
                    }
                    else
                    {
                        cout << "\nPoint already exist!!!" << endl;
                        delete point;
                    }
                }
            }
        }
        else
        {
            cout << "\nEnter Valid Vertex!!!" << endl;
        }
    }

    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            node *ptr = vertex[i];
            cout << "Vertex: " << i << "-----";
            while (ptr != nullptr)
            {
                cout << " | " << ptr->data << " | "
                     << "---->";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }

    void BFS(int v)
    {
        node *ptr;
        // Queue q;
        queue<int> q;
        int visited[SIZE], w;
        for (int i = 0; i < SIZE; i++)
        {
            visited[i] = 0;
        }
        q.push(v);
        visited[v] = 1;
        cout << "\nVisit: " << v << endl;
        while (!q.empty())
        {
            v = q.front();
            q.pop();
            for (ptr = vertex[v]; ptr != NULL; ptr = ptr->next)
            {
                w = ptr->data;
                if (visited[w] == 0)
                {
                    q.push(w);
                    visited[w] = 1;
                    cout << "\nVisit: " << w << endl;
                }
            }
        }
    }

    void DFS(int v)
    {
        node *ptr;
        int visited[SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            visited[i] = 0;
        }
        int w;
        stack<int> s;
        s.push(v);
        visited[v] = 1;
        // cout << "Top: " << s.top() << endl;
        while (!s.empty())
        {
            w = s.top();
            s.pop();
            cout << "\nVisit: " << w << endl;
            for (ptr = vertex[w]; ptr != NULL; ptr = ptr->next)
            {
                if (visited[ptr->data] == 0)
                {
                    s.push(ptr->data);
                    visited[ptr->data] = 1;
                }
            }
        }
    }
};

int main()
{
    graph g;
    int choice;
    while (1)
    {
        cout << "\n1.To Insert a point .\n2.To Display. \n3.BFS display \n4.DFS display \n5.To Exit!!!" << endl;
        cout << "\nEnter the choice: ";
        cin >> choice;
        if (choice == 1)
        {
            int srs;
            cout << "\nEnter the vertex: ";
            cin >> srs;
            g.insert(srs);
        }
        else if (choice == 2)
        {
            g.display();
        }
        else if (choice == 3)
        {
            int v;
            cout << "\nEnter the start point: ";
            cin >> v;
            g.BFS(v);
        }
        else if (choice == 4)
        {
            int v;
            cout << "\nEnter the start point: ";
            cin >> v;
            g.DFS(v);
        }
        else if (choice == 5)
        {
            break;
        }
    }

    return 0;
}