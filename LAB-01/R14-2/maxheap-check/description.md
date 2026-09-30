# MaxHeap Check

Kiểm tra dãy số có phải dãy maxheap không? **Yêu cầu bắt buộc: dùng các biến childLeft và childRight với ý nghĩa tương tự trong tài liệu slide đã học.**

## INPUT
Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)
* Số nguyên đầu tiên: số lượng phần tử của mảng ($>=0$)
* Các số nguyên còn lại: giá trị của các phần tử của mảng

## OUTPUT
Nếu thỏa tính chất MaxHeap, xuất `true`. Ngược lại xuất `false`

## EXAMPLE

| Input | Output |
| :--- | :--- |
| 10<br>10 9 5 5 6 4 0 1 2 4 | true |
| 0 | true |
| 2<br>8 9 | false |

## Limitations
* Language: C++
* (Runtime, Memory) = (0.5s, 50MB)