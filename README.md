# Game Rắn Săn Mồi trên LCD 16x2

## Giới thiệu
Đây là một trò chơi **rắn săn mồi** được thiết kế để chạy trên **màn hình LCD 16x2** kết hợp với **vi điều khiển Arduino Uno R3**. Trò chơi được điều khiển bằng **joystick**, mang đến trải nghiệm đơn giản nhưng thú vị trên phần cứng giới hạn.

## Tính năng chính
- **Điều khiển bằng Joystick:** Dễ dàng điều khiển hướng di chuyển của rắn.
- **Vi điều khiển Arduino Uno R3:** Phần cứng phổ biến, dễ tiếp cận.
- **Màn hình LCD 16x2:** Hiển thị tình trạng của rắn, điểm số, v.v.

## Lưu ý về bộ nhớ
- **Giới hạn sRAM (2KB):** Khi rắn ngày càng dài, việc cập nhật vị trí có thể gây giật lag do giới hạn bộ nhớ.
- **Giới hạn CGRAM (8 ký tự custom):** Nếu màn hình bị chiếm 9 ô ký tự trở lên, bạn có thể gặp lỗi hiển thị vì CGRAM chỉ chứa được tối đa 8 ký tự tùy chỉnh.

## Phần cứng và linh kiện
- **Arduino Uno R3**
- **Joystick**
- **Màn hình LCD 16x2**
- Dây nối và các linh kiện phụ trợ (tùy thuộc vào cách bạn thiết kế mạch)

## Hướng dẫn cài đặt
1. **Kết nối phần cứng:**
   - Kết nối màn hình LCD 16x2 với Arduino Uno theo sơ đồ (chân VSS, VDD, V0, RS, RW, E, D4-D7, v.v.).
   - Gắn Joystick vào các chân phù hợp (chân A0, A1) để đọc tín hiệu X/Y.
2. **Nạp code vào Arduino:**
   - Mở Arduino IDE (hoặc công cụ bạn ưa thích).
   - Tải file code của dự án.
   - Chọn Board là **Arduino Uno**.
   - Chọn cổng COM tương ứng với Arduino.
   - Nhấn **Upload** để nạp chương trình.
3. **Chạy trò chơi:**
   - Sau khi nạp code thành công, màn hình LCD sẽ hiển thị giao diện game.
   - Dùng Joystick để điều khiển rắn di chuyển.

## Cách chơi
- **Mục tiêu:** Điều khiển rắn ăn mồi để tăng độ dài và ghi điểm.
- **Di chuyển:** Sử dụng Joystick để điều khiển rắn lên/xuống/trái/phải.
- **Kết thúc:** Trò chơi kết thúc khi rắn va vào chính nó hoặc ra khỏi vùng màn hình.

## Lời kết
Bạn có thể tuỳ chỉnh code, cải tiến thuật toán hoặc bổ sung tính năng để trò chơi chạy mượt hơn trong giới hạn phần cứng. Nếu có bất kỳ thắc mắc hoặc góp ý, hãy liên hệ hoặc tạo issue trên repository của dự án.

Chúc bạn thành công và có những trải nghiệm thú vị khi phát triển trò chơi rắn săn mồi trên Arduino!
