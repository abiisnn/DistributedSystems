#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include "respuesta.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <iostream>
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

int main(int argc, char* argv[]){
	// Root of Trie
	struct TrieNode *root = getNode(); 
	int dest;
	if((dest = open(argv[1],  O_WRONLY | O_APPEND)) == -1){
		perror(argv[1]);
		exit(-1);
	}
	Respuesta r(7200);

	while(1) {
		struct mensaje *m;
		int num[1];
		timeval hora;
		gettimeofday(&hora,NULL);
		m = r.getRequest();
		//printf("segundos: %ld\n",hora.tv_sec);
		//printf("microsegundos: %ld\n",hora.tv_usec);
		int reply = 0;
		//cout << "Recibí cadena " << i << endl;
	
		if(m != NULL) {
			char datos[31];
			memcpy(datos, m->arguments, sizeof(char) * 31);
		
			string aux="";	
			for(int i =0; i < 10; i++)
				aux += datos[i];				
			cout << aux <<endl;
			if(aux == "10") {
				close(dest);
				r.sendReply((char *)&hora);
				break;
			}
			if(search(root, aux)) {
				//poner hora en cero
				//contestar
				hora.tv_sec = 0;
				hora.tv_usec = 0;
				r.sendReply((char *)&hora);
				printf("---------------------TELEFONO REPETIDO----------------------\n");	
				continue;
			}
			else {
				// Add trie
				insert(root, aux);
			}
						
			write(dest, datos, 31);
			write(dest, " ", 1);
			write(dest,to_string(hora.tv_sec).c_str(),strlen(to_string(hora.tv_sec).c_str()));
			write(dest, " ", 1);
			write(dest,to_string(hora.tv_usec).c_str(),strlen(to_string(hora.tv_usec).c_str()));
			write(dest, "\n", 1);
			fsync(dest);
			reply = 1;
			r.sendReply((char *)&hora);
		}
	}

	return 0;
}
