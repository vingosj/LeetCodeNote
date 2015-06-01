#include <map>

//   2015-5-31

class TrieNode {
public:
    // Initialize your data structure here.
    bool end;
    map<char, TrieNode*> index;
    TrieNode() : end(false) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        if(s == ""){
            this->root->end = true;
            true;
        }
        
        int n = s.size(), i = 0;
        TrieNode* node = root;
        while(i < n){
            if(node->index.count(s[i]) == 0){
                TrieNode* temp = new TrieNode();
                node->index[s[i]] = temp;
            }
            node = node->index[s[i++]];
        }
        node->end = true;
        return;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        if(key == "") return true;
        int n = key.size(), i = 0;
        TrieNode* node = root;
        while(i < n){
            if(node->index.count(key[i]) == 0) return false;
            node = node->index[key[i++]];
        }
        return node->end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if(prefix == "") return true;
        int n = prefix.size(), i = 0;
        TrieNode* node = root;
        while(i < n){
            if(node->index.count(prefix[i]) == 0) return false;
            node = node->index[prefix[i++]];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");