#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<string>
#include<queue>

using namespace std;

class Node_Vertex_connection
{
	string C_name;
	int cost_length;
public:
	Node_Vertex_connection* C_next;
	Node_Vertex_connection()
	{
		C_name = "";
		cost_length = -999;
		C_next = NULL;
	}
	Node_Vertex_connection(string name, int cost)
	{
		C_name = name;
		cost_length = cost;
		C_next = NULL;
	}
	string getName() const
	{
		return this->C_name;
	}
	int getCost() const
	{
		return this->cost_length;
	}
};

class Node_Vertex
{
	string name;
	string color;
	int min_dist;
public:
	Node_Vertex* predecessor;
	Node_Vertex* next;
	Node_Vertex_connection* connection;
	Node_Vertex()
	{
		name = "";
		color = "";
		min_dist = INT_MAX;
		next = NULL;
		connection = NULL;
		predecessor = NULL;
	}
	Node_Vertex(string name)
	{
		this->name = name;
		color = "";
		min_dist = INT_MAX;
		next = NULL;
		connection = NULL;
		predecessor = NULL;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setColor(string color)
	{
		this->color = color;
	}
	void setMinDistance(int min_dis)
	{
		this->min_dist = min_dis;
	}
	string getName() const
	{
		return this->name;
	}
	string getColor() const
	{
		return this->color;
	}
	int getMinDist() const
	{
		return this->min_dist;
	}

	friend bool operator<(const Node_Vertex& a, const Node_Vertex& b);
	friend bool operator<=(const Node_Vertex& a, const Node_Vertex& b);
	friend bool operator>(const Node_Vertex& a, const Node_Vertex& b);
	friend bool operator>=(const Node_Vertex& a, const Node_Vertex& b);
	friend bool operator==(const Node_Vertex& a, const Node_Vertex& b);
};

bool operator<(const Node_Vertex& a, const Node_Vertex& b)
{
	return a.min_dist > b.min_dist;
}
bool operator<=(const Node_Vertex& a, const Node_Vertex& b)
{
	return a.min_dist >= b.min_dist;
}
bool operator>(const Node_Vertex& a, const Node_Vertex& b)
{
	return a.min_dist < b.min_dist;
}
bool operator>=(const Node_Vertex& a, const Node_Vertex& b)
{
	return a.min_dist <= b.min_dist;
}
bool operator==(const Node_Vertex& a, const Node_Vertex& b)
{
	return a.min_dist == b.min_dist;
}

class GRAPH
{
	Node_Vertex* vertex;
	
	bool exist(string name)
	{
		Node_Vertex* temp = vertex;

		while (temp != NULL)
		{
			if (temp->getName() == name)
				return true;

			temp = temp->next;
		}
		return false;
	}
	Node_Vertex* search(string name)
	{
		Node_Vertex* temp = vertex;

		while (temp != NULL)
		{
			if (temp->getName() == name)
				return temp;

			temp = temp->next;
		}
		return NULL;
	}
	bool found(Node_Vertex* check, string name)
	{
		if (check == NULL || check->connection == NULL)
			return false;
		if (check->getName() == name)
			return true;
		else
		{
			bool find = false;
			Node_Vertex_connection* temp = check->connection;

			while (temp != NULL)
			{
				Node_Vertex* to_send = search(temp->getName());
				find = found(to_send, name);

				if (find) return true;

				temp = temp->C_next;
			}
		}
	}
	int Vertex_Number(string name)
	{
		Node_Vertex* temp = vertex;
		int count = 0;

		while (temp != NULL)
		{
			if (temp->getName() == name)
				return count;
			count++;
			temp = temp->next;
		}
		return -1;
	}
	
	void PrintDijkstra(string start)
	{
		if (exist(start))
		{
			Node_Vertex* temp = search(start);
			cout << "Start -> End \tdistance" << endl;

			while (temp != NULL)
			{
				cout << start << "    ->   " << temp->getName() << "\t";
				if (temp->getMinDist() != INT_MAX)
					cout << temp->getMinDist() << endl;
				else
					cout << "infinity" << endl;
				temp = temp->next;
			}

		}
	}
	void MoveToHead(string name)
	{
		Node_Vertex* temp = vertex;
		Node_Vertex* start = vertex;
		Node_Vertex* node = search(name);
		Node_Vertex* prev = temp;
		Node_Vertex* nextn = node->next;

		while (temp != NULL)
		{
			if (temp->getName() == name)
			{
				prev->next = start;
				node->next = start->next;
				start->next = nextn;

				vertex = node;
				return;
			}
			prev = temp;
			temp = temp->next;
		}
	}
	void PrintBellManFords(string start, string end)
	{
		Node_Vertex* temp = search(start);
		cout << "Start -> End \tdistance" << endl;

		while (temp != NULL)
		{
			if (temp->getMinDist() != INT_MAX)
				cout << start << "    ->   " << temp->getName() << "\t" << temp->getMinDist() << endl;

			temp = temp->next;
		}
	}
public:
	GRAPH()
	{
		vertex = NULL;
	}
	GRAPH(const GRAPH& ref)
	{
		if (ref.vertex != NULL)
		{
			Node_Vertex* tempref = ref.vertex;
			Node_Vertex_connection* connref;

			while (tempref != NULL)
			{
				this->Insert(tempref->getName());

				tempref = tempref->next;
			}
			tempref = ref.vertex;
			Node_Vertex* tempthis = this->vertex;

			while (tempref != NULL)
			{
				connref = tempref->connection;

				while (connref != NULL)
				{
					this->Link(tempthis->getName(), connref->getName(), connref->getCost());

					connref = connref->C_next;
				}

				tempthis = tempthis->next;
				tempref = tempref->next;
			}
		}
		else
		{
			vertex = NULL;
		}
	}
	int Vertex_count()
	{
		Node_Vertex* temp = vertex;
		int count = 0;

		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}

	bool Insert(string name)
	{
		if (exist(name))
			return false;

		Node_Vertex* newVertex = new Node_Vertex(name);

		if (!newVertex)	return false;

		if (vertex == NULL)
		{
			vertex = newVertex;
		}
		else
		{
			Node_Vertex* temp = vertex;

			while (temp->next != NULL)
				temp = temp->next;

			temp->next = newVertex;
		}
		return true;
	}
	bool Link(string to_link, string link_with, int cost)
	{
		if (exist(to_link) && exist(link_with))
		{
			Node_Vertex_connection* connect = new Node_Vertex_connection(link_with, cost);

			if (!connect) return false;

			Node_Vertex* temp = search(to_link);
			Node_Vertex_connection* check = temp->connection;

			if (temp->connection == NULL)
				temp->connection = connect;
			else
			{
				while (check->C_next != NULL)
				{
					check = check->C_next;
				}

				check->C_next = connect;

			}

			return true;
		}
		else
		{
			return false;
		}
	}
	
	int possiblePaths(string VertexA, string VertexB)
	{
		if (exist(VertexA) && exist(VertexB))
		{
			int possible_paths = 0;

			Node_Vertex* VA = search(VertexA);
		
			Node_Vertex_connection* vac = VA->connection;

			while (vac != NULL)
			{
				Node_Vertex* temp = search(vac->getName());
				if (found(temp, VertexB) || vac->getName() == VertexB)
					possible_paths++;

				vac = vac->C_next;
			}
			return possible_paths;
		}
		return 0;
	}

	GRAPH T_Graph()
	{
		GRAPH Transpose_Graph;

		Node_Vertex* tempOrig = vertex;
		Node_Vertex_connection* tempvOrg;
		
		while (tempOrig != NULL)
		{
			Transpose_Graph.Insert(tempOrig->getName());

			tempOrig = tempOrig->next;
		}
		tempOrig = vertex;

		while (tempOrig != NULL)
		{
			tempvOrg = tempOrig->connection;

			while (tempvOrg != NULL)
			{
				Transpose_Graph.Link(tempvOrg->getName(), tempOrig->getName(), tempvOrg->getCost());

				tempvOrg = tempvOrg->C_next;
			}

			tempOrig = tempOrig->next;
		}

		return Transpose_Graph;
	}

	void Dijkstra(string start)
	{
		if (exist(start))
		{
			if (Vertex_Number(start) > 0)
				MoveToHead(start);

			Node_Vertex* tempstore = search(start);
			Node_Vertex* temp = tempstore;

			priority_queue<Node_Vertex> min_queue;

			while (temp != NULL)
			{
				temp->setMinDistance(INT_MAX);
				temp->predecessor = NULL;

				min_queue.push(*temp);

				temp = temp->next;
			}

			temp = tempstore;
			temp->setMinDistance(0);

			while (!min_queue.empty())
			{
				Node_Vertex PcheckVertex = min_queue.top();
				Node_Vertex* checkVertex = search(PcheckVertex.getName());
				min_queue.pop();
				Node_Vertex_connection* checkVertexConn = checkVertex->connection;

				int alt, dist, length;

				while (checkVertexConn != NULL)
				{
					alt = 0;
					Node_Vertex* checkNode = search(checkVertexConn->getName());

					dist = checkVertex->getMinDist();
					length = checkVertexConn->getCost();

					alt = dist + length;

					if (alt < checkNode->getMinDist() && alt >= 0)
					{
						checkNode->setMinDistance(alt);
						checkNode->predecessor = checkVertex;
					}

					checkVertexConn = checkVertexConn->C_next;
				}
			}
			PrintDijkstra(start);
		}
	}

	void BellManFords(string start, string end)
	{
		if (exist(start) && exist(end))
		{
			Node_Vertex* startingNode = search(start);
			Node_Vertex* startStore = startingNode;

			while (startingNode != NULL)
			{
				startingNode->setMinDistance(INT_MAX);
				startingNode->predecessor = NULL;

				if (end == startingNode->getName())
				{
					break;
				}

				startingNode = startingNode->next;
			}

			startingNode = startStore;
			startingNode->setMinDistance(0);

			Node_Vertex_connection* tempConn;

			while (startingNode != NULL)
			{
				tempConn = startingNode->connection;

				while (tempConn != NULL)
				{
					Node_Vertex* temp = search(tempConn->getName());

					if (startingNode->getMinDist() + tempConn->getCost() < temp->getMinDist() && startingNode->getMinDist() != INT_MAX)
					{
						temp->setMinDistance(startingNode->getMinDist() + tempConn->getCost());
						temp->predecessor = startingNode;
					}

					tempConn = tempConn->C_next;
				}

				if (end == startingNode->getName())
					break;
				startingNode = startingNode->next;
			}
		}
		PrintBellManFords(start, end);
	}

	void printGeneralGraph()
	{
		Node_Vertex* temp = vertex;
		Node_Vertex_connection* checks = temp->connection;

		while (temp != NULL)
		{
			checks = temp->connection;

			cout << "Vertex : " << temp->getName() << endl;
			while (checks != NULL)
			{

				cout << "Link with " << checks->getName() << " with cost " << checks->getCost() << endl;

				checks = checks->C_next;
			}
			temp = temp->next;
		}
	}
	GRAPH& operator=(const GRAPH& ref)
	{
		if (this->vertex)
		{
			Node_Vertex* temp = vertex;
			Node_Vertex_connection* tempconn;

			while (vertex != NULL)
			{
				temp = vertex;
				tempconn = temp->connection;

				while (vertex->connection != NULL)
				{
					tempconn = vertex->connection;
					vertex->connection = vertex->connection->C_next;

					delete tempconn;
				}

				vertex = vertex->next;

				delete temp;
			}
		}

		if (ref.vertex != NULL)
		{
			Node_Vertex* tempref = ref.vertex;
			Node_Vertex_connection* connref;

			while (tempref != NULL)
			{
				this->Insert(tempref->getName());

				tempref = tempref->next;
			}
			tempref = ref.vertex;
			Node_Vertex* tempthis = this->vertex;

			while (tempref != NULL)
			{
				connref = tempref->connection;

				while (connref != NULL)
				{
					this->Link(tempthis->getName(), connref->getName(), connref->getCost());

					connref = connref->C_next;
				}

				tempthis = tempthis->next;
				tempref = tempref->next;
			}
		}
		else
		{
			vertex = NULL;
		}
	}
	~GRAPH()
	{
		Node_Vertex* temp = vertex;
		Node_Vertex_connection* tempconn;

		while (vertex != NULL)
		{
			temp = vertex;
			tempconn = temp->connection;

			while (vertex->connection != NULL)
			{
				tempconn = vertex->connection;
				vertex->connection = vertex->connection->C_next;

				delete tempconn;
			}

			vertex = vertex->next;

			delete temp;
		}
	}
};

#endif // !GRAPH_H
