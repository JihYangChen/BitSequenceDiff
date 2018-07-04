#include "BitSequenceList.h"
#include <algorithm>
#include <unordered_map>
#include <iostream>
using std::next_permutation;
using std::sort;
using std::unordered_map;
using std::cout;

struct Edge {
	BitSequence *from, *to;
	int weight;
	Edge(BitSequence *u, BitSequence *v, int w) : from(u), to(v), weight(w) {};
};

// To represent Disjoint Sets
struct DisjointSets
{
	unordered_map<BitSequence *, BitSequence *> parentMap;
	unordered_map<BitSequence *, int> rankMap;

	// Constructor.
	DisjointSets(vector<BitSequence *> bitSequenceList)
	{
		// Initially, all vertices are in
		// different sets and have rank 0.
		for (auto bitSequence : bitSequenceList)
		{
			//every element is parent of itself
			parentMap[bitSequence] = bitSequence;
			rankMap[bitSequence] = 0;
		}
	}

	// Find the parent of a node 'u'
	// Path Compression
	BitSequence* find(BitSequence *u)
	{
		/* Make the parent of the nodes in the path
		from u--> parent[u] point to parent[u] */
		if (u != parentMap[u])
			parentMap[u] = find(parentMap[u]);
		return parentMap[u];
	}

	// Union by rank
	void unionSet(BitSequence *x, BitSequence *y)
	{
		x = find(x), y = find(y);

		/* Make tree with smaller height
		a subtree of the other tree  */
		if (rankMap[x] > rankMap[y])
			parentMap[y] = x;
		else // If rank[x] <= rank[y]
			parentMap[x] = y;

		if (rankMap[x] == rankMap[y])
			rankMap[y]++;
	}
};

BitSequenceList::BitSequenceList(vector<BitSequence *> bitSequenceList) : bitSequenceList(bitSequenceList) {}

int BitSequenceList::calculateDiffBitAmount() {
	int totalCount = 0;
	for (auto sequence = bitSequenceList.begin(); sequence != bitSequenceList.end() - 1; sequence++)
		totalCount += (*sequence)->calculateDiffBitAmount(**(sequence + 1));
	return totalCount;
}

string BitSequenceList::getDisplayString() {
	string displayString = "";
	for (int i = 0; i < bitSequenceList.size(); i++)
		displayString += "[" + std::to_string(i+1) + "]: " + bitSequenceList[i]->getBitSequence() + "\n";
	return displayString;
}

BitSequenceList BitSequenceList::getMinDiffBitAmountListWithBruteForce() {
	vector<BitSequence *> permutationBitSequenceList = bitSequenceList;
	sort(permutationBitSequenceList.begin(), permutationBitSequenceList.end());
	
	BitSequenceList minDiffBitAmountList(permutationBitSequenceList);
	int minDiffBitAmount = minDiffBitAmountList.calculateDiffBitAmount();

	while (next_permutation(permutationBitSequenceList.begin(), permutationBitSequenceList.end())) {
		BitSequenceList list(permutationBitSequenceList);
		int diffBitAmount = list.calculateDiffBitAmount();
		if (diffBitAmount < minDiffBitAmount) {
			minDiffBitAmount = diffBitAmount;
			minDiffBitAmountList = list;
		}
	};

	return minDiffBitAmountList;
}

BitSequenceList BitSequenceList::getMinDiffBitAmountListWithTSPApproximation() {
	vector<struct Edge> edgesetMST =  kruskalMST();
	vector<BitSequence *> preorderSequenceList;
	preorderTraversal(edgesetMST[0].from, edgesetMST, preorderSequenceList);

	return BitSequenceList(preorderSequenceList);
}

vector<struct Edge> BitSequenceList::kruskalMST() {
	vector<struct Edge> edgesetMST;

	// init disjointSets
	DisjointSets disjointSets(bitSequenceList);

	// 得到排好序的edges
	vector<struct Edge> sortedEdges = getSortedEdges();

	for (auto edge : sortedEdges) {
		if (disjointSets.find(edge.from) != disjointSets.find(edge.to)) {
			edgesetMST.push_back(edge);
			disjointSets.unionSet(edge.from, edge.to);
		}
	}

	cout << "\n========== edgesetMST ==========\n";
	for (int i = 0; i < edgesetMST.size(); i++) {
		cout << "From: " << edgesetMST[i].from->getBitSequence() << " " << "  To: " << edgesetMST[i].to->getBitSequence() << " ";
		cout << "  Weight: " << edgesetMST[i].weight << "\n";
	}
	cout << "=================================\n\n";

	return edgesetMST;
}

vector<struct Edge> BitSequenceList::getSortedEdges() {
	vector<struct Edge> edges;
	for (int i = 0; i < bitSequenceList.size(); i++) {
		for (int j = i + 1; j < bitSequenceList.size(); j++) {
			int diffBitAmount = bitSequenceList[i] -> calculateDiffBitAmount(*bitSequenceList[j]);
			edges.push_back(Edge(bitSequenceList[i], bitSequenceList[j], diffBitAmount));
		}
	}

	sort(edges.begin(), edges.end(), [] (const struct Edge &a, const struct Edge &b) -> bool {
		return a.weight < b.weight;
	});

	return edges;
}

void BitSequenceList::preorderTraversal(BitSequence *currentVertex, vector<struct Edge> &edgesetsMST, vector<BitSequence *> &resultList) {
	resultList.push_back(currentVertex);
	for (auto edge : edgesetsMST) {
		// 邊上其中有一個點是currentVertex，而且下一個要走的點還沒被visit過
		if ((edge.from == currentVertex) && (find(resultList.begin(), resultList.end(), edge.to) == resultList.end()))
			preorderTraversal(edge.to, edgesetsMST, resultList);
		else if (edge.to == currentVertex && (find(resultList.begin(), resultList.end(), edge.from) == resultList.end()))
			preorderTraversal(edge.from, edgesetsMST, resultList);
	}
}