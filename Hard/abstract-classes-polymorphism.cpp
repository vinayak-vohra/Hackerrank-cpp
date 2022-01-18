/**
 * @file abstract-classes-polymorphism.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem
 */

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int value;
    int key;
    Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val){};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache
{

protected:
    map<int, Node *> mp;            //map the key to the node in the linked list
    int cp;                         //capacity
    Node *tail;                     // double linked list tail pointer
    Node *head;                     // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0;       //get function
};

class LRUCache : public Cache
{
public:
    // global node counter
    static int counter;
    // Constructor
    LRUCache(int capactiy)
    {
        this->cp = capactiy;            // initialise capacity
        this->head = this->tail = NULL; // initialise pointers
    }

    // Set function
    void set(int, int);

    // Get function
    int get(int);

    // Print
    void print();
};

// Class member definition
int LRUCache::counter = 0;

void LRUCache::set(int key, int value)
{
    // Case 1: Empty list
    if (!counter)
    {
        counter++;
        Node *node = new Node(key, value); // create a node
        this->head = this->tail = node;    // point to node
    }
    // Case 2: Capacity is 1
    else if (this->cp == 1)
    {
        Node *temp = this->head->next;     // temp points to node
        Node *node = new Node(key, value); // create new node
        this->head = this->tail = node;    // point to new node
        delete temp;                       // free temp variable
    }
    else
    {
        bool hit = false;
        // Case 3: Cache hit
        Node *temp = this->head;
        while (temp != NULL && !hit)
        {

            if (temp->key == key)
            {
                hit = true;
                if (temp == this->head)
                {
                    temp->value = value;
                }

                else
                {
                    (temp->prev)->next = temp->next;

                    if (temp == this->tail)
                    {
                        this->tail = temp->prev;
                    }
                    else
                    {
                        (temp->next)->prev = temp->prev;
                    }

                    temp->next = head;
                    head->prev = temp;
                    temp->prev = NULL;
                    this->head = temp;
                    temp->value = value;
                }
            }
            temp = temp->next;
        }

        if (!hit)
        {
            // Case 4: Cache miss
            Node *node = new Node(NULL, this->head, key, value); // create a node
            (this->head)->prev = node;
            this->head = node; // shift head to start

            // Check if capacity reached
            if (counter == this->cp)
            {
                // Delete last node;
                Node *t = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete t;
            }
            else
            {
                counter++;
            }
        }
    }
    // this->print();
}

int LRUCache::get(int key)
{
    Node *t = this->head;
    int val = -1;
    while (t != NULL)
    {
        if (t->key == key)
        {
            val = t->value;
            break;
        }
        t = t->next;
    }
    return val;
}

int main()
{
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "get")
        {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set")
        {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
