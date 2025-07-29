// We have search in the form of this -> 00000000000000111111111111
// Either we are searching for the last zero or the first one

// 2 Invariants :
// Left -> 0 (left points to zero)
// right -> 1 (right points to one)

// Initialize left and right properly (l -> 0, r -> 1)
// Upon termination : right = left + 1

int l, r;
while(r > l + 1){
  int m = l + (r - l) >> 1;
  if(1 at mid){
    r = mid;
  } 
  else{
    l = mid;
  }
}

// After loop:
// r → index of first 1
// l → index of last 0
