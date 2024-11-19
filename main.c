#include <stdio.h>
#include <ctype.h>

typedef struct {
    char flags[5];   // لتخزين العلامات مثل '-' أو '+'
    int width;       // العرض
    int precision;   // الدقة
    char length;     // معدل الطول (h, l)
    char type;       // النوع (d, f, s)
} FormatSpecifier;

void parse_specifier(const char *format, FormatSpecifier *fs) {
    int i = 1; // تخطي '%'
    
    // قراءة العلامات
    int flag_index = 0;
    while (format[i] == '-' || format[i] == '+' || format[i] == ' ' || format[i] == '0' || format[i] == '#') {
        fs->flags[flag_index++] = format[i++];
    }
    fs->flags[flag_index] = '\0'; // إنهاء سلسلة العلامات
    
    // قراءة العرض
    fs->width = 0;
    while (isdigit(format[i])) {
        fs->width = fs->width * 10 + (format[i++] - '0');
    }
    
    // قراءة الدقة
    fs->precision = -1; // القيمة الافتراضية
    if (format[i] == '.') {
        i++;
        fs->precision = 0;
        while (isdigit(format[i])) {
            fs->precision = fs->precision * 10 + (format[i++] - '0');
        }
    }
    
    // قراءة معدل الطول
    if (format[i] == 'h' || format[i] == 'l') {
        fs->length = format[i++];
    } else {
        fs->length = '\0';
    }
    
    // قراءة النوع
    fs->type = format[i];
}

int main() {
    const char *format = "%08.2f";
    FormatSpecifier fs;

    parse_specifier(format, &fs);

    printf("Flags: %s\n", fs.flags);
    printf("Width: %d\n", fs.width);
    printf("Precision: %d\n", fs.precision);
    printf("Length: %c\n", fs.length ? fs.length : 'N'); // 'N' تعني لا يوجد معدل طول
    printf("Type: %c\n", fs.type);

    return 0;
}
