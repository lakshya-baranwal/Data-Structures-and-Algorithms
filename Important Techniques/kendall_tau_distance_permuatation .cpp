// Kendall-Tau Distance
// Minimum number of adjacent swaps needed to transform permutation b into permutation a.
int dis(vector<int> a, vector<int> b){
   int l = a.size()-1;
   vector<int> pos(l+1);
   for(int i = 1; i <= l; i++){
      pos[a[i]] = i;
   }
   for(int i = 1; i <= l; i++){
      b[i] = pos[b[i]];
   }

   int cost = 0;
   // count number of inversions in b
   // can be done in nlogn using fenwick tree 
   // each adjacent swap fixes atmost one swap
   for(int i = 1; i <= l; i++){
      for(int j = 1; j < i; j++){
          if(b[j] > b[i]) cost++;
      }
   }
   return cost;
}
