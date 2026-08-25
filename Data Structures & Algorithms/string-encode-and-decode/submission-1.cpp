using ll = long long;
class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        // pad each string with its size before with the character that has ascii value equal to the size

        for (auto& e: strs){
            ll sz = e.size();
            string szz = to_string(sz);
            s += szz;
            s += ";";
            s += e;
        }
        cout << s.size() << endl;
        return s;
    }

    vector<string> decode(string s) {
        vector<string> v;
        for (ll i=0;i<s.size();i++){
            string szz;
            while (s[i]!=';'){
                szz.push_back(s[i]);
                i++;
            }
            ll sz = stoll(szz);
            string e;
            for (ll j=i+1;j<=i+sz;j++){
                e.push_back(s[j]);
            }
            i = i+sz;
            v.push_back(e);
        }
        return v;
    }
};
