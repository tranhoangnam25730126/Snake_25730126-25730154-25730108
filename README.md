# 🐍 Snake Game Console

Dự án game con rắn (Snake) cổ điển chạy trên nền tảng Console Windows. Đây là sản phẩm đồ án môn học Kỹ năng nghề nghiệp,
tập trung vào việc xử lý logic lập trình C++, quản lý dự án với Git/GitHub và tối ưu hóa trải nghiệm người dùng trên môi trường terminal.

## 👥 Thành viên thực hiện
* **Trần Hoàng Nam (25730126):** Khởi tạo cấu trúc dự án (Common.h) và quản lý luồng game chính (Snake.cpp).
* **Võ Trần Tín (25730154):** Logic Core (Xử lý di chuyển, va chạm, trạng thái game, logic ăn mồi).
* **Nguyễn Thùy Dương (25730108):** UI & Rendering (Xử lý hiển thị màn hình, vẽ khung, vẽ rắn và màu sắc).

## 🛠 Yêu cầu hệ thống
* **Hệ điều hành:** Windows (Sử dụng thư viện `windows.h` và `conio.h` để điều khiển tọa độ và bàn phím).
* **Trình biên dịch:**
  * MSVC (Tích hợp trong Visual Studio).
  * GCC/MinGW (Tích hợp trong Code::Blocks hoặc Dev-C++).

## 🚀 Hướng dẫn cài đặt và Chạy

### 1. Tải mã nguồn
Mở Terminal (Command Prompt, PowerShell hoặc Git Bash) và chạy các lệnh sau:
```bash
git clone https://github.com/tranhoangnam25730126/Snake_KNNN.git
cd Snake_KNNN
```

### 2. Biên dịch trên Visual Studio
1. Mở Visual Studio, chọn **Create a new project** -> **Empty Project (C++)**.
2. Đặt tên project và nhấn **Create**.
3. Trong cửa sổ *Solution Explorer*, chuột phải vào Project chọn **Add > Existing Item...**
4. Chọn tất cả các file `.cpp` và `.h` vừa tải về.
5. Nhấn `Ctrl + F5` để biên dịch và chạy.

### 3. Biên dịch trên Code::Blocks
1. Mở Code::Blocks, chọn **File > New > Project > Empty Project**.
2. Chuột phải vào tên Project ở cột bên trái, chọn **Add files...**
3. Chọn tất cả file trong thư mục dự án.
4. Nhấn `F9` (Build and Run).

## 🎮 Cách điều khiển & Chế độ chơi
Ngay khi bắt đầu game, người dùng sẽ được chọn một trong hai chế độ:
* **Chế độ 1 (Solid Walls):** Rắn đâm vào tường sẽ kết thúc trò chơi.
* **Chế độ 2 (No Walls):** Rắn có thể đi xuyên qua tường và xuất hiện ở phía đối diện.

**Phím bấm thao tác:**
* **W / A / S / D:** Di chuyển Lên / Trái / Xuống / Phải.
* **P:** Tạm dừng (Pause) game.
* **R:** Chơi lại (Play Again) ngay lập tức sau khi thua.
* **X:** Thoát game (Exit).

## 📂 Cấu trúc mã nguồn
* `Common.h`: Khai báo các hằng số (`WIDTH`, `HEIGHT`), struct (`Snake`, `Food`) và các biến trạng thái toàn cục.
* `SnakeLogic.cpp`: Chứa toàn bộ logic xử lý di chuyển, kiểm tra va chạm thân/tường, tạo mồi và tính điểm.
* `UI.cpp`: Xử lý các hàm đồ họa console như `gotoxy`, vẽ khung, vẽ rắn và mồi.
* `Snake.cpp`: Chứa hàm `main`, quản lý vòng lặp game (Game Loop) và nhận tương tác menu từ người dùng.
