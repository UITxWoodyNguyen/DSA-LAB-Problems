# Insertion Sort (Giảm dần)

## Problem Statement
Sắp xếp mảng một chiều các số nguyên **giảm dần** bằng phương pháp `insertion sort`. Biết rằng số lượng phần tử của mảng $\le 30,000$; giá trị các phần tử $< 1\text{ tỷ}$.

## Input
Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)
* Số nguyên đầu tiên: số lượng phần tử của mảng.
* Các số nguyên còn lại: giá trị của các phần tử của mảng.

## Output
Xuất trên 2 dòng liền kề nhau:
* **Dòng 1:** Xuất số lượng phần tử mảng.
* **Dòng 2:** Xuất danh sách đã được sắp xếp, mỗi phần tử cách nhau 1 khoảng trắng. Nếu mảng rỗng thì dòng này trống.

## Example

| Input | Output |
| :--- | :--- |
| `7`<br>`8 5 3 9 0 1 2` | `7`<br>`9 8 5 3 2 1 0` |
| `0` | `0` |

## Limitations
* Language: C++
* Time limit: 1.5s
* Memory limit: 50MB