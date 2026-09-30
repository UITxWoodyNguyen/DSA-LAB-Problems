# First Absent Student

## Problem Statement
A teacher is taking attendance for a class of $N$ students. Each student is marked either **P** (Present) or **A** (Absent). The teacher wants to find the **first absent student** in the list to address them.

## Input Format
* **Line 1:** Integer $N$ ($1 \le N \le 1,000,000$)
* **Lines 2 to $N+1$:** `name status` (status is `P` or `A`)

## Output Format
* The name of the first absent student, or `All Present` if none.

## Constraints
* $1 \le N \le 1,000,000$
* Names are alphabetic, length $1\text{--}30$

## Sample Test Cases

| Input | Output |
| :--- | :--- |
| `4`<br>`Alice P`<br>`Bob A`<br>`Charlie P`<br>`Diana A` | `Bob` |
| `3`<br>`Tom P`<br>`Jerry P`<br>`Spike P` | `All Present` |

## Limitations
* Language: C++
* Time limit: 0.5s
* Memory limit: 50MB