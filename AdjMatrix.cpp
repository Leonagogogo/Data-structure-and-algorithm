/*
 * AdjMatrix.cpp
 *
 *  Created on: Mar 15, 2018
 *      Author: fumelody
 */

#include <iostream>
#include <queue>
#include <list>

using namespace std;

#define vertexMax 100

class Graph{

public:
	int vertexNum;
	int edgesNum;
	char startVertices;                            //vertices type is char

	int matrix[vertexMax][vertexMax];              //store information  Adjacent Matrix
	char vertexMatrix[vertexMax];                  //store all the vertices
	int DFSmatrixFlag[vertexMax];
	int BFSmatrixFlag[vertexMax];

	queue<char>DFSqueue;
	queue<char>BFSqueue;
	queue<char>BFSqueueFinal;

	void inputMatrixInfo();
	void cleanMatrix();
	void printMatrix();
	void DFScheck(int val);
	void DFStraversal();
	void BFStraversal();
	void BFScheck(int val);
};

/*****************************************************************************************************
 * desc: clean up all the numbers in the matrix
 *
 *
 *
 *****************************************************************************************************/
void Graph::cleanMatrix()
{
	for(int i=0;i<vertexNum;i++)
	{
		vertexMatrix[i] = 0;
		for(int j=0; j<edgesNum; j++)
		{
			matrix[i][j] = 0;
		}
	}

	for(int i=0;i<vertexNum;i++)
	{
		DFSmatrixFlag[i] = 0;
	}

	for(int i=0;i<vertexNum;i++)
	{
		BFSmatrixFlag[i] = 0;
	}
}
/*****************************************************************************************************
 * desc: user input the matrix information according to their demands
 *
 *
 *
 *****************************************************************************************************/
void Graph::inputMatrixInfo()
{
	int vertexnum = 0;
	cout << "Please input the number of Vertices: ";
	while(cin>>vertexnum)
	{
		vertexNum = vertexnum;
		if(cin.get() == '\n')
		{
			break;
		}
	}

	cout << "Please input all the Vertices: ";
	for(int i = 0;i<vertexNum; i++)
	{
		cin >> vertexMatrix[i];
	}

	cout << "Please input the matrix: ";
	for(int i=0;i<vertexNum;i++)
	{
		for(int j=0; j<vertexNum; j++)
		{
			cin>>matrix[i][j];
			if(cin.get() == '\n')
			{
				return;
			}
		}
	}
}
/*****************************************************************************************************
 * desc: print all the information
 *
 *
 *
 *****************************************************************************************************/
void Graph::printMatrix()
{
	cout << "All the vertices are: ";
	for(int i = 0; i< vertexNum; i++)
	{
		cout << vertexMatrix[i];
		cout << " ";
	}
	cout << endl;

	cout << "All the edges are: " << endl;
	for(int i=0; i< vertexNum; i++)
	{
		for(int j=0; j< vertexNum; j++)
		{
			if(matrix[i][j] == 1)
			{
				cout << "(" << vertexMatrix[i]<< "," << vertexMatrix[j]<< ")";
				cout << " ";
			}
		}
	}

	cout << endl;
	cout << "The matrix is: " << endl;
	for(int i=0;i<vertexNum;i++)
	{
		for(int j=0; j<vertexNum; j++)
		{
			cout << matrix[i][j];
			cout << " ";
		}
		cout << endl;
	}

	cout << endl;
}
/*****************************************************************************************************
 * desc: Using DFS traversal to check each vertices and edges
 *
 *
 *
 *
 *****************************************************************************************************/
void Graph::DFScheck(int val)
{
	if(DFSmatrixFlag[val] != 1)
	{
		DFSmatrixFlag[val] = 1;
		DFSqueue.push(vertexMatrix[val]);        //using queue to store the checked vertices
	}

	for(int j=0; j<vertexNum; j++)
	{
		if((matrix[val][j] == 1) && (DFSmatrixFlag[j] == 0))
		{
			DFScheck(j);
		}
	}
}
/*****************************************************************************************************
 * desc: check each vertices
 *       user could input any vertices as the first vertices to check
 *
 *       first check the vertices after the started vertices and then checking the after vertices
 *
 *****************************************************************************************************/
void Graph::DFStraversal()
{
	for(int i=0;i<vertexNum;i++)
	{
		if(vertexMatrix[i] == startVertices)
		{
			for(int index_R=i; index_R<vertexNum; index_R++)
			{
				DFScheck(index_R);
			}

			for(int index_L=0; index_L<i; index_L++)
			{
				DFScheck(index_L);
			}
		}
	}
}
/*****************************************************************************************************
 * desc: Using DFS traversal to check each vertices and edges
 *
 *
 *
 *
 *****************************************************************************************************/
void Graph::BFScheck(int val)
{
	char vertex;

	if(BFSmatrixFlag[val] != 1)
	{
		BFSmatrixFlag[val] = 1;
		BFSqueue.push(vertexMatrix[val]);        //using queue to store the checked vertices
	}

	while(1)
	{
		if(BFSqueue.empty())
		{
			break;
		}
		vertex = BFSqueue.front();
		BFSqueue.pop();
		BFSqueueFinal.push(vertex);
		for(int i=0; i<vertexNum; i++)
		{
			if(vertexMatrix[i] == vertex)
			{
				for(int j=0; j<vertexNum; j++)
				{
					if((matrix[i][j] == 1) && (BFSmatrixFlag[j] == 0))
					{
						BFSmatrixFlag[j] = 1;
						BFSqueue.push(vertexMatrix[j]);
					}
				}
			}
		}
	}
}
/*****************************************************************************************************
 * desc: check each vertices
 *       user could input any vertices as the first vertices to check
 *
 *
 *       first check the vertices after the started vertices and then checking the after vertices
 *
 *****************************************************************************************************/
void Graph::BFStraversal()
{
	for(int i=0;i<vertexNum;i++)
	{
		if(vertexMatrix[i] == startVertices)
		{
			for(int index_R=i; index_R<vertexNum; index_R++)
			{
				BFScheck(index_R);
			}

			for(int index_L=0; index_L<i; index_L++)
			{
				BFScheck(index_L);
			}
		}
	}
}

int main()
{
	char startnode;

	Graph graph;

	graph.cleanMatrix();
	graph.inputMatrixInfo();
	cout << endl;
	graph.printMatrix();

	cout << endl;
	cout << "Please input the started vertices: ";
	while(cin>>startnode)
	{
		graph.startVertices = startnode;
		if(cin.get() == '\n')
		{
			break;
		}
	}

	graph.DFStraversal();
	cout << "DFS traversal is: ";
	while(!graph.DFSqueue.empty())
	{
		cout <<graph.DFSqueue.front();
		graph.DFSqueue.pop();
		cout << "->";
	}

	cout << endl;
	graph.BFStraversal();
	cout << "BFS traversal is: ";
	while(!graph.BFSqueueFinal.empty())
	{
		cout <<graph.BFSqueueFinal.front();
		graph.BFSqueueFinal.pop();
		cout << "->";
	}
	cout << endl;

	return 0;
}



