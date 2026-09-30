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