# BÀI THỰC HÀNH SỐ 1 - THAO TÁC TRÊN GCC

## Chạy chương trình

Ở folder `Bai1`, gõ lệnh sau vào Terminal/Command Prompt:
Complie code

```bash
cd ./completed
gcc -o bai1 indexer.c
```

Chạy chương trình (MacOS/Linux)

```bash
./bai1
```

Chạy chương trình (Windows)

```bash
./bai1.exe
```

## Đề bài

Đọc một  tệp văn bản (tệp mẫu ở đây là `vanban.txt`). Hãy lập một bảng chỉ dẫn (Index) cho tệp văn bản.

Bảng chỉ dẫn liệt kê tất cả các từ xuất hiện trong văn bản, mỗi từ một lần và chỉ ra số của dòng xuất hiện từ đó

Ví dụ

```txt
answer 7,8,12,15
ant 2,4,6
baby 7,9,21
cruel 2,4,5
```

Chú ý

- Từ là những dãy chữ cái phân biệt nhờ khoảng trống hay dấu phân cách. Không phân biệt chữ hoa, chữ thường. Khi đưa vào chỉ số phải chuyển tất cả các ký tự thành chữ thường.
- Các từ phải được sắp xếp theo thứ tự từ điển.
- Giả sử số mục từ xuất hiện trong văn bản không lớn nên có thể lưu trữ trong một mảng.
- Không đưa vào bảng chỉ dẫn:
  - Những từ không có ý nghĩa để tra cứu.Danh sách các từ đó được lưu trữ trong tệp `stopw.txt`, mỗi mục từ trên một dòng. Danh sách này cũng không lớn nên có thể đọc vào một mảng.
  - Những danh từ riêng, tức là những từ chứa chữ cái đầu là chữ hoa nhưng không đứng sau dấu chấm câu.
- Danh sách các dòng mà mỗi mục từ xuất hiện có thể chứa trong một xâu ký tự.
