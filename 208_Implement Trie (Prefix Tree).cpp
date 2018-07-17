class TrieNode{
public:
    unordered_map<char,TrieNode*> next;
};
class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        
        for(char ch: word)
        {
            if(!cur->next[ch])
            {
                cur->next[ch] = new TrieNode;
            }
            cur = cur->next[ch];
        }
        cur->next['\0'] = new TrieNode;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for(char ch: word)
        {
            if(!cur->next[ch])
            {
                return false;
            }
            cur = cur->next[ch];
        }
        return cur->next['\0'];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(char ch: prefix)
        {
            if(!cur->next[ch])
            {
                return false;
            }
            cur = cur->next[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
