# THI THỬ CUỐI KỲ 2022

## Chỉnh sửa compiler

## Chạy chương trình sinh mã

Install make hay Cmake, thêm PATH vào enviroment variables

Chuyển directory vào folder `mock-final-2022`

```bash
cd mock-final-2022
```

Chạy Make để compile project kèm libraries
Chọn file test đi kèm với parser

- Với MacOS/Linux

```bash
cd codegen && make && cd ..
```

- Với Windows

```bash
cd codegen && mingw32-make && cd ..
```

Chạy chương trình sinh mã

- Với MacOS/Linux

```bash
./codegen/kplc ./test/final_1.kpl ./test/final_1 -dump
./codegen/kplc ./test/final_2.kpl ./test/final_2 -dump
```

- Với Windows

```bash
./codegen/kplc.exe ./test/final_1.kpl ./test/final_1 -dump
./codegen/kplc.exe ./test/final_2.kpl ./test/final_2 -dump
```

## Chạy chương trình thông dịch kplrun

- Với MacOS/Linux

```bash
./interpreter/kplrun ./test/final_1
./interpreter/kplrun ./test/final_2
```

- Với Windows

```bash
./interpreter/kplrun.exe ./test/final_1
./interpreter/kplrun.exe ./test/final_2
```
