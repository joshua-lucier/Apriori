#include "header.h"
/*        Pre:  A BST is most likely initialized
*     Post: a new node is initialized
*  Purpose: create a new node for a BST
***************************************************************/
BST_Node_Candidate::BST_Node_Candidate()
{
	//add your code
	mCandidate = new Candidate<int>();
	mLeft = NULL;
	mRight = NULL;
}



BST_Node_Candidate::~BST_Node_Candidate()
{

}


void BST_Node_Candidate::add(Candidate<int>* candidate)
{
	if (candidate->getData(0) < mCandidate->getData(0))
	{
		if (mLeft)
			mLeft->add(candidate);
		else
			mLeft = new BST_Node_Candidate(candidate);
	}
	else if (candidate->getData(0) >= mCandidate->getData(0))
	{
		if (candidate->compare(mCandidate))
		{
			return;
		}
		if (mRight)
			mRight->add(candidate);
		else
			mRight = new BST_Node_Candidate(candidate);
	}
}


bool BST_Node_Candidate::isExist(Candidate<int>* candidate)
{
	bool exists = false;
	if (candidate->compare(mCandidate)) return true;
	if (mLeft) exists = mLeft->isExist(candidate);
	if (exists) return true;
	if (mRight) exists = mRight->isExist(candidate);
	if (exists) return true;
	return false;

}

/*        Pre: a BST is most likely initialized
*     Post: a new node is initialized with a given value
*  Purpose: create a new node with a chosen value for a BST
***************************************************************/
BST_Node_Candidate::BST_Node_Candidate(Candidate<int>* candidate)
{
	//add your code
	mCandidate = candidate;
	mLeft = NULL;
	mRight = NULL;
}

/*        Pre: a BST is most likely initialized or being initialized and up to 2 BST nodes may be provided
*     Post: a new node is initialized for addition to a BST
*  Purpose: initialize a new node with pre-attached nodes to a BST
*****************************************************************/
BST_Node_Candidate::BST_Node_Candidate(Candidate<int>* candidate, BST_Node_Candidate *left, BST_Node_Candidate *right)
{
	mCandidate = candidate;
	mLeft = left;
	mRight = right;
}

void BST_Node_Candidate::prune(Transaction<int>* transaction, DDLinkedList<Candidate<int>*>* CT, BST_Node_Candidate* node)
{
	if (node == NULL) return;
	if (transaction->contains(node->mCandidate)) CT->insert(node->mCandidate);
	prune(transaction, CT, node->mLeft);
	prune(transaction, CT, node->mRight);
}
