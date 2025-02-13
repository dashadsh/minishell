# Minishell Parser

## Overview
The parser component of the minishell project is responsible for processing and validating user input commands. It consists of several stages that transform raw input into a structured format that can be executed by the shell.

## Components

### 1. Early Error Checking
Located in `01early_err.c` and related utility files, this stage performs initial validation of the input:

- **Spaces Check**: Ensures the input isn't just whitespace
- **Quotes Check**: Validates matching quotes (single and double)
- **Pipes Check**: Ensures proper pipe syntax
- **Special Characters**: Validates allowed special characters
- **Redirections**: Checks proper syntax for input/output redirections

### 2. Parser
The main parser (`02parser.c`) orchestrates three main operations:
- Removes consecutive quotes
- Tokenizes the input
- Expands environment variables and special parameters

### 3. Tokenizer
Implemented in `03tokenizer.c` and its utility files, this component breaks down the command into meaningful tokens:

#### Token Types:
- `WORD`: Regular command words and arguments
- `PIPE`: Command pipe operator (|)
- `SEP`: Separators (spaces)
- `IN_RED`: Input redirection (<)
- `OUT_RED`: Output redirection (>)
- `HERE_DOC`: Here document (<<)
- `APP_RED`: Append redirection (>>)

#### Token Initialization Functions:
- `init_in_quotes`: Handles quoted strings
- `init_pipe_or_sep`: Processes pipes and separators
- `init_single_redirection`: Handles < and > operators
- `init_double_redirection`: Handles << and >> operators
- `init_word`: Processes regular words

### 4. Expander
Located in `04expander.c` and related files, this component handles variable expansion:

#### Features:
- Environment variable expansion ($VAR)
- Exit status expansion ($?)
- PID expansion ($$)
- Quote handling (prevents expansion in single quotes)

## Implementation Details

### Error Handling
- Proper memory allocation checks
- Syntax validation
- Quote matching
- Redirection syntax verification

### Memory Management
- Dynamic allocation for tokens
- Proper freeing of resources
- Prevention of memory leaks

### Quote Handling
- Support for both single (') and double (") quotes
- Preservation of quoted content
- Special handling of nested quotes

## Usage Example
```bash
# Valid command examples
echo "Hello $USER"    # Expands environment variable
echo 'Hello $USER'    # Preserves literal string
ls -l | grep "file"   # Pipe operation
echo test > outfile   # Output redirection

# Invalid commands (will be caught by error checking)
echo "unclosed quote  # Missing closing quote
|                     # Pipe without command
ls >>                 # Redirection without target
```

## Technical Notes

1. **Quote Removal**:
   - Consecutive quotes of the same type are removed
   - Quotes inside other quotes are preserved
   - Example: `echo hi""bye` becomes `echo hibye`

2. **Environment Variables**:
   - Expanded in double quotes
   - Preserved literally in single quotes
   - $? expands to last exit status
   - $$ displays as a single $

3. **Redirections**:
   - Supports standard input/output
   - Handles append mode
   - Implements here documents
   - Validates file names and descriptors

## Error Messages
The parser provides clear error messages for various scenarios:
- `minishell: unsupported open quotes`
- `minishell: token error: '|'`
- `minishell: unsupported special char`
- `minishell: token error: '<' or '>'`

## Data Structures

### Token Structure
```c
typedef struct s_token {
    char            *string;    // Token content
    enum e_type     type;      // Token type
    enum e_quotes   quote_type; // Quote type if applicable
    struct s_token  *next;     // Next token in list
} t_token;
```

## Limitations
- Does not support certain special characters (;, &, \, *, etc.)
- Limited to basic redirection operations
- No support for advanced shell features (&&, ||, etc.)