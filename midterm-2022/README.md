# THI THỬ GIỮA KỲ 2022

## Chạy chương trình sinh mã

Install make hay Cmake, thêm PATH vào enviroment variables

Chuyển directory vào folder `mock-final-2022`

```bash
cd mock-midterm-2022
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
./codegen/kplc ./test/midterm.kpl ./test/midterm -dump
```

- Với Windows

```bash
./codegen/kplc.exe ./test/midterm.kpl ./test/midterm -dump
```

## Chạy chương trình thông dịch kplrun

- Với MacOS/Linux

```bash
./interpreter/kplrun ./test/midterm
```

- Với Windows

```bash
./interpreter/kplrun.exe ./test/midterm
```
