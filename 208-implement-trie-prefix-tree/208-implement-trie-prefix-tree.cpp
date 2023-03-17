const int ALPHABET_SIZE=26;
class Trie {
public:
    
    typedef struct TrieNode{
    struct TrieNode *child[ALPHABET_SIZE];
    bool isEndOfWord;
    }TrieNode;

    TrieNode *root = NULL;
    struct TrieNode * getNode(void){
        struct TrieNode *node = new TrieNode;
        node->isEndOfWord = false;
        for(int i=0; i<ALPHABET_SIZE;i++){
            node->child[i]=NULL; 
        }
        return node;
    }
    
    Trie() {
        
    }
    
    void insert(string word) {
        if(root == NULL)
            root = getNode();
        TrieNode *pcrawl = root;
        for(int i=0; i<word.length();i++){
            int index = word[i] - 'a';
            if(pcrawl->child[index] == NULL)
                pcrawl->child[index] = getNode();
            pcrawl = pcrawl->child[index];
        }
        pcrawl->isEndOfWord = true;
    }
    
    bool search(string word) {
        if(root == NULL)
            return false;
        TrieNode *pcrawl = root;
        for(int i=0; i<word.length();i++){
            int index = word[i] - 'a';
            if(pcrawl->child[index] == NULL)
                return false;
            pcrawl = pcrawl->child[index];
        }
        return (pcrawl->isEndOfWord);
    }
    
    bool startsWith(string prefix) {
        if(root == NULL)
            return false;
        TrieNode *pcrawl = root;
        for(int i=0; i<prefix.length();i++){
            int index = prefix[i] - 'a';
            if(pcrawl->child[index] == NULL)
                return false;
            pcrawl = pcrawl->child[index];
        }
        return true; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */