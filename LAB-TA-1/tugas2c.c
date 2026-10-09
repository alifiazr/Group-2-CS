#include <stdio.h>

#define KELIPATAN_KUPON 100000   /* 1 kupon per Rp 100.000 */
#define MIN_DISKON      100000   /* minimal belanja untuk dapat diskon */
#define PERSEN_DISKON   5        /* besar diskon (5%) */

/* Mencetak bilangan dengan pemisah ribuan.*/
void cetak_ribuan(long long n)
{
    if (n >= 1000) {
        cetak_ribuan(n / 1000);      /* cetak bagian depan dulu */
        printf(".%03lld", n % 1000); /* lalu 3 digit terakhir */
    } else {
        printf("%lld", n);
    }
}

/* Mencetak uang dari satuan sen.*/
void cetak_rupiah(long long sen)
{
    printf("Rp ");
    cetak_ribuan(sen / 100);         /* bagian rupiah */
    printf(",%02lld", sen % 100);    /* bagian sen (2 digit) */
}

int main()
{
    long long total;        /* total pembelian awal (rupiah) */
    long long kupon;        /* jumlah kupon undian */
    long long diskon_sen;   /* nominal diskon (sen) */
    long long bayar_sen;    /* total yang harus dibayar (sen) */

    /* 1. Minta input */
    printf("Masukkan total pembelian (Rp): ");
    if (scanf("%lld", &total) != 1 || total <= 0) {
        printf("Input tidak valid. Masukkan angka lebih dari 0.\n");
        return 1;
    }

    /* 2. Hitung jumlah kupon */
    kupon = total / KELIPATAN_KUPON;

    /* 3. Hitung diskon.*/
    if (total >= MIN_DISKON) {
        diskon_sen = total * PERSEN_DISKON;
    } else {
        diskon_sen = 0;
    }

    /* 4. Hitung total yang harus dibayar (dalam sen) */
    bayar_sen = total * 100 - diskon_sen;

    /* 5. Tampilkan hasil */
    printf("\n===== RINCIAN PEMBELIAN =====\n");

    printf("Total pembelian awal : ");
    cetak_rupiah(total * 100);
    printf("\n");

    printf("Jumlah kupon undian  : %lld\n", kupon);

    printf("Nominal diskon       : ");
    cetak_rupiah(diskon_sen);
    printf("\n");

    printf("Total yang dibayar   : ");
    cetak_rupiah(bayar_sen);
    printf("\n");

    return 0;
}