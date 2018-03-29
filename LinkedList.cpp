/*
 * LinkedList.cpp
 *
 *  Created on: Jan 25, 2018
 *      Author: fumelody
 */

#include <iostream>

using namespace std;

struct Node{
	int number;
	struct Node *next;
};

struct Node *tailer;
struct Node *head1 = NULL;
struct Node *prev1 = NULL;
struct Node *current1 = NULL;
struct Node *current;
int flag = 0;

int swap(struct Node *temp1, struct Node *temp2)
{
	int count = 0;
	struct Node *p1;

	if (temp1 == NULL)
	{
		return 0;
	}
	if (flag == 1)
	{
		flag = 0;
		return 0;
	}

	if ((temp1->number) < (temp2->number))
	{
		p1 = temp1;
		temp1 = temp1->next;
		tailer->next = p1;
		p1 ->next = NULL;
		tailer = p1;
		if(temp1->next == NULL)
		{
			temp2 = tailer;
		}
		else
		{
			temp2 = temp1->next;
		}
	}
	else
	{
		temp2 = temp2->next;
		if (temp2 == NULL)
		{
			current1 = temp1;

			if(head1 == NULL)
			{
				head1 = current1;
			}
			else
			{
				prev1->next = current1;
			}
			current1->number = temp1->number;
			prev1 = current1;

			if((temp1->next)->next == NULL)
			{
				flag = 1;
			}
			else
			{
				temp1 = temp1->next;
				temp2 = temp1->next;
				current1->next = NULL;
	 		}
		}
	}
	return swap(temp1, temp2);

}

//print the all the input node
int traversalnode(struct Node *temp)
{
	struct Node *current;
	int count = 0;
	current  = new Node;

	if (temp == NULL)
		cout << "No data enter.\n" << endl;
	else
		current = temp;
		while (current != NULL)
		{
			count = count + 1;
				cout << count << " node number is " << current->number << "\n";
			current = current->next;
		}
	count = 0;

	return 0;
}

int main()
{
	int tmp_number = 0;
	struct Node *head = NULL;
	struct Node *current;
	struct Node *prev;
	int nodeLen = 0;
	int len=0;

//user define the array length
	cout << "Please input the linked list length(note: the length must be at lease 10): ";
	while(1)
	{
		while(cin >> len)
		{
			nodeLen = len;
			while (cin.peek() == ' ')
			{
				cin.get();
			}
			if(cin.peek() == '\n')
			{
				break;
			}
		}
		if((nodeLen <=0) || (nodeLen < 10))
		{
			cout << "Please input the right linked list length(note: the length must be at lease 10): ";
		}
		else
		{
			break;
		}
	}
	cout << "linked list length is: " << nodeLen << '\n';

//input numbers
	cout << "Please input random numbers(using space to represent different number and return represent finishing inputing): ";
	while(cin >> tmp_number)
	{
		current = new Node;               //create a new Node

		if(head == NULL)
		{
			head = current;
		}
		else
		{
			prev->next = current;
		}

		current->number = tmp_number;
		current->next = NULL;

		prev = current;
		while (cin.peek() == ' ')
		{
			cin.get();
	    }
		if (cin.peek() == '\n')
		{
			tailer = current;
			break;
		}

	}
	cout << "\n";

//print all the input node
	cout << "Here is the original order traversal: " << endl;
	traversalnode(head);
	cout << "\n" << endl;

//sort the linked list
	swap(head, head->next);

//print all the sorted node
	cout << "Here is the descending order traversal: " << endl;
	traversalnode(head1);
	cout << "\n" << endl;

	return 0;
}

/*int main()
{
	int tmp_number;
	struct Node *head = NULL;
	struct Node *current;
	struct Node *prev;

    cout << "Please input at least 10 numbers.\n";
 	cout << "NOTE: input numbers should be different and in random order.\n";
 	cout << "\n";
//input numbers
	cout << "Please enter the first number: ";
	while(cin >> tmp_number)
	{
		current = new Node;               //create a new Node

		if(head == NULL)
		{
			head = current;
		}
		else
		{
			prev->next = current;
		}

		current->number = tmp_number;
		current->next = NULL;
		if (cin.peek() == ' ')
		{
			tailer = current;
			break;
		}

		cout << "Please enter the next number(input space to stop): ";
		prev = current;
		while (cin.peek() == '\n')
		{
			cin.get();
	    }

	}
	cout << "\n";

//print all the input node
	cout << "Here is the original order traversal: " << endl;
	traversalnode(head);
	cout << "\n" << endl;

//sort the linked list
	swap(head, head->next);

//print all the sorted node
	cout << "Here is the descending order traversal: " << endl;
	traversalnode(head1);
	cout << "\n" << endl;

	return 0;
}*/


