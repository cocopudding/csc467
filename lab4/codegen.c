#include "codegen.h"
#include "ast.h"
#include "symbol.h"
#include "semantic.h"
#include "common.h"
#include "parser.tab.h"

#include <stdio.h>

FILE * outFile;
int outFlag=0;
int scope_print_code=0;
int if_else_condition=0;
int conditionValueCounter = 0;
int tempValueCounter= 0;
int maxTempValueCounter=0;

char index_char(int n) {
	switch (n) {
	case 0:
		return 'x';
	case 1:
		return 'y';
	case 2:
		return 'z';
	case 3:
		return 'w';
	}
}

int genCode(node *ast){
	//call print_to_file here
	if(outFlag==0){
		outFile=fopen("frag.txt","w");
	}
	outFlag=1;

	fprintf(outFile, "!!ARBfp1.0\n");
	print_to_file(ast);
	fprintf(outFile, "END\n");

	return 0;
}

int print_to_file(node *ast){
	if (ast==NULL){
		return 0;
	}
	switch (ast->kind) {
	case SCOPE_NODE:
		if (true){
			//printf("\nenter scope here!!!!!!!!\n");
			scope_print_code++;
			int temp1=print_to_file(ast->scope.declarations);
			int temp2=print_to_file(ast->scope.statements);
			scope_print_code--;
			if (temp1 == 0&& temp2 == 0)return 0;
			else return -1;
			break;
		}

	case UNARY_EXPRESION_NODE:
		//printf("\nenter unary here!!!!!!!!\n");
		if(true){
			int temp1=0;
			tempValueCounter++;
			fprintf(outFile, "TEMP exprTemp%d;\n",tempValueCounter);
			if (ast->unary_expr.right->kind == UNARY_EXPRESION_NODE || ast->unary_expr.right->kind == BINARY_EXPRESSION_NODE
					|| ast->unary_expr.right->kind == FUNCTION_NODE){
				temp1=print_to_file(ast->unary_expr.right);
				if (ast->unary_expr.op=='-'){
					fprintf(outFile, "MUL exprTemp%d, exprTemp%d, -1.0;\n", tempValueCounter, temp1);
					return tempValueCounter;
				}
				else if (ast->unary_expr.op=='!'){
					fprintf(outFile, "NOT exprTemp%d, exprTemp%d;\n", tempValueCounter, temp1);
					return tempValueCounter;
				}
			}
			else{
				if (ast->unary_expr.op=='-'){
					fprintf(outFile, "MUL exprTemp%d;\n", tempValueCounter);
					temp1=print_to_file(ast->unary_expr.right);
					fprintf(outFile, " , -1.0;\n");
					return tempValueCounter;
				}
				else if (ast->unary_expr.op=='!'){
					fprintf(outFile, "NOT exprTemp%d;\n", tempValueCounter);
					temp1=print_to_file(ast->unary_expr.right);
					fprintf(outFile, ";\n");
					return tempValueCounter;
				}
			}
		}
	   	break;

	case BINARY_EXPRESSION_NODE:
		//printf("\nenter binary here!!!!!!!!\n");
		if(true){
			int temp1=0;
			int temp2=0;
			int t1,t2,t3,t4,t5,t6;
			tempValueCounter++;
			if(tempValueCounter>maxTempValueCounter){
				fprintf(outFile,"TEMP exprTemp%d;\n",tempValueCounter);
				maxTempValueCounter++;
			}
			if (ast->binary_expr.left->kind == UNARY_EXPRESION_NODE || ast->binary_expr.left->kind == BINARY_EXPRESSION_NODE
											|| ast->binary_expr.left->kind == FUNCTION_NODE){
				temp1=print_to_file(ast->binary_expr.left);
			}
			if (ast->binary_expr.right->kind == UNARY_EXPRESION_NODE || ast->binary_expr.right->kind == BINARY_EXPRESSION_NODE
								|| ast->binary_expr.right->kind == FUNCTION_NODE){
				temp2=print_to_file(ast->binary_expr.right);
			}
			if(ast->binary_expr.op== AND){
				fprintf(outFile, "ADD exprTemp%d, ",tempValueCounter);
				if(temp1==0){
					temp1=print_to_file(ast->binary_expr.left);
				}else{
					fprintf(outFile,"exprTemp%d ",temp1);
				}
				fprintf(outFile,",");
				if(temp2==0){
					temp2=print_to_file(ast->binary_expr.right);
				}else{
					fprintf(outFile,"exprTemp%d ",temp2);
				}
				fprintf(outFile,";\nSUB exprTemp%d, exprTemp%d, 1.0;\n",tempValueCounter,tempValueCounter);
				tempValueCounter++;
				if(tempValueCounter>maxTempValueCounter){
					fprintf(outFile,"TEMP exprTemp%d;\n",tempValueCounter);
					maxTempValueCounter++;
				}
				fprintf(outFile,"CMP exprTemp%d, exprTemp%d, -1.0, 1.0;\n", tempValueCounter,tempValueCounter-1);
				fprintf(outFile,"MOV exprTemp%d, exprTemp%d;\n", tempValueCounter-1,tempValueCounter);
				tempValueCounter--;
				return tempValueCounter;
			}else if(ast->binary_expr.op== OR){
				fprintf(outFile, "ADD exprTemp%d, ",tempValueCounter);
				if(temp1==0){
					temp1=print_to_file(ast->binary_expr.left);
				}else{
					fprintf(outFile,"exprTemp%d ",temp1);
				}
				fprintf(outFile,",");
				if(temp2==0){
					temp2=print_to_file(ast->binary_expr.right);
				}else{
					fprintf(outFile,"exprTemp%d ",temp2);
				}
				fprintf(outFile,";\nADD exprTemp%d, exprTemp%d, 1.0;\n",tempValueCounter,tempValueCounter);
				tempValueCounter++;
				if(tempValueCounter>maxTempValueCounter){
					fprintf(outFile,"TEMP exprTemp%d;\n",tempValueCounter);
					maxTempValueCounter++;
				}
				fprintf(outFile,"CMP exprTemp%d, exprTemp%d, -1.0, 1.0;\n", tempValueCounter,tempValueCounter-1);
				fprintf(outFile,"MOV exprTemp%d, exprTemp%d;\n", tempValueCounter-1,tempValueCounter);
				tempValueCounter--;
				return tempValueCounter;
			}else if(ast->binary_expr.op== '<'){
				fprintf(outFile,"SLT ");
			}else if(ast->binary_expr.op== LEQ){
				//cannot use -> fprintf(outFile,"SLE ");
				//A<=B? use SGE temp, B, A
				fprintf(outFile,"SGE exprTemp%d, ",tempValueCounter);
				if(temp2==0){
					temp2=print_to_file(ast->binary_expr.right);
				}else{
					fprintf(outFile,"exprTemp%d",temp2);
				}

				fprintf(outFile,", ");
				if(temp1==0){
					temp1=print_to_file(ast->binary_expr.left);
				}else{
					fprintf(outFile,"exprTemp%d ",temp1);
				}

				fprintf(outFile,";\n");
				return tempValueCounter;
			}else if(ast->binary_expr.op== '>'){
				//cannot use -> fprintf(outFile,"SGT ");
				//A>B? use SLT temp, B, A
				fprintf(outFile,"SLT exprTemp%d, ",tempValueCounter);
				if(temp2==0){
					temp2=print_to_file(ast->binary_expr.right);
				}else{
					fprintf(outFile,"exprTemp%d",temp2);
				}

				fprintf(outFile,", ");
				if(temp1==0){
					temp1=print_to_file(ast->binary_expr.left);
				}else{
					fprintf(outFile,"exprTemp%d ",temp1);
				}

				fprintf(outFile,";\n");
				return tempValueCounter;
			}else if(ast->binary_expr.op== GEQ){
				fprintf(outFile,"SGE ");
			}else if(ast->binary_expr.op== EQ||ast->binary_expr.op== NEQ){
				fprintf(outFile,"SGE exprTemp%d, ", tempValueCounter);
				if(temp1==0){
					temp1=print_to_file(ast->binary_expr.left);
				}else{
					fprintf(outFile,"exprTemp%d ",temp1);
				}
				fprintf(outFile,",");
				if(temp2==0){
					temp2=print_to_file(ast->binary_expr.right);
				}else{
					fprintf(outFile,"exprTemp%d ",temp2);
				}
				fprintf(outFile,";\n");
				if((tempValueCounter+1)>maxTempValueCounter){
					fprintf(outFile,"TEMP exprTemp%d;\n",(tempValueCounter+1));
					maxTempValueCounter++;
				}
				fprintf(outFile,"SGE exprTemp%d, ", tempValueCounter+1);
				if(temp2==0){
					temp2=print_to_file(ast->binary_expr.right);
				}else{
					fprintf(outFile,"exprTemp%d ",temp2);
				}
				fprintf(outFile,",");
				if(temp1==0){
					temp1=print_to_file(ast->binary_expr.left);
				}else{
					fprintf(outFile,"exprTemp%d ",temp1);
				}
				fprintf(outFile,";\n");
				fprintf(outFile,"ADD exprTemp%d, exprTemp%d, exprTemp%d;\n",tempValueCounter+1,tempValueCounter+1,tempValueCounter);
				fprintf(outFile,"SUB exprTemp%d, exprTemp%d, 2.0;\n",tempValueCounter+1,tempValueCounter+1);
				if(ast->binary_expr.op== EQ){
					fprintf(outFile,"CMP exprTemp%d, exprTemp%d, -1.0, 1.0;\n", tempValueCounter,tempValueCounter+1);
				}else{
					fprintf(outFile,"CMP exprTemp%d, exprTemp%d, 1.0, -1.0;\n", tempValueCounter,tempValueCounter+1);
				}
				tempValueCounter++;
				return tempValueCounter-1;
			}else if(ast->binary_expr.op== '+'){
				fprintf(outFile, "ADD ");
			}else if(ast->binary_expr.op== '-'){
				fprintf(outFile, "SUB ");
			}else if(ast->binary_expr.op== '*'){
				fprintf(outFile, "MUL ");
			}else if(ast->binary_expr.op== '^'){
				fprintf(outFile, "POW ");
			}else if(ast->binary_expr.op== '/'){
				fprintf(outFile, "RCP exprTemp%d, ",tempValueCounter);
				if(temp2==0){
					temp2=print_to_file(ast->binary_expr.right);
				}else{
					fprintf(outFile,"exprTemp%d ",temp2);
				}
				fprintf(outFile,";\n");
				fprintf(outFile, "MUL exprTemp%d, ",tempValueCounter);
				if(temp1==0){
					temp1=print_to_file(ast->binary_expr.left);
				}else{
					fprintf(outFile,"exprTemp%d ",temp1);
				}
				fprintf(outFile,",exprTemp%d ",tempValueCounter);
				tempValueCounter++;
				return tempValueCounter;
			}

			fprintf(outFile,"exprTemp%d, ",tempValueCounter);
			if(temp1==0){
				temp1=print_to_file(ast->binary_expr.left);
			}else{
				fprintf(outFile,"exprTemp%d",temp1);
			}

			fprintf(outFile,", ");
			if(temp2==0){
				temp2=print_to_file(ast->binary_expr.right);
			}else{
				fprintf(outFile,"exprTemp%d ",temp2);
			}

			fprintf(outFile,";\n");
			return tempValueCounter;
		}

	   	break;

	case INT_NODE:
		//printf("\nenter int here!!!!!!!!\n");
		fprintf(outFile,"%d.0", ast->int_value);
		return 0;
	   	break;

	case FLOAT_NODE:
		//printf("\nenter float here!!!!!!!!\n");
		fprintf(outFile,"%f", ast->float_value);
		return 0;
	   	break;

	case BOOL_NODE:
		//printf("\nenter bool here!!!!!!!!\n");
	   	if (ast->bool_value == 1)
	   		fprintf(outFile,"1.0");
	   	else
	   		fprintf(outFile,"-1.0");
	   	return 0;
	   	break;

	case VAR_NODE:
		//printf("\nenter var node here!!!!!!!!\n");
		if (true){

			   if (strcmp(ast->variable.id, "gl_FragColor") == 0) {
				   if (ast->variable.is_array == 1){
					   fprintf(outFile,"result.color.%c", index_char(ast->variable.index));
				   } else {
					   fprintf(outFile,"result.color");
				   }
			   } else if (strcmp(ast->variable.id, "gl_FragDepth") == 0) {
				   if (ast->variable.is_array == 1){
					   fprintf(outFile,"result.depth.%c", index_char(ast->variable.index));
				   } else {
					   fprintf(outFile,"result.depth");
				   }
			   } else if (strcmp(ast->variable.id, "gl_FragCoord") == 0) {
				   if (ast->variable.is_array == 1){
					   fprintf(outFile,"fragment.position.%c", index_char(ast->variable.index));
				   } else {
					   fprintf(outFile,"fragment.position");
				   }
			   } else if (strcmp(ast->variable.id, "gl_TexCoord") == 0) {
				   if (ast->variable.is_array == 1){
					   fprintf(outFile,"fragment.texcoord.%c", index_char(ast->variable.index));
				   } else {
					   fprintf(outFile,"fragment.texcoord");
				   }
			   } else if (strcmp(ast->variable.id, "gl_Color") == 0) {
				   if (ast->variable.is_array == 1){
					   fprintf(outFile,"fragment.color.%c", index_char(ast->variable.index));
				   } else {
					   fprintf(outFile,"fragment.color");
				   }
			   } else if (strcmp(ast->variable.id, "gl_Secondary") == 0) {
				   if (ast->variable.is_array == 1){
					   fprintf(outFile,"fragment.color.secondary.%c", index_char(ast->variable.index));
				   } else {
					   fprintf(outFile,"fragment.color.secondary");
				   }
			   } else if (strcmp(ast->variable.id, "gl_FogFragCoord") == 0) {
				   if (ast->variable.is_array == 1){
					   fprintf(outFile,"fragment.fogcoord.%c", index_char(ast->variable.index));
				   } else {
					   fprintf(outFile,"fragment.fogcoord");
				   }
			   } else if (strcmp(ast->variable.id, "gl_Light_Half") == 0) {
				   if (ast->variable.is_array == 1){
					   fprintf(outFile,"state.light[0].half.%c", index_char(ast->variable.index));
				   } else {
					   fprintf(outFile,"state.light[0].half");
				   }
			   } else if (strcmp(ast->variable.id, "gl_Light_Ambient") == 0) {
				   if (ast->variable.is_array == 1){
					   fprintf(outFile,"state.lightmodel.ambient.%c", index_char(ast->variable.index));
				   } else {
					   fprintf(outFile,"state.lightmodel.ambient");
				   }
			   } else if (strcmp(ast->variable.id, "gl_Material_Shininess") == 0) {
				   if (ast->variable.is_array == 1){
					   fprintf(outFile,"state.material.shininess.%c", index_char(ast->variable.index));
				   } else {
					   fprintf(outFile,"state.material.shininess");
				   }
			   } else if (strcmp(ast->variable.id, "env1") == 0) {
				   if (ast->variable.is_array == 1){
					   fprintf(outFile,"program.env[1].%c", index_char(ast->variable.index));
				   } else {
					   fprintf(outFile,"program.env[1]");
				   }
			   } else if (strcmp(ast->variable.id, "env2") == 0) {
				   if (ast->variable.is_array == 1){
					   fprintf(outFile,"program.env[2].%c", index_char(ast->variable.index));
				   } else {
					   fprintf(outFile,"program.env[2]");
				   }
			   } else if (strcmp(ast->variable.id, "env3") == 0) {
				   if (ast->variable.is_array == 1){
					   fprintf(outFile,"program.env[3].%c", index_char(ast->variable.index));
				   } else {
					   fprintf(outFile,"program.env[3]");
				   }
			   } else {
				   if (ast->variable.is_array == 1){
					   fprintf(outFile,"%s.%c", ast->variable.id, index_char(ast->variable.index));
				   } else {
					   fprintf(outFile,"%s", ast->variable.id);
				   }
			   }
		}
		return 0;
	   	break;

	case FUNCTION_NODE:
		//printf("\nenter function here!!!!!!!!\n");
		tempValueCounter++;
		if (tempValueCounter > maxTempValueCounter) {
			fprintf(outFile,"TEMP exprTemp%d;\n",tempValueCounter);
			maxTempValueCounter++;
		}

		if (ast->function_call.name == 0) {
			fprintf(outFile,"DP3 exprTemp%d, ",tempValueCounter);
		} else if (ast->function_call.name == 1) {
			fprintf(outFile,"LIT exprTemp%d, ",tempValueCounter);
		} else if (ast->function_call.name == 2) {
			fprintf(outFile,"RSQ exprTemp%d, ",tempValueCounter);
		}

		print_to_file(ast->function_call.arguments);
		fprintf(outFile,";\n");

		return tempValueCounter;
	   	break;

	case CONSTRUCTOR_NODE:
		//printf("\nenter constructor here!!!!!!!!\n");

		print_to_file(ast->constructor.type);

		fprintf(outFile,"{");
		print_to_file(ast->constructor.arguments);
		fprintf(outFile,"}");

		return 0;
	   	break;

	case STATEMENT_NODE:
		if(true){
			//printf("\nenter statement here!!!!!!!!\n");
			int temp1=print_to_file(ast->statements.statements);
			int temp2=print_to_file(ast->statements.statement);
			if (temp1 == 0&& temp2 == 0) return 0;
			else return -1;
		}
	   	break;

	case IF_STATEMENT_NODE:
		if (true){
			//printf("\nenter if here!!!!!!!!\n");
			conditionValueCounter++;

			int temp3=0;
			int temp1 = 0;

			fprintf(outFile, "TEMP condTemp%d;\n", conditionValueCounter);
			if (ast->statement_if_else.condition_expression->kind == UNARY_EXPRESION_NODE || ast->statement_if_else.condition_expression->kind == BINARY_EXPRESSION_NODE
					|| ast->statement_if_else.condition_expression->kind == FUNCTION_NODE) {
				temp1 = print_to_file(ast->statement_if_else.condition_expression);
				fprintf(outFile, "MOV condTemp%d, exprTemp%d;\n", conditionValueCounter, temp1);
			} else {
				fprintf(outFile, "MOV condTemp%d, ", conditionValueCounter);
				print_to_file(ast->statement_if_else.condition_expression);
				fprintf(outFile, ";\n");
			}

			//nested in if
			// condition = inner condition && outer condition
		    if (if_else_condition == 1) {
		    	fprintf(outFile, "MUL condTemp%d, condTemp%d, condTemp%d;\n", conditionValueCounter, conditionValueCounter, (conditionValueCounter - 1));
			}

		    //nested in else
		    //opposite condition of nested in if
		    if (if_else_condition == 2){
		    	fprintf(outFile, "MUL condTemp%d, condTemp%d, condTemp%d;\n", conditionValueCounter, conditionValueCounter, (conditionValueCounter - 1));
		    	fprintf(outFile, "MUL condTemp%d, condTemp%d, -1;\n", conditionValueCounter, conditionValueCounter, conditionValueCounter);
		    }


			if (ast->statement_if_else.else_statement != NULL){
				fprintf(outFile, "#else\n");
				if_else_condition=2;
				temp3=print_to_file(ast->statement_if_else.else_statement);
				if_else_condition=0;
			}

			fprintf(outFile, "#then\n");
			if_else_condition=1;
			int temp2=print_to_file(ast->statement_if_else.if_statement);
			if_else_condition=0;
			fprintf(outFile, "#endif\n");

			conditionValueCounter--;
			if (temp1 == 0&& temp2 == 0 && temp3==0) return 0;
			else return -1;
			break;
		}

	case ASSIGNMENT_NODE:
		if (true){
			//printf("\nenter assignment here!!!!!!!!\n");
			int temp1=0;
			int temp2=0;
			node_complete_type variable_type;
			get_type(ast->statement_assign.variable, &variable_type, scope_print_code);

			if ((variable_type.type == VEC2 || variable_type.type == VEC3 || variable_type.type == VEC4) && variable_type.is_index_vector) {
				variable_type.type = FLOAT;
			} else if ((variable_type.type == IVEC2 || variable_type.type == IVEC3 || variable_type.type == IVEC4) && variable_type.is_index_vector) {
				variable_type.type = INT;
			} else if ((variable_type.type == BVEC2 || variable_type.type == BVEC3 || variable_type.type == BVEC4) && variable_type.is_index_vector) {
				variable_type.type = BOOL;
			}
			if(if_else_condition == 1 || if_else_condition==2){
				if (ast->statement_assign.expression->kind == UNARY_EXPRESION_NODE || ast->statement_assign.expression->kind == BINARY_EXPRESSION_NODE
						|| ast->statement_assign.expression->kind == FUNCTION_NODE) {
					temp2=print_to_file(ast->statement_assign.expression);
					fprintf(outFile, "CMP ");
					temp1=print_to_file(ast->statement_assign.variable);
					fprintf(outFile, ", condTemp%d, ", conditionValueCounter);

					if (if_else_condition == 1) {
						temp1=print_to_file(ast->statement_assign.variable);
						fprintf(outFile, ", exprTemp%d;\n", temp2);
					} else {
						fprintf(outFile, "exprTemp%d;\n", temp2);
						temp1=print_to_file(ast->statement_assign.variable);
						fprintf(outFile, ";\n");
					}

				} else {
					fprintf(outFile, "CMP ");
					temp1=print_to_file(ast->statement_assign.variable);
					fprintf(outFile, ", condTemp%d, ", conditionValueCounter);

					if (if_else_condition == 1) {
						temp1=print_to_file(ast->statement_assign.variable);
						fprintf(outFile, ", ");
						temp2=print_to_file(ast->statement_assign.expression);
						fprintf(outFile, ";\n");
					} else {
						temp2=print_to_file(ast->statement_assign.expression);
						fprintf(outFile, ", ");
						temp1=print_to_file(ast->statement_assign.variable);
						fprintf(outFile, ";\n");
					}

				}
			} else {
				if (ast->statement_assign.expression->kind == UNARY_EXPRESION_NODE || ast->statement_assign.expression->kind == BINARY_EXPRESSION_NODE
						|| ast->statement_assign.expression->kind == FUNCTION_NODE) {
					temp2=print_to_file(ast->statement_assign.expression);
					fprintf(outFile, "MOV ");
					temp1=print_to_file(ast->statement_assign.variable);
					fprintf(outFile, ", exprTemp%d;\n", temp2);
				} else {
					fprintf(outFile, "MOV ");
					temp1=print_to_file(ast->statement_assign.variable);
					fprintf(outFile, ", ");
					temp2=print_to_file(ast->statement_assign.expression);
					fprintf(outFile, ";\n");
				}
			}

			if (temp1 == 0&& temp2 == 0) return 0;
			else return -1;
			break;
		}

	case NESTED_SCOPE_NODE:
		//printf("\nenter nested here!!!!!!!!\n");
		return 0;
	   	break;

	case DECLARATIONS_NODE:
		if (true){
			//printf("\nenter declarations here!!!!!!!!\n");
			int temp1=print_to_file(ast->declarations.declarations);
			int temp2=print_to_file(ast->declarations.declaration);
			if (temp1 == 0&& temp2 == 0) return 0;
			else return -1;
			break;
		}


	case DECLARATION_NODE:
		if (true) {
			int temp1=0;
			int temp2=0;
			if (ast->declaration.expression == NULL) {
				fprintf(outFile,"TEMP %s;\n", ast->declaration.id);
			} else {
				if (ast->declaration.is_const == 0) {
					if(if_else_condition == 1 || if_else_condition==2){
						if (ast->declaration.expression->kind == UNARY_EXPRESION_NODE || ast->declaration.expression->kind == BINARY_EXPRESSION_NODE
								|| ast->declaration.expression->kind  == FUNCTION_NODE) {
							temp2=print_to_file(ast->declaration.expression);
							fprintf(outFile, "TEMP %s;\nCMP %s, condTemp%d, ", ast->declaration.id, ast->declaration.id, conditionValueCounter);

							if (if_else_condition == 1) {
								fprintf(outFile, "%s , exprTemp%d;\n", ast->declaration.id, temp2);
							} else {
								fprintf(outFile, "exprTemp%d, %s;\n",temp2, ast->declaration.id);
							}

						} else {
							fprintf(outFile, "TEMP %s;\nCMP %s, condTemp%d, ", ast->declaration.id, ast->declaration.id, conditionValueCounter);

							if (if_else_condition == 1) {
								fprintf(outFile, "%s, ", ast->declaration.id);
								temp2=print_to_file(ast->declaration.expression);
							} else {
								temp2=print_to_file(ast->declaration.expression);
								fprintf(outFile, ", %s", ast->declaration.id);
							}
							fprintf(outFile, ";\n");
						}
					} else {
						if (ast->declaration.expression->kind == UNARY_EXPRESION_NODE || ast->declaration.expression->kind == BINARY_EXPRESSION_NODE
								|| ast->declaration.expression->kind == FUNCTION_NODE) {
							fprintf(outFile, "TEMP %s;\nMOV %s, exprTemp%d", ast->declaration.id, ast->declaration.id, temp2);
						} else {
							fprintf(outFile, "TEMP %s;\nMOV %s, ", ast->declaration.id, ast->declaration.id, temp2);
							temp2=print_to_file(ast->declaration.expression);
						}
						fprintf(outFile, ";\n");
					}
				} else {
					if (ast->declaration.expression->kind == UNARY_EXPRESION_NODE || ast->declaration.expression->kind == BINARY_EXPRESSION_NODE
							|| ast->declaration.expression->kind  == FUNCTION_NODE) {
						temp2=print_to_file(ast->declaration.expression);
						fprintf(outFile, "PARAM %s = exprTemp%d", ast->declaration.id, temp2);
					} else {
						fprintf(outFile, "PARAM %s = ", ast->declaration.id);
						temp2=print_to_file(ast->declaration.expression);
					}
					fprintf(outFile, ";\n");
				}
			}
		}
		return 0;
	   	break;

	case TYPE_NODE:
		//printf("\nenter type here!!!!!!!!\n");
		//fprintf(outFile,"%s ", type_to_string(ast->type_node.type_name));
		return 0;
	   	break;

	case NESTED_EXPRESSION_NODE:
		//printf("\nenter nested here!!!!!!!!\n");
		return 0;
	    break;

	case EXP_VAR_NODE:
		//printf("\nenter exp var here!!!!!!!!\n");
		return print_to_file(ast->expr_variable.variable);
	    break;

	case ARGUMENTS_NODE:
		//printf("\nenter arg node here!!!!!!!!\n");
		print_to_file(ast->arguments.arg);
		if (ast->arguments.expr != NULL && ast->arguments.arg != NULL)
			fprintf(outFile, ", ");
		print_to_file(ast->arguments.expr);

		return 0;
	   	break;

	default:
		//printf("\nenter default here!!!!!!!!\n");
		fprintf(outFile,"DEFAULT\n");
		return 0;
	   	break;
	}
	return 0;
}
