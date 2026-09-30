# Xây dựng mảng có tính chất max-heap

Xây dựng mảng có tính chất max-heap (Giả sử giá trị x có 2 liên đới bằng nhau thì ưu tiên chọn lưu đới bên trái). Biết rằng số lượng phần tử của mảng $\le 150,000$; giá trị các phần tử $< 1$ tỷ.

## INPUT
Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)
* Số nguyên đầu tiên: số lượng phần tử của mảng
* Các số nguyên còn lại: giá trị của các phần tử của mảng

## OUTPUT
Xuất trên 2 dòng liền kề nhau:
* Dòng 1: Xuất số lượng phần tử mảng
* Dòng 2: Xuất dãy max heap, mỗi phần tử cách nhau 1 khoảng trắng. Nếu mảng rỗng thì dòng này trống.

## EXAMPLE

| Input | Output |
| :--- | :--- |
| 10<br>5 5 5 5 6 6 6 10 20 20 | 10<br>20 20 6 10 6 5 6 5 5 5 |
| 10<br>5 9 4 5 6 10 0 1 2 4 | 10<br>10 9 5 5 6 4 0 1 2 4 |
| 0 | 0 |