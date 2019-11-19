// C++ implementation of search and insert 
// operations on Trie 
#include <bits/stdc++.h> 
using namespace std; 
  
const int ALPHABET_SIZE = 10; 
  
struct TrieNode { 
    struct TrieNode *children[ALPHABET_SIZE]; 
    bool isEndOfWord; 
}; 
  
struct TrieNode *getNode(void) { 
    struct TrieNode *pNode =  new TrieNode; 
    pNode->isEndOfWord = false; 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
    return pNode; 
} 
  
void insert(struct TrieNode *root, string key) { 
    struct TrieNode *pCrawl = root; 
    for (int i = 0; i < key.length(); i++) { 
        int index = key[i] - 48; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 
  
// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) { 
    struct TrieNode *pCrawl = root; 
    for (int i = 0; i < key.length(); i++) { 
        int index = key[i] - 48; 
        if (!pCrawl->children[index]) 
            return false; 
        pCrawl = pCrawl->children[index]; 
    } 
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
  
// Driver 
int main() { 
    // Input keys (use only 'a' through 'z' 
    // and lower case) 
    string keys[] = {"5851", "123", "4585", 
                    "000", "85858", "2222", 
                     "888253", "888252" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
  
    struct TrieNode *root = getNode(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    // Search for different keys 
    search(root, "000")? cout << "Yes\n" : 
                         cout << "No\n"; 
    search(root, "45")? cout << "Yes\n" : 
                           cout << "No\n"; 
    return 0; 
} 