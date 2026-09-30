# DSA Lab Problems - Competitive Programming Judge System

Hệ thống chấm bài tự động (Local Grader / Auto-judge) cho các bài tập Competitive Programming trong môn Cấu trúc dữ liệu và Giải thuật (DSA).

## Cấu trúc thư mục

```
DSA-LAB-Problems/
├── judge.py                    # Local Grader chính
├── LAB-01/
│   └── R14-2/
│       ├── pharmacy-stock-alert/          # Tìm thuốc tồn kho thấp nhất
│       ├── supermarket-price-lookup/      # Tìm giá sản phẩm (Binary Search)
│       ├── lower-bound/                   # Lower Bound Queries
│       ├── selection-sort/                # Selection Sort (giảm dần + debug)
│       ├── insertion-sort/                # Insertion Sort (giảm dần + debug)
│       ├── insertion-sort-student/        # Insertion Sort sinh viên (multi-key)
│       ├── maxheap-check/                 # Kiểm tra Max Heap
│       ├── build-maxheap/                 # Xây dựng Max Heap
│       ├── heapsort/                      # Heap Sort (tăng dần)
│       └── gifts/                         # Chọn 2 món quà (Two Pointers)
└── .opencode/
    └── GUIDE.md                 # Hướng dẫn cấu trúc bài tập & sinh test
```

Mỗi bài toán có cấu trúc chuẩn:
```
<problem>/
├── dataset/
│   ├── input/                  # 50 test cases (.inp)
│   ├── output/                 # 50 expected outputs (.out)
│   ├── test_generator.cpp      # Sinh input test cases
│   └── output_generator.cpp    # Sinh output từ solution.cpp
├── description.md              # Đề bài, ràng buộc, format I/O
└── solution.cpp                # Lời giải chuẩn (model solution)
```

## Tính năng của judge.py

- **CLI Arguments**: `--sub` (submission), `--problem` (thư mục bài toán), `--template` (template.cpp)
- **Template Compliance**: Kiểm tra submission có tuân thủ template.cpp (BEGIN/END TEMPLATE, required functions/classes/includes)
- **Auto-config từ description.md**: Parse Time Limit, Memory Limit, Float epsilon
- **Compilation**: g++ -O3 -std=c++17 -static
- **Execution Monitoring**: Time Limit (TLE), Memory Limit (MLE), Runtime Error (RTE)
- **Output Comparison**: Normalize whitespace, hỗ trợ float comparison với epsilon
- **Reporting**: Bảng kết quả màu sắc (Rich/Tabulate/ASCII), Score summary

## Cài đặt

```bash
# Python 3.8+
pip install psutil tabulate rich  # Optional: để có bảng đẹp và đo memory chính xác
```

## Sử dụng

### Chạy test generator (sinh input)
```bash
cd LAB-01/R14-2/pharmacy-stock-alert/dataset
g++ -std=c++17 -O3 test_generator.cpp -o test_generator
./test_generator
```

### Chạy output generator (sinh expected output)
```bash
cd LAB-01/R14-2/pharmacy-stock-alert/dataset
g++ -std=c++17 -O3 output_generator.cpp -o output_generator
./output_generator
```

### Chấm bài với judge.py
```bash
# Chấm submission.cpp cho bài pharmacy-stock-alert
python judge.py --sub submission.cpp --problem LAB-01/R14-2/pharmacy-stock-alert -v

# Chấm với template.cpp tùy chọn
python judge.py -s main.cpp -p LAB-01/R14-2/selection-sort -t template.cpp

# Giữ binary sau khi chấm
python judge.py -s solution.cpp -p LAB-01/R14-2/gifts --no-clean
```

### Tham số dòng lệnh
| Tham số | Mô tả |
|---------|-------|
| `--sub`, `--submission` | Đường dẫn file submission.cpp (bắt buộc) |
| `--problem`, `-p` | Thư mục gốc bài toán (mặc định: `.`) |
| `--template`, `-t` | Đường dẫn template.cpp (tùy chọn) |
| `--no-clean` | Giữ binary sau khi chấm |
| `--verbose`, `-v` | In chi tiết từng test case |

## Danh sách 10 bài toán (LAB-01/R14-2)

| # | Problem | Thuật toán chính | Constraints |
|---|---------|------------------|-------------|
| 1 | **pharmacy-stock-alert** | Linear Scan (Min) | N ≤ 1,000,000 |
| 2 | **supermarket-price-lookup** | Binary Search | N ≤ 2,000,000 |
| 3 | **lower-bound** | Sort + Binary Search | N ≤ 10^5, Q ≤ 5×10^5 |
| 4 | **selection-sort** | Selection Sort (debug) | N < 200 |
| 5 | **insertion-sort** | Insertion Sort (debug) | N < 200 |
| 6 | **insertion-sort-student** | Insertion Sort + Comparator | N ≤ 10^3 |
| 7 | **maxheap-check** | Heap Property Check | N ≤ 150,000 |
| 8 | **build-maxheap** | Heapify (Bottom-up) | N ≤ 150,000 |
| 9 | **heapsort** | Heap Sort | N ≤ 150,000 |
| 10 | **gifts** | Two Pointers (Sorted) | N ≤ 10^5 |

## Kết quả chấm thử (Reference Solutions)

| Problem | Tests Passed | Score | Notes |
|---------|--------------|-------|-------|
| pharmacy-stock-alert | 49/50 | 98.0% | Test 49 TLE (N=1M, TL=1s) |
| supermarket-price-lookup | 50/50 | 100% | - |
| lower-bound | 48/50 | 96% | 2 TLE (N=100K, Q=500K) |
| selection-sort | 50/50 | 100% | - |
| insertion-sort | 50/50 | 100% | - |
| insertion-sort-student | 50/50 | 100% | - |
| maxheap-check | 50/50 | 100% | - |
| build-maxheap | 50/50 | 100% | - |
| heapsort | 50/50 | 100% | - |
| gifts | 50/50 | 100% | - |

> **Lưu ý**: Các bài có TLE là do test case lớn (N=100K-1M) với Time Limit 1s mặc định từ description.md. Có thể điều chỉnh TL trong description.md hoặc tối ưu solution.

## Ví dụ Output judge.py

```
Problem: pharmacy-stock-alert
Submission: solution.cpp
Time Limit: 1.0s
Memory Limit: 256MB

Compiling...
[OK] Compilation successful
Found 50 test case(s)
Running tests...

  01: AC (340.5ms, 0.0MB)
  02: AC (11.8ms, 0.0MB)
  ...

Test ID    Status       Time(ms)    Mem(MB) Details
--------------------------------------------------------------------------------
01         AC              340.5        0.0
02         AC               11.8        0.0
...
49         TLE            1116.5        0.0 Time limit exceeded
50         AC              230.5        0.0
Score: 49/50 [98.0%]
```

## Mở rộng

### Thêm bài toán mới
1. Tạo thư mục `LAB-XX/RYY-<name>/<problem-name>/`
2. Tạo `description.md` theo format (có Time limit, Memory limit)
3. Tạo `dataset/test_generator.cpp` (sinh 50 test cases)
4. Tạo `dataset/output_generator.cpp` (template có sẵn)
5. Viết `solution.cpp` chuẩn
6. Chạy: `test_generator` → `output_generator` → `judge.py`

### Custom Checker
Trong `description.md` thêm:
```
Float epsilon: 1e-9
```
hoặc implement custom checker trong solution.

## License

Dự án dành cho mục đích học tập và giảng dạy môn DSA.