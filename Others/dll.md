# Doubly Linked List (std::list) – Quick Reference

## Note

A doubly linked list supports:

1. Bidirectional traversal
2. O(1) insertion and deletion of a given node

---

## Insertion Operations

```cpp
dll.push_front(x);              // insert at head
dll.push_back(x);               // insert at tail
auto it = dll.begin();
dll.insert(it, x);              // insert before iterator
```

---

## Deletion Operations

```cpp
dll.pop_front();                // remove head (O(1))
dll.pop_back();                 // remove tail (O(1))
dll.erase(it);                  // erase node at iterator (O(1))
```

---

## Access Operations

```cpp
dll.front();                    // access head element (O(1))
dll.back();                     // access tail element (O(1))
```

---

## Node Movement

```cpp
dll.splice(dll.end(), dll, it);     // move node at it to end (O(1))
dll.splice(dll.begin(), dll, it);   // move node at it to front (O(1))
```
