class Solution {
public:
    unordered_map<string,vector<char>> mp;
    unordered_set<string> failed; 

    bool pyramidTransition(string bottoms, vector<string>& allowed) {
        for(string s:allowed){
            string key=s.substr(0,2);
            char value=s[2];
            mp[key].push_back(value);
        }

        return dfs(bottoms);
    }
private:
    bool dfs(string bottom){
        if(failed.count(bottom)) return false;

        if(bottom.size()==1){
            return true;
        }

        vector<string> nextRows;
        string temp="";

        buildRow(bottom,0,temp,nextRows);

        for(string next:nextRows){
            if(dfs(next)) return true;
        }

        failed.insert(bottom);
        return false;
    }

    void buildRow(string &bottom, int index, string &temp,vector<string> &nextRows){
        
        if(index==bottom.size()-1){
            nextRows.push_back(temp);
            return;
        }

        string pair=bottom.substr(index,2);
        if (mp.find(pair) == mp.end()) return;

        for(char ch:mp[pair]){
            temp.push_back(ch);
            buildRow(bottom,index+1,temp,nextRows);
            temp.pop_back();
        }

    }
};

