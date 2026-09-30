# [share chung] Insertion Sort

Dựa vào đoạn code mẫu trong slide bài giảng, hãy cài đặt và tùy chỉnh thuật toán sắp xếp InsertionSort để sắp xếp mảng số nguyên A theo trật tự **giảm dần** và in ra màn hình theo mẫu ví dụ.

Các bạn có thể tham khảo code trong link sau, link2

## Input
* Dòng đầu tiên là số nguyên N dương ($0 < N < 200$)
* Dòng tiếp theo chứa N số nguyên (với giá trị mỗi số nguyên nhỏ hơn $2 \times 10^9$) là các phần tử của mảng A

## Output
* In ra màn hình theo mẫu ví dụ

## Example

| INPUT | OUTPUT |
| :--- | :--- |
| 7<br>3 0 8 2 1 4 7 | Mang truoc khi sap xep:<br>3 0 8 2 1 4 7<br><br>Sap xep:<br>i = 1<br>Mang truoc khi xu ly: 3 0 8 2 1 4 7<br>Phan tu dang xet A[1] = 0<br>Chen 0 vao vi tri k = 1<br>Mang sau khi xu ly: 3 0 8 2 1 4 7<br><br>i = 2<br>Mang truoc khi xu ly: 3 0 8 2 1 4 7<br>Phan tu dang xet A[2] = 8<br>Chen 8 vao vi tri k = 0<br>Mang sau khi xu ly: 8 3 0 2 1 4 7<br><br>i = 3<br>Mang truoc khi xu ly: 8 3 0 2 1 4 7<br>Phan tu dang xet A[3] = 2<br>Chen 2 vao vi tri k = 2<br>Mang sau khi xu ly: 8 3 2 0 1 4 7<br><br>i = 4<br>Mang truoc khi xu ly: 8 3 2 0 1 4 7<br>Phan tu dang xet A[4] = 1<br>Chen 1 vao vi tri k = 3<br>Mang sau khi xu ly: 8 3 2 1 0 4 7<br><br>i = 5<br>Mang truoc khi xu ly: 8 3 2 1 0 4 7<br>Phan tu dang xet A[5] = 4<br>Chen 4 vao vi tri k = 1<br>Mang sau khi xu ly: 8 4 3 2 1 0 7<br><br>i = 6<br>Mang truoc khi xu ly: 8 4 3 2 1 0 7<br>Phan tu dang xet A[6] = 7<br>Chen 7 vao vi tri k = 1<br>Mang sau khi xu ly: 8 7 4 3 2 1 0<br><br>Mang sau khi sap xep:<br>8 7 4 3 2 1 0 |

## Limitations
* Language: C++
* (Runtime, Memory) = (0.5s, 50MB)