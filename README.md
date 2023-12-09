

## We invite everyone to contribute to this repo...

---

# Calculator

## Overview

The Calculator is a tool designed to perform basic arithmetic operations on numbers. Unlike traditional calculators, it accepts input as strings and handles operations with an extended range of numbers. This solves the limitation of typical calculators that require inputs within a finite range.

## Problem Statement

The main problem with conventional calculators is their restriction to a specific range of numbers for operations like addition, subtraction, multiplication, and division. The Calculator addresses this limitation by working with numbers, allowing users to perform operations on a broader range of numerical values.

## Approach

### Infix to Postfix Conversion

One of the key features of the Calculator is its ability to handle mathematical expressions in infix notation. The calculator converts the infix expression to postfix notation, a more suitable format for computation.

### Doubly Linked List Storage

To store numbers, the calculator utilizes a doubly linked list data structure. This facilitates efficient storage and manipulation of digits. The input strings are converted into digit nodes and linked together to represent the numbers.

### Operations

#### Addition

The addition operation involves traversing both linked lists, digit by digit, and performing addition. The result is stored in a new linked list.

#### Subtraction

Subtraction is implemented similarly to addition, involving subtraction on each digit pair. The result is stored in a new linked list.

#### Multiplication

Multiplication is achieved through a multiplication algorithm, utilizing the standard multiplication process but adapted for numbers.

#### Division

Division is implemented using a division algorithm, resembling long division in base-10 arithmetic.

## Usage

To use the Calculator, provide the input as a string representing the mathematical expression. The calculator will process the input, perform the specified operation, and display the result.


## License

This project is licensed under the GPL License - see the [LICENSE](LICENSE) file for details.


Feel free to customize this template according to the specifics of your project and include additional details or sections as needed.



Contributors:

Bhavya Shah 

Pratham Tandale
