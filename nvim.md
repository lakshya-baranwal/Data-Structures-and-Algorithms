# Neovim Basics

A quick reference for moving, editing, copying, and managing text in Neovim.

---

## Moving Around

* `h` → left
* `l` → right
* `j` → down
* `k` → up
* `0` → beginning of line
* `^` → first non-blank character of line
* `$` → end of line
* `w` → jump to beginning of next word
* `e` → jump to end of current/next word
* `b` → jump to beginning of previous word
* `gg` → top of file
* `G` → bottom of file
* `{number}G` → go to line number (e.g. `42G`)

### Page-wise movement

* `Ctrl + f` → move forward one page (page down)
* `Ctrl + b` → move backward one page (page up)
* `Ctrl + d` → move down half a page
* `Ctrl + u` → move up half a page

---

## Editing and Deleting

* `i` → insert before cursor
* `a` → insert after cursor
* `o` → open new line below
* `O` → open new line above
* `dd` → delete current line
* `5dd` → delete 5 lines starting here
* `d$` → delete from cursor to end of line
* `d0` → delete from cursor to beginning of line
* `x` → delete one character
* `X` → delete character before cursor
* `V + move + d` → select multiple lines and delete

---

## Undo and Redo

* `u` → undo
* `Ctrl + r` → redo

---

## Copy and Paste

* `yy` → copy current line
* `5yy` → copy 5 lines
* `yw` → copy one word
* `y$` → copy from cursor to end of line

Paste:

* `p` → paste after cursor / line
* `P` → paste before cursor / line

---

## Cut and Paste

* `dd` → cut current line
* Move cursor where you want to put it
* `p` → paste after cursor
* `P` → paste before cursor

---

## Visual Mode (select and act)

* `v` → start character selection
* `V` → start line selection
* `Ctrl + v` → start block selection
* After selecting:

  * `d` → delete
  * `y` → copy
  * `p` → paste

---

## Searching and Replacing

* `/word` → search for "word" forward
* `?word` → search for "word" backward
* `n` → next occurrence
* `N` → previous occurrence
* `:%s/old/new/g` → replace all `old` with `new` in file
* `:10,20s/foo/bar/g` → replace between lines 10–20

---

## Saving and Quitting

* `:w` → save
* `:q` → quit
* `:wq` or `ZZ` → save and quit
* `:q!` → quit without saving

---
