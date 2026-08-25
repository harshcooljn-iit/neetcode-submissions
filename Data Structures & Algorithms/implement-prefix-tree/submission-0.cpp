class PrefixTree {
public:
    struct node{
        node* child[26];
        int cnt_end=0,cnt_prefix=0;
        node(){
            for(int i=0;i<26;i++){
                child[i] = nullptr;
            }
        }
    };
    node* root;
    PrefixTree() {
        root = new node();
    }
    
    void insert(string& s) {
        node* cur = root;
        for (auto& c: s){
            cur->cnt_prefix++;
            if (cur->child[c-'a'] == nullptr){
                cur->child[c-'a'] = new node();
            }
            cur = cur->child[c-'a'];
        }
        cur->cnt_end++;
    }
    
    bool search(string& s) {
        node* cur = root;
        for (auto& c: s){
            if (cur->child[c-'a'] == nullptr){
                return false;
            }
            cur = cur->child[c-'a'];
        }
        return cur->cnt_end>0;
    }
    
    bool startsWith(string& s) {
        node* cur = root;
        for (auto& c: s){
            if (cur->child[c-'a'] == nullptr){
                return false;
            }
            cur = cur->child[c-'a'];
        }
        return cur->cnt_end + cur->cnt_prefix>0;
    }
};
