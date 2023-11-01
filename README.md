# Term Project - A Pascal Subset Compiler (Stolen from CSC 645 @ Adelphi University)

#### Note: I am doing this project for fun. I'm not currently enrolled in this course and the code present here may not be used for academic dishonesty. The following project description has been stripped from the CSC 645 webpage, available here: https://home.adelphi.edu/~siegfried/cs645/645ProjSpec.html

## Project Description

This term project involves implementing a compiler for a subset of the Pascal programming language. The subset is based on Turbo Pascal but simplified by omitting arrays and records for ease of implementation. The project components include a scanner, symbol table, parser, and, if time permits, a type checker and intermediate code generator.

## Language Specifications

### Lexical Conventions

- Comments are enclosed in curly braces `{}`.
- Blanks between tokens are generally optional, except that reserved words must be surrounded by blanks, newlines, the beginning of the program, or the final period.
- Token `id` matches a letter or a letter followed by letters and digits:
  - `letter` → `[a-zA-Z]`
  - `digit` → `[0-9]`
  - `id` → `letter (letter | digit)*`
- Token `num` matches unsigned integers:
  - `digits` → `digit digit*`
  - `optional_fractional` → `. digits | →`
  - `optional_exponent` → `(E | (+ | - | e) digits) | →`
  - `num` → `digits optional_fraction optional_exponent`

### Keywords

Keywords are reserved words and appear in boldface in the grammar.

### Operators

- Relational operators (relops): `=`, `>`, `<`, `>=`, `<=`, `<>`
- Addops: `+`, `-`, `OR`
- Mulops: `*`, `/`, `DIV`, `MOD`, `AND`
- The lexeme for the `assignop` is `:=`

### Pascal Subset Syntax

#### Program Structure

- `Program` → `Header Declarations Block .`
- `Header` → `program id ;`

#### Declarations

- `Declarations` → `VariableDeclarationSection ProcedureDeclarations`
- `VariableDeclarationSection` → `VAR VariableDeclarations` or ε (empty)
- `VariableDeclarations` → `VariableDeclarations VariableDeclaration` or `VariableDeclaration`
- `VariableDeclaration` → `IdentifierList : Type ;`
- `IdentifierList` → `IdentifierList , id` or `id`
- `Type` → `integer` or `real`

#### Procedure Declarations

- `ProcedureDeclarations` → `ProcedureHeader Declarations Block ;`
- `ProcedureHeader` → `procedure id ;`

#### Block and Statements

- `Block` → `begin Statements end`
- `Statements` → `Statements ; Statement` or `Statement`
- `Statement` can be:
  - `id := Expression`
  - `id ()`
  - `Block`
  - `if Expression then Statement ElseClause`
  - `while Expression do Statement`
  - ε (empty)

#### Expression and Operators

- `ElseClause` → `else Statement` or ε (empty)
- `ExpressionList` → `ExpressionList , Expression` or `Expression`
- `Expression` → `SimpleExpression relop SimpleExpression` or `SimpleExpression`

#### Simple Expression

- `SimpleExpression` → `Term` or `addop Term` or `SimpleExpression addop Term`

#### Term and Factors

- `Term` → `Term mulop Factor` or `Factor`
- `Factor` can be:
  - `id`
  - `num`
  - `( Expression )`
  - `not Factor`

This README provides an overview of the term project, its components, and the specific syntax and lexical conventions of the Pascal subset language you will be working with.
