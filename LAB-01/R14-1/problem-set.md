# [IT003.R14.1] Assignment 1 - Problem Set

## 1. First Absent Student

* **Giới hạn thực thi (C++):** `0.5s`, `50MB`
* **Điểm:** 10

### Problem Statement

A teacher is taking attendance for a class of $N$ students. Each student is marked either **P** (Present) or **A** (Absent). The teacher wants to find the **first absent student** in the list to address them.

### Input Format

* **Line 1:** Integer $N$ ($1 \le N \le 1,000,000$)
* **Lines 2 to $N+1$:** `name status` (status is `P` or `A`)

### Output Format

* The name of the first absent student, or `All Present` if none.

### Constraints

* $1 \le N \le 1,000,000$
* Names are alphabetic, length $1\text{--}30$

### Sample Test Cases

| Input | Output |
| :--- | :--- |
| `4`<br>`Alice P`<br>`Bob A`<br>`Charlie P`<br>`Diana A` | `Bob` |
| `3`<br>`Tom P`<br>`Jerry P`<br>`Spike P` | `All Present` |

---

## 2. binary.search (Giam dan) no recursive & recursive (nộp 2 cách)

* **Giới hạn thực thi (C++):** `0.5s`, `50MB`
* **Điểm:** 15

### Problem Statement

Tìm giá trị $X$ trong mảng 1 chiều lưu $n$ phần tử ($n \le 150,000$) các số nguyên ($< 1\text{ tỷ}$) **GIẢM DẦN**.

> **Yêu cầu:** Viết hàm tìm kiếm tuyến nhị phân **KHÔNG sử dụng đệ quy**.

### Input

Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)

* Số nguyên đầu tiên: số nguyên $X$ cần tìm.
* Số nguyên thứ hai: số lượng phần tử của mảng 1 chiều.
* Các số nguyên còn lại: giá trị của các phần tử của mảng.

### Output

Xuất ra `true` nếu tìm thấy, `false` nếu không tìm thấy.

### Example

| Input | Output |
| :--- | :--- |
| `4`<br>`7`<br>`20 15 10 8 5 4 1` | `true` |
| `7`<br>`0` | `false` |
| `7`<br>`3`<br>`12 1 -9` | `false` |

---

## 3. [share chung] Upper Bound (dùng binary.search)

* **Giới hạn thực thi (C++):** `1s`, `50MB`
* **Điểm:** 10

### Problem Statement

Cho một dãy số nguyên $a$ gồm $N$ phần tử.

Có $Q$ truy vấn, mỗi truy vấn cho một số nguyên $x$. Với mỗi truy vấn, hãy tìm số nhỏ nhất trong dãy $a$ mà lớn hơn $x$.

Nếu không có phần tử nào lớn hơn $x$, hãy in ra `-1`.

### Input

* Dòng đầu tiên chứa hai số nguyên dương $N, Q$ ($1 \le N \le 10^5$, $1 \le Q \le 5 \times 10^5$).
* Dòng thứ hai chứa $N$ số nguyên — các phần tử của mảng $a$ ($-10^9 \le a_i \le 10^9$).
* $Q$ dòng tiếp theo, mỗi dòng chứa một số nguyên $x$ ($-10^9 \le x \le 10^9$).

### Output

* Gồm $Q$ dòng, mỗi dòng in ra số nhỏ nhất trong mảng $a$ lớn hơn $x$.
* Nếu không có phần tử nào lớn hơn $x$, in ra `-1`.

### Ví dụ

| Input | Output |
| :--- | :--- |
| `10 8`<br>`10 -5 15 4 -2 0 7 -2 10 3`<br>`-3`<br>`4`<br>`8`<br>`15` | `-2`<br>`7`<br>`10`<br>`-1`<br>`-1` |

---

## 4. selection.sort

* **Giới hạn thực thi (C++):** `2.5s`, `50MB`
* **Điểm:** 15

### Problem Statement

Sắp xếp mảng một chiều các số nguyên tăng dần bằng phương pháp **selection sort**. Biết rằng số lượng phần tử của mảng $< 100,000$; giá trị các phần tử $< 1\text{ tỷ}$.

### Input

Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)

* Số nguyên đầu tiên: số lượng phần tử của mảng.
* Các số nguyên còn lại: giá trị của các phần tử của mảng.

### Output

`"true"` nếu mảng sắp xếp thành công. `"false"` nếu mảng sắp không thành công.

### Example

| Input | Output |
| :--- | :--- |
| `7`<br>`12`<br>`14`<br>`0`<br>`41`<br>`567`<br>`0`<br>`-545` | `true` |

---

## 5. Chen tang

* **Giới hạn thực thi (C++):** `0.5s`, `50MB`
* **Điểm:** 15

### Problem Statement

Chèn giá trị $X$ trong mảng 1 chiều lưu $n$ phần tử ($n \le 150,000$) các số nguyên ($< 1\text{ tỷ}$) **TĂNG DẦN**. Sau khi chèn ta vẫn sẽ được mảng 1 chiều có thứ tự **TĂNG DẦN**.

> **Yêu cầu:** Áp dụng hàm tìm kiếm tuyến tính.

### Lưu ý

* Không dùng thuật toán sắp xếp.
* Dùng thuật toán tìm kiếm có số lần so sánh ít nhất trong các thuật toán có độ phức tạp $O(n)$ đã học.

### Input

Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)

* Số nguyên đầu tiên: số nguyên $X$ cần thêm vào.
* Số nguyên thứ hai: số lượng phần tử của mảng 1 chiều.
* Các số nguyên còn lại: giá trị của các phần tử của mảng.

### Output

Xuất ra mảng số nguyên đã thêm $X$.

### Example

| Input | Output |
| :--- | :--- |
| `18`<br>`7`<br>`1 4 6 7 9 10 15` | `1 4 6 7 9 10 15 18` |
| `0`<br>`7`<br>`1 4 6 7 9 10 15` | `0 1 4 6 7 9 10 15` |
| `2`<br>`0` | `2` |

---

## 6. insertion.sort (ms-kB)

* **Giới hạn thực thi (C++):** `1.5s`, `50MB`
* **Điểm:** 15

### Problem Statement

Sắp xếp mảng một chiều các số nguyên **giảm dần** bằng phương pháp `insertion sort`. Biết rằng số lượng phần tử của mảng $\le 30,000$; giá trị các phần tử $< 1\text{ tỷ}$.

### Input

Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)

* Số nguyên đầu tiên: số lượng phần tử của mảng.
* Các số nguyên còn lại: giá trị của các phần tử của mảng.

### Output

Xuất trên 2 dòng liền kề nhau:

* **Dòng 1:** Xuất số lượng phần tử mảng.
* **Dòng 2:** Xuất danh sách đã được sắp xếp, mỗi phần tử cách nhau 1 khoảng trắng. Nếu mảng rỗng thì dòng này trống.

### Example

| Input | Output |
| :--- | :--- |
| `7`<br>`8 5 3 9 0 1 2` | `7`<br>`9 8 5 3 2 1 0` |
| `0` | `0` |

---

## 7. Chen tang dung binary.search

* **Giới hạn thực thi (C++):** `0.5s`, `50MB`
* **Điểm:** 10

### Problem Statement

Chèn giá trị $X$ trong mảng 1 chiều lưu $n$ phần tử ($n \le 150,000$) các số nguyên ($< 1\text{ tỷ}$) **TĂNG DẦN**. Sau khi chèn ta vẫn sẽ được mảng 1 chiều có thứ tự **TĂNG DẦN**. Lưu ý không dùng thuật toán sắp xếp.

> **Yêu cầu:** Áp dụng hàm tìm kiếm nhị phân **KHÔNG sử dụng đệ quy**.

### Input

Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)

* Số nguyên đầu tiên: số nguyên $X$ cần thêm vào.
* Số nguyên thứ hai: số lượng phần tử của mảng 1 chiều.
* Các số nguyên còn lại: giá trị của các phần tử của mảng.

### Output

Xuất ra mảng số nguyên đã thêm $X$.

### Example

| Input | Output |
| :--- | :--- |
| `18`<br>`7`<br>`1 4 6 7 9 10 15` | `1 4 6 7 9 10 15 18` |
| `0`<br>`7`<br>`1 4 6 7 9 10 15` | `0 1 4 6 7 9 10 15` |
| `2`<br>`0` | `2` |

---

## 8. Bài 07 - Insertion Sort danh sách sinh viên

* **Chủ đề:** Insertion sort + comparator nhiều điều kiện
* **Độ khó:** Trung bình
* **Điểm:** 10

### Vấn đề

Cho danh sách $n$ sinh viên, mỗi sinh viên gồm **mã số** (số nguyên), **tên** (chuỗi không chứa khoảng trắng) và **điểm** (số nguyên). Hãy sắp xếp danh sách bằng thuật toán **Insertion Sort** theo quy tắc:

* Giảm dần theo điểm.
* Nếu cùng điểm thì tăng dần theo tên (so sánh theo thứ tự từ điển).

### Input

* Dòng đầu chứa số nguyên $n$.
* $n$ dòng tiếp theo, mỗi dòng gồm: mã số, tên, điểm (cách nhau bởi khoảng trắng).

### Output

* In danh sách sinh viên sau khi sắp xếp thỏa mãn điều kiện đề bài.

---

## 9. ĐỔI MỚI (Renew - optional)

* **Giới hạn thực thi (C++):** `0.5s`, `50MB`
* **Điểm:** 0 (optional)

### Problem Statement

Thành phố quyết định chặt hạ hết $n$ cây xanh hiện có trong thành phố để trồng chỉ một loại cây mới. Nhiệm vụ được giao cho Công ty Cây xanh thành phố. Do hạn chế về thiết bị, Công ty chỉ tổ chức được 2 đội đốn hạ cây:

* **Đội I:** hạ được $a$ cây mỗi ngày, nhưng cứ mỗi ngày thứ $k$ thì phải nghỉ để bảo dưỡng kỹ thuật, tức là đội I sẽ nghỉ vào các ngày $k, 2k, 3k, \dots$
* **Đội II:** hạ được $b$ cây mỗi ngày, nhưng cứ mỗi ngày thứ $m$ thì phải nghỉ để bảo dưỡng kỹ thuật, tức là đội II sẽ nghỉ vào các ngày $m, 2m, 3m, \dots$
* Ở ngày nghỉ, số cây chặt hạ của đội sẽ là 0. Cả hai đội bắt đầu công việc vào cùng một ngày và làm việc song song với nhau.

Công việc trồng cây mới sẽ bắt đầu sau khi toàn bộ cây cũ đã bị đốn hạ. Hãy xác định sau bao nhiêu ngày thì có thể bắt đầu việc trồng mới cây.

### Dữ liệu

Vào từ thiết bị nhập chuẩn gồm một dòng chứa 5 số nguyên $a, k, b, m$ và $n$:

* $1 \le a, b \le 10^9$
* $2 \le k, m \le 10^{18}$
* $1 \le n \le 10^{18}$

### Kết quả

Đưa ra thiết bị xuất chuẩn một số nguyên — số ngày tính được.

### Ví dụ

| INPUT | OUTPUT |
| :--- | :--- |
| `2 4 3 3 25` | `7` |