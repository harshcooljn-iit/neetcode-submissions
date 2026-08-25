class WordDictionary {
public:
    struct node{
        node* child[26];
        int cnt;
        node(){
            for (int i=0;i<26;i++){
                child[i] = nullptr;
            }
            cnt=0;
        }
    };

    node* root;
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string& s) {
        node* cur = root;
        for (auto& c: s){
            if (cur->child[c-'a'] == nullptr){
                cur->child[c-'a'] = new node();
            }
            cur = cur->child[c-'a'];
        }
        cur->cnt++;
    }

    bool bfs(string& s, node* cur, int i=0){
        if (i == s.size()){
            return cur->cnt > 0;
        }
        if (s[i] == '.'){
            bool ans = false;
            for (int j=0;j<26;j++){
                if (cur->child[j] != nullptr){
                    ans |= bfs(s, cur->child[j], i+1);
                    if (ans == true) return true;
                }
            }
            return false;
        }
        else{
            if (cur->child[s[i]-'a'] == nullptr) return false;
            return bfs(s, cur->child[s[i]-'a'], i+1);
        }
    }
    
    bool search(string& s) {
        node* cur = root;
        return bfs(s, cur);
    }
};
