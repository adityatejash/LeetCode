class Trie {
public:
    Trie* child[26];
    bool isWord;
    
    Trie() {
        isWord = false;
        for (int i=0; i<26; i++){
            child[i] = nullptr;
        }
    }
    
    void insert(string word) {
        Trie* temp = this;

        for (char c : word){
            int ind = c - 'a';

            if (temp->child[ind] == nullptr){
                temp->child[ind] = new Trie();
            }

            temp = temp->child[ind];
        }

        temp->isWord = true;
    }
    
    bool search(string word) {
        Trie* temp = this;

        for (char c : word){
            int ind = c - 'a';

            if (temp->child[ind] == nullptr){
                return false;
            }

            temp = temp->child[ind];
        }

        return temp->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* temp = this;

        for (char c : prefix){
            int ind = c - 'a';

            if (temp->child[ind] == nullptr){
                return false;
            }

            temp = temp->child[ind];
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