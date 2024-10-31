#include <iostream>
#include <limits>
#include <math.h>

using namespace std;

class Node 
{
    public:
        int value;
        Node* next;
    
        Node(int value)
        {
            this->value = value;
            next = nullptr;
        }
};

class SinglyLinkedList
{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        SinglyLinkedList()
        {
            head = nullptr;
            tail = nullptr;
            length = 0;
        };

        SinglyLinkedList(int value)
        {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~SinglyLinkedList()
        {
            Node* temp = head;

            while(temp != nullptr)
            {
                temp = temp->next;
                delete head;
                head = temp;
            }
        }

        int getLength() { return length; }
        Node* getHead() { return head; } 
        Node* getTail() { return tail; }

        void display()
        {
            Node* temp = head;

            cout << "---------Nodes-value------------" << endl;

            while(temp != nullptr)
            {
                cout << temp->value << endl;
                temp = temp->next;
            }

            cout << "--------------------------------" << endl;
        }

        void recursiveDisplay(Node* temp)
        {
            if(temp != nullptr)
            {
                cout << temp->value << endl;
                recursiveDisplay(temp->next);
            }
        }

        void create(int* array, int arraySize)
        {
            Node* temp = new Node(array[0]);
            length = 1;

            head = temp;
            tail = head;

            for(int i = 1; i < arraySize; i++)
            {
                Node* current = new Node(array[i]);
                tail->next = current;
                tail = current;
                length++;
            }
        }

        int countNodes()
        {
            Node* temp = head;
            int count = 0;

            if(length > 0)
            {
                while(temp != nullptr)
                {
                    count++;
                    temp = temp->next;
                }
            }

            return count;
        }

        int sumOfNodesValue()
        {
            Node* temp = head;
            int sum = 0;

            if(length > 0)
            {
                while(temp != nullptr)
                {
                    sum += temp->value;
                    temp = temp->next;
                }
            }

            return sum;
        }

        int maxElement()
        {
            Node* temp = head;

            if(length <= 0)
                return 0;
            else
            {
                int maxValue = head->value;
                while(temp != nullptr)
                {
                    if(temp->value > maxValue)
                        maxValue = temp->value;
                    temp = temp->next;
                }
                return maxValue;
            }
        }

        int linearSearch(int key)
        {
            Node* temp = head;
            
            while(temp != nullptr)
            {
                if(temp->value == key)
                {
                    int change = temp->value;
                    temp->value = head->value;
                    head->value = change;
                    return key;
                }
                temp = temp->next;
            }

            return INT_MIN;
        }

        void append(int value)
        {
            Node* temp = new Node(value);

            if(head == nullptr)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }

            length++;
        }

        void prepand(int value)
        {
            Node* temp = new Node(value);

            if(head == nullptr)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                temp->next = head;
                head = temp;
            }
            length++;
        }

        void insert(int value, int index)
        {
            if(index > length)
                return;

            if(index == 0)
                prepand(value);
            else if(index == length) 
                append(value);
            else
            {
                Node* newNode = new Node(value);
                Node* temp = head;
                int i = 1;

                while(i != index)
                {
                    temp = temp->next;
                    i++;
                }

                newNode->next = temp->next;
                temp->next = newNode;
            }
            length++;
        }

        void delte(int index)
        {
            if(index < 0 || index >= length)
                return;
            
            Node* temp = head;
            Node* nodeToDelete = head;

            for(int i = 0; i < index; i++)
            {
                temp = nodeToDelete;
                nodeToDelete = nodeToDelete->next;
            }

            if(index == 0)
                head = temp->next;
            
            if(index == length - 1)
                tail = temp;
            
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
        }

};



int main()
{
    int anArray[] = {1, 2, 3, 4, 5};
    int sizeOfArray = 5;

    SinglyLinkedList* mySLL = new SinglyLinkedList;
    SinglyLinkedList* secondList = new SinglyLinkedList();

    mySLL->create(anArray, sizeOfArray);
    //cout << mySLL->linearSearch(5) << endl;
    mySLL->display();

    mySLL->delte(0);

    mySLL->display();

    cout << mySLL->getHead()->value << endl;
    cout << mySLL->getTail()->value << endl;

    return 0;
}