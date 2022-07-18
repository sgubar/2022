#pragma once
#include <iostream>

class BinaryTree;

class Node	
{
	friend class BinaryTree;
private:
	
	double Key;		
	Node* pParent;	
	Node* pLeft;	
	Node* pRight;	

	Node(double otherKey = double(), Node* otherpParent = nullptr, Node* otherpLeft = nullptr, Node* otherpRight = nullptr)	
	{
		this->Key = otherKey;
		this->pParent = otherpParent;
		this->pLeft = otherpLeft;
		this->pRight = otherpRight;
	}
};

class BinaryTree
{
private:

	Node* m_pRoot;	
	int m_iSize;	

	bool delete_node_h(const double& key)	
	{
		Node* toDeleteNode = this->m_pRoot;
		Node* prev = nullptr;

		while (toDeleteNode != nullptr && !(toDeleteNode->Key == key))	
		{
			prev = toDeleteNode;
			if (key < toDeleteNode->Key)
			{
				toDeleteNode = toDeleteNode->pLeft;
			}
			else
			{
				toDeleteNode = toDeleteNode->pRight;
			}
		}

		if (toDeleteNode == nullptr)	
		{
			return false;
		}

		if (toDeleteNode->pLeft == nullptr || toDeleteNode->pRight == nullptr)	
		{
			Node* newCurr; 

			
			if (toDeleteNode->pLeft == nullptr)
			{
				newCurr = toDeleteNode->pRight;
			}
			else
			{
				newCurr = toDeleteNode->pLeft;
			}

			if (toDeleteNode->pParent == nullptr)
			{
				this->m_pRoot = newCurr;
			}
			if (toDeleteNode->pParent && toDeleteNode == toDeleteNode->pParent->pLeft)
			{
				toDeleteNode->pParent->pLeft = newCurr;
			}
			else if (toDeleteNode->pParent && toDeleteNode == toDeleteNode->pParent->pRight)
			{
				toDeleteNode->pParent->pRight = newCurr;
			}
			if (newCurr)
			{
				newCurr->pParent = toDeleteNode->pParent;
			}
			

			delete toDeleteNode;	
		}
		else 
		{
			Node* prev = nullptr;
			Node* temp = toDeleteNode->pRight;
			while (temp && temp->pLeft)	
			{
				prev = temp;
				temp = temp->pLeft;
			}

			
			if (prev != nullptr)
			{
				prev->pLeft = temp->pRight;
				if (temp->pRight)
				{
					temp->pRight->pParent = temp->pParent;
				}
			}
			else
			{
				toDeleteNode->pRight = temp->pRight;
				if (temp->pRight)
				{
					temp->pRight->pParent = toDeleteNode;
				}
			}
			

			toDeleteNode->Key = temp->Key;	
			delete temp;	
		}
		return true;
	}

	void preorder_output_h(Node* currentNode) const
	{
		if (currentNode == nullptr)
		{
			return;
		}
		std::cout << currentNode->Key << "  ";
		preorder_output_h(currentNode->pLeft);
		preorder_output_h(currentNode->pRight);
		
	}

	void recursive_clear_h(Node* pNode) 
	{
		if (pNode != nullptr)
		{
			recursive_clear_h(pNode->pLeft);
			recursive_clear_h(pNode->pRight);
			delete pNode;
			pNode = nullptr;
		}
	}

public:

	BinaryTree(); 

	~BinaryTree(); 

	int size() const; 

	void clear();		

	bool insert(const double& key);	

	bool erase(const double& key);	


	bool is_present(const double& key) const; 

	void preorder_output() const;		

};


BinaryTree::BinaryTree()
{
	this->m_pRoot = nullptr;
	this->m_iSize = 0;
}

BinaryTree::~BinaryTree()
{
	recursive_clear_h(this->m_pRoot);
}


int BinaryTree::size() const
{
	return this->m_iSize;
}

void BinaryTree::clear()
{
	recursive_clear_h(this->m_pRoot);
	this->m_iSize = 0;
	this->m_pRoot = nullptr;
}

bool BinaryTree::insert(const double& key)
{
	Node* currentNode = this->m_pRoot;
	Node* prev = nullptr;
	while (currentNode)	
	{
		prev = currentNode;	
		if (key < currentNode->Key)
		{
			currentNode = currentNode->pLeft;
		}
		else if (key > currentNode->Key)
		{
			currentNode = currentNode->pRight;
		}
		else
		{
			return false;	
		}
	}
	if (currentNode == nullptr)	
	{
		Node* newNode = new Node(key, prev);	
		if (prev)	
		{
			
			if (key < prev->Key)
			{
				prev->pLeft = newNode;
			}
			else
			{
				prev->pRight = newNode;
			}
		}
		else
		{
			
			this->m_pRoot = newNode;
		}
	}
	this->m_iSize++;	
	return true;
}

bool BinaryTree::erase(const double& key)
{
	if (delete_node_h(key))	
	{
		
		this->m_iSize--;	
		return true;
	}
	return false;
}


bool BinaryTree::is_present(const double& key) const
{
	Node* currentNode = this->m_pRoot;
	while (currentNode)	
	{
		if (currentNode->Key > key)
		{
			currentNode = currentNode->pLeft;
		}
		else if (currentNode->Key < key)
		{
			currentNode = currentNode->pRight;
		}
		else
		{
			return true;
		}
	}
	return false;
}

void BinaryTree::preorder_output() const
{
	preorder_output_h(this->m_pRoot);	
	std::cout << std::endl;
}

