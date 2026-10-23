# yyparse grammar (libGLProgrammability, Tiger PPC) - recovered from the binary's bison tables
**How this was recovered (all of it checkable):**
- The bison tables `yytranslate, yyr1, yyr2, yydefact, yydefgoto, yypact, yypgoto, yytable, yycheck` sit in `__TEXT,__const` (symbols `_yytranslate` 0x97c3576c ... `_yycheck` 0x97c36c6a; read with `Tools/userspace/machoutil.py`). Dimensions: 95 internal tokens (`YYNTOKENS`), 74 nonterminals, 215 rules (+ rule 0), 334 states, `YYLAST` 1263, 350 external token codes.
- `yyr2[r]` (rule length) and `yyr1[r]` (LHS number) for all 215 rules reproduce, rule for rule, the GLSL grammar of the 3Dlabs `glslang.y` front end (the ATI compiler descends from it): 215/215 lengths and a consistent LHS numbering (same LHS -> same number, different LHS -> different number). The ATI build differs from stock 3Dlabs in two extra sampler tokens (`sampler2DRect`, `sampler2DRectShadow`, internal tokens 42 and 43, +2 `type_specifier` rules) which the table counts (95 tokens, 26 `type_specifier` alternatives) force.
- The right-hand sides were then checked against the LALR automaton rebuilt from the tables (shift/goto edges from `yypact/yytable/yycheck`, `yypgoto/yydefgoto`): for each rule the last RHS symbol equals the accessing symbol of every state that reduces it, and where explicit predecessor edges exist (110 rules) the whole RHS path exists; 0 of 215 rules fail. 105 rules reach only their last symbol because their predecessors are default-goto states. (Scripts: `Tools/userspace/yygrammar/` in this branch.)
- Token and nonterminal NAMES are the 3Dlabs names, not read from the binary (this build has no `yytname`); the tier is INFERRED for names, CONFIRMED for the rule shapes.
- Mid-rule actions are the empty rules 177/178 (compound_statement scope open/close), 193 (while), 195 (do), 197 (for), 214 (function body); bison numbers them before the rule that contains them.
- yyparse's action switch is `switch(rule)`: `case N` is rule N (`case 0xbb` etc. are the hex rule numbers, shared tails `switchD_97ba39c8_caseD_*` are the default action `$$ = $1`).

## Rule table: rule | production | `case` line in part_006.c
| rule | production | case line (part_006.c) | string literals in the action (evidence) |
|---|---|---|---|
| 1 | `variable_identifier : IDENTIFIER` | 2090 | `undeclared identifier`; `variable expected` |
| 2 | `primary_expression : variable_identifier` | (default action `$$ = $1`) |  |
| 3 | `primary_expression : INTCONSTANT` | 2224 | ` integer constant overflow` |
| 4 | `primary_expression : FLOATCONSTANT` | 2247 |  |
| 5 | `primary_expression : BOOLCONSTANT` | 2253 |  |
| 6 | `primary_expression : LEFT_PAREN expression RIGHT_PAREN` | 2270 |  |
| 7 | `postfix_expression : primary_expression` | (default action `$$ = $1`) |  |
| 8 | `postfix_expression : postfix_expression LEFT_BRACKET integer_expression RIGHT_BRACKET` | 2273 | `expression`; ` left of \'[\' is not of type array, matrix, or vector `; `field selection out of range \'%d\'`; `array index out of range \'%d\'` |
| 9 | `postfix_expression : function_call` | (default action `$$ = $1`) |  |
| 10 | `postfix_expression : postfix_expression DOT FIELD_SELECTION` | 2679 | `cannot apply dot operator to an array`; ` field selection requires structure, vector, or matrix on le`; `structure has no fields`; `Internal Error` |
| 11 | `postfix_expression : postfix_expression INC_OP` | 2937 | `++` |
| 12 | `postfix_expression : postfix_expression DEC_OP` | 2974 | `--` |
| 13 | `integer_expression : expression` | 3013 | `[]` |
| 14 | `function_call : function_call_generic` | 3016 | `assign`; `Constant value cannot be passed for \'out\' or \'inout\' par`; `Error`; ` wrong operand type` |
| 15 | `function_call_generic : function_call_header_with_parameters RIGHT_PAREN` | 3215 |  |
| 16 | `function_call_generic : function_call_header_no_parameters RIGHT_PAREN` | 3216 |  |
| 17 | `function_call_header_no_parameters : function_call_header VOID_TYPE` | 3223 |  |
| 18 | `function_call_header_no_parameters : function_call_header` | 3226 |  |
| 19 | `function_call_header_with_parameters : function_call_header assignment_expression` | 3231 |  |
| 20 | `function_call_header_with_parameters : function_call_header_with_parameters COMMA assignment_expression` | 3296 |  |
| 21 | `function_call_header : function_identifier LEFT_PAREN` | 3367 |  |
| 22 | `function_identifier : constructor_identifier` | 3370 |  |
| 23 | `function_identifier : IDENTIFIER` | 3482 |  |
| 24 | `constructor_identifier : FLOAT_TYPE` | 3538 |  |
| 25 | `constructor_identifier : INT_TYPE` | 3542 |  |
| 26 | `constructor_identifier : BOOL_TYPE` | 3546 |  |
| 27 | `constructor_identifier : VEC2` | 3550 |  |
| 28 | `constructor_identifier : VEC3` | 3554 |  |
| 29 | `constructor_identifier : VEC4` | 3558 |  |
| 30 | `constructor_identifier : BVEC2` | 3562 | `bvec2`; ` supported in vertex/fragment shaders only ` |
| 31 | `constructor_identifier : BVEC3` | 3577 | `bvec3`; ` supported in vertex/fragment shaders only ` |
| 32 | `constructor_identifier : BVEC4` | 3592 | `bvec4`; ` supported in vertex/fragment shaders only ` |
| 33 | `constructor_identifier : IVEC2` | 3607 | `ivec2`; ` supported in vertex/fragment shaders only ` |
| 34 | `constructor_identifier : IVEC3` | 3622 | `ivec3`; ` supported in vertex/fragment shaders only ` |
| 35 | `constructor_identifier : IVEC4` | 3637 | `ivec4`; ` supported in vertex/fragment shaders only ` |
| 36 | `constructor_identifier : MATRIX2` | 3652 | `mat2`; ` supported in vertex/fragment shaders only ` |
| 37 | `constructor_identifier : MATRIX3` | 3667 | `mat3`; ` supported in vertex/fragment shaders only ` |
| 38 | `constructor_identifier : MATRIX4` | 3682 | `mat4`; ` supported in vertex/fragment shaders only ` |
| 39 | `constructor_identifier : TYPE_NAME` | 3697 |  |
| 40 | `unary_expression : postfix_expression` | (default action `$$ = $1`) |  |
| 41 | `unary_expression : INC_OP unary_expression` | 3724 | `++` |
| 42 | `unary_expression : DEC_OP unary_expression` | 3758 | `--` |
| 43 | `unary_expression : unary_operator unary_expression` | 3794 |  |
| 44 | `unary_operator : PLUS` | 3836 |  |
| 45 | `unary_operator : DASH` | 3840 |  |
| 46 | `unary_operator : BANG` | 3844 |  |
| 47 | `unary_operator : TILDE` | 3848 | ` reserved for future use ` |
| 48 | `multiplicative_expression : unary_expression` | (default action `$$ = $1`) |  |
| 49 | `multiplicative_expression : multiplicative_expression STAR unary_expression` | 3863 | ` supported in vertex/fragment shaders only ` |
| 50 | `multiplicative_expression : multiplicative_expression SLASH unary_expression` | 3913 | ` supported in vertex/fragment shaders only ` |
| 51 | `multiplicative_expression : multiplicative_expression PERCENT unary_expression` | 3963 | ` reserved for future use ` |
| 52 | `additive_expression : multiplicative_expression` | (default action `$$ = $1`) |  |
| 53 | `additive_expression : additive_expression PLUS multiplicative_expression` | 4013 |  |
| 54 | `additive_expression : additive_expression DASH multiplicative_expression` | 4057 |  |
| 55 | `shift_expression : additive_expression` | (default action `$$ = $1`) |  |
| 56 | `shift_expression : shift_expression LEFT_OP additive_expression` | 4101 | ` reserved for future use `; `<<` |
| 57 | `shift_expression : shift_expression RIGHT_OP additive_expression` | 4151 | ` reserved for future use `; `>>` |
| 58 | `relational_expression : shift_expression` | (default action `$$ = $1`) |  |
| 59 | `relational_expression : relational_expression LEFT_ANGLE shift_expression` | 4201 |  |
| 60 | `relational_expression : relational_expression RIGHT_ANGLE shift_expression` | 4244 |  |
| 61 | `relational_expression : relational_expression LE_OP shift_expression` | 4287 | `<=` |
| 62 | `relational_expression : relational_expression GE_OP shift_expression` | 4330 | `>=` |
| 63 | `equality_expression : relational_expression` | (default action `$$ = $1`) |  |
| 64 | `equality_expression : equality_expression EQ_OP relational_expression` | 4373 | `==` |
| 65 | `equality_expression : equality_expression NE_OP relational_expression` | 4416 | `!=` |
| 66 | `and_expression : equality_expression` | (default action `$$ = $1`) |  |
| 67 | `and_expression : and_expression AMPERSAND equality_expression` | 4459 | ` reserved for future use ` |
| 68 | `exclusive_or_expression : and_expression` | (default action `$$ = $1`) |  |
| 69 | `exclusive_or_expression : exclusive_or_expression CARET and_expression` | 4509 | ` reserved for future use ` |
| 70 | `inclusive_or_expression : exclusive_or_expression` | (default action `$$ = $1`) |  |
| 71 | `inclusive_or_expression : inclusive_or_expression VERTICAL_BAR exclusive_or_expression` | 4559 | ` reserved for future use ` |
| 72 | `logical_and_expression : inclusive_or_expression` | (default action `$$ = $1`) |  |
| 73 | `logical_and_expression : logical_and_expression AND_OP inclusive_or_expression` | 4619 | `&&` |
| 74 | `logical_xor_expression : logical_and_expression` | (default action `$$ = $1`) |  |
| 75 | `logical_xor_expression : logical_xor_expression XOR_OP logical_and_expression` | 4662 | `^^` |
| 76 | `logical_or_expression : logical_xor_expression` | (default action `$$ = $1`) |  |
| 77 | `logical_or_expression : logical_or_expression OR_OP logical_xor_expression` | 4735 | `\|\|` |
| 78 | `conditional_expression : logical_or_expression` | (default action `$$ = $1`) |  |
| 79 | `conditional_expression : logical_or_expression QUESTION expression COLON assignment_expression` | 4780 |  |
| 80 | `assignment_expression : conditional_expression` | (default action `$$ = $1`) |  |
| 81 | `assignment_expression : unary_expression assignment_operator assignment_expression` | 4845 | `assign` |
| 82 | `assignment_operator : EQUAL` | 4895 |  |
| 83 | `assignment_operator : MUL_ASSIGN` | 4899 | `*=`; ` supported in vertex/fragment shaders only ` |
| 84 | `assignment_operator : DIV_ASSIGN` | 4914 | `/=`; ` supported in vertex/fragment shaders only ` |
| 85 | `assignment_operator : MOD_ASSIGN` | 4929 | `%=`; ` reserved for future use ` |
| 86 | `assignment_operator : ADD_ASSIGN` | 4944 |  |
| 87 | `assignment_operator : SUB_ASSIGN` | 4948 |  |
| 88 | `assignment_operator : LEFT_ASSIGN` | 4952 | `<<=`; ` reserved for future use ` |
| 89 | `assignment_operator : RIGHT_ASSIGN` | 4967 | `<<=`; ` reserved for future use ` |
| 90 | `assignment_operator : AND_ASSIGN` | 4982 | `&=`; ` reserved for future use ` |
| 91 | `assignment_operator : XOR_ASSIGN` | 4997 | `^=`; ` reserved for future use ` |
| 92 | `assignment_operator : OR_ASSIGN` | 5012 | `\|=`; ` reserved for future use ` |
| 93 | `expression : assignment_expression` | (default action `$$ = $1`) |  |
| 94 | `expression : expression COMMA assignment_expression` | 5027 |  |
| 95 | `constant_expression : conditional_expression` | 5081 |  |
| 96 | `declaration : function_prototype SEMICOLON` | 5086 |  |
| 97 | `declaration : init_declarator_list SEMICOLON` | 5092 |  |
| 98 | `function_prototype : function_declarator RIGHT_PAREN` | 5103 |  |
| 99 | `function_declarator : function_header` | 5109 |  |
| 100 | `function_declarator : function_header_with_parameters` | 5110 |  |
| 101 | `function_header_with_parameters : function_header parameter_declaration` | 5114 |  |
| 102 | `function_header_with_parameters : function_header_with_parameters COMMA parameter_declaration` | 5192 | `void`; `cannot be an argument type except for \'(void)\'` |
| 103 | `function_header : fully_specified_type IDENTIFIER LEFT_PAREN` | 5261 | `no qualifiers allowed for function return` |
| 104 | `parameter_declarator : type_specifier IDENTIFIER` | 5374 | `illegal use of type \'void\'` |
| 105 | `parameter_declarator : type_specifier IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET` | 5460 | `cannot declare arrays of this type` |
| 106 | `parameter_declaration : type_qualifier parameter_qualifier parameter_declarator` | 5626 |  |
| 107 | `parameter_declaration : parameter_qualifier parameter_declarator` | 5633 |  |
| 108 | `parameter_declaration : type_qualifier parameter_qualifier parameter_type_specifier` | 5627 |  |
| 109 | `parameter_declaration : parameter_qualifier parameter_type_specifier` | 5634 |  |
| 110 | `parameter_qualifier : /* empty */` | 5659 |  |
| 111 | `parameter_qualifier : IN_QUAL` | 5660 |  |
| 112 | `parameter_qualifier : OUT_QUAL` | 5663 |  |
| 113 | `parameter_qualifier : INOUT_QUAL` | 5666 |  |
| 114 | `parameter_type_specifier : type_specifier` | 5669 |  |
| 115 | `parameter_type_specifier : type_specifier LEFT_BRACKET constant_expression RIGHT_BRACKET` | 5740 | `cannot declare arrays of this type` |
| 116 | `init_declarator_list : single_declaration` | 5899 |  |
| 117 | `init_declarator_list : init_declarator_list COMMA IDENTIFIER` | 5905 |  |
| 118 | `init_declarator_list : init_declarator_list COMMA IDENTIFIER LEFT_BRACKET RIGHT_BRACKET` | 5910 |  |
| 119 | `init_declarator_list : init_declarator_list COMMA IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET` | 5922 |  |
| 120 | `init_declarator_list : init_declarator_list COMMA IDENTIFIER EQUAL initializer` | 5927 |  |
| 121 | `single_declaration : fully_specified_type` | 5954 |  |
| 122 | `single_declaration : fully_specified_type IDENTIFIER` | 5964 |  |
| 123 | `single_declaration : fully_specified_type IDENTIFIER LEFT_BRACKET RIGHT_BRACKET` | 5986 |  |
| 124 | `single_declaration : fully_specified_type IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET` | 6013 |  |
| 125 | `single_declaration : fully_specified_type IDENTIFIER EQUAL initializer` | 6059 |  |
| 126 | `fully_specified_type : type_specifier` | 6087 |  |
| 127 | `fully_specified_type : type_qualifier type_specifier` | 6096 | `cannot be bool or int` |
| 128 | `type_qualifier : CONST_QUAL` | 6133 |  |
| 129 | `type_qualifier : ATTRIBUTE` | 6136 | ` supported in vertex shaders only `; `attribute` |
| 130 | `type_qualifier : VARYING` | 6155 | `varying` |
| 131 | `type_qualifier : UNIFORM` | 6188 | `uniform` |
| 132 | `type_specifier : VOID_TYPE` | 6219 |  |
| 133 | `type_specifier : FLOAT_TYPE` | 6244 |  |
| 134 | `type_specifier : INT_TYPE` | 6248 |  |
| 135 | `type_specifier : BOOL_TYPE` | 6252 |  |
| 136 | `type_specifier : VEC2` | 6256 |  |
| 137 | `type_specifier : VEC3` | 6260 |  |
| 138 | `type_specifier : VEC4` | 6264 |  |
| 139 | `type_specifier : BVEC2` | 6268 |  |
| 140 | `type_specifier : BVEC3` | 6275 |  |
| 141 | `type_specifier : BVEC4` | 6279 |  |
| 142 | `type_specifier : IVEC2` | 6283 |  |
| 143 | `type_specifier : IVEC3` | 6291 |  |
| 144 | `type_specifier : IVEC4` | 6298 |  |
| 145 | `type_specifier : MATRIX2` | 6305 | `mat2`; ` supported in vertex/fragment shaders only ` |
| 146 | `type_specifier : MATRIX3` | 6317 | `mat3`; ` supported in vertex/fragment shaders only ` |
| 147 | `type_specifier : MATRIX4` | 6329 | `mat4`; ` supported in vertex/fragment shaders only ` |
| 148 | `type_specifier : SAMPLER1D` | 6365 | `sampler1D`; ` supported in vertex/fragment shaders only ` |
| 149 | `type_specifier : SAMPLER2D` | 6377 | `sampler2D`; ` supported in vertex/fragment shaders only ` |
| 150 | `type_specifier : SAMPLER3D` | 6389 | `sampler3D`; ` supported in vertex/fragment shaders only ` |
| 151 | `type_specifier : SAMPLERCUBE` | 6401 | `samplerCube`; ` supported in vertex/fragment shaders only ` |
| 152 | `type_specifier : SAMPLER1DSHADOW` | 6413 | `sampler1DShadow`; ` supported in vertex/fragment shaders only ` |
| 153 | `type_specifier : SAMPLER2DSHADOW` | 6425 | `sampler2DShadow`; ` supported in vertex/fragment shaders only ` |
| 154 | `type_specifier : SAMPLER2DRECT` | 6437 | `sampler2DRect`; ` supported in vertex/fragment shaders only `; `GL_ARB_texture_rectangle` |
| 155 | `type_specifier : SAMPLER2DRECTSHADOW` | 6454 | `sampler2DRectShadow`; ` supported in vertex/fragment shaders only `; `GL_ARB_texture_rectangle` |
| 156 | `type_specifier : struct_specifier` | 6498 | `struct`; ` supported in vertex/fragment shaders only ` |
| 157 | `type_specifier : TYPE_NAME` | 6520 |  |
| 158 | `struct_specifier : STRUCT IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE` | 6545 | `struct`; `redefinition` |
| 159 | `struct_specifier : STRUCT LEFT_BRACE struct_declaration_list RIGHT_BRACE` | 6704 |  |
| 160 | `struct_declaration_list : struct_declaration` | 5111 |  |
| 161 | `struct_declaration_list : struct_declaration_list struct_declaration` | 6790 | `duplicate field name in structure:`; `struct` |
| 162 | `struct_declaration : type_specifier struct_declarator_list SEMICOLON` | 6855 |  |
| 163 | `struct_declarator_list : struct_declarator` | 6886 |  |
| 164 | `struct_declarator_list : struct_declarator_list COMMA struct_declarator` | 6900 |  |
| 165 | `struct_declarator : IDENTIFIER` | 6926 |  |
| 166 | `struct_declarator : IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET` | 6948 | `structure field array size must be a positive integer` |
| 167 | `initializer : assignment_expression` | (default action `$$ = $1`) |  |
| 168 | `declaration_statement : declaration` | (default action `$$ = $1`) |  |
| 169 | `statement : compound_statement` | (default action `$$ = $1`) |  |
| 170 | `statement : simple_statement` | (default action `$$ = $1`) |  |
| 171 | `simple_statement : declaration_statement` | (default action `$$ = $1`) |  |
| 172 | `simple_statement : expression_statement` | (default action `$$ = $1`) |  |
| 173 | `simple_statement : selection_statement` | (default action `$$ = $1`) |  |
| 174 | `simple_statement : iteration_statement` | (default action `$$ = $1`) |  |
| 175 | `simple_statement : jump_statement` | (default action `$$ = $1`) |  |
| 176 | `compound_statement : LEFT_BRACE RIGHT_BRACE` | 5087 |  |
| 177 | `@new_scope : /* empty */` | 6998 |  |
| 178 | `@pop_scope : /* empty */` | 7033 |  |
| 179 | `compound_statement : LEFT_BRACE @new_scope statement_list @pop_scope RIGHT_BRACE` | 7046 |  |
| 180 | `statement_no_new_scope : compound_statement_no_new_scope` | (default action `$$ = $1`) |  |
| 181 | `statement_no_new_scope : simple_statement` | (default action `$$ = $1`) |  |
| 182 | `compound_statement_no_new_scope : LEFT_BRACE RIGHT_BRACE` | 5088 |  |
| 183 | `compound_statement_no_new_scope : LEFT_BRACE statement_list RIGHT_BRACE` | 5093 |  |
| 184 | `statement_list : statement` | 7056 |  |
| 185 | `statement_list : statement_list statement` | 7065 |  |
| 186 | `expression_statement : SEMICOLON` | 5089 |  |
| 187 | `expression_statement : expression SEMICOLON` | 2271 |  |
| 188 | `selection_statement : IF LEFT_PAREN expression RIGHT_PAREN selection_rest_statement` | 7071 |  |
| 189 | `selection_rest_statement : statement ELSE statement` | 7089 |  |
| 190 | `selection_rest_statement : statement` | 7094 |  |
| 191 | `condition : expression` | 7097 |  |
| 192 | `condition : fully_specified_type IDENTIFIER EQUAL initializer` | 7103 |  |
| 193 | `@while_scope : /* empty */` | 7129 |  |
| 194 | `iteration_statement : WHILE LEFT_PAREN @while_scope condition RIGHT_PAREN statement_no_new_scope` | 7136 |  |
| 195 | `@do_scope : /* empty */` | 7151 |  |
| 196 | `iteration_statement : DO @do_scope statement WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON` | 7153 |  |
| 197 | `@for_scope : /* empty */` | 7173 |  |
| 198 | `iteration_statement : FOR LEFT_PAREN @for_scope for_init_statement for_rest_statement RIGHT_PAREN statement_no_new_scope` | 7211 |  |
| 199 | `for_init_statement : expression_statement` | (default action `$$ = $1`) |  |
| 200 | `for_init_statement : declaration_statement` | (default action `$$ = $1`) |  |
| 201 | `conditionopt : condition` | (default action `$$ = $1`) |  |
| 202 | `conditionopt : /* empty */` | 5090 |  |
| 203 | `for_rest_statement : conditionopt SEMICOLON` | 7239 |  |
| 204 | `for_rest_statement : conditionopt SEMICOLON expression` | 7090 |  |
| 205 | `jump_statement : CONTINUE SEMICOLON` | 7244 | `continue statement only allowed in loops` |
| 206 | `jump_statement : BREAK SEMICOLON` | 7256 | `break statement only allowed in loops` |
| 207 | `jump_statement : RETURN SEMICOLON` | 7268 | `non-void function must return a value` |
| 208 | `jump_statement : RETURN expression SEMICOLON` | 7283 | `void function cannot return a value`; `function return is not matching type:`; `return` |
| 209 | `jump_statement : DISCARD SEMICOLON` | 7322 | `discard`; ` supported in fragment shaders only ` |
| 210 | `translation_unit : external_declaration` | 7339 |  |
| 211 | `translation_unit : translation_unit external_declaration` | 7342 |  |
| 212 | `external_declaration : function_definition` | (default action `$$ = $1`) |  |
| 213 | `external_declaration : declaration` | (default action `$$ = $1`) |  |
| 214 | `@function_scope : /* empty */` | 7353 | `function already has a body`; `main`; `function cannot take any parameter(s)`; `function cannot return a value` |
| 215 | `function_definition : function_prototype @function_scope compound_statement_no_new_scope` | 7621 | `function does not return a value`; ` !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXY`; `overloaded functions must have the same return type`; `overloaded functions must have the same parameter qualifiers` |
