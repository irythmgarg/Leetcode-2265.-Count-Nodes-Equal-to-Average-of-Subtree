# Leetcode-2265.-Count-Nodes-Equal-to-Average-of-Subtree

# 🧮 Average of Subtree — Binary Tree Problem

This repository provides two clean and efficient C++ implementations to solve the classic binary tree problem:

> **Count the number of nodes where the value of the node is equal to the average of all values in its subtree (including itself).**

---

## 📌 Problem Overview

Given the root of a binary tree, the task is to return the count of nodes whose values are equal to the **integer average** of values in their respective subtrees.

Each subtree includes the node itself and all of its descendants. The average is **integer division** (i.e., floor of sum divided by count).

---

## 🧠 Approaches

### ✅ Approach 1: Two-Pass DFS Using `unordered_map`

- **Step 1:** Traverse the tree once to count the number of nodes in each subtree using a hashmap.
- **Step 2:** Traverse again to calculate the subtree sum at each node and check if the average equals the node value.
- **Pros:** Clear separation of subtree size and sum logic.
- **Cons:** Requires extra space for a hash map.
- **Time Complexity:** `O(n)`  
- **Space Complexity:** `O(n)` due to the map.

---

### ✅ Approach 2: Single-Pass DFS with Pair Return

- **Step 1:** Perform a single DFS traversal.
- **Step 2:** At each node, return a pair containing:
  - Sum of the subtree
  - Number of nodes in the subtree
- Check the average directly during traversal.
- **Pros:** Clean, minimal space usage. No extra data structures.
- **Cons:** Slightly more tightly coupled logic.
- **Time Complexity:** `O(n)`  
- **Space Complexity:** `O(h)` (stack space; `h` is the height of the tree)

---

## 📊 Comparison Table

| Feature            | Two-Pass DFS (Map) | Single-Pass DFS |
|--------------------|--------------------|-----------------|
| Traversals         | 2                  | 1               |
| Extra Space        | `O(n)`             | `O(h)`          |
| Code Simplicity    | Moderate           | High            |
| Efficiency         | Good               | Excellent       |

---

## 👨‍💻 Author

**@ChatGPT (OpenAI)**  
This code and documentation were prepared with attention to clarity, structure, and performance, suitable for technical interviews or learning advanced tree traversal techniques.

---
