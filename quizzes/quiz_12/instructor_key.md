# Quiz 12 Answer Key — INSTRUCTOR-ONLY

**Restricted** per [../../instructor/ACCESS_CONTROL.md](../../instructor/ACCESS_CONTROL.md).
Week 12 · lectures L23–L24 · Searching and Sorting · total 10 marks · CLO-6

**Q1 (1 mk) — B**



**Q2 (1 mk) — B**



**Q3 (1 mk) — B**



**Q4 (2 mk) — 1 2 9 5**

Pass 0 swaps the minimum (1) into position 0; positions 1–3 keep 2, 9, 5 in order. Verified by hand and by machine.

**Q5 (2 mk) — high = n with low <= high can read a[n] (out of bounds) or loop on absent keys; pick one discipline: high = n-1 with low <= high, or high = n with low < high.**



**Q6 (2 mk) — Equal keys keep their relative input order.**



**Q7 (1 mk) — C**

log2(1000) is about 10.

## Common wrong answers to watch for

Q4: accept only the exact post-pass-0 row; Q6: 'stable' confused with 'fast' frequently.