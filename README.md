*This project has been created as part of the 42 curriculum by malves-a, mtomanar.*

# push_swap

> Sort data on two stacks using the lowest possible number of actions.

A 42 school project: given a set of unique integers in stack `a` (stack `b`
starts empty), display the smallest sequence of Push_swap operations that
sorts `a` in ascending order. Built by **mtomanar** and **malves-a**.

---

## Table of Contents

1. [Rules](#rules)
2. [Allowed Operations](#allowed-operations)
3. [Build](#build)
4. [Usage](#usage)
5. [Flags](#flags)
6. [Algorithms](#algorithms)
7. [Data Structures](#data-structures)
8. [Project Structure](#project-structure)
9. [Performance Targets](#performance-targets)
10. [Authors](#authors)
11. [Resources](#resources)
12. [AI Usage](#ai-usage)
13. [Conclusion](#conclusion)


---

## Rules

- Two stacks: **a** and **b**.
- At the beginning, stack `a` contains a random amount of negative and/or
  positive numbers, none of which are duplicated. Stack `b` is empty.
- The goal is to sort in **ascending order** numbers into stack `a`.
- The program must display the **smallest** list of instructions possible.
- Instructions must be separated by `\n` and nothing else.
- If no arguments are given, the program displays nothing and exits.
- Invalid input (non-integer, duplicates, overflow) prints `Error` on stderr.

---

## Allowed Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements of stack `a`. Does nothing if there is one or no elements. |
| `sb` | Swap the first 2 elements of stack `b`. Does nothing if there is one or no elements. |
| `ss` | `sa` and `sb` at the same time. |
| `pa` | Take the first element of `b` and put it at the top of `a`. Does nothing if `b` is empty. |
| `pb` | Take the first element of `a` and put it at the top of `b`. Does nothing if `a` is empty. |
| `ra` | Shift all elements of stack `a` up by 1. The first element becomes the last. |
| `rb` | Shift all elements of stack `b` up by 1. The first element becomes the last. |
| `rr` | `ra` and `rb` at the same time. |
| `rra` | Shift all elements of stack `a` down by 1. The last element becomes the first. |
| `rrb` | Shift all elements of stack `b` down by 1. The last element becomes the first. |
| `rrr` | `rra` and `rrb` at the same time. |

---

## Build

```bash
make        # compile push_swap
make clean  # remove object files
make fclean # remove object files and binary
make re     # full rebuild
```

The Makefile compiles with `-Wall -Wextra -Werror`.

---

## Usage

```bash
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3 6 5 8"
./push_swap 4 67 3 87 23 -5
```

Arguments can be passed as separate integers or as quoted space-separated
strings. The first argument is at the top of the stack.

**Example output:**

```
$ ./push_swap 2 1 3 6 5 8
sa
rra
```

---

## Flags

Flags must appear **before** the numeric arguments and start with `--`.

| Flag | Description |
|------|-------------|
| `--simple` | Force the simple O(n^2) selection-sort strategy. |
| `--medium` | Force the medium O(n sqrt(n)) chunk-sort strategy. |
| `--complex` | Force the complex O(n log n) radix-sort strategy. |
| `--adaptive` | **(default)** Automatically choose the best strategy based on disorder. |
| `--bench` | Print a benchmark report to stderr after sorting. |

```bash
./push_swap --complex "4 67 3 87 23"
./push_swap --adaptive --bench 5 1 4 2 3
./push_swap --simple --bench 10 7 3 9 1 5
```

**Benchmark output example** (to stderr):

```
Disorder:  73.33%
Strategy:  complex
Complexity: O(n log(n))
Total ops: 42
sa: 0 | sb: 0 | ss: 0
pa: 6 | pb: 6 | ra: 12
rb: 0 | rr: 0  | rra: 18
rrb: 0 | rrr: 0
```

---

## Algorithms

Before sorting, the program computes a **disorder metric**: the ratio of
inverted pairs to total pairs. Values are then coordinate-compressed to their
ranks (0 to n-1), enabling all strategies to work with dense integers regardless
of the original values.

### Simple -- O(n^2)

A naive selection sort. Repeatedly finds the minimum element in stack `a`,
rotates it to the top (choosing the shorter direction), pushes it to `b`,
then pushes everything back to `a`.

Used when disorder is low (< 0.2), meaning the stack is nearly sorted.

### Medium -- O(n sqrt(n))

A chunk-based sort. Partitions the normalized values into `sqrt(n)` chunks.
For each chunk, pushes its elements from `a` to `b`. Then empties `b` back
into `a` by repeatedly finding the maximum in `b`, rotating it to the top,
and pushing it.

Used when disorder is moderate (0.2 <= disorder < 0.5).

### Complex -- O(n log n)

An LSD (Least Significant Digit) binary radix sort. For each bit position
from 0 to `log2(n)`, partitions elements by that bit: bits that are 0 go to
`b` via `pb`, bits that are 1 stay in `a` via `ra`. After each pass,
everything is pushed back from `b` to `a`. The number of passes is
`ceil(log2(n))`.

Used when disorder is high (>= 0.5), meaning the stack is heavily shuffled.

### Adaptive (default)

Selects the strategy automatically based on the disorder metric:

| Disorder | Strategy |
|----------|----------|
| < 0.2 | Simple (nearly sorted -- few moves needed) |
| 0.2 -- 0.5 | Medium (moderate shuffling) |
| >= 0.5 | Complex (heavily shuffled) |

---

## Data Structures

```c
typedef struct s_stack
{
    int             *values;    // array of integers
    long            size;       // current number of elements
    int             capacity;   // allocated capacity
    struct s_stats  *stats;     // operation counter (NULL if disabled)
} t_stack;

typedef struct s_stats
{
    long    counts[11];  // one counter per operation (sa..rrr)
    long    total;       // total operations executed
} t_stats;

typedef struct s_config
{
    t_strategy  strategy;   // SIMPLE, MEDIUM, COMPLEX, or ADAPTIVE
    int         bench;      // 1 = print benchmark to stderr
} t_config;
```

---

## Project Structure

```
push_swap/
├── Makefile              # Build rules: all, clean, fclean, re
├── push_swap.h           # Header: structs, enums, all prototypes
│
├── main.c                # Entry point, error handling, program flow
│
│   ── Parsing (malves-a) ──
├── split.c               # ft_split: tokenize strings by separator
├── parse.c               # (placeholder -- logic in parse_number.c)
├── parse_number.c        # ft_atoi_safe, parse_args, overflow checks
├── count_elements.c      # Count total integers across all arguments
├── parse_flags.c         # Parse --simple/--medium/--complex/--bench flags
│
│   ── Stack Management (malves-a) ──
├── stack_init.c          # init_stack, free_stack, alloc_stack
├── check_duplicates.c    # has_duplicate, is_sorted
├── disorder.c            # compute_disorder: inverted-pair ratio
│
│   ── Operations (mtomanar) ──
├── op_swap.c             # ft_swap, sa, sb, ss
├── op_push.c             # ft_push, pa, pb
├── op_rotate.c           # ft_rotate, ra, rb, rr
├── op_reverse.c          # ft_reverse, rra, rrb, rrr
│
│   ── Sorting Algorithms ──
├── sort_small.c          # ft_sort_small: 3-5 elements (mtomanar)
├── sort_helpers.c        # sort_two, sort_three (malves-a)
├── sort_radix.c          # ft_sort_radix: LSD radix sort (malves-a)
├── sort_chunk.c          # ft_chunk_sort: chunk-based sort (mtomanar)
├── push_swap.c           # sort_stack, ft_sort_simple, strategy dispatch (malves-a)
│
│   ── Utilities ──
├── utils.c               # strcmp
├── utils_chunk.c         # ft_sqrt, normalize_stack, ft_haschunk (mtomanar)
├── operation_log.c       # print_operation, print_benchmark (malves-a)
```

---

## Performance Targets

Based on the 42 correction sheet:

| Input Size | Maximum Allowed Operations |
|------------|---------------------------|
| 3 numbers | 2 |
| 5 numbers | 12 |
| 100 numbers | 700 |
| 500 numbers | 5500 |

---

## Authors

| Student | Role | Files |
|---------|------|-------|
| **mtomanar** | Operations & core algorithms | `op_swap.c`, `op_push.c`, `op_rotate.c`, `op_reverse.c`, `sort_small.c`, `sort_chunk.c`, `utils_chunk.c` |
| **malves-a** | Parsing, validation, strategy & benchmark | `main.c`, `push_swap.c`, `split.c`, `parse.c`, `parse_number.c`, `count_elements.c`, `parse_flags.c`, `disorder.c`, `check_duplicates.c`, `stack_init.c`, `utils.c`, `sort_helpers.c`, `sort_radix.c`, `operation_log.c` |

---

## Resources

The following resources were used to understand the concepts required by the project:

* **42 push_swap subject** — Official project requirements and allowed operations.
* **C documentation** — Reference for arrays, pointers, structures, dynamic memory allocation, and functions.
* **GNU C Library / C reference documentation** — Reference for standard C concepts and memory management.
* **Algorithm and data structure references** — Used to understand sorting strategies, indexing, complexity, and stack manipulation.
* **42 peer learning and code reviews** — Used to discuss implementation approaches and identify problems in the algorithms.

## AI Usage

AI tools were used as a learning and development aid during the project.

AI was mainly used for:

* Explaining C concepts and pointer manipulation;
* Discussing different ways of implementing stacks;
* Understanding array-based stack operations;
* Reviewing and debugging operation implementations;
* Understanding sorting strategies such as simple sorting and chunk sorting;
* Helping identify logic errors in the algorithms;
* Refactoring functions to respect the 42 coding standards, including the 25-line function limit;
* Reviewing code structure and suggesting improvements.

AI was **not used to replace the understanding or implementation of the project**. The generated suggestions were reviewed, tested, adapted, and integrated manually.

In particular, the implementation of the push, swap, rotate, reverse rotate, simple, small, and chunk components was developed and adapted as part of the project work.

---

## Conclusion

The `push_swap` project combines data structures, algorithm design, memory management, and optimization.

The implementation demonstrates how the choice of data structure and sorting strategy affects the number of operations required to solve the same problem.

The use of specialized algorithms for small inputs and a chunk-based strategy for larger inputs provides a practical balance between simplicity, performance, and maintainability.