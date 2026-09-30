# Chèn Tăng (Binary Search)

## Problem Statement
Chèn giá trị $X$ trong mảng 1 chiều lưu $n$ phần tử ($n \le 150,000$) các số nguyên ($< 1\text{ tỷ}$) **TĂNG DẦN**. Sau khi chèn ta vẫn sẽ được mảng 1 chiều có thứ tự **TĂNG DẦN**. Lưu ý không dùng thuật toán sắp xếp.

> **Yêu cầu:** Áp dụng hàm tìm kiếm nhị phân **KHÔNG sử dụng đệ quy** (iterative).

## Input
Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)
* Số nguyên đầu tiên: số nguyên $X$ cần thêm vào.
* Số nguyên thứ hai: số lượng phần tử của mảng 1 chiều.
* Các số nguyên còn lại: giá trị của các phần tử của mảng.

## Output
Xuất ra mảng số nguyên đã thêm $X$.

## Example

| Input | Output |
| :--- | :--- |
| `18`<br>`7`<br>`1 4 6 7 9 10 15` | `1 4 6 7 9 10 15 18` |
| `0`<br>`7`<br>`1 4 6 7 9 10 15` | `0 1 4 6 7 9 10 15` |
| `2`<br>`0` | `2` |

## Limitations
* Language: C++
* Time limit: 0.5s
* Memory limit: 50MB