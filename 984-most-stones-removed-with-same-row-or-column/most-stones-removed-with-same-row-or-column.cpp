class DSU{public:
	long long size=0;  vector<long long> vec;
	DSU(long long n)
	{
		size=n;
		for(long long i=0;i<n;i++)        vec.push_back(i);
	}
	void join(long long x,long long y){
		vector<long long> a,b;
		while(vec[x]!=x)
		{
			a.push_back(x);
			x=vec[x];
		}
		while(vec[y]!=y)
		{
			b.push_back(y);
			y=vec[y];
		}
		for(auto &i:a)    vec[i]=y;
		for(auto &i:b)    vec[i]=y;
		vec[x]=y;
	}
	long long parent(long long a)
	{
		vector<long long> arr;
		while(vec[a]!=a)
		{

		 a=vec[a];
		 arr.push_back(a);
		}
		for(auto &i:arr)
		{
			vec[i]=a;

		}
		return a;
	}
	void print()
	{
		for(auto & i:vec)cout<<i<<" ";cout<<endl;
	}
	long long clusters()
	{
		set<long long> st;
		for(long long i=0;i<size;i++)    st.insert(parent(i));
		return st.size();
	}
	void printClusters()
	{
		map<long long,vector<long long>> mp;
		for(int i=0;i<size;i++)
		{
			mp[parent(i)].push_back(i);
		}
		for(auto &[a,b]:mp)
		{
			cout<<a<<"    ->    ";
			for(auto  &j:b)
			{
				cout<<j<<" ";
			}
			cout<<"\n";

		}
	}

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DSU ds(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    ds.join(i,j);
                }
            }
        }
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[ds.parent(i)]++;
        }
        int ans=0;
        for(auto &[a,b]:mp)
        {
            ans+=b-1;
        }
        return ans;

        
    }
};