class Solution {
public:
    string simplifyPath(string path) {
        string s;
        int n = path.size();
        for (int i=0;i<n;i++){
            if (path[i] == '/'){
                if (s.empty() || s.back() != '/'){
                    s.push_back('/');
                }
            }
            else if (path[i] == '.'){
                int j = i;
                while (j < n && path[j]!='/'){
                    j++;
                }
                int cnt = j-i;
                if (cnt > 2){
                    j = i;
                    while (j < n && path[j]=='.'){
                        s.push_back('.');
                        j++;
                    }
                }
                else{ 
                    while (!s.empty() && cnt > 0){
                        if (s.back()=='/') cnt--;
                        s.pop_back();
                    }
                }
                i = j-1;
            }
            else{
                int j = i;
                while (j < n && path[j] != '/'){
                    s.push_back(path[j]);
                    j++;
                }
                i = j-1;
            }
        }
        if (s.back()=='/') s.pop_back();
        if (s.empty()) s.push_back('/');
        return s;
    }
};