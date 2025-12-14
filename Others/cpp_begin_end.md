# `.begin()` and `.end()` in C++

This document explains what `.begin()` and `.end()` point to in C++ Standard Library containers.

---

## What they are

* `.begin()` and `.end()` are member functions of STL containers.
* They return **iterators**.
* Iterators represent positions inside a container.

---

## `.begin()`

* Points to the **first element** of the container.
* If the container is empty, `begin()` equals `end()`.

---

## `.end()`

* Points to **one position past the last element**.
* It does **not** point to a valid element.
* It is used as a termination marker.

---

## Why `.end()` is one past the last element

* Enables half-open ranges: `[begin, end)`
* Simplifies iteration logic
* Allows empty containers to be handled cleanly

---

## Const iterators

* `cbegin()` points to the first element (read-only)
* `cend()` points one past the last element (read-only)

---

## Reverse iterators

* `rbegin()` points to the last element
* `rend()` points one before the first element

---

## Important notes

* `end()` must never be dereferenced
* `end()` is not the last element
* Iterators can become invalid after modifying a container

---

## Summary

| Function   | Meaning               |
| ---------- | --------------------- |
| `begin()`  | First element         |
| `end()`    | One past last element |
| `cbegin()` | First element (const) |
| `cend()`   | One past last (const) |
| `rbegin()` | Last element          |
| `rend()`   | Before first element  |

---

Always work within the range `[container.begin(), container.end())`.
