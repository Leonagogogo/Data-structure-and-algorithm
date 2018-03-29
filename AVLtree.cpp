/*
 * AVLTree.cpp
 *
 *  Created on: Feb 9, 2018
 *      Author: fumelody
 */

#include <iostream>

using namespace std;

typedef struct AVLNode *AVLNodePtr;

struct AVLNode{
	int value;
	int height;
	struct AVLNode * AVLleft;
	struct AVLNode * AVLright;
	struct AVLNode * AVLparent;
};

class AVLTree{
public:

	void makeempty(AVLNode *T);
	int calHeight(struct AVLNode *Htemp,int level);
	int LcalHeight(struct AVLNode *Htemp);
	int RcalHeight(struct AVLNode *Htemp);
	void Lheight(struct AVLNode *temp);
	void Rheight(struct AVLNode *temp);
	int printNode(struct AVLNode *temp1,struct AVLNode *temp2);
	void PreOrderPrint(struct AVLNode *T, int level);
	AVLNodePtr SrightRotation(struct AVLNode *T1);
	AVLNodePtr SleftRotation(struct AVLNode *T1);
	AVLNodePtr DrightleftRotation(struct AVLNode *T1);
	AVLNodePtr DleftrightRotation(struct AVLNode *T1);
	AVLNodePtr insertNode(AVLNodePtr temp, int val);

};

struct AVLNode *LlastNode = NULL;
struct AVLNode *RlastNode = NULL;
struct AVLNode *head =NULL;
int Leftflag = 0;
int Rightflag = 0;

void visit(int c,int level)
{
    cout << "Node is " << c <<" locate at level "<< level <<'\n';
}

void PreOrderTraverse(struct AVLNode *T, int level){
	if(T){ // 当节点不为空时执行
    	 	visit(T->value,level);
        PreOrderTraverse(T->AVLleft,level+1);
        PreOrderTraverse(T->AVLright,level+1);
    }
    else
        cout << "Node is NULL!" << endl;
}

/************************************************************************************************************
 * input: node structure
 * output: none
 *
 *
 * description: delete all the nodes after operation is done.
 *
**************************************************************************************************************/
void AVLTree::makeempty(AVLNode *T)
{
    if (T == NULL)
        return;
    else
    {
        makeempty(T->AVLleft);
        makeempty(T->AVLright);
        delete(T);
    }
}

/************************************************************************************************************
 * input: node structure, the node level
 * output: the highest of the node's left and right
 *
 *
 * description: calculate the node's left and right height. Output the higher height between the left and right
 *
**************************************************************************************************************/
int AVLTree::calHeight(struct AVLNode *Htemp,int level)
{

	if(Htemp == NULL)
		return -1;
	else
	{
		int lHeight = calHeight(Htemp->AVLleft,level +1);
		int rHeight = calHeight(Htemp->AVLright,level+1);

		return (lHeight > rHeight ? lHeight : rHeight) + 1;
	}
}

/************************************************************************************************************
 * input: node structure, the node level
 * output: node value, height and level
 *
 *
 * description: output each level, the level's node and the node's height
 *
**************************************************************************************************************/
void AVLTree::PreOrderPrint(struct AVLNode *T, int level){
	if(T){ // 当节点不为空时执行
		cout << "Node is " << T->value << ".  Height is " << T->height <<". level is " << level <<endl;
    	 	PreOrderPrint(T->AVLleft,level+1);
    	 	PreOrderPrint(T->AVLright,level+1);
    }
    else
        cout << "# " << endl;
}
/************************************************************************************************************
 * input: node structure
 * output: the node's left tree's height
 *
 *
 * description: using recursive calculate the node's left height
 *
**************************************************************************************************************/
int AVLTree::LcalHeight(struct AVLNode *Htemp)
{

	if(Htemp == NULL)
		return 0;
	else
	{
		int lHeight = LcalHeight(Htemp->AVLleft);

		return (lHeight + 1);
	}
}
/************************************************************************************************************
 * input: node structure
 * output: the node's right tree's height
 *
 *
 * description: using recursive calculate the node's right height
 *
**************************************************************************************************************/
int AVLTree::RcalHeight(struct AVLNode *Htemp)
{

	if(Htemp == NULL)
		return 0;
	else
	{
		int rHeight = RcalHeight(Htemp->AVLright);

		return (rHeight + 1);
	}
}
/************************************************************************************************************
 * input: node structure
 * output: print left height
 *
 *
 * description:
 *
**************************************************************************************************************/
void AVLTree::Lheight(struct AVLNode *temp)
{
	int height = 0;
	if(temp)
	{
		height = LcalHeight(temp->AVLleft);
		cout << "Node is " << temp->value << ".   The left height is " << height;
	}
	else
	{
		cout << "#" << endl;
	}
}
/************************************************************************************************************
 * input: node structure
 * output: print right height
 *
 *
 * description:
 *
**************************************************************************************************************/
void AVLTree::Rheight(struct AVLNode *temp)
{
	int height = 0;
	if(temp)
	{
		height = RcalHeight(temp->AVLright);
		cout << ".   The right height is " << height << endl;
	}
	else
	{
		cout << "#" << endl;
	}
}
/************************************************************************************************************
 * input: node structure
 * output: print left height
 *
 *
 * description: when all the input is done. the function finds all the nodes from the last node to the root
 *              output all the nodes in the trace left and right height
 *
**************************************************************************************************************/
int AVLTree::printNode(struct AVLNode *temp1,struct AVLNode *temp2)
{
//	cout << "temp1 is " << temp1->value << endl;
//	cout << "temp2 is " << temp2->value << endl;
	if(temp2->value < temp1->value)
	{
		if(temp1->AVLleft->value == temp2->value)
		{
			Lheight(temp2);
			Rheight(temp2);
			temp2 = temp1;
			return printNode(head,temp2);
		}
		else
		{
			temp1 = temp1->AVLleft;
			return printNode(temp1,temp2);
		}
	}
    else if(temp2->value > temp1->value)
	{
    		if(temp1->AVLright->value == temp2->value)
    		{
    			Lheight(temp2);
    			Rheight(temp2);
    		 	temp2 = temp1;
    		 	return printNode(head,temp2);
    		}
    		else
    		{
    			temp1 = temp1->AVLright;
    			return printNode(temp1,temp2);
    		}
	}
    else
    {
		Lheight(temp2);
		Rheight(temp2);
		return 0;
    }
}

/*********************************************************************
* all the nodes locate at the left
* clockwise rotation
 *********************************************************************/
AVLNodePtr AVLTree::SrightRotation(struct AVLNode *T1)
{
	int level = 0;
	struct AVLNode *T2;

	T2 = T1->AVLleft;
	T1->AVLleft = T2->AVLright;
	T2->AVLright = T1;

	T1->height = calHeight(T1,level);
	T2->height = calHeight(T2,level);

//	cout << "T2 is " << T2->value << endl;

	return T2;
}

/********************************************************************
* all the nodes locate at the right
* counterclockwise rotation
 *********************************************************************/
AVLNodePtr AVLTree::SleftRotation(struct AVLNode *T1)
{
	int level = 0;
	struct AVLNode *T2;

	T2 = T1->AVLright;
	T1->AVLright = T2->AVLleft;
	T2->AVLleft = T1;

	T1->height = calHeight(T1,level);
	T2->height = calHeight(T2,level);

	//cout << "T2 is " << T2->value << endl;

	return T2;
}

/*****************************************************************************
* the brokenode and the next node locates at the right
* the last node locates at the left
* clockwise rotation first and then counterclockwise rotation
 ****************************************************************************/
AVLNodePtr AVLTree::DrightleftRotation(struct AVLNode *T1)
{
	struct AVLNode *temp;
	T1->AVLright = SrightRotation(T1->AVLright);
	temp = SleftRotation(T1);
	return temp;
}

/*****************************************************************************
* the brokenode and the next node locates at the left
* the last node locates at the right
* counterclockwise rotation first and then clockwise rotation
 ****************************************************************************/
AVLNodePtr AVLTree::DleftrightRotation(struct AVLNode *T1)
{
	struct AVLNode *temp;
	T1->AVLleft = SleftRotation(T1->AVLleft);
	temp = SrightRotation(T1);
	return temp;
}

/*****************************************************************************
* insert node: each insert from head to check.
*
* after insert, checking whether the AVLTree is balance.
* If balance, return to insert another node
* If not, make rotation to keep it balance and then insert another node
 ****************************************************************************/
AVLNodePtr AVLTree::insertNode(AVLNodePtr temp, int val)
{
	int level = 1;
	//cout << "insert start\n" << endl;
	int dLHeight = 0;
	int dRHeight = 0;
//	cout << "temp is " << temp->value << endl;
	if (temp == NULL)
	{

		temp = (AVLNodePtr)new AVLNode;
		if(temp == NULL)
		{
			cout << "out of space!!" << endl;
			return NULL;
		}
		else
		{
			temp->value = val;
			temp->height = 0;
			temp->AVLleft = NULL;
			temp->AVLright = NULL;
			if(temp->value < head->value)
			{
				Leftflag = 1;
				LlastNode = temp;
			}
			else if(temp->value > head->value)
			{
				Rightflag = 1;
				RlastNode = temp;
			}
			else
			{
				cout << "no insert" << endl;
			}

		}
	}
	else if(val < temp->value)         // insert value is less than the current value
	{
		temp->AVLleft = insertNode(temp->AVLleft, val);
		temp->AVLleft->AVLparent = temp->AVLleft;
//		cout << "temp is " << temp->value << endl;
		dLHeight = calHeight(temp->AVLleft,level) - calHeight(temp->AVLright,level);
		if(dLHeight == 2)
		{
		//	cout << "broke value is " << temp->value << endl;
			if(val < temp->AVLleft->value)
			{
				temp = SrightRotation(temp);
			}
			else
			{
				temp = DleftrightRotation(temp);
			}
		}
	}
	else if(val > temp->value)             // insert value is bigger than the current value
	{
		temp->AVLright = insertNode(temp->AVLright, val);
		temp->AVLright->AVLparent = temp->AVLright;
		dRHeight = calHeight(temp->AVLright,level) - calHeight(temp->AVLleft,level);
//		cout << "temp is " << temp->value << endl;
		if(dRHeight == 2)
		{
			//cout << "broke value is " << temp->value << endl;
			if(val > temp->AVLright->value)
			{
				temp = SleftRotation(temp);
			}
			else
			{
				temp = DrightleftRotation(temp);
			}
		}
	}
	//cout << "insert over\n" << endl;
	temp->height = calHeight(temp,level);
	return temp;
}
/************************************************************************************************************
* main()
*
**************************************************************************************************************/
int main()
{
	AVLTree Avltree;
	int level = 1;
	int nValue = 0;
	struct AVLNode *current = NULL;

	cout << "Please input the first node(return represents the end of inputing number and # represents the end of inputing): ";
	while(cin >> nValue)
	{
		current = new AVLNode;
		if(current == NULL)
		{
			cout << "out of space. Head is not builded!" << endl;
		}
		else
		{
			if(head == NULL)
			{
				head = current;
				head->value = nValue;
				head->height = 0;
				head->AVLleft = NULL;
				head->AVLright = NULL;
				head->AVLparent = NULL;
			}
			else
			{
				//cout << "insert start!" << endl;
				head = Avltree.insertNode(head, nValue);
				//cout << "insert over!" << endl;
			}
		}

	//	cout << "check over\n" << endl;

		while (cin.peek() == '#')
		{
			break;
		}
		cout << "Please input the next node(return represents the end of inputing number and # represents the end of inputing): ";

		if (cin.peek() == '\n')
		{
			cin.get();
		}
	}
	cout << "\n";
	cout << "Using preorder outputing all the nodes' hegight: " << endl;
	Avltree.PreOrderPrint(head,level);
	cout << "\n";
    if(Rightflag == 0)
    {
    		cout << "The right doesn't insert any node!" << endl;
    }
    else
    {
		cout << "The right last inserted is " << RlastNode->value << endl;
		cout << "The trace is: " << endl;
		Avltree.printNode(head,RlastNode);
	}
    cout << "\n";
	if(Leftflag == 0)
    {
    		cout << "The left doesn't insert any node!" << endl;
    }
    else
    {
		Leftflag = 0;
    	    cout << "The left last inserted is " << LlastNode->value << endl;
		cout << "The trace is: " << endl;
		Avltree.printNode(head,LlastNode);
	}

	Avltree.makeempty(head);

	return 0;
}


