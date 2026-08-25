class PrefixTree {
public:

    struct node{
        node* child[26];
        int cnt_prefix,cnt_exact;
        node(){
            for (int i=0;i<26;i++){
                child[i] = nullptr;
            }
            cnt_prefix = cnt_exact = 0;
        }
    };

    node* root;

    PrefixTree() {
        root = new node();
    }
    
    void insert(string s) {
        node* cur = root;
        for (auto& c: s){
            cur->cnt_prefix++;
            if (cur->child[c-'a'] == nullptr){
                cur->child[c-'a'] = new node();
            }
            cur = cur->child[c-'a'];
        }
        cur->cnt_exact++;
    }
    
    bool search(string s) {
        node* cur = root;
        for (auto& c: s){
            if (cur->child[c-'a'] == nullptr) return false;
            cur = cur->child[c-'a'];
        }
        if (cur->cnt_exact > 0) return true;
        return false;
    }
    
    bool startsWith(string p) {
        node* cur = root;
        for (auto& c: p){
        if (cur->child[c-'a'] == nullptr) return false;
            cur = cur->child[c-'a'];
        }
        if (cur->cnt_exact + cur->cnt_prefix > 0) return true;
        return false;
    }
};
