# sort_radix.c -- Refactoring Report

**File:** sort_radix.c
**Date:** 2026-08-28
**Goal:** Reduce all functions to max 25 lines, keep exactly 5 functions max.

---

## Problem

The original file had 5 functions, but `ft_sort_radix` was 30 lines
(over the 25-line limit). `max_bits` was a trivial 6-line helper called
only once.

---

## Summary of Changes

| Action | Function | Lines Before | Lines After |
|--------|----------|-------------|-------------|
| Kept   | sort_copy | 23 | 23 |
| Kept   | value_rank | 13 | 13 |
| Kept   | sorted_values | 17 | 17 |
| Removed | max_bits | 12 | -- (inlined) |
| Added  | radix_pass | -- | 17 |
| Rewritten | ft_sort_radix | 30 | 25 |

**Result: 5 functions, all under 25 lines. Zero behavioral change.**

---

## What Was Removed

### max_bits (was lines 71-84)

```
static int	max_bits(int size)
{
	int	bits;
	int	max;

	bits = 0;
	max = size - 1;
	while (max > 0)
	{
		bits++;
		max >>= 1;
	}
	return (bits);
}
```

**Why removed:** This function was a 6-line loop that only computed
`ceil(log2(size))`. It was called exactly once, inside `ft_sort_radix`.
Extracting such a trivial operation into its own function adds call
overhead with no clarity gain. The logic was inlined directly into
`ft_sort_radix` (lines 99-105 of the new file).

---

## What Was Added

### radix_pass (new, lines 71-87)

```
static void	radix_pass(t_stack *a, t_stack *b, int *sorted, int bit)
{
	int	count;
	int	size;

	size = a->size;
	count = a->size;
	while (count-- > 0)
	{
		if ((value_rank(sorted, size, a->values[0]) >> bit) & 1)
			ra(a);
		else
			pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
}
```

**Why added:** The original `ft_sort_radix` had the entire per-bit-pass
logic (the `while(count--)` loop + the `while(b->size > 0)` drain)
nested inside the outer `while(bit < bits)` loop. This inner block was
the reason `ft_sort_radix` exceeded 25 lines. Extracting it into its own
function makes each function single-responsibility.

**Line-by-line:**

- `static void` -- file-internal only, no external linkage needed.
- `int count` -- loop counter, captures `a->size` before modifications.
- `int size` -- snapshot of `a->size` for `value_rank` calls, since
  `a->size` shrinks as elements are pushed to `b`.
- `size = a->size` -- take the snapshot before the loop starts.
- `count = a->size` -- will decrement to zero, processing every element.
- `while (count-- > 0)` -- process all elements currently in stack `a`.
- `value_rank(sorted, size, a->values[0])` -- maps the top value of `a`
  to its normalized rank (0 to size-1).
- `>> bit` -- right-shifts to expose the bit at position `bit`.
- `& 1` -- isolates that bit.
- `ra(a)` -- bit is 1: rotate element to bottom of `a` (keep in `a`).
- `pb(a, b)` -- bit is 0: push element to `b`.
- `while (b->size > 0) pa(a, b)` -- drain `b` back into `a` after the
  full pass. Elements return to `a` in stable order for this bit.

---

## What Was Rewritten

### ft_sort_radix (was lines 86-115, now lines 89-113)

**Before (30 lines):**

```
void	ft_sort_radix(t_stack *a, t_stack *b)
{
	int	*sorted;
	int	size;
	int	bits;
	int	bit;
	int	count;

	size = a->size;
	sorted = sorted_values(a);
	if (!sorted)
		return ;
	bits = max_bits(size);
	bit = 0;
	while (bit < bits)
	{
		count = a->size;
		while (count-- > 0)
		{
			if ((value_rank(sorted, size, a->values[0]) >> bit) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
	free(sorted);
}
```

**After (25 lines):**

```
void	ft_sort_radix(t_stack *a, t_stack *b)
{
	int	*sorted;
	int	bits;
	int	bit;
	int	max;

	sorted = sorted_values(a);
	if (!sorted)
		return ;
	max = a->size - 1;
	bits = 0;
	while (max > 0)
	{
		bits++;
		max >>= 1;
	}
	bit = 0;
	while (bit < bits)
	{
		radix_pass(a, b, sorted, bit);
		bit++;
	}
	free(sorted);
}
```

**Line-by-line diff:**

- `int size;` was removed -- no longer needed, `radix_pass` captures
  `a->size` internally.
- `int count;` was removed -- now local to `radix_pass`.
- `int max;` was added -- holds `a->size - 1` for the inlined bit count.
- `size = a->size;` was removed -- was only used to pass to `max_bits`
  and `value_rank`. Both are now handled elsewhere.
- `sorted = sorted_values(a);` -- unchanged. mallocs a sorted copy.
- `if (!sorted) return ;` -- unchanged. malloc guard.
- `max = a->size - 1;` -- replaces `max_bits(size)`. Same logic, inline.
- `bits = 0;` -- same init, was inside `max_bits`.
- `while (max > 0) { bits++; max >>= 1; }` -- same loop, was inside
  `max_bits`.
- `bit = 0;` -- unchanged. Loop counter.
- `while (bit < bits)` -- unchanged. Outer radix loop.
- `radix_pass(a, b, sorted, bit);` -- replaces the entire 10-line inner
  block (count loop + drain loop). Single function call.
- `bit++;` -- unchanged.
- `free(sorted);` -- unchanged. Frees the malloc'd sorted copy.

---

## What Was NOT Changed

### sort_copy (lines 15-37, 23 lines)

Bubble-sorts an integer array in-place. Used by `sorted_values` to
create the rank-mapping reference array. Unchanged because it was already
under the 25-line limit and served its purpose cleanly.

### value_rank (lines 39-51, 13 lines)

Linear search returning the index (rank) of a value in a sorted array.
Used by `radix_pass` to map each stack value to its normalized rank.
Unchanged.

### sorted_values (lines 53-69, 17 lines)

Allocates a copy of `a->values`, sorts it with `sort_copy`, and returns
it. Used once at the start of `ft_sort_radix`. Unchanged.

---

## Compilation

Compiled with `make re` using flags `-Wall -Wextra -Werror -fsanitize=address`.
Zero warnings, zero errors. Behavioral output is identical to the original.
