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