struct Node {
    map<string, Node*> child;
};

class Solution {
private:
    string computeFreq(map<string, int>& freq, Node* node) {
        if(!node)
            return "";

        string curr = "";
        for(auto x : node->child){
            curr+=x.first;
            curr+="/";
            string childStr = computeFreq(freq, x.second);
            curr+=childStr;
            curr+="/";
        }
        freq[curr]++;
        return curr;
    }

    pair<vector<vector<string>>, string> computeAns(map<string, int>& freq, Node* node, vector<string>&currVec){
        if(!node)
            return {{},""};

        string curr = "";
        vector<vector<string>>combinedRes;
        
        if(currVec.size())
            combinedRes.push_back(currVec);

        for(auto x : node->child){
            curr+=x.first;
            currVec.push_back(x.first);
            pair<vector<vector<string>>, string> childRes = computeAns(freq, x.second, currVec);
            string childStr = childRes.second;
            for(auto res: childRes.first)
                combinedRes.push_back(res);
            curr+="/";
            curr+=childStr;
            curr+="/";
            currVec.pop_back();
        }

        if(curr != "" && freq[curr] > 1) // Not a leaf & Have been seen multiple times
            return {{}, curr};

        return {combinedRes, curr};
    }
public:
    vector<vector<string>>
    deleteDuplicateFolder(vector<vector<string>>& paths) {
        vector<string>curr;
        map<string, int> freq;

        // Graph Construction
        Node* root = new Node();
        for (auto path : paths) {
            int pathSize = path.size();
            Node* node = root;
            for (int i = 0; i < pathSize; i++) {
                if (node->child.find(path[i]) == node->child.end())
                    node->child[path[i]] = new Node();
                node = node->child[path[i]];
            }
        }

        computeFreq(freq, root);
        pair<vector<vector<string>>, string> res = computeAns(freq, root, curr);

        return res.first;
    }
};