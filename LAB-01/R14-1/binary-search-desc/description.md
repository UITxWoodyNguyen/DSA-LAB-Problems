# Binary Search (Giảm dần) - Iterative & Recursive

## Problem Statement
Tìm giá trị $X$ trong mảng 1 chiều lưu $n$ phần tử ($n \le 150,000$) các số nguyên ($< 1\text{ tỷ}$) **GIẢM DẦN**.

> **Yêu cầu:** Viết hàm tìm kiếm tuyến nhị phân **KHÔNG sử dụng đệ quy** (iterative) VÀ một hàm **SỬ DỤNG ĐỆ QUY** (recursive).

## Input
Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)
* Số nguyên đầu tiên: số nguyên $X$ cần tìm.
* Số nguyên thứ hai: số lượng phần tử của mảng 1 chiều.
* Các số nguyên còn lại: giá trị của các phần tử của mảng.

## Output
Xuất ra `true` nếu tìm thấy, `false` nếu không tìm thấy.

## Example

| Input | Output |
| :--- | :--- |
| `4`<br>`7`<br>`20 15 10 8 5 4 1` | `true` |
| `7`<br>`0` | `false` |
| `7`<br>`3`<br>`12 1 -9` | `false` |

## Limitations
* Language: C++
* Time limit: 0.5s
* Memory limit: 50MB