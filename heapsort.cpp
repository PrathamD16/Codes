#include <iostream>
using namespace std;

class minheap
{
    int size;
    int *arr;

public:
    minheap()
    {
        size = 0;
        arr = new int[size];
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }
    int getMin()
    {
        return arr[0];
    }

    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < size && arr[l] < arr[smallest])
        {
            smallest = l;
        }
        if(r < size && arr[r] < arr[smallest])
        {
            smallest = r;
        }
        if(smallest != i)
        {
            swap(arr[i],arr[smallest]);
            heapify(smallest);
        }
    }


    int extract()
    {
        if(size<0)
        {
            return 9999999;
        }
        if(size == 1)
        {
            size--;
            return arr[0];
        }
        else
        {
            int val = arr[0];
            arr[0] = arr[size-1];
            size--;
            heapify(0);
            return val;
        }
    }


    void insert(int x)
    {
        size++;
        int i = size - 1;
        arr[i] = x;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void display()
    {
        for(int i = 0; i < size; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }

    void sort()
    {
        int temp[5];
        cout << "[  ";
        for(int i = 0; i < 5; i++)
        {
            temp[i] = extract();
            cout << temp[i] << "  ";
        }
        cout << "  ]" << endl;
    }
};

int main()
{
    minheap m;
    m.insert(10);
    m.insert(26);
    m.insert(-5);
    m.insert(1);
    m.insert(6);
    m.insert(-990);
    m.display();
    m.sort();

    return 0;
}