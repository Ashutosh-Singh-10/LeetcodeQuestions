class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,pair<int,pair<int,char>>>> vec,rob;
        int x,bit;
        for(int i=0;i<healths.size();i++)
        {
            vec.push_back({positions[i],{healths[i],{i,directions[i]}}});
            healths[i]=0;
        }
        sort(vec.begin(),vec.end());
        // for(const auto &i:vec)
        // {
        //     cout<<i.first<<"  "<<i.second.first<<"   "<<i.second.second.first<<"  "<<i.second.second.second<<endl;
        // }
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i].second.second.second=='R')
            {
                
                rob.push_back(vec[i]);
            }
            else
            {
                x=rob.size()-1;
                bit=1;
                while(vec[i].second.second.second=='L' && rob.size())
                {
                    if(rob[rob.size()-1].second.first==vec[i].second.first)
                    {
                        rob.pop_back();
                        bit=0;
                        break;
                    }
                    else if(rob[x].second.first>vec[i].second.first)
                    {
                        rob[rob.size()-1].second.first--;
                        bit=0;
                   
                        break;
                    }
                    else
                    {
                        rob.pop_back();
                        vec[i].second.first--;
                            x--;
                    }
                }
                if(rob.size()==0 && bit)
                {
                     healths[vec[i].second.second.first]=vec[i].second.first;
                }
                
            }
        }
        for(const auto &i:rob)
        {
            healths[i.second.second.first]=i.second.first;
        }
        vector<int> fin;
        for(const auto &i:healths)
        {
            if(i)
            {
                fin.push_back(i);
            }
        }
        return fin;
        
        
    }
};