-  Chuỗi là 1 tập hợp kí tự (char) được lưu trữ trên các ô nhớ liên tiếp và luôn luôn có 1 ký tự null là \0 báo hiệu kết thúc chuỗi

- Có 2 cách để khai báo chuỗi
C1: Biểu thị bằng con trỏ kiểu char
    char *ten = "NHD";
C2: Biẻu thị bằng mảng ký tự
    char ten[] = "NHD";
    => N|H|D|\0

- Sự khác nhau giữa 2 kiểu khai báo:
1. Chuỗi được lưu vào vùng nhớ hằng. Data sheetment.
2. Lưu trên vùng nhớ stack, dễ dàng chỉnh sửa được chuỗi thông qua cách truy cập thông qua phân tử mảng.


- Một số hàm quan trọng:
1.strlen
syntax: int strlen (const char *str);
không tính \0 vào độ dài của chuỗi

2.strcpm
Hàm so sánh độ lớn 2 chuỗi
syntax: int strcpm (const char *str1, const char *str2);

Giá trị trả về số nguyên > 0 : Chuỗi 1 có giá trị lớn hơn chuỗi 2
Giá trị trả về số nguyên <> 0 : Chuỗi 1 có giá trị nhỏ hơn chuỗi 2
Bằng 0: 2 chuỗi giống 
Nguyên tắc so sánh là từ bảng mã ASCII 

3.strcpt
copy chổ sau lên chuỗi trước, Không nên để thằng chuỗi đích là vùng nhớ hằng là sai (Vùng nhớ hằng là con trỏ )
syntax  
char *strcpy (char *dest, const char *src);
-dest: đây là con trỏ tới mảng chứa chuỗi vừa được sao chép
-src: chuỗi để được sao 
char str1[] = "NHD1123";
    char *str2 = "NHD22232";

    strcpy(&str1[3], str2);

4.strcat
Được dùng để nối chuỗi nguồn vào đuôi chuỗi đích
syntax : char *strcat (char *dest, const char *src)

5.strstr
Được sử dụng để tìm 1 chuỗi con trong 1 chuỗi mẹ
syntax:  char * strstr(const char *str, const char &str)
