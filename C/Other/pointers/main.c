int main() {
    int array[1024] = { 0 }; // * set all the 1024 values to 0

    int *ptr = array; // * create a pointer thar point to the array (it means that this pointers stores the memory addres of this array)

    // NOTE
    // ptr += 2; this means that you are changing the value that this pointer it's pointing and not it's actual value. Example below
    // where the pointer is pointing is assigned to the letter p
    // this [] means the index of the array
    // [p][0][0][0]
    // 
    // When you add the ptr + 2 (ptr += 2) you where this pointer it's pointing
    // [0][0][p][0]

    ptr = array + 1023; // it make the pointer point to the last element
    ptr = &array[1023]; // it makes the same thing at the code above

    // (array == &array[0]) always true

    int array2[1024] = { 0 };
    char *ptr = array;

    ptr += 2; 
    // NOTE
    // Now when you do that, you're not anymore changing what index the pointer is pointing
    // you're changing the byte that this pointer is pointing (int = 4 bytes)
    // from the first byte you go to the third byte

    // * Common errors with pointers
    // ! Dereference mistakes are fatal
    
    /**
     * ``` C
     *  int *ptr = NULL; // NOTE you cannot deref. NULL
     *  *ptr = 0; // ! crash
     *  ptr[i] = 0; // ! crash
     * ```
     * 
     * ``` C
     *  Man *man; // NOTE you cannot deref. uninitialized 'wild' pointers
     *  man->x = 50; // ! crash
     *  man->name = NULL; // ! crash
     * ```
     * 
     * ``` C
     *  Man men[10] // NOTE you cannot deref. outside the bounds od an array
     * 
     *  men[500].x = 50; // ! Crash
     *  men[10].y = 50; // ! Crash
     * ```
     * 
     * ``` C
     *  char *str1 = "a string"; // NOTE you cannot modify string constantss
     *  char str2[1024] = "a string";
     * 
     *  str1[0] = 'b'; // ! Crash
     *  srd2[0] = 'b'; // * Ok
     * ```
    */
}