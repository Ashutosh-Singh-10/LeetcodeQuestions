#include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    #include<iostream>
    template <class T> using OrderSet = tree<T, null_type, 
    less<T>, rb_tree_tag,tree_order_statistics_node_update>;
class Solution {
public:

    int numTeams(vector<int>& rating) {
        int ans=0;
        OrderSet<int> a,b;
        for(auto &i:rating) 
        {
            b.insert(i);
        }
        for(auto &i:rating) 
        {
            auto x=a.order_of_key(i);
            auto y=b.order_of_key(i+1);
            ans+=x*(b.size()-y);

            x=b.order_of_key(i);
            y=a.order_of_key(i+1);
            ans+=x*(a.size()-y);

            a.insert(i);
            b.erase(b.find(i));
        }
        return ans;

        
        

        
    }
};