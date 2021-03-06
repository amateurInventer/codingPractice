// searches a string in dictionary in O(L) time
// has facility to count the prefixes
// 1)- web browser can auto complete your text or show you many
//     possibilities of the text that you could be writing.
// 2)- an orthographic corrector can check that every word that 
//     you type is in a dictionary.
// 3)- for suggested corrections of the words that are present 
//     in the text but not in the dictionary.

#include<iostream>
#include<string>
#include <stdlib.h>
struct TrieNode {
   bool isEndOfWord;
   TrieNode *children[26];
};

TrieNode * getTrieNode() {
   TrieNode *temp = (TrieNode*)malloc(sizeof(TrieNode));
   temp->isEndOfWord = false;
   for(int i=0; i<26; ++i)
     temp->children[i] = NULL;
   return temp;
}

bool search(TrieNode *head, std::string str ) {
   for(int i=0; i<str.size(); ++i){
      int index = str[i]-'a';
      if(head->children[index]==NULL)
         return false;
      head = head->children[index];
   } 
   return head->isEndOfWord;
}

int main() {
   TrieNode *root = getTrieNode(); 
   TrieNode *head = root;
   std::string dict[10] = {"dog","cat","door","cater","ear","ease","ant","and","told","top"};
   for(int i=0; i<10; ++i) {
      for(int j=0; j<dict[i].size();++j) {
         int index = dict[i][j]-'a';
         if(head->children[index]==NULL) {
            head->children[index] = getTrieNode();
         }  
         head = head->children[index];
      }
      head->isEndOfWord = true;
      head = root;
   }
   std::cout << "search do " << search(root,"do") << std::endl;
   std::cout << "search ca " << search(root,"ca") << std::endl;
   std::cout << "search dor " << search(root,"dor") << std::endl;
   std::cout << "search an " << search(root,"an") << std::endl;
   std::cout << "search ant " << search(root,"ant") << std::endl;
   std::cout << "search cat " << search(root,"cat") << std::endl;

   return 0;
}
