//DISJOINT SET UNION (DSU)

//Find
int find(int i, vector<int> &parent){
 if(i == parent[i]) return i;
 
 return find(parent[i], parent);
}

//Union
vector<int> parent;
void union(int x, int y, vector<int>& parent){
 int x_parent = find(x, parent);
 int y_parent = fint(y, parent);

 if(x_parent != y_parent){
  parent[x_parent] = y_parent; 
 }
}

//Path Compression
int find(int i, vector<int> &parent){
 if(i == parent[i]) return i;
 
 return parent[i] = find(parent[i], parent);
}

//Union by rank (Less Depth and Fast Query)
vector<int> parent;
vector<int> rank;

	void union(int x, int y, vector<int>& parent, vector<int>& rank){
  	 int x_parent = find(x, parent);
  	 int y_parent = find(y, parent);
  	 if(x_parent == y_parent) return;
  
 	  if(rank[x_parent] > rank[y_parent]){
 	   parent[y_parent] = x_parent;
 	  }
 	  else if(rank[x_parent] < rank[y_parent]){
 	  parent[x_parent] = y_parent;
 	  }
 	  else{
 	  parent[y_parent] = x_parent;
 	  rank[x_parent]++;
 	  }
	}	


IMPLEMENTATION OF DISJOINT SET / UNION FIND USING DSU CLASS
 class DSU {
    vector<int> parent, rank;
    public:
    DSU(int n){
        parent.resize(n+1,0);
        rank.resize(n+1, 1);
        for(int i = 0; i < n+1; i++){
            parent[i] = i;
        }
    }
    int find(int i){
     if(i == parent[i]) return i;
 
    return parent[i] = find(parent[i]);
    }

    void unite(int x, int y){
     int x_parent = find(x);
     int y_parent = find(y);
     if(x_parent == y_parent) return;
  
     if(rank[x_parent] > rank[y_parent]){
       parent[y_parent] = x_parent;
     }
     else if(rank[x_parent] < rank[y_parent]){
       parent[x_parent] = y_parent;
     }
     else{
       parent[y_parent] = x_parent;
       rank[x_parent]++;
     }
    }
};
