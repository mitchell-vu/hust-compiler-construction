# BUỔI THỰC HÀNH 2 - SCANNER

## Scanner là gì?

Là bộ phân tích từ vựng với nhiệm vụ

- Bỏ qua các ký tự vô nghĩa như: spaces, tab, ký tự xuống dòng, comment.
- Phát hiện các ký tự không hợp lệ (Phát hiện lỗi)
- Phát hiện token
- Chuyển lần lượt các token cho bộ phân tích cú pháp (parser)

### Data Sctructure trong Scanner

Data structure của một Token

```c
typedef struct {
    char string[MAX_IDENT_LEN + 1];
    int lineNo, colNo;
    TokenType tokenType;
    int value;
} Token;
```

Chỉ số dòng, cột hiện tại

```c
int lineNo, colNo;
```

Ký tự hiện tại

```c
int currentChar;
```

### Function trong Scanner

Đọc một ký tự từ input

```c
int readChar(void);
```

Kiểm tra string có là Keyword hay không

```c
TokenType checkKeyword(char *string);
```

Tạo một token mới với kiểu và vị trí

```c
Token* makeToken(TokenType tokenType, int lineNo, int colNo);
```

## Bài tập

Hoàn thiện các hàm sau trong `scanner.c`

- `void skipBlank();`
- `void skipComment();`
- `Token* readIdentKeyword(void);`
- `Token* readNumber(void);`
- `Token* readConstChar(void);`
- `Token* getToken(void);`

## Chạy chương trình

Install make hay Cmake, thêm PATH vào enviroment variables)

Chuyển directory vào folder `Bai2`
Chạy Make để compile project kèm libraries

```bash
cd incomplete
make
```

Chọn file test đi kèm với scanner
Với MacOS/Linux

```bash
./scanner ../test/<file_name>
```

Với Windows

```bash
./scanner.exe ../test/<file_name>
```
