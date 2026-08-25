#include <string>
class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        // before the start of every string just mention where the next string starts
        for (auto& s: strs){
            int n = s.size();
            string len = to_string(n) + ",";
            encoded += len;
            encoded += s;
        }
        cout << encoded << endl;
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int n = s.size();
        for (int i=0;i<n;i++){
            int j = i;
            int sz = 0;
            cout << i << ":\n";
            while (j < n && s[j]!=','){
                sz = sz * 10 + (s[j]-'0');
                j++;
            }
            i = j+sz;
            cout << sz << ",";
            string str;
            j++;
            for (int k=0;k<sz;k++){
                str.push_back(s[j]);
                j++;
            }
            decoded.push_back(str);
        }
        return decoded;
    }
};
