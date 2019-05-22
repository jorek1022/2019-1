// Lab 007	: Disjoint Sets
// Name :
// Student ID :

import java.util.*;


class DisjointSets {
	int numofelements;  // the total number of elements in all the disjoint sets
	private int[] parent; // maintains the parent pointer of each element in the disjoint sets
	private int[] weight; // maintains the weight of each set


	DisjointSets() { 
		// DisjointSets constructor. 
	}

	public String toString() { // Show all the element in sequence
		String str = new String();
	    // Show the array elements in parent[]

		str = "parent[] = - ";
		for(int i = 1; i <= numofelements; i++)
			str += parent[i] + " ";
		return str;
	}

	void InitSet(int n) { 
		// Initialize the array parent[] and weight[]
		numofelements = n;

		parent = new int[numofelements + 1];
		weight = new int[numofelements + 1];

		for(int i=1; i <= numofelements; i++)
		{
			parent[i] = 0;
			weight[i] = 1;
		}
	}

	boolean Union(int i, int j) { 
	// Union the set that contains i and the set that contains j
	// the set that has larger weight is the new root of the unioned set
	// when the weights are the same, choose the root of smaller value

		// first find the root of i and j
		int root_i;
		int root_j;
		root_i = SimpleFind(i);
		root_j = SimpleFind(j);

		if(root_i == root_j)
			return false;
		
		if(weight[root_i] == weight[root_j])
		{
			if(root_i > root_j)
			{
				parent[root_j] = root_i;
				weight[root_i] += weight[root_j];
			}
			else
			{
				parent[root_i] = root_j;
				weight[root_j] += weight[root_i];
			}
		}
		else if (weight[root_i] > weight[root_j])
		{
			parent[root_j] = root_i;
			weight[root_i] += weight[root_j];
		}
		else
		{
			parent[root_i] = root_j;
			weight[root_j] += weight[root_i];
		}

		return true;
	}

	int SimpleFind(int i) { 
	// return the root node that contains the element i
		int root = i;
		while(parent[root] > 0)
			root = parent[root];
		
		return root;
	}
}

