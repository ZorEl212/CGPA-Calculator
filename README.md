# GPA Calculator

This repository contains a GPA Calculator program written in C++. The program allows users to input and manage student data, including their subjects, scores, credit hours, and grade points. It calculates the CGPA (Cumulative Grade Point Average) for each student and provides various functionalities to interact with the data.
# Table of Contents
- [Getting Started](#getting-started)
- [Compilation](#compilation)
- [Usage](#usage)
- [Features](#features)
- [Contributing](#contributing)
- [Valgrind Report](#valgrind-report)
- [License](#license)
- [Author](#author)

## <a id="getting-started"></a>Getting Started

To get started with the GPA Calculator, follow these steps:

   Clone the repository to your local machine.

>     bash 
>     git clone https://github.com/your-username/gpa-calculator.git

   Change into the project directory.
   

>   cd CGPA-Calculator

## <a id="compilation"></a>Compilation

To compile the GPA Calculator, make sure you have a C++ compiler installed on your system. Here's how you can compile the source code:

   Open a terminal or command prompt.
    Navigate to the project directory.
    Run the following command to compile the source code.

>   bash 
>    g++ *.cpp -o gpa-calculator

   Once the compilation is successful, an executable file named

>  gpa-calculator

will be generated.

## <a id="usage"></a> Usage

The program provides a command-line interface to interact with the functionalities. Here's how you can use it:

   Run the compiled executable.

> ./gpa-calculator

   Choose an option from the menu to perform specific actions, such as adding a student, inputting subject details, calculating CGPA, etc.
    Follow the on-screen prompts to provide the required information.
    View the calculated CGPA and other details.
   
   To import inputs from a file follow these steps.
   1. Create a text file
   2. Open the file and enter your records in this format

       

> Name
>        [subject],[score],[credithours]
>        [subject2],[score],[creditHours]

For example:
> Yeab
> Eng,85,5
>  Physics,77,5
>   Math,77,5

3. Save and exit. 
4. Then choose "load from file" option in the program and calculate your results.

## <a id=features></a> Features

The GPA Calculator offers the following features:

   

 - Adding and managing student records.
 - Adding and managing subject details for each student.
 -  Calculating CGPA based on the entered data.
 - Saving and loading data to/from a file.
 -  Displaying student information and CGPA.

## <a id=valgrindreport></a>  Valgrind Report

    ==23514== 
    ==23514== HEAP SUMMARY:
    ==23514==     in use at exit: 0 bytes in 0 blocks
    ==23514==   total heap usage: 17 allocs, 17 frees, 84,319 bytes allocated
    ==23514== 
    ==23514== All heap blocks were freed -- no leaks are possible
    ==23514== 
    ==23514== For lists of detected and suppressed errors, rerun with: -s
    ==23514== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


## <a id=contributing></a> Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request. Please follow the contribution guidelines outlined in the repository.
License

## Author
Yeabsira Desalegn
yabsirad212@gmail.com

