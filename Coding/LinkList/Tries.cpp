#include<iostream>

using namespace std;

struct TriesNode{
    TriesNode* children[26];

    bool isEndOfWord;
};


TriesNode* getNode()
{
    TriesNode* node = new TriesNode();

    node->isEndOfWord = false;

    for(int i=0;i<26;i++)
    {
        node->children[i]=NULL;
    }
    return node;
}

void insert(TriesNode* root,string key)
{
    TriesNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
}