#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define MAX 1000

typedef struct SinhVien
{
    int msv;
    char ho[50];
    char dem[50];
    char ten[50];
    int tuoi;
    char gioitinh[10];
    float diemtoan;
    float diemanh;
    float diemvan;
    float diemtrungbinh;
} sv_info_t;

sv_info_t sv_arr[MAX];
int numberSV = 0;

// Dnh nghia ham
sv_info_t nhapSV(void);
void themSV();
void inAllSV(sv_info_t *sv, int num);
void inSV(sv_info_t sv, int index);
void SapXepSV(sv_info_t *sv, int num, char *option);
void xoaSV();
void Menu(void);

sv_info_t nhapSV(void)
{
    sv_info_t sv;

    printf("Nhap MSSV: ");
    scanf("%d", &sv.msv);

    printf("Nhap ho dem ten: ");
    scanf("%s %s %s", sv.ho, sv.dem, sv.ten);

    printf("Nhap tuoi: ");
    scanf("%d", &sv.tuoi);

    printf("Nhap gioi tinh: ");
    scanf("%s", sv.gioitinh);

    printf("Nhap diem toan: ");
    scanf("%f", &sv.diemtoan);

    printf("Nhap diem van: ");
    scanf("%f", &sv.diemvan);

    printf("Nhap diem anh: ");
    scanf("%f", &sv.diemanh);

    sv.diemtrungbinh = (sv.diemtoan + sv.diemvan + sv.diemanh) / 3.0;

    return sv;
}

void themSV()
{
    if (numberSV >= MAX)
    {
        printf("Danh sac da day!\n");
    }
    sv_arr[numberSV++] = nhapSV();
}

void inSV(sv_info_t sv, int index)
{
    printf("SV[%d]:\n", index);
    printf("%-10d%-10s%-10s%-10s%-10d%-10s%-10.2f%-10.2f%-10.2f%-10.2f\n",
           sv.msv, sv.ho, sv.dem, sv.ten,
           sv.tuoi, sv.gioitinh,
           sv.diemtoan, sv.diemvan, sv.diemanh, sv.diemtrungbinh);
}

void inAllSV(sv_info_t *sv, int num)
{
    printf("\n%-10s%-10s%-10s%-10s%-10s%-12s%-10s%-10s%-10s%-10s\n",
           "MaSV", "Ho", "Dem", "Ten", "Tuoi",
           "GioiTinh", "Toan", "Van", "Anh", "TB");

    for (int i = 0; i < num; ++i)
    {
        printf("%-10d%-10s%-10s%-10s%-10d%-12s%-10.2f%-10.2f%-10.2f%-10.2f\n",
               sv[i].msv, sv[i].ho, sv[i].dem, sv[i].ten,
               sv[i].tuoi, sv[i].gioitinh,
               sv[i].diemtoan, sv[i].diemvan, sv[i].diemanh, sv[i].diemtrungbinh);
    }
}

void SapXepSV(sv_info_t *sv, int num, char *option)
{
    if (strstr(option, "ten")) // Sắp xếp theo tên A → Z
    {
        for (int i = 0; i < num - 1; ++i)
        {
            for (int j = i + 1; j < num; ++j)
            {
                if (strcmp(sv[i].ten, sv[j].ten) > 0) // A→Z
                {
                    sv_info_t tmp = sv[i];
                    sv[i] = sv[j];
                    sv[j] = tmp;
                }
            }
        }
        printf("Da sap xep theo TEN (A → Z)\n");
    }
    else if (strstr(option, "diem")) // Sắp xếp theo điểm tăng dần
    {
        for (int i = 0; i < num - 1; ++i)
        {
            for (int j = i + 1; j < num; ++j)
            {
                if (sv[i].diemtrungbinh > sv[j].diemtrungbinh)
                {
                    sv_info_t tmp = sv[i];
                    sv[i] = sv[j];
                    sv[j] = tmp;
                }
            }
        }
        printf("Da sap xep theo DIEM TB (tang dan)\n");
    }
    else
    {
        printf("Lua chon sap xep khong hop le!\n");
    }
}

void xoaSV()
{
    int mssv;
    printf("Nhap MSSV can xoa: ");
    scanf("%d", &mssv);

    int found = -1;
    for (int i = 0; i < numberSV; ++i)
    {
        if (sv_arr[i].msv == mssv)
        {
            found = i;
            break;
        }
    }
    if (found == -1)
    {
        printf("Khong tim thay MSSV!\n");
        return;
    }
    for (int i = found; i < numberSV - 1; ++i)
    {
        sv_arr[i] = sv_arr[i + 1];
    }
    numberSV--;
    printf("Da xoa sinh vien!\n");
}
void Menu(void)
{
    int ch;
    do
    {
        printf("=====MENU=====\n");
        printf("1. Them sinh vien.\n");
        printf("2. Xoa sinh vien.\n");
        printf("3. In toan bo sinh vien.\n");
        printf("4. Sap xep sinh vien theo ten.\n");
        printf("5. Sap xep sinh vien theo diem TB.\n");
        printf("6. Thoat.\n");
        printf("Chon: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            themSV();
            break;
        case 2:
            xoaSV();
            break;
        case 3:
            inAllSV(sv_arr, numberSV);
            break;
        case 4:
            SapXepSV(sv_arr, numberSV, "ten");
            break;
        case 5:
            SapXepSV(sv_arr, numberSV, "diem");
            break;
        case 6:
            printf("Thoat chuong trinh!\n");
            break;
        default:
            printf("Lua chon khong kop le!\n");
            break;
        }
    } while (ch != 6);
}
int main()
{
    Menu();
    return 0;
}
