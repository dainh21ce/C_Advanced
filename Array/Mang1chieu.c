#include <stdio.h>

#define SIZE 100
int mang[SIZE];

void nhapmang(int arr[], int *n);
void inmang(int arr[], int n);
void sapxep_tangdan(int arr[], int n);
void sapxep_giamdan(int arr[], int n);

void nhapmang(int arr[], int *n)
{
    printf("Nhap so luong phan tu: ");
    scanf("%d", n);
    printf("Nhap mang:\n");
    for (int i = 0; i < *n; ++i)
    {
        printf("Mang[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("====================\n");
}

void inmang(int arr[], int n)
{
    printf("In mang\n");
    for (int i = 0; i < n; ++i)
    {
        printf("Mang[%d]: %d\n", i, arr[i]);
    }
}

void sapxep_tangdan(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep tang dan:\n");
    inmang(arr, n);
}

void sapxep_giamdan(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep giam dan:\n");
    inmang(arr, n);
}

int check_SoNguyenTo(int n)
{
    if (n == 1 || n == 2)
        return 0;
    for (int i = 2; i * i < n; ++i)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void in_SoNguyenTo(int arr[], int n)
{
    printf("Cac so nguyen to: ");
    for (int i = 0; i < n; i++)
    {
        if (check_SoNguyenTo(arr[i]))
        {
            printf("%4d", arr[i]);
        }
    }
}
int main()
{
    int n;
    nhapmang(mang, &n); // mang = &mang[0]
    sapxep_giamdan(mang, n);
    in_SoNguyenTo(mang, n);
}