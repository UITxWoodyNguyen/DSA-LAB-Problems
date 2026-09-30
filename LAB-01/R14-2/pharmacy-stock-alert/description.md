# Pharmacy Stock Alert

## Problem Statement
A pharmacist needs to identify which medicine is running lowest on stock to trigger a reorder. Given **N** medicines and their stock levels, find the medicine with the **minimum stock**. If there's a tie, return the **first** one in the list.

## Input Format
* Line 1: Integer **N** ($1 \le N \le 1,000,000$)
* Lines 2 to N+1: `name stock`

## Output Format
* The name of the medicine with the lowest stock.

## Sample Test Cases

| Input | Output |
| :--- | :--- |
| 4<br>Aspirin 50<br>Ibuprofen 20<br>Paracetamol 5<br>Amoxicillin 30 | Paracetamol |
| 3<br>DrugA 100<br>DrugB 100<br>DrugC 100 | DrugA |

## Constraints
* $1 \le N \le 1,000,000$
* $1 \le \text{stock} \le 10^6$

## Limitations
* Language: C++
* Time limit: 3.5s
* Memory limit: 50MB