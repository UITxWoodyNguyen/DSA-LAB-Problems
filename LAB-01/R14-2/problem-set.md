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

---

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

---

# [share chung] Lower Bound

Cho một dãy số nguyên a gồm N phần tử.

Có Q truy vấn, mỗi truy vấn cho một số nguyên x.  
Với mỗi truy vấn, hãy tìm số nhỏ nhất trong dãy a mà lớn hơn hoặc bằng x.

Nếu không có phần tử nào lớn hơn hoặc bằng x, hãy in ra -1.

## Input:
* Dòng đầu tiên chứa hai số nguyên dương N, Q ($1 \le N \le 10^5, 1 \le Q \le 5 \times 10^5$)
* Dòng thứ hai chứa N số nguyên — các phần tử của mảng a ($ -10^9 \le a_i \le 10^9 $)
* Q dòng tiếp theo, mỗi dòng chứa một số nguyên x ($ -10^9 \le x \le 10^9 $)

## Output:
* Gồm Q dòng, mỗi dòng in ra số nhỏ nhất trong mảng a lớn hơn hoặc bằng x.
* Nếu không có phần tử nào lớn hơn hoặc bằng x, in ra -1.

## Ví dụ:

| Input | Output |
| :--- | :--- |
| 10 8<br>10 -5 15 4 -2 0 7 -2 10 3<br>-3<br>4<br>8<br>15<br>16<br>-10<br>0<br>5 | -2<br>4<br>10<br>15<br>-1<br>-5<br>0<br>7 |

---

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

---

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

---

# Bài 07 - Insertion Sort danh sách sinh viên

**Chủ đề:** Insertion sort + comparator nhiều điều kiện  
**Độ khó:** Trung bình  

## Vấn đề
Cho danh sách $n$ sinh viên, mỗi sinh viên gồm **mã số** (số nguyên), **tên** (chuỗi không chứa khoảng trắng) và **điểm** (số nguyên). Hãy sắp xếp danh sách bằng thuật toán **Insertion Sort** theo quy tắc:
* Giảm dần theo điểm.
* Nếu cùng điểm thì tăng dần theo tên (so sánh theo thứ tự từ điển).

## Input
* Dòng đầu chứa số nguyên $n$.
* $n$ dòng tiếp theo, mỗi dòng gồm: mã số, tên, điểm (cách nhau bởi khoảng trắng).

## Output
* In ra $n$ dòng, mỗi dòng gồm mã số, tên, điểm của một sinh viên theo thứ tự đã sắp xếp.

## Ràng buộc
* $1 \le n \le 10^3$
* $1 \le \text{mã số} \le 10^9$
* $0 \le \text{điểm} \le 100$
* Tên gồm tối đa 20 ký tự chữ cái, không chứa khoảng trắng.

## Sample 1

### Input
```text
3
1 An 8
2 Binh 9
3 Cuong 8
```

### Output
```text
2 Binh 9
1 An 8
3 Cuong 8
```

## Sample 2

### Input
```text
4
10 Lan 7
11 Hoa 7
12 Mai 9
13 Nam 5
```

### Output
```text
12 Mai 9
11 Hoa 7
10 Lan 7
13 Nam 5
```

---

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

---

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

---

# Sắp xếp mảng một chiều bằng HeapSort

Sắp xếp mảng một chiều các số nguyên tăng dần bằng phương pháp heapsort. Biết rằng số lượng phần tử của mảng $\le 150,000$; giá trị các phần tử $< 1$ tỷ.

## INPUT
Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)
* Số nguyên đầu tiên: số lượng phần tử của mảng
* Các số nguyên còn lại: giá trị của các phần tử của mảng

## OUTPUT
Xuất trên 2 dòng liền kề nhau:
* Dòng 1: Xuất số lượng phần tử mảng
* Dòng 2: Xuất danh sách đã được sắp xếp, mỗi phần tử cách nhau 1 khoảng trắng. Nếu mảng rỗng thì dòng này trống

## EXAMPLE

| Input | Output |
| :--- | :--- |
| 7<br>8 5 3 9 0 1 2 | 7<br>0 1 2 3 5 8 9 |
| 0 | 0 |

---

# QUÀ TẶNG

*Tên chương trình: GIFTS.CPP*

Nhân dịp năm mới Steve quyết định mua tặng 2 người bạn thân của mình mỗi người một món quà. Trong cửa hàng lưu niệm có $n$ mặt hàng khác nhau, mặt hàng thứ $i$ có giá $a_i$, $i = 1 \div n$. Với tổng số tiền trong túi là $x$, Steve quyết định sẽ mua 2 món quà khác nhau có tổng giá trị lớn nhất và tất nhiên – không vượt quá khả năng chi trả của mình.

Ví dụ, có 6 mặt hàng với giá nêu ở trên và số tiền có thể chi tối đa là 18, Steve sẽ chọn các món quà thứ nhất và thứ ba. Tổng số tiền cần chi sẽ là $5 + 10 = 15$.

Hãy xác định tổng số tiền Steve cần chi trả.

## Dữ liệu: Vào từ thiết bị nhập chuẩn:
* Dòng đầu tiên chứa một số nguyên $n$ và $x$ ($2 \le n \le 10^5, 2 \le x \le 10^9$),
* Dòng thứ 2 chứa $n$ số nguyên $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9, i = 1 \div n$).

## Kết quả: Đưa ra thiết bị xuất chuẩn một số nguyên – số tiền cần chi trả.

## Ví dụ:

| INPUT | OUTPUT |
| :--- | :--- |
| 6 18<br>5 3 10 2 4 9 | 15 |