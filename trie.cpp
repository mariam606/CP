class Trie {
public:
    Trie* child[26];
    bool isleaf = 0;
    Trie() {
        isleaf = 0;
        for (int i = 0; i < 26; i++)
            this->child[i] = nullptr;
    }
    void insert(string word) {
        Trie* cur = this;
        for (int i = 0; i < word.length(); i++){
            if (cur->child[word[i] - 'a'] == nullptr) 
                cur->child[word[i] - 'a'] = new Trie();       
            cur = cur->child[word[i] - 'a'];
        }
        cur->isleaf = true;   
    }
    bool search(string word){
        if(this == 0) return false;
        Trie* cur = this;
        for(int i = 0; i < word.length(); ++i){
            cur = cur->child[word[i] - 'a'];
            if (cur == nullptr) 
                return false;
        }
        return cur->isleaf;
    }
    
    bool startsWith(string prefix) {
        if(this == nullptr) return false;
        Trie* cur = this;
        for(int i = 0 ; i < prefix.length(); ++i){
            cur = cur-> child[prefix[i] - 'a'];
            if(cur == 0)
                return false;
        }
        return true; 
    }
};
