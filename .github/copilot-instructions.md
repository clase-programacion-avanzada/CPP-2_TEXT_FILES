# Copilot Instructions for C++ Text File Processing Examples

## Project Overview
This is an educational C++ project demonstrating text file I/O operations with structured data processing. The codebase contains numbered examples that progress from basic file operations to complex data parsing and reporting.

## Architecture & Key Components

### Core Data Structure
- **Movie struct** (`libs/Movie.hh`): Central data model with fixed-size char arrays (not std::string)
  - Uses `char title[256]` for memory-efficient storage
  - Implements both `equals()` method and `operator==` for comparisons
  - Contains incomplete `getMovieFromLine()` function that needs implementation

### File Processing Patterns
- **Progressive examples** (1-6): Each numbered file demonstrates incremental complexity
- **Text data format**: Semicolon-delimited CSV (`id;year;rating;title`)
- **Error handling**: Always use `file.fail()` checks after opening files
- **File modes**: `ios::in` for reading, `ios::out` for writing, `ios::app` for appending

## Development Workflow

### Building & Running
```bash
# Use the configured VS Code task (preferred method)
# VS Code: Ctrl+Shift+P → "Tasks: Run Task" → "C/C++: clang++ build active file"

# Or manually with clang++
clang++ -fcolor-diagnostics -fansi-escape-codes -g <filename>.cpp -o <executable>
```

### File Dependencies
- Include `libs/Movie.hh` for data structures
- Include `libs/TextFileHandler.hh` (currently empty, ready for implementation)
- Data files use `.txt` extension with consistent naming pattern

## Critical Patterns & Conventions

### File I/O Style
```cpp
// Standard pattern used throughout
fstream file;
file.open(fileName, ios::in);  // or ios::out, ios::app
if (file.fail()) {
    cerr << "Error opening file" << endl;
    exit(1);
}
// ... file operations
file.close();  // Always close explicitly
```

### Data Parsing Approach
- Use `getline(file, line)` for line-by-line reading
- Parse semicolon-delimited format: `id;year;rating;title`
- Handle fixed-size char arrays with `strncpy()` for safety
- Example shows both `stringstream` and manual parsing approaches (commented code in Movie.hh)

### Memory Management
- Prefer fixed-size arrays (`char[256]`) over dynamic strings
- Use `strncmp()` for string comparisons in structs
- Initialize arrays with `strncpy(title, "", 256)` in constructors

## Key Implementation Points

### Movie Data Processing
- **Incomplete implementation**: `getMovieFromLine()` in `Movie.hh` needs completion
- **Expected workflow**: Read CSV → Parse to Movie objects → Filter/sort → Generate reports
- **Report format**: Specific header/footer pattern with movie details between delimiters

### Common Tasks
1. **Reading**: Parse CSV data into Movie structs
2. **Filtering**: Movies with rating > 80
3. **Sorting**: By year (newest first), then by rating (highest first)
4. **Reporting**: Formatted output with count statistics

### File Naming Convention
- Examples: `<number>_<operation>_<detail>.cpp` (e.g., `1_reading_text_files.cpp`)
- Data files: `example_<operation>.txt` (e.g., `example_reading.txt`)

## Integration Points
- VS Code tasks configured for clang++ compilation
- Uses standard C++ libraries (`iostream`, `fstream`, `string`, `sstream`)
- Educational context: Comments explain concepts step-by-step
- Real movie data from `example_reading.txt` (87 movies with ratings/years)

## Testing Data
Primary dataset (`example_reading.txt`) contains movies from 1968-2016 with ratings 17-100, perfect for demonstrating filtering and sorting algorithms.
