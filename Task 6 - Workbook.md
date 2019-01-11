1 Describe the properties and function of dynamic variables in C

##Anwser 1##
 The all the memory for variables are allocated at compile and link time for executable (ELF in Linux) in .Data or .BSS segments. However, some of the memory are required to be allocated and and deleted during execution time of program. The variables which required this kind of runtime memory allocation are called dynamic variable. These memories are located at HEAP area and malloc(), calloc() and realloc() functions from stdlib are used to create and free() function is used to remove this dynamically allocated memory from HEAP. 

 The dynamically allocated memory can be accessed by the pointer and after the memory is used, it is prepferable to be freed to prevent from heap memory leakage which can cause the process corruption. It also can cause the memory fragmentation in HEAP area because not all the allocated memory in HEAP are not equal size and the memory freed time is not known. To remove these problems, some of HEAP is managed by various size of pools and allocate the memory area based on the size of required size of memory.

 Dynamic variable can be used for resizable array during the program running time.

2. Describe medium-size application development in detail with regard to:
- dividing source code into multiple ﬁles 
- the use of header ﬁles in C 
- the use of C libraries

##Anwser 2##
 C codes are compiled and linked into libraries in .a (static) or .so (dynamic) forms to increase the portability and reusability and more maintainable.

 Each C files is compiled individually into object file and linked during link time. However, the c compiler is one pass compiling so the functions or variables must be known before it is seen by compiler to generate assembly which will be compiled into object file by assembler. To solve out these problem, header files containing the declaration of global variables and functions (prototype) from other c files are added during preprocessing time by using #include statement.

 Header files are providing the declaration of functions, other constant or variables but not the actually function definition which will be linked during link time from other libraries or object files.

 The functions are divided and grouped into related libraries and c provides 15 standard libraries (assert, ctype, error, float, limits, locale, math, setjmp, signal, stdarg, stdio, stdlib, stddef, string and time) and also operating systems and kernels provide the system and driver related libraries to help programmer coding and also increase the portability of the source code.

 Many libraies can contain 3rd parties software.

3. Describe the properties and function of arrays in C.

##Answer 3##
 The array in c stores the same data type of variables not like list from other programming languages. The first location of array can be pointed by the array variable and each of the element is accessed by the index number starting from 0. The array in c doesn't have any boundary or length checking system like other high level languages. So overflow in array is totally the programmer's responsibility.

 The size and the memory location for array in c is determined at compile and link time so the  assignment of array size during program execution is not allowd and array variable is constant  so it must not be assigned to other value at other place except it is declared.

 The array example like following:

 '''
 // array definition
 int array1[length];         //size of length
 int array2[] = {1,2,3,4,5}; //size of 5
 // array access
 for (i = 0; i < length - 1; i++) // for array1
 { dosomethingcode .... array1[i] .... }
 '''

4. Describe the properties and function of ﬁle handling in C.

##Answer 4##
 In c, file is handles by File stream structure, FILE, defined at stdio standard libraries. This structure wrapping the file descripter and has EOF, error indicator , buffer and other properties for file manupuration. There are two type of FILE stream - text and binary.

 There are three pre defined file stream of stdin, stdout and stderr and each of them represents the file descriptor 0, 1 and 2 in Linux system. 

 Files can be opend by fopen, freopen (assigned other file to existing FILE structure), fdopen functions with mode such as read, write, append for text and also the similar mode for binary file streams. 

 The file stream has file pointer which indicates the current position in file for read and write action and when the file pointer reaches the end of file, EOF is set on file stream structure. 

 To write the data into open file, the buffer must be flushed by function call (fflush()) or full the buffer with data. 

 After using the file, it must be flushed and closed. The stream can be closed when fclose() function is called or exit() function automatically flush and close all the file streams before terminate the progcess.

 The following functions are provided in c:
 fopen(), freopen()
 fseek(),ftell()
 fwrite(),fgetc(),getc(),getchar(),fgets(),gets()
 fwrite(),fputc(),putc(),putchar(),fputs(),puts()
 printf and scanf type functions
 fclose() .....

5. Describe the properties and function of user-deﬁned data structures in C

##Answer 5##
 The structue in c is the place where the different data types are grouped and managed as single data type similar to object in other programming language. It can have the function as member so it is very similar to object. However, the members of structure is fixed and ordered in memory address - occupying continuous memory space - and not added or removed from variable like other oop based languages.
 
 It also can recursively points the same structure type so it is used in many data strucutes such as linked list or tree. Also because it has many differnet values as goupe, it is well suitable to be used for Database parsing and similar purpose.

 The members can be access by . operator if it is declared in .data, .bss or stack segment but if it is declared dynamically using pointer, -> operator is used to access the member.

 The structure is good method to pass the multiple arguments to function and also return the multiple values from function with pointer. 

6. Describe TWO development methodologies appropriate for the development of small tools such as the ones implemented in this assessment task.

##Answer 6##
 The small tools with only main function or only few help functions can be tested and managed by the black box with input and output test or flow chart for development methodologies. 
 
 Flow chart simply shows the process flow using simple diagrams for starting, process, branch or end point. We can use it to visualize the flow of the work or program process.

 The Waterfall Model also can be used for silmple and small tools development. This methodology is the well known and proved classical lifecycle paradigm that approaches and develops the software by sequential and downward through the analysis, design, implementation test and maintenance process by the review, test and approval on each steps. Waterfall model works well for smaller projects where requirements are clearly defined and very well understood.

 ![Waterfall Model](Waterfall-model.jpg?raw=true "Waterfall Model Diagram")

 The advantage of waterfall model is as following:

    -   Simple and easy to understand and use.
    -   Easy to manage due to the rigidity of the model – each phase has specific deliverables and a review process.
    -   In this model, phases are processed and completed one at a time. Phases do not overlap.
 
 Also the standard assert() from assert head can be used to test the expected values at various point during the process execution. 

 If we use use the assert to check the value, using NDEBUG macro can be used to remove all the assert function at final compile and link stage. So assert will provide simple and reliable methodology for small tools development.

 For the final test, simple and small size files can be created using various method (copy and paste) or existing files also enough to test the final behaviour of the code.

7. Outline the develoment of the C language, making reference to the types of software C is intended for.

##Answer 7##

 C is the procedule based programming language created by Dennis Ritchie of AT & T’s Bell Laboratory” in 1972 to develop the UNIX system. It is developed to simplify the programming by assembler and provides more human readable code. Eventhough the populatiry of language at that time, the first specification was made in 1999 and it was named as C99. Current C specfication is made in 2011 called as C11.

 C is low-level, compile, hardware oriented and general purpose language and it generated the minimal size of code comparing other similar language. It is also portable because it can generate any executable code for any machine wiht profer compiler or assembler for that machine.

 For the characteristics of generating fast and minimal size code, it is normally used to develop the base system for various areas such as other high level languages' virtual-machines or os including kernel. It also widely used in various embed system with limites resources such as small memory or slow MCU. 

 Many high-level programming languages also provide the interface to c generated code for the high performance or hardware access purpose such as native method in java and c-extension in python etc.

 However, it doesn't provide the fancy functionalities such as array bound check, garbage collecting or high level exception checking etc from current popular high-level languages.  




