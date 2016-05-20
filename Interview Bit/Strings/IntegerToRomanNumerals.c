/**
 * @input A : Integer
 * 
 * @Output string. Make sure the string ends with null character
 */
void convertToRoman (unsigned int val, char *res) {
    char *huns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    int   size[] = { 0,   1,    2,     3,    2,   1,    2,     3,      4,    2};

    //  Add 'M' until we drop below 1000.

    while (val >= 1000) {
        *res++ = 'M';
        val -= 1000;
    }

    // Add each of the correct elements, adjusting as we go.

    strcpy (res, huns[val/100]); res += size[val/100]; val = val % 100;
    strcpy (res, tens[val/10]);  res += size[val/10];  val = val % 10;
    strcpy (res, ones[val]);     res += size[val];

    // Finish string off.

    *res = '\0';
}
 

char* intToRoman(int A) {
    char arr[100000];
    convertToRoman (A, arr);
    return arr;
}

