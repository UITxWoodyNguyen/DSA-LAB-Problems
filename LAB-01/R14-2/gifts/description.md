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