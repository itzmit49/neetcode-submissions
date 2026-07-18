class Node{
    public:
    Node* links[26]={nullptr};
    bool flag=false;

    bool containsKey(char ch){return links[ch-'a']!=nullptr;}
    void put(char ch,Node* node){links[ch-'a']=node;}
    Node* get(char ch){return links[ch-'a'];}
    bool isEnd(){ return flag;}
    void  setEnd(){flag=true;}

};
class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root=new Node();
        
    }
    void insert(string word) {

        Node* node = root;

        for (char ch : word) {

            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }

            node = node->get(ch);
        }

        node->setEnd();
    }

    
    void addWord(string word) {
        insert(word);
        
    }

    bool dfs(string &word, int idx, Node* node) {
    if (idx == word.size())
        return node->isEnd();

    char ch = word[idx];

    if (ch == '.') {
        for (int i = 0; i < 26; i++) {
            if (node->links[i] && dfs(word, idx + 1, node->links[i]))
                return true;
        }
        return false;
    }

    if (!node->containsKey(ch))
        return false;

    return dfs(word, idx + 1, node->get(ch));
}
    
    bool search(string word) {
       return dfs(word,0,root);
    }
};
