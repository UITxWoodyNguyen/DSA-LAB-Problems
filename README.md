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
├── solution.cpp                # Lời giải chuẩn (model solution)
└── template.cpp                # (Optional) Khung code cho thí sinh
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

### Cách 1: Cài đặt DSA Judge CLI Tool (Khuyến nghị)
```bash
cd DSA-LAB-Problems
pip install -e .
```
Sau đó có thể chạy `dsa-judge` từ bất kỳ đâu.

### Cách 2: Chạy trực tiếp judge.py (Legacy)
```bash
# Python 3.8+
pip install psutil tabulate rich  # Optional: để có bảng đẹp và đo memory chính xác
```

## Sử dụng DSA Judge CLI Tool

### 1. Interactive Mode (Menu-driven)
```bash
dsa-judge
```
Hoặc:
```bash
python -m dsa_judge.cli
```

Banner hiển thị khi khởi động:
```
    ____  ____  __  __  ____  _____ _____ ____  
   |  _ \|  _ \|  \/  |/ ___||_   _| ____|  _ \ 
   | |_) | |_) | |\/| | |  _   | | |  _| | |_) |
   |  _ <|  _ <| |  | | |_| |  | | | |___|  _ < 
   |_| \_\_| \_\_|  |_|\____|  |_| |_____|_| \_\

   DDDD   SSSS   AAAA   -   JJJJ   U   U  DDDD   EEEEE
   D   D  S      A   A      J    U   U  D   D  E     
   D   D  SSSS   AAAAA      J    U   U  D   D  EEEE  
   D   D     S   A   A      J    U   U  D   D  E     
   DDDD   SSSS   A   A   JJ J     UUU   DDDD   EEEEE

   Local Grader / Auto-judge for CP
   Competitive Programming Lab - UIT
   Version 1.0.0
```

Menu tương tác:
```
============================================================
MAIN MENU
============================================================
  1. Set Submission File
  2. Set Problem Directory
  3. Set Template File (optional)
  4. Toggle Verbose Mode: OFF
  5. Toggle Keep Binary: OFF
  6. View Current Settings
  7. Run Judge
  8. Exit
============================================================
Select option (1-8):
```

**Các thao tác:**
- **Option 1**: Chọn file `submission.cpp` (validate tồn tại, đuôi .cpp/.cc/.cxx)
- **Option 2**: Chọn thư mục bài toán (validate có `description.md`)
- **Option 3**: Chọn `template.cpp` (optional, để trống = auto-detect trong problem dir)
- **Option 4**: Bật/tắt verbose mode (in chi tiết từng test case)
- **Option 5**: Bật/tắt keep binary (giữ file thực thi sau khi chấm)
- **Option 6**: Xem cài đặt hiện tại
- **Option 7**: Chạy judge với cài đặt hiện tại
- **Option 8**: Thoát

### 2. Direct Mode (Command Line Arguments)
```bash
# Chạy nhanh với tham số
dsa-judge -s submission.cpp -p ./problem -v

# Chạy với template
dsa-judge --sub main.cpp --problem LAB-01/R14-2/gifts --template template.cpp

# Giữ binary sau khi chấm
dsa-judge -s solution.cpp -p LAB-01/R14-2/gifts --no-clean
```

### Tham số dòng lệnh
| Tham số | Mô tả |
|---------|-------|
| `-s`, `--sub`, `--submission` | Đường dẫn file submission.cpp (bắt buộc) |
| `-p`, `--problem` | Thư mục gốc bài toán |
| `-t`, `--template` | Đường dẫn template.cpp (tùy chọn) |
| `-v`, `--verbose` | In chi tiết từng test case |
| `--no-clean` | Giữ binary sau khi chấm |
| `--version` | Xem phiên bản |

### 3. Chạy trực tiếp judge.py (Legacy)
```bash
# Chấm submission.cpp cho bài pharmacy-stock-alert
python judge.py --sub submission.cpp --problem LAB-01/R14-2/pharmacy-stock-alert -v

# Chấm với template.cpp tùy chọn
python judge.py -s main.cpp -p LAB-01/R14-2/selection-sort -t template.cpp

# Giữ binary sau khi chấm
python judge.py -s solution.cpp -p LAB-01/R14-2/gifts --no-clean
```

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

## Template Compliance Checking

judge.py tự động kiểm tra submission có tuân thủ `template.cpp` không:

1. **Extract template structure**:
   - Required functions (signature)
   - Required classes
   - Required includes
   - BEGIN/END TEMPLATE markers

2. **Validate submission**:
   - Có đầy đủ required functions/classes/includes
   - BEGIN marker xuất hiện trước END marker
   - Không vi phạm forbidden patterns (nếu có)

3. **Reject** nếu vi phạm: `[REJECTED] Submission does not follow the required template!` (exit code 2)

### Template format mẫu
```cpp
// template.cpp
#include <iostream>
#include <vector>

// BEGIN TEMPLATE
void NhapMang(int A[], int &N);
bool isMaxHeap(int A[], int N);
// END TEMPLATE

int main() { ... }
```

## Cấu hình description.md

File `description.md` chứa metadata để judge tự động parse:

```markdown
## Limitations
* Language: C++
* Time limit: 1.5s
* Memory limit: 50MB
```

Hoặc format khác:
```markdown
Time limit: 1.5s
Memory limit: 256MB
```

Hỗ trợ các format: `Time limit:`, `Time Limit:`, `time limit:`, `Memory limit:`, `Memory Limit:`, đơn vị `s`, `ms`, `MB`, `MiB`.

## Ví dụ Output judge.py

```
Problem: pharmacy-stock-alert
Submission: solution.cpp
Template: template.cpp
Time Limit: 1.5s
Memory Limit: 50MB

Checking template compliance...
[OK] Template compliance check passed
Compiling...
[OK] Compilation successful
Found 50 test case(s)
Running tests...

  01: AC (177.5ms, 0.0MB)
  02: AC (5.1ms, 0.0MB)
  ...

Test ID    Status       Time(ms)    Mem(MB) Details
--------------------------------------------------------------------------------
01         AC              177.5        0.0
02         AC                5.1        0.0
...
50         AC              609.2        0.0
Score: 50/50 [100.0%]
```

## Exit Codes

| Code | Meaning |
|------|---------|
| 0 | All tests AC |
| 1 | Some tests failed (WA/TLE/MLE/RTE) |
| 2 | Template compliance rejected |
| 3 | Compilation error (CE) |

## Mở rộng

### Thêm bài toán mới
1. Tạo thư mục `LAB-XX/RYY-<name>/<problem-name>/`
2. Tạo `description.md` theo format (có Time limit, Memory limit)
3. Tạo `dataset/test_generator.cpp` (sinh 50 test cases)
4. Tạo `dataset/output_generator.cpp` (template có sẵn)
5. Viết `solution.cpp` chuẩn
6. (Optional) Tạo `template.cpp` cho thí sinh
7. Chạy: `test_generator` → `output_generator` → `judge.py`

### Custom Checker
Trong `description.md` thêm:
```markdown
Float epsilon: 1e-9
```
hoặc implement custom checker trong solution.

## License

Dự án dành cho mục đích học tập và giảng dạy môn DSA.