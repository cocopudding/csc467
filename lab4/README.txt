CSC467 Lab4 Report
 
Workflow: 
Start by creating 2 files: codegen.c and codegen.h. Also create a file for the output called frag.txt
Change the Makefile(add codegen to the file that it can link the codegen with other files), otherwise will get error message: undefined reference to ‘genCode(node_*)’
In compiler call genCode function
In genCode function call print_to_file function - print to the output file frag.txt
Implement all the print_to_file function according to different cases
Test the output frag.txt using the 2 given demo code

Problem encountered: 
We did not know we need to modify the makefile first and we could not compile the code. 
We spent a lot of time allocating variables(registers). We had 2 temp variables, one is condTemp the other one is exprTemp. 
It required some thought to allocate registers correctly and use the correct indexes in a recursive call.
We were having difficulty implementing the math operations because we did not understand too much assembly code.
The if-else statement also takes us a long time. We were having trouble implementing it.
Testing the code also took us a long time. The code compilation always gave us an error because we forgot to delete all the .o file in the util folder. 


• How did you implement non-trivial math operations.
For math operations like add(+), subtract(-), multiply(*), power(^) ARB has an existing instruction set. We can directly use instruction set like ADD, SUB, MUL, and POW. For divide(C = A / B), we found the reciprocal of B and multiplied it with A. 

For logical operations like greater than (>) and less than or equal (=<), ARB does not have a supported instruction set. However, ARB has less than (<, SLT) and greater than or equal (=>, SGE). We can use the existing support instructions to implement it. For example, if we want to implement A>B, we just need to implement B>A, if B>A is true, that means A>B is false, vice versa. 


• How did you handle boolean types.
If boolean equals to true we set it to 1.0, if it is false we set it to -1.0. Since in CMP R0, R1, R2, R3; the logic is: R0.x = (R1.x < 0.0) ? R2.x : R3.x; (Same applies for y, z, w). So we want false to be smaller than 0 and true to be bigger than 0.


• How did you implement if statements.
We first check the type of the condition expression to see if it is unary, binary or a function. If it belongs in these types, we need to use an expression temp to store the result of the condition and then save it to the condition temp. Or else we could directly save the value to a condition temp.

Then we check and see if the statements include an else statement. If it does not include an else statement, we do not need to recurse to the else statement, only print out the content in the if statement.

For the statements in an “if” we run CMP result, condition_temp, result, expression. So the result will be changed to the expression if condition_temp is true (greater than 0).
For the statements in an “else” we run CMP result, condition_temp, expression, result. So the result will be changed to the expression if condition_temp is false (less than 0).

If it is a nested if-else statement, we change the inner condition according to to outer condition. If it is nested in “if”, inner condition = inner condition * outer condition. If it is nested in “else”,  inner condition = inner condition * (-1) * outer condition.


• How did you implement constants.
We declare constant variables using the keyword PARAM. (example: PARAM red = {1.0, 0.0, 1.0, 1.0};, PARAM blue = 1;) Or if we implicitly create a constant in an expression or assignment, we directly print out the value (MOV red, {1.0, 2.0, 3.0, 4.0}).


• How the code for each type of node was generated.
We use the same recursive logic in printing AST trees (preorder traversal). We follow the basic recursive case function similar to ast_print and the corresponding assembly code will be printed out for each type of node. Other than taking care of declarations and printing out commands, we need to allocated temporary registers for conditions in if-else statements and expressions such as unary and binary expressions. The indexes of the temporary registers need to be saved using global variables to make sure they are used correctly in the recursive function. 

