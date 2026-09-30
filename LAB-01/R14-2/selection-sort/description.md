# [share chung] Selection Sort

Dựa vào đoạn code mẫu trong slide bài giảng, hãy cài đặt và tùy chỉnh thuật toán sắp xếp SelectionSort để sắp xếp mảng số nguyên A theo trật tự **giảm dần** và in ra màn hình theo mẫu ví dụ.

Các bạn có thể tham khảo code trong link sau, link2

## Input
* Dòng đầu tiên là số nguyên N dương ($0 < N < 200$)
* Dòng tiếp theo chứa N số nguyên (với giá trị mỗi số nguyên nhỏ hơn $2 \times 10^9$) là các phần tử của mảng A

## Output
* In ra màn hình theo mẫu ví dụ

## Example

| INPUT | OUTPUT |
| :--- | :--- |
| 7<br>3 0 8 2 1 4 7 | Mang truoc khi sap xep:<br>3 0 8 2 1 4 7<br><br>Sap xep:<br>i = 0<br>Mang truoc khi swap: 3 0 8 2 1 4 7<br>Phan tu lon nhat trong doan [1, 6]: 8<br>Swap 3 va 8<br>Mang sau khi swap: 8 0 3 2 1 4 7<br><br>i = 1<br>Mang truoc khi swap: 8 0 3 2 1 4 7<br>Phan tu lon nhat trong doan [2, 6]: 7<br>Swap 0 va 7<br>Mang sau khi swap: 8 7 3 2 1 4 0<br><br>i = 2<br>Mang truoc khi swap: 8 7 3 2 1 4 0<br>Phan tu lon nhat trong doan [3, 6]: 4<br>Swap 3 va 4<br>Mang sau khi swap: 8 7 4 2 1 3 0<br><br>i = 3<br>Mang truoc khi swap: 8 7 4 2 1 3 0<br>Phan tu lon nhat trong doan [4, 6]: 3<br>Swap 2 va 3<br>Mang sau khi swap: 8 7 4 3 1 2 0<br><br>i = 4<br>Mang truoc khi swap: 8 7 4 3 1 2 0<br>Phan tu lon nhat trong doan [5, 6]: 2<br>Swap 1 va 2<br>Mang sau khi swap: 8 7 4 3 2 1 0<br><br>i = 5<br>Mang truoc khi swap: 8 7 4 3 2 1 0<br>Phan tu lon nhat trong doan [6, 6]: 1<br>Swap 1 va 1<br>Mang sau khi swap: 8 7 4 3 2 1 0<br><br>Mang sau khi sap xep:<br>8 7 4 3 2 1 0 |