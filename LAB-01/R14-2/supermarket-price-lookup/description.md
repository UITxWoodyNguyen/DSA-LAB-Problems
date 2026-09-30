# Supermarket Price Lookup

## Problem Statement
A supermarket's inventory is sorted by product code (integer). Given a query product code, find its price using binary search.

## Input Format
* Line 1: Integer **N** ($1 \le N \le 2,000,000$)
* Lines 2 to N+1: `code price` (sorted by code)
* Line N+2: Query code

## Output Format
* Price or `Not Found`.

## Sample Test Cases

| Input | Output |
| :--- | :--- |
| 4<br>1001 25<br>2002 50<br>3003 75<br>4004 100<br>3003 | 75 |
| 3<br>100 10<br>200 20<br>300 30<br>250 | Not Found |

## Constraints
* $1 \le N \le 2,000,000$
* $1 \le \text{code} \le 10^9$
* $1 \le \text{price} \le 10^6$

## Limitations
* Language: C++
* (Runtime, Memory) = (0.999s, 50MB)