Game Rắn Săn Mồi trên LCD 16x2
Giới thiệu
Đây là một trò chơi rắn săn mồi được thiết kế để chạy trên màn hình LCD 16x2 kết hợp với vi điều khiển Arduino Uno R3. Trò chơi được điều khiển bằng joystick, mang đến trải nghiệm đơn giản nhưng thú vị trên phần cứng giới hạn.

Tính năng chính
Hiển thị trên màn hình LCD 16x2: Sử dụng LCD để hiển thị trò chơi.

Điều khiển bằng Joystick: Dễ dàng điều khiển hướng di chuyển của rắn.

Thực hiện trên Arduino Uno R3: Tích hợp với phần cứng phổ biến và dễ tiếp cận.

Quản lý bộ nhớ hạn chế: Lưu ý khi sử dụng sRAM 2KB của vi điều khiển:

Khi rắn tăng quá dài có thể gây giật lag do giới hạn bộ nhớ.

Khi màn hình bị chiếm 9 ô ký tự trở lên, có thể gặp lỗi do CGRAM chỉ chứa tối đa 8 ký tự custom.

Hướng dẫn cài đặt và chạy
Phần cứng cần chuẩn bị:

Arduino Uno R3.

Màn hình LCD 16x2.

Joystick.

Dây nối và các linh kiện phụ trợ.

Kết nối phần cứng:

Kết nối màn hình LCD với Arduino theo sơ đồ mạch đi kèm.

Gắn joystick vào các chân phù hợp trên Arduino.

Cài đặt phần mềm:

Tải và cài đặt Arduino IDE.

Mở file code nguồn và nạp chương trình vào Arduino thông qua Arduino IDE.

Chạy trò chơi:

Sau khi nạp code, trò chơi sẽ tự động chạy.

Sử dụng joystick để điều khiển rắn và thưởng thức trò chơi.

Lưu ý
Giới hạn bộ nhớ: Khi rắn tăng quá dài, có thể xảy ra giật lag do sRAM chỉ có 2KB.

Giới hạn CGRAM: Nếu màn hình bị chiếm tới 9 ô ký tự trở lên, sẽ gặp lỗi hiển thị do CGRAM chỉ chứa được tối đa 8 ký tự custom.
